// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vpr_ObjectReader_Wrapper : vpr::ObjectReader, wrapper<vpr::ObjectReader>
{
   virtual ~vpr_ObjectReader_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void beginTag(const std::string& p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::beginTag()\n",
                               "vpr_ObjectReader_Wrapper::beginTag() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("beginTag")(boost::ref(p0));
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void endTag()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::endTag()\n",
                               "vpr_ObjectReader_Wrapper::endTag() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("endTag")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void beginAttribute(const std::string& p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::beginAttribute()\n",
                               "vpr_ObjectReader_Wrapper::beginAttribute() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("beginAttribute")(boost::ref(p0));
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void endAttribute()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::endAttribute()\n",
                               "vpr_ObjectReader_Wrapper::endAttribute() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("endAttribute")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void resetReading()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::resetReading()\n",
                               "vpr_ObjectReader_Wrapper::resetReading() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("resetReading")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void pushState()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::pushState()\n",
                               "vpr_ObjectReader_Wrapper::pushState() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("pushState")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void popState()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::popState()\n",
                               "vpr_ObjectReader_Wrapper::popState() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("popState")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   vpr::Uint8 readUint8()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::readUint8()\n",
                               "vpr_ObjectReader_Wrapper::readUint8() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readUint8")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   vpr::Uint16 readUint16()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::readUint16()\n",
                               "vpr_ObjectReader_Wrapper::readUint16() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readUint16")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   vpr::Uint32 readUint32()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::readUint32()\n",
                               "vpr_ObjectReader_Wrapper::readUint32() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readUint32")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   vpr::Uint64 readUint64()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectReader_Wrapper::readUint64()\n",
                               "vpr_ObjectReader_Wrapper::readUint64() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readUint64")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   float readFloat()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectWriter_Wrapper::readFloat()\n",
                               "vpr_ObjectReader_Wrapper::readFloat() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readFloat")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   double readDouble()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectWriter_Wrapper::readDouble()\n",
                               "vpr_ObjectReader_Wrapper::readDouble() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readDouble")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   std::string readString()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectWriter_Wrapper::readString()\n",
                               "vpr_ObjectReader_Wrapper::readString() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readString")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   bool readBool()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_ObjectWriter_Wrapper::readBool()\n",
                               "vpr_ObjectReader_Wrapper::readBool() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return this->get_override("readBool")();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }
};


}// namespace pyj


// Module ======================================================================
void _Export_ObjectReader()
{
   class_<pyj::vpr_ObjectReader_Wrapper, boost::noncopyable>("ObjectReader",
       "Interface used to read object data from a stream.\n\n"
       "ObjectReader and ObjectWriter support an interface that allows for\n"
       "using tags and attributes in the written output data.  This allows\n"
       "support for formats such as XML where there is a logical grouping\n"
       "of the data.\n\n"
       "The structure looks something like the following (based on XML):\n\n"
       "<tag1>\n"
       "  <tag2 attrib1=\"XXX\">\n"
       "  </tag2>\n"
       "</tag1>"
       ,
       no_init
      )
      .def("beginTag", pure_virtual(&vpr::ObjectReader::beginTag),
           "beginTag(tagName)\n"
           "Starts a new section/element of name tagName."
      )
      .def("endTag", pure_virtual(&vpr::ObjectReader::endTag),
           "endTag()\n"
           "Ends the most recently named tag."
      )
      .def("beginAttribute", pure_virtual(&vpr::ObjectReader::beginAttribute),
           "beginAttribute(attributeName)\n"
           "Starts an attribute of the name attributeName."
      )
      .def("endAttribute", pure_virtual(&vpr::ObjectReader::endAttribute),
           "endAttribute()\n"
           "Ends the most recently named attribute."
      )
#if ! defined(_MSC_VER)
      .def("resetReading", pure_virtual(&vpr::ObjectReader::resetReading),
           "resetReading()\n"
           "Resets the reading to the initial reading state.\n"
           "<b>Post condition:</b> The reaer can be reused and will\n"
           "function as if it were just initialized."
      )
      .def("pushState", pure_virtual(&vpr::ObjectReader::pushState),
           "pushState()\n"
           "This allows users to push the active state of reading.  Later,\n"
           "this can be used to move back to the previous reading state if\n"
           "needed."
      )
      .def("popState", pure_virtual(&vpr::ObjectReader::popState),
           "pushState()\n"
           "This allows users to pop the active state of reading.  This\n"
           "is used to move back to the previous reading state."
      )
#endif
      .def("readUint8",
           pure_virtual((vpr::Uint8 (vpr::ObjectReader::*)()) &vpr::ObjectReader::readUint8))
      .def("readUint16",
           pure_virtual((vpr::Uint16 (vpr::ObjectReader::*)()) &vpr::ObjectReader::readUint16))
      .def("readUint32",
           pure_virtual((vpr::Uint32 (vpr::ObjectReader::*)()) &vpr::ObjectReader::readUint32))
      .def("readUint64",
           pure_virtual((vpr::Uint64 (vpr::ObjectReader::*)()) &vpr::ObjectReader::readUint64))
      .def("readFloat",
           pure_virtual((float (vpr::ObjectReader::*)()) &vpr::ObjectReader::readFloat))
      .def("readDouble",
           pure_virtual((double (vpr::ObjectReader::*)()) &vpr::ObjectReader::readDouble))
      .def("readString",
           pure_virtual((std::string (vpr::ObjectReader::*)()) &vpr::ObjectReader::readString))
      .def("readBool",
           pure_virtual((bool (vpr::ObjectReader::*)()) &vpr::ObjectReader::readBool))
      .def("isBinary", &vpr::ObjectReader::isBinary,
           "Returns true if the reader is using a binary-based format.\n"
           "This can be used to choose whether to use human-readable forms\n"
           "of serialization."
      )
      .def("attribExists", &vpr::AttributeMapBase::attribExists,
           "attribExists(name) -> bool\n"
           "Determines if the named attribute exists."
      )
   ;
}
