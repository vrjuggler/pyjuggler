// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/OpenGL/DrawManager.h>
#include <vrj/Draw/OpenGL/App.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_opengl_App_Wrapper : vrj::opengl::App, wrapper<vrj::opengl::App>
{
   vrj_opengl_App_Wrapper(vrj::Kernel* const& kernel = NULL)
      : vrj::opengl::App(kernel)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_opengl_App_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void draw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::draw()\n",
                               "vrj_opengl_App_Wrapper::draw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("draw")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void contextInit()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::contextInit()\n",
         "vrj_opengl_App_Wrapper::contextInit() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextInit = this->get_override("contextInit") )
         {
            contextInit();
         }
         else
         {
            vrj::opengl::App::contextInit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextInit()
   {
      vrj::opengl::App::contextInit();
   }

   void contextClose()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::contextClose()\n",
         "vrj_opengl_App_Wrapper::contextClose() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextClose = this->get_override("contextClose") )
         {
            contextClose();
         }
         else
         {
            vrj::opengl::App::contextClose();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextClose()
   {
      vrj::opengl::App::contextClose();
   }

   void contextPreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::contextPreDraw()\n",
         "vrj_opengl_App_Wrapper::contextPreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPreDraw = this->get_override("contextPreDraw") )
         {
            contextPreDraw();
         }
         else
         {
            vrj::opengl::App::contextPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPreDraw()
   {
      vrj::opengl::App::contextPreDraw();
   }

   void contextPostDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::contextPostDraw()\n",
         "vrj_opengl_App_Wrapper::contextPostDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override contextPostDraw = this->get_override("contextPostDraw") )
         {
            contextPostDraw();
         }
         else
         {
            vrj::opengl::App::contextPostDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPostDraw()
   {
      vrj::opengl::App::contextPostDraw();
   }

   void bufferPreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::bufferPreDraw()\n",
         "vrj_opengl_App_Wrapper::bufferPreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override bufferPreDraw = this->get_override("bufferPreDraw") )
         {
            bufferPreDraw();
         }
         else
         {
            vrj::opengl::App::bufferPreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_bufferPreDraw()
   {
      vrj::opengl::App::bufferPreDraw();
   }

   void pipePreDraw()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::pipePreDraw()\n",
         "vrj_opengl_App_Wrapper::pipePreDraw() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override pipePreDraw = this->get_override("pipePreDraw") )
         {
            pipePreDraw();
         }
         else
         {
            vrj::opengl::App::pipePreDraw();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_pipePreDraw()
   {
      vrj::opengl::App::pipePreDraw();
   }

   void init()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::init()\n",
                               "vrj_opengl_App_Wrapper::init() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override init = this->get_override("init") )
         {
            init();
         }
         else
         {
            vrj::opengl::App::init();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_init()
   {
      vrj::opengl::App::init();
   }

   void apiInit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::apiInit()\n",
                               "vrj_opengl_App_Wrapper::apiInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override apiInit = this->get_override("apiInit") )
         {
            apiInit();
         }
         else
         {
            vrj::opengl::App::apiInit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_apiInit()
   {
      vrj::opengl::App::apiInit();
   }

   void exit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::exit()\n",
                               "vrj_opengl_App_Wrapper::exit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override exit = this->get_override("exit") )
         {
            exit();
         }
         else
         {
            vrj::opengl::App::exit();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_exit()
   {
      vrj::opengl::App::exit();
   }

   void preFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::preFrame()\n",
                               "vrj_opengl_App_Wrapper::preFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override preFrame = this->get_override("preFrame") )
         {
            preFrame();
         }
         else
         {
            vrj::opengl::App::preFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_preFrame()
   {
      vrj::opengl::App::preFrame();
   }

   void latePreFrame()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::latePreFrame()\n",
         "vrj_opengl_App_Wrapper::latePreFrame() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override latePreFrame = this->get_override("latePreFrame") )
         {
            latePreFrame();
         }
         else
         {
            vrj::opengl::App::latePreFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_latePreFrame()
   {
      vrj::opengl::App::latePreFrame();
   }

   void intraFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::intraFrame()\n",
                               "vrj_opengl_App_Wrapper::intraFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override intraFrame = this->get_override("intraFrame") )
         {
            intraFrame();
         }
         else
         {
            vrj::opengl::App::intraFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_intraFrame()
   {
      vrj::opengl::App::intraFrame();
   }

   void postFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::postFrame()\n",
                               "vrj_opengl_App_Wrapper::postFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override postFrame = this->get_override("postFrame") )
         {
            postFrame();
         }
         else
         {
            vrj::opengl::App::postFrame();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_postFrame()
   {
      vrj::opengl::App::postFrame();
   }

   void reset()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::reset()\n",
                               "vrj_opengl_App_Wrapper::reset() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override reset = this->get_override("reset") )
         {
            reset();
         }
         else
         {
            vrj::opengl::App::reset();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_reset()
   {
      vrj::opengl::App::reset();
   }

   void focusChanged()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::focusChanged()\n",
         "vrj_opengl_App_Wrapper::focusChanged() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override focusChanged = this->get_override("focusChanged") )
         {
            focusChanged();
         }
         else
         {
            vrj::opengl::App::focusChanged();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_focusChanged()
   {
      vrj::opengl::App::focusChanged();
   }

   float getDrawScaleFactor()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::getDrawScaleFactor()\n",
         "vrj_opengl_App_Wrapper::getDrawScaleFactor() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override getDrawScaleFactor =
                 this->get_override("getDrawScaleFactor") )
         {
            return getDrawScaleFactor();
         }
         return vrj::opengl::App::getDrawScaleFactor();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vrj::opengl::App::getDrawScaleFactor();
   }

   float default_getDrawScaleFactor()
   {
      return vrj::opengl::App::getDrawScaleFactor();
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::configCanHandle()\n",
         "vrj_opengl_App_Wrapper::configCanHandle() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configCanHandle = this->get_override("configCanHandle") )
         {
            return configCanHandle(p0);
         }
         return vrj::opengl::App::configCanHandle(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::App::configCanHandle(p0);
   }

   bool depSatisfied()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::depSatisfied()\n",
         "vrj_opengl_App_Wrapper::depSatisfied() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override depSatisfied = this->get_override("depSatisfied") )
         {
            return depSatisfied();
         }
         return vrj::opengl::App::depSatisfied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return true;
   }

   bool default_depSatisfied()
   {
      return vrj::opengl::App::depSatisfied();
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_opengl_App_Wrapper::configAdd()\n",
                               "vrj_opengl_App_Wrapper::configAdd() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configAdd = this->get_override("configAdd") )
         {
            return configAdd(p0);
         }
         return vrj::opengl::App::configAdd(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::App::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::configRemove()\n",
         "vrj_opengl_App_Wrapper::configRemove() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override configRemove = this->get_override("configRemove") )
         {
            return configRemove(p0);
         }
         return vrj::opengl::App::configRemove(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::opengl::App::configRemove(p0);
   }

   vrj::DrawManager* getDrawManager()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::getDrawManager()\n",
         "vrj_opengl_App_Wrapper::getDrawManager() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         if ( override getDrawManager = this->get_override("getDrawManager") )
         {
           return getDrawManager();
         }
         return vrj::opengl::App::getDrawManager();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return NULL;
   }

   void default_getDrawManager()
   {
      vrj::opengl::App::getDrawManager();
   }

   int configProcessPending()
   {
      vpr::DebugOutputGuard og(
         pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_opengl_App_Wrapper::configProcessPending()\n",
         "vrj_opengl_App_Wrapper::configProcessPending() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

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

}// namespace 


// Module ======================================================================
void _Export_App()
{
   class_<pyj::vrj_opengl_App_Wrapper, bases<vrj::App>, boost::noncopyable>
      ("App",
       "vrj.opengl.App encapsulates an actual OpenGL application object.\n"
       "This defines the base class from which OpenGL-based application\n"
       "objects should be derived.  The interface given what the kernel\n"
       "and the OpenGL Draw Manager expect in order to interact with the\n"
       "application object.\n\n"
       "The control loop will look similar to this:\n\n"
       "glapp_obj.contextInit()        # called for each context\n"
       "while drawing:\n"
       "   glapp_obj.preFrame()\n"
       "   glapp_obj.latePreFrame()\n"
       "   glapp_obj.bufferPreDraw()   # called for each draw buffer\n"
       "   glapp_obj.contextPreDraw()  # called for each context\n"
       "   glapp_obj.draw()            # called for each viewport\n"
       "   glapp_obj.contextPostDraw() # called for each context\n"
       "   glapp_obj.intraFrame()      # called in parallel to the draw functions\n"
       "   sync()\n"
       "   glapp_obj.postFrame()\n\n"
       "   updateAllDevices()\n"
       "glapp_obj.contextClose()       # called for each context\n\n"
       "Note: One time through the loop is a Juggler Frame.\n\n"
       "See also: vrj.App, vrj.Kernel"
       ,
       init< optional<vrj::Kernel*> >(
          "__init__()\n"
          "Default constructor.  Uses vrj.Kernel.instance().\n\n"
          "__init__(kernel)\n"
          "Arguments:\n"
          "kernel -- The vrj.Kernel instance that is active (so the\n"
          "          application has easy access to the kernel)."
       )
      )
      .def("draw", pure_virtual(&vrj::opengl::App::draw),
           "draw()\n"
           "Function that renders the scene.  Override this function with\n"
           "the application-specific rendering routine.\n\n"
           "Pre-condition:\n"
           "OpenGL state has transformation and buffer selected.\n\n"
           "Post-condition:\n"
           "The current scene has been drawn."
      )
      .def("contextInit", &vrj::opengl::App::contextInit,
           &pyj::vrj_opengl_App_Wrapper::default_contextInit,
           "contextInit()\n"
           "Function that is called immediately after a new context is\n"
           "created.  Use this function to create context-specific data\n"
           "structures such as display lists and texture objects that are\n"
           "known to be required when the context is created.\n\n"
           "Pre-condition:\n"
           "The OpenGL context has been set to the new context.\n\n"
           "Post-condition:\n"
           "The application has completed context-specific initialization."
      )
      .def("contextClose", &vrj::opengl::App::contextClose,
           &pyj::vrj_opengl_App_Wrapper::default_contextClose,
           "contextClose()\n"
           "Function that is called immediately before a context is closed.\n"
           "Use this function to clean up any context-specific data\n"
           "structures."
      )
      .def("contextPreDraw", &vrj::opengl::App::contextPreDraw,
           &pyj::vrj_opengl_App_Wrapper::default_contextPreDraw,
           "contextPreDraw()\n"
           "Function that is called upon entry into the context before\n"
           "rendering begins.  This can be used to allocate\n"
           "context-specific data dynamically.\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditins:\n"
           "The application object has executed any commands that need to\n"
           "be executed only once per context, per frame.\n\n"
           "This function can be used for things that need to happen every\n"
           "frame but only once per context."
      )
      .def("contextPostDraw", &vrj::opengl::App::contextPostDraw,
           &pyj::vrj_opengl_App_Wrapper::default_contextPostDraw,
           "contextPostDraw()\n"
           "Function that is called upon exit of the context after\n"
           "rendering\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing."
      )
      .def("bufferPreDraw", &vrj::opengl::App::bufferPreDraw,
           &pyj::vrj_opengl_App_Wrapper::default_bufferPreDraw,
           "bufferPreDraw()\n"
           "Function that is called once for each frame buffer of an\n"
           "OpenGL context.  This function is executed after contextInit()\n"
           "(if neede) but before contextPreDraw().  It is called once\n"
           "per frame buffer (see note below).\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditions:\n"
           "The application object has executed any commands that need to\n"
           "be executed once per context, per buffer, per frame.\n\n"
           "Note:\n"
           "This function is designed to be used when some task must be\n"
           "performed only once per frame buffer (i.e., once for the left\n"
           "tbuffer, once for the right buffer).  For example, the OpenGL\n"
           "clear color should be defined and glClear(GL_COLOR_BUFFER_BIT)\n"
           "should be called in this method."
      )
      .def("pipePreDraw", &vrj::opengl::App::pipePreDraw,
           &pyj::vrj_opengl_App_Wrapper::default_pipePreDraw,
           "pipePreDraw()\n"
           "Function that is called at the beginning of the drawing of eacn\n"
           "pipe.\n\n"
           "Pre-conditions:\n"
           "The library is preparing to render all windows on a given\n"
           "pipe.\n\n"
           "Post-conditions:\n"
           "Any pre-pipe user calls have been done.\n\n"
           "Note:\n"
           "Currently the OpenGL context is not set when this function is\n"
           "called.  This is a TEST function.  USE AT YOUR OWN RISK!"
      )
      .def("init", &vrj::opengl::App::init,
           &pyj::vrj_opengl_App_Wrapper::default_init,
           "init()\n"
           "Application initialization function.  Execute any\n"
           "initialization needed before the graphics API is started.\n\n"
           "Note:\n"
           "Derived classes MUST call the base class version of this\n"
           "method."
      )
      .def("apiInit", &vrj::opengl::App::apiInit,
           &pyj::vrj_opengl_App_Wrapper::default_apiInit,
           "apiInit()\n"
           "Application graphics API initialization function.  Execute any\n"
           "initialization needed after the graphics API is started but\n"
           "before the Draw Manager starts the rendering loop(s)."
      )
      .def("exit", &vrj::opengl::App::exit,
           &pyj::vrj_opengl_App_Wrapper::default_exit,
           "exit()\n"
           "Executes any final clean-up needed for the application before\n"
           "exiting."
      )
      .def("preFrame", &vrj::opengl::App::preFrame,
           &pyj::vrj_opengl_App_Wrapper::default_preFrame,
           "preFrame()\n"
           "Function called before the Juggler frame starts.  This is\n"
           "called after input device updates but before the start of a\n"
           "new frame."
      )
      .def("latePreFrame", &vrj::opengl::App::latePreFrame,
           &pyj::vrj_opengl_App_Wrapper::default_latePreFrame,
           "latePreFrame()\n"
           "Function called after preFrame() and application-specific data\n"
           "synchronization (in a cluster conifguration) but before the\n"
           "start of a new frame.\n\n"
           "Note:\n"
           "This is required because we cannot update data during the\n"
           "rendering process since it might be using multiple threads."
      )
      .def("intraFrame", &vrj::opengl::App::intraFrame,
           &pyj::vrj_opengl_App_Wrapper::default_intraFrame,
           "intraFrame()\n"
           "Function called during the application's drawing time."
      )
      .def("postFrame", &vrj::opengl::App::postFrame,
           &pyj::vrj_opengl_App_Wrapper::default_postFrame,
           "postFrame()\n"
           "Function alled before updating input devices but after the\n"
           "frame is complete."
      )
      .def("reset", &vrj::opengl::App::reset,
           &pyj::vrj_opengl_App_Wrapper::default_reset,
           "reset()\n"
           "Resets the application.  This is used when the kernel (or\n"
           "applications would like this application to reset to its\n"
           "initial state."
      )
      .def("focusChanged", &vrj::opengl::App::focusChanged,
           &pyj::vrj_opengl_App_Wrapper::default_focusChanged,
           "focusChanged()\n"
           "Called when the focus state changes."
      )
      .def("getDrawScaleFactor", &vrj::opengl::App::getDrawScaleFactor,
           &pyj::vrj_opengl_App_Wrapper::default_getDrawScaleFactor,
           "getDrawScaleFactor() -> float\n"
           "Returns the scale factor to convert from Juggler units\n"
           "(meters) to application units.  Internally, VR Juggler stores\n"
           "and processes all position values in meterrs.  The scale\n"
           "factor returned by this method is used by VR Juggler to scale\n"
           "the rendering state from meters to whatever units this\n"
           "application wants to use.  For example, to render in feet,\n"
           "return 3.28 (gadget.PositionUnitConversion.ConvertToFeet)."
      )
      .def("configCanHandle", &vrj::opengl::App::configCanHandle,
           &pyj::vrj_opengl_App_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean\n"
           "Defaults to handling nothing.\n\n"
           "Arguments:\n"
           "element -- An instance of jccl.ConfigElement."
      )
      .def("depSatisfied", &vrj::opengl::App::depSatisfied,
           &pyj::vrj_opengl_App_Wrapper::default_depSatisfied,
           "depSatisfied() -> Boolean\n"
           "Are any application dependencies satisified?  If this\n"
           "application requires anything special of the system for\n"
           "successful initialization, check it here.  If the return value\n"
           "is False, then this application will not be started yet.  If\n"
           "the return value is True, this application will be allowed to\n"
           "enter the system."
      )
//      .def("getDrawManager", &vrj::opengl::App::getDrawManager,
//           &pyj::vrj_opengl_App_Wrapper::default_getDrawManager,
//           return_internal_reference<1>()
//      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::vrj_opengl_App_Wrapper::default_configProcessPending,
           "configProcessPending() -> int\n"
           "Inherited from jccl.ConfigElementHandler and not overridden."
      )
   ;
}
