// PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// File:          $RCSfile$
// Date modified: $Date$
// Version:       $Revision$

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vpr/IO/ObjectReader.h>
#include <vpr/IO/ObjectWriter.h>
#include <gadget/Type/KeyboardMouse.h>
#include <container_conversions.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj {

struct gadget_KeyboardMouse_Wrapper: gadget::KeyboardMouse
{
    gadget_KeyboardMouse_Wrapper(PyObject* self_, const gadget::KeyboardMouse& p0):
        gadget::KeyboardMouse(p0), self(self_) {}

    gadget_KeyboardMouse_Wrapper(PyObject* self_):
        gadget::KeyboardMouse(), self(self_) {}

    std::string getInputTypeName() {
        return call_method< std::string >(self, "getInputTypeName");
    }

    std::string default_getInputTypeName() {
        return gadget::KeyboardMouse::getInputTypeName();
    }

    vpr::ReturnStatus writeObject(vpr::ObjectWriter* p0) {
        return call_method< vpr::ReturnStatus >(self, "writeObject", p0);
    }

    vpr::ReturnStatus default_writeObject(vpr::ObjectWriter* p0) {
        return gadget::KeyboardMouse::writeObject(p0);
    }

    vpr::ReturnStatus readObject(vpr::ObjectReader* p0) {
        return call_method< vpr::ReturnStatus >(self, "readObject", p0);
    }

    vpr::ReturnStatus default_readObject(vpr::ObjectReader* p0) {
        return gadget::KeyboardMouse::readObject(p0);
    }

    bool config(jccl::ConfigElementPtr p0) {
        return call_method< bool >(self, "config", p0);
    }

    bool default_config(jccl::ConfigElementPtr p0) {
        return gadget::KeyboardMouse::config(p0);
    }

    PyObject* self;
};


}// namespace 


// Module ======================================================================
void _Export_KeyboardMouse()
{
    class_< gadget::KeyboardMouse, boost::noncopyable, pyj::gadget_KeyboardMouse_Wrapper >("KeyboardMouse",
         "gadget.KeyboardMouse is an abstract class for interfacing with\n"
         "keyboard and mouse devices.  Informally, a keyboard/mouse device\n"
         "can be thought of as a map of keyboard and mouse events (presses,\n"
         "releases, and movements) to integers.  The integers indicate the\n"
         "number of times the event occurred since the last update.  That is\n"
         "to say, gadget.KeyboardMouse counts the number of keyboard and\n"
         "mouse events between updates.  Updates in Juggler occur once per\n"
         "frame."
         ,
         init<  >()
        )
        .def(init< const gadget::KeyboardMouse& >())
        .def("getInputTypeName", &gadget::KeyboardMouse::getInputTypeName,
             &pyj::gadget_KeyboardMouse_Wrapper::default_getInputTypeName)
        .def("writeObject",
             (vpr::ReturnStatus (gadget::KeyboardMouse::*)(vpr::ObjectWriter*) )&gadget::KeyboardMouse::writeObject,
             (vpr::ReturnStatus (pyj::gadget_KeyboardMouse_Wrapper::*)(vpr::ObjectWriter*))&pyj::gadget_KeyboardMouse_Wrapper::default_writeObject,
             "writeObject(writer) -> vpr.ReturnStatus object\n"
             "Writes both mCurKeys and mCurEventQueueLock to a stream using\n"
             "the given object writer."
         )
        .def("readObject",
             (vpr::ReturnStatus (gadget::KeyboardMouse::*)(vpr::ObjectReader*) )&gadget::KeyboardMouse::readObject,
             (vpr::ReturnStatus (pyj::gadget_KeyboardMouse_Wrapper::*)(vpr::ObjectReader*))&pyj::gadget_KeyboardMouse_Wrapper::default_readObject,
             "readObject(reader) -> vpr.ReturnStatus object\n"
             "Reads mCurKeys and mCurEventQueueLock from a stream using the\n"
             "given object reader."
         )
        .def("config", &gadget::KeyboardMouse::config,
             &pyj::gadget_KeyboardMouse_Wrapper::default_config,
             "config(element) -> Boolean\n"
             "Configures this keyboard/mouse device.\n"
             "Arguments:\n"
             "element -- The config element for an keyboard/mouse device."
         )
        .def("getSyncTime", &gadget::KeyboardMouse::getSyncTime,
             "getSyncTime -> vpr.Interval object\n"
             "Gets the interval that will be used for synchronization while\n"
             "only sharing keyboard data across the cluster."
         )
        .def("keyPressed", &gadget::KeyboardMouse::keyPressed,
             "keyPressed(keyId) -> int\n"
             "Returns the number of times the given key was pressesd during\n"
             "the last frame.  This can be used in a conditional expression\n"
             "to determine if the key was pressed at all."
             "Arguments:\n"
             "keyId -- A value from gadget.Keys identifiing the key whose\n"
             "         state will be queried.\n"
             "Returns:\n"
             "The number of times the named key was pressed since the last\n"
             "update."
         )
        .def("modifierOnly", &gadget::KeyboardMouse::modifierOnly,
             "modifierOnly(modKey) -> Boolean\n"
             "Determines if the given modifier key is the only modifier\n"
             "pressed.\n"
             "Pre-conditions:\n"
             "The given key identifier must be one of gadget.Keys.NONE,\n"
             "gadget.Keys.KEY_ALT, gadget.Keys.KEY_CTRL, or\n"
             "gadget.Keys.KET_SHIFT.\n"
             "Arguments:\n"
             "modKey -- A gadget.Keys value that must be one of\n"
             "          gadget.Keys.NONE, gadget.Keys.KEY_ALT,\n"
             "          gadget.Keys.KEY_CTRL, or gadget.Keys.KEY_SHIFT.\n"
             "Returns:\n"
             "True is returned if the given modifier is the only modifier\n"
             "key pressed."
         )
        .def("getKeyName", &gadget::KeyboardMouse::getKeyName,
             "getKeyName(keyId) -> string object\n"
             "Returns the symbolic Gadgeteer name associated with the given\n"
             "key identifier.  For example, getKeyName(gadget.Keys.KEY_UP)\n"
             "returns \"KEY_UP\".\n"
             "Arguments:\n"
             "keyId -- A value from gadget.Keys identifiing the key whose\n"
             "         name will be returned.\n"
             "Returns:\n"
             "A string that is the symbolic name of the given key."
         )
        .def("getEventQueue", &gadget::KeyboardMouse::getEventQueue,
             "getEventQueue() -> tuple of gadget.Event objects\n"
             "Returns a copy of the current queue of events for this device."
         )
        .def("addEvent", &gadget::KeyboardMouse::addEvent,
             "addEvent(event)\n"
             "Adds the given event object to the in-progress queue."
             "Arguments:\n"
             "event -- The gadget.Event object that is the new event."
         )
    ;

    pyj::std_vector_copyable_to_tuple<gadget::EventPtr>();
}
