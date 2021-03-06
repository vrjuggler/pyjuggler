// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

// Includes ====================================================================
#include <vrj/Kernel/Kernel.h>
#include <vrj/Kernel/App.h>
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_Kernel_Wrapper : vrj::Kernel, wrapper<vrj::Kernel>
{
   virtual ~vrj_Kernel_Wrapper()
   {
      /* Do nothing. */ ;
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return vrj::Kernel::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::Kernel::configCanHandle(p0);
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return vrj::Kernel::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::Kernel::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return vrj::Kernel::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::Kernel::configRemove(p0);
   }

   int configProcessPending()
   {
      try
      {
         if ( override configProcessPending =
                 this->get_override("configProcessPending") )
         {
            return configProcessPending();
         }
         return jccl::ConfigElementHandler::configProcessPending();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   int default_configProcessPending()
   {
      return jccl::ConfigElementHandler::configProcessPending();
   }
};

void vrj_Kernel_init(vrj::Kernel* kernel, list pythonArgv)
{
   const int orig_len = extract<int>(pythonArgv.attr("__len__")());
   int argc = orig_len;
   std::vector<char*> argv(argc);

   for ( int i = 0; i < argc; ++i )
   {
      argv[i] = extract<char*>(pythonArgv[i]);
   }

   kernel->init(argc, &argv[0]);

   // vrj::Kernel::init() may have removed items from argv by relocating them
   // to the range [argc,orig_len) within argv. We need to remove each of
   // those values from pythonArgv.
   for ( int i = argc; argc < orig_len; ++i )
   {
      pythonArgv.remove(argv[i]);
   }
}

void vrj_Kernel_waitForKernelStop(vrj::Kernel* kernel)
{
   // A VR Juggler application written entirely in Python will call
   // vrj.Kernel.waitForKernelStop() and block until the kernel shuts down.
   // This is definitely a blocking I/O kind of case, so we need to release
   // the global interpreter lock before we block on the kernel shutdown
   // condition.
   Py_BEGIN_ALLOW_THREADS;
      kernel->waitForKernelStop();
   Py_END_ALLOW_THREADS;
}

}// namespace 


// Module ======================================================================
void _Export_Kernel()
{
   class_<pyj::vrj_Kernel_Wrapper, boost::noncopyable>("Kernel",
       "Main control class for all VR Juggler applications.\n\n"
       "The kernel takes care of all initialization and object creation.\n"
       "This class is the only class that MUST be instantiated for all\n"
       "application objects."
       ,
       no_init
      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::vrj_Kernel_Wrapper::default_configProcessPending,
           "configProcessPending() -> int\n"
           "Inherited from jccl.ConfigElementHandler and not overridden."
      )
      .def("init", &pyj::vrj_Kernel_init,
           "init(list)\n"
           "Parses command line arguments."
      )
      .def("start", &vrj::Kernel::start,
           "start()\n"
           "Starts the kernel running by spawning the kernel thread."
      )
      .def("stop", &vrj::Kernel::stop,
           "Stops the kernel control loop.  If there is an application\n"
           "set, then it will be closed first.\n\n"
           "Post-conditions:\n"
           "The kernel exits, and the VR Juggler system shuts down."
      )
      .def("isRunning", &vrj::Kernel::isRunning,
           "isRunning() -> Boolean\n"
           "Returns the status of the kernel."
      )
      .def("waitForKernelStop", pyj::vrj_Kernel_waitForKernelStop,
           "waitForKernelStop()\n"
           "Blocks until the kernel exits."
      )
      .def("setApplication", &vrj::Kernel::setApplication,
           "setApplication(newApp)\n"
           "Sets the application object for the kernel to deal with.  If\n"
           "there is another application active, the kernel has to stop\n"
           "that application first and then restart all graphics\n"
           "API-specific Managers.\n\n"
           "Arguments:\n"
           "newApp -- An instance of vrj.App.  If it is None, the current\n"
           "          application is stopped."
      )
      .def("loadConfigFile",
           (void (vrj::Kernel::*)(const char*) )&vrj::Kernel::loadConfigFile,
           "loadConfigFile(filename)\n"
           "Loads configuration data for the kernel.\n\n"
           "Post-conditions:\n"
           "Config data has been read into the initial buffer.\n\n"
           "Arguments:\n"
           "filename -- The string name of the configuration file to load."
      )
      .def("scanForConfigDefinitions",
           &vrj::Kernel::scanForConfigDefinitions,
           "scanForConfigDefinitions(path)\n"
           "Scans the given directory (or directories) for .jdef files\n"
           "and loads all discovered files into the JCCL Element Factory.\n\n"
           "Post-conditions:\n"
           "The Element Factory can now manage elements with the discovered\n"
           "types.\n\n"
           "Arguments:\n"
           "path -- One or more directories, delineated by a\n"
           "        platform-specific path separator, that will be searched\n"
           "        for .jdef files."
      )
      .def("getUser", &vrj::Kernel::getUser,
           "getUser(userName) -> vrj.User object\n"
           "Gets the user associated with the given name.\n\n"
           "Arguments:\n"
           "name -- The name of the user to be returned."
      )
      .def("getUsers", &vrj::Kernel::getUsers,
           return_value_policy<copy_const_reference>(),
           "getUsers() -> vrj.UserVec object (indexable container)\n"
           "Returns an indexable container of all the users."
      )
      .def("instance", &vrj::Kernel::instance,
           return_value_policy<reference_existing_object>(),
           "vrj.Kernel.instance() -> vrj.Kernel object\n"
           "Returns the singleton VR Juggler kernel reference."
      )
      .staticmethod("instance")
   ;

   class_< std::vector<vrj::UserPtr> >("UserVec",
       "An indexable container of vrj.User objects."
      )
      .def(vector_indexing_suite< std::vector<vrj::UserPtr> >())
   ;
}
