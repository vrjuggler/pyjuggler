// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/String.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_String_Wrapper : gadget::String, wrapper<gadget::String>
{
   gadget_String_Wrapper()
      : gadget::String()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_String_Wrapper()
   {
      /* Do nothing. */ ;
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::String::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::String::config(p0);
   }

   void writeObject(vpr::ObjectWriter* p0)
   {
      try
      {
         if ( override writeObject = this->get_override("writeObject") )
         {
            writeObject(ptr(p0));
         }
         else
         {
            gadget::String::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_String_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0)
   {
      gadget::String::writeObject(p0);
   }

   void readObject(vpr::ObjectReader* p0)
   {
      try
      {
         if ( override readObject = this->get_override("readObject") )
         {
            readObject(ptr(p0));
         }
         else
         {
            gadget::String::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_String_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0)
   {
      gadget::String::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_String()
{
   class_<pyj::gadget_String_Wrapper, gadget::StringPtr, boost::noncopyable>(
       "String",
       "gadget.String is the abstract base class for devices that return\n"
       "strinsg.  Drivers for all such devices must derive from this class.\n"
       "This is in addition to gadget.Input.  gadget.Input provides pure\n"
       "virtual function constraints in the following functions:\n"
       "startSampling(), stopSampling(), sample(), and updateData().\n\n"
       "gadget.String adds the function getStringDdta() for\n"
       "retrieving the received commands.  This is similar to the\n"
       "additions made by gadget.Position and gadget.Analog."
       ,
       no_init
      )
      .def("create", &gadget::String::create)
      .def("config", &gadget::String::config,
           &pyj::gadget_String_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this string device.\n"
           "Arguments:\n"
           "element -- The config element for a string device.  It must\n"
           "           derive from the base config element type\n"
           "           'string_device'."
      )
      .def("writeObject", &gadget::String::writeObject,
           &pyj::gadget_String_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this object."
      )
      .def("readObject", &gadget::String::readObject,
           &pyj::gadget_String_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this object."
      )
      .def("getStringData", &gadget::String::getStringData,
           (args("devNum") = 0),
           return_value_policy<copy_const_reference>(),
           "getStringData(devNum = 0) -> gadget.StringData object\n"
           "Returns string data.\n"
           "Keyword arguments:\n"
           "devNum -- The device unit numbmer to access.  This parameter\n"
           "          optional.  It defaults to 0."
      )
      .def("addStringSample", &gadget::String::addStringSample,
           "addStringSample(sampleList)\n"
           "Helper method to add a collection of samples to the digital\n"
           "sample buffers for this device.  This MUST be called by all\n"
           "digital devices to add a new sample.\n"
           "Post-condition:\n"
           "The given samples are added to the buffers.\n"
           "Arguments:\n"
           "sampleList -- The list of newly collected samples as a\n"
           "              gadget.StringDataVec object."
      )
      .def("swapStringBuffers", &gadget::String::swapStringBuffers,
           "swapStringBuffers()\n"
           "Swaps the digital data buffers.\n"
           "Post-condition:\n"
           "If the ready queue has values, then those values are copied\n"
           "from the ready queue to the stable queue.  If not, the stable\n"
           "queue is not changed."
      )
      .def("getStringDataBuffer", &gadget::String::getStringDataBuffer,
           return_value_policy<copy_const_reference>(),
           "getStringDataBuffer() -> list of lists of StringData objects\n"
           "Returns the current stable sample buffers for this device."
      )
      .staticmethod("create")
   ;

   class_< std::vector<gadget::StringData> >("StringDataVec",
       "An indexable container of gadget.StringData objects."
      )
      .def(vector_indexing_suite< std::vector<gadget::StringData> >())
   ;
}
