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
#include <gadget/Type/Digital.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_Digital_Wrapper : gadget::Digital, wrapper<gadget::Digital>
{
   gadget_Digital_Wrapper()
      : gadget::Digital()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_Digital_Wrapper()
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
         return gadget::Digital::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::Digital::config(p0);
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
            gadget::Digital::writeObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Digital_Wrapper::writeObject()",
            VPR_LOCATION
         );
      }
   }

   void default_writeObject(vpr::ObjectWriter* p0)
   {
      gadget::Digital::writeObject(p0);
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
            gadget::Digital::readObject(p0);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
         throw vpr::IOException(
            "Python exception caught by pyj::gadget_Digital_Wrapper::readObject()",
            VPR_LOCATION
         );
      }
   }

   void default_readObject(vpr::ObjectReader* p0)
   {
      gadget::Digital::readObject(p0);
   }
};

}// namespace 


// Module ======================================================================
void _Export_Digital()
{
   scope* gadget_DigitalState_scope = new scope(
   class_<gadget::DigitalState, boost::noncopyable>("DigitalState", no_init)
   );

   enum_<gadget::DigitalState::State>("State")
      .value("TOGGLE_OFF", gadget::DigitalState::TOGGLE_OFF)
      .value("ON", gadget::DigitalState::ON)
      .value("OFF", gadget::DigitalState::OFF)
      .value("TOGGLE_ON", gadget::DigitalState::TOGGLE_ON)
   ;

   delete gadget_DigitalState_scope;

   class_<pyj::gadget_Digital_Wrapper, gadget::DigitalPtr, boost::noncopyable>(
       "Digital",
       "gadget.Digital is the abstract base class from which devices\n"
       "returning digital data must derive.  This is in addition to\n"
       "gadget.Input.  gadget.Input provides pure virtual function\n"
       "constraints in the following functions: startSampling(),\n"
       "stopSampling(), sample(), and updateData().\n\n"
       "gadget.Digital adds the function getDigitalDdta() for retrieving\n"
       "the received digital data.  This is similar to the additions made\n"
       "by gadget.Position and gadget.Analog."
       ,
       no_init
      )
      .def("create", &gadget::Digital::create)
      .def("config", &gadget::Digital::config,
           &pyj::gadget_Digital_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this digital device.\n"
           "Arguments:\n"
           "element -- The config element for a digital device.  It must\n"
           "           derive from the base config element type\n"
           "           'digital_device'."
      )
      .def("writeObject", &gadget::Digital::writeObject,
           &pyj::gadget_Digital_Wrapper::default_writeObject,
           "writeObject(writer)\n"
           "Serializes this object."
      )
      .def("readObject", &gadget::Digital::readObject,
           &pyj::gadget_Digital_Wrapper::default_readObject,
           "readObject(reader)\n"
           "De-serializes this object."
      )
      .def("getDigitalData", &gadget::Digital::getDigitalData,
           (args("devNum") = 0),
           "getDigitalData(devNum = 0) -> gadget.DigitalData object\n"
           "Returns digital data.\n"
           "Keyword arguments:\n"
           "devNum -- The device unit numbmer to access.  This parameter\n"
           "          optional.  It defaults to 0."
      )
      .def("addDigitalSample", &gadget::Digital::addDigitalSample,
           "addDigitalSample(sampleList)\n"
           "Helper method to add a collection of samples to the digital\n"
           "sample buffers for this device.  This MUST be called by all\n"
           "digital devices to add a new sample.\n"
           "Post-condition:\n"
           "The given samples are added to the buffers.\n"
           "Arguments:\n"
           "sampleList -- The list of newly collected samples as a\n"
           "              gadget.DigitalDataVec object."
      )
      .def("swapDigitalBuffers", &gadget::Digital::swapDigitalBuffers,
           "swapDigitalBuffers()\n"
           "Swaps the digital data buffers.\n"
           "Post-condition:\n"
           "If the ready queue has values, then those values are copied\n"
           "from the ready queue to the stable queue.  If not, the stable\n"
           "queue is not changed."
      )
      .def("getDigitalDataBuffer", &gadget::Digital::getDigitalDataBuffer,
           return_internal_reference<1>(),
           "getDigitalDataBuffer() -> list of lists of DigitalData objects\n"
           "Returns the current stable sample buffers for this device."
      )
      .staticmethod("create")
   ;

   class_< std::vector<gadget::DigitalData> >("DigitalDataVec",
       "An indexable container of gadget.DigitalData objects."
      )
      .def(vector_indexing_suite< std::vector<gadget::DigitalData> >())
   ;
}
