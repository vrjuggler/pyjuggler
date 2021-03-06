// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <snx/sonix.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ===============================================================

namespace pyj
{

tuple getPositionWrapper(const std::string& alias)
{
   float p0, p1, p2;
   snx::sonix::instance()->getPosition(alias, p0, p1, p2);
   return make_tuple(p0, p1, p2);
}

}

// Module ======================================================================
void _Export_sonix()
{
   class_<snx::sonix, boost::noncopyable>("sonix", no_init)
      .def("trigger", &snx::sonix::trigger,
           (arg("alias"), arg("repeat") = 1),
           "trigger(alias, repeat = 1)\n"
           "Triggers a sound.\n\n"
           "Pre-condition:\n"
           "alias does not have to be associated with a loaded sound.\n\n"
           "Post-condition:\n"
           "If allias is associated with a loaded sound, then the loaded\n"
           "sound is triggered.  If not, nothing happens.\n\n"
           "Arguments:\n"
           "alias  -- Alias of the sound to trigger.\n"
           "repeat -- The number of times to play.  Use -1 to repeat\n\n"
           "          forever.  The default is to trigger the sound once."
      )
      .def("isPlaying", &snx::sonix::isPlaying,
           "isPlaying(alias) -> Boolean\n"
           "Is the named sound currently playing?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("setRetriggerable", &snx::sonix::setRetriggerable,
           "setRetriggerable(alias, onOff)\n"
           "Specifies whether the named sound retriggers from the beginning\n"
           "when triggered while playing.  In other words, when the named\n"
           "sound is already playing and trigger() is called, does the\n"
           "sound restart from the beginning?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to change.\n"
           "onOff -- A Boolean value enabling or disabling retriggering."
      )
      .def("isRetriggerable", &snx::sonix::isRetriggerable,
           "isRetriggerable(alais) -> Boolean\n"
           "Is the named sound retriggerable?\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("stop", &snx::sonix::stop,
           "stop(alias)\n"
           "Stops the named sound.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to stop."
      )
      .def("pause", &snx::sonix::pause,
           "pause(alias)\n"
           "Pauses the sound.  Use unpause() to return playback from where\n"
           "the sound was paused.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to pause."
      )
      .def("unpause", &snx::sonix::unpause,
           "unpause(alias)\n"
           "Resumes playback of the named sound from a paused state.  This\n"
           "does nothing if the sound was not paused.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to unpause."
      )
      .def("isPaused", &snx::sonix::isPaused,
           "isPaused(alias) -> Boolean\n"
           "If the sound is paused, then return True.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to query."
      )
      .def("setAmbient", &snx::sonix::setAmbient,
           (arg("alias"), arg("ambient") = false),
           "setAmbient(alias, ambient = False)\n"
           "Sets the named sound as either ambient or positional depending\n"
           "on the value of the given argument.  If the sound is ambient,\n"
           "it is attached to the listener, and its volume does not change\n"
           "when the listener moves.  If the sound is positional, the\n"
           "volume changes when the listener moves.\n\n"
           "Arguments:\n"
           "alias   -- The alias of the sound to change\n"
           "ambient -- A Boolean flag identifying whether this sound is\n"
           "           ambient (True) or positional (False).  The default is\n"
           "           positional."
      )
      .def("isAmbient", &snx::sonix::isAmbient,
           "isAmbient(alias) -> Boolean\n"
           "Is the named sound ambient?\n\n"
           "Arguments:\n"
           "alias -- The name of the sound to query."
      )
      .def("setPitchBend", &snx::sonix::setPitchBend,
           "setPitchBend(alias, amount)\n"
           "Alters the frequency of the named sound.\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the pitch\n"
           "          bend.  1.0 means that there is no change.  A value\n"
           "          less than 1.0 is low; a value greather than 1.0 is\n"
           "          high."
      )
      .def("setVolume", &snx::sonix::setVolume,
           "setVolume(alias, amount)\n"
           "Sets the effect volume of the named sound.  The value must be\n"
           "in the range [0,1].\n\n"
           "Argument:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the volume.\n"
           "          It must be between 0.0 and 1.0 inclusive."
      )
      .def("setCutoff", &snx::sonix::setCutoff,
           "setCutoff(alias, amount)\n"
           "Sets the effect cutoff of the named sound.  Set to a value in\n"
           "the range [0,1].\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n"
           "amount -- A floating-point value that determines the cutoff.\n"
           "          The value must be between 0.0 and 1.0 inclusive.\n"
           "          1.0 means no change; 0.0 is total cutoff."
      )
      .def("setPosition", &snx::sonix::setPosition,
           "setPosition(alias, x, y, z)\n"
           "Sets the named sound's three-dimensional position.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to change.\n"
           "x     -- The X coordinate of the sound in 3D OpenGL coordinates.\n"
           "y     -- The Y coordinate of the sound in 3D OpenGL coordinates.\n"
           "z     -- The Z coordinate of the sound in 3D OpenGL coordinates."
      )
      .def("getPosition", &pyj::getPositionWrapper,
           "getPosition(alias) -> tuple\n"
           "Gets the named sound's 3D position.\n\n"
           "Arguments:\n"
           "alias  -- The alias of the sound to change.\n\n"
           "Returns:\n"
           "A tuple of floating-point values providing the (x, y, z)\n"
           "position of the named sound."
      )
      .def("setListenerPosition", &snx::sonix::setListenerPosition,
           "setListenerPosition(matrix)\n"
           "Sets the position of the listener.\n\n"
           "Arguments:\n"
           "matrix -- A gmtl.Matrix44f object representing the position\n"
           "          of the listener."
      )
      .def("getListenerPosition", &snx::sonix::getListenerPosition,
           "getListenerPosition(matrix)\n"
           "Gets the listeners's 3D position.\n\n"
           "Arguments:\n"
           "matrix -- A gmtl.Matrix44f object used to store the position\n"
           "          of the listener."
      )
      .def("changeAPI", &snx::sonix::changeAPI,
           "changeAPI(apiName)\n"
           "Changes the underlying sound API to something else.  This\n"
           "function is safe.  It always changes to a valid implementation.\n"
           "It runs in O(1) (constant) time.\n\n"
           "Pre-condition:\n"
           "The named sound implementation should be registered.\n\n"
           "Post-condition:\n"
           "The underlying API is chagned to the named API.  If apiName's\n"
           "implementation is not registered, then the underlying API is\n"
           "changed to the stub version.\n\n"
           "Arguments:\n"
           "apiName -- Usually a name of a valid, registered sound API\n"
           "           implementation."
      )
      .def("configure",
           (void (snx::sonix::*)(const snx::SoundAPIInfo&)) &snx::sonix::configure,
           "configure(description)\n"
           "Configures/reconfigures the sound API global settings.\n\n"
           "Arguments:\n"
           "description -- A snx.SoundAPIInfo object that describes the\n"
           "               settings for this sound API."
      )
      .def("configure",
           (void (snx::sonix::*)(const std::string&, const snx::SoundInfo&)) &snx::sonix::configure,
           "configure(alais, description)\n"
           "Configures/reconfigures the named sound by associating sound\n"
           "data with the named sound.  Afterwards, the alias can be used\n"
           "to operate on sound data.\n\n"
           "Configure: associate a name (alias) with the description if\n"
           "not already done.\n"
           "Reconfigure: change properties of the sound to the description\n"
           "provided.\n\n"
           "Pre-condition:\n"
           "Provide a snx.SoundInfo that describes the sound.\n\n"
           "Post-condition:\n"
           "This handle will point to loaded sound data.\n\n"
           "Arguments:\n"
           "alias       -- The alias of the sound to be associated with the\n"
           "               given sound data.\n"
           "description -- A snx.SoundInfo object that describes the sound\n"
           "               for which this object will be a handle."
      )
      .def("remove", &snx::sonix::remove,
           "remove(alias)\n"
           "Removes a configured sound.  Any future reference to the alias\n"
           "will not cause an error, but it will not result in a rendered\n"
           "sound.\n\n"
           "Arguments:\n"
           "alias -- The alias of the sound to remove."
      )
      .def("step", &snx::sonix::step,
           "step(timeElapsed)\n"
           "Call once per sound frame (which does not have to be the same\n"
           "as the graphics frame).\n\n"
           "Arguments:\n"
           "timeElapsed -- A floating-point value giving the time elapsed\n"
           "               since the last sound frame."
      )
      .def("instance", &snx::sonix::instance,
           return_value_policy<reference_existing_object>(),
           "instance() -> snx.sonix object\n"
           "Retruns the singleton snx.sonix object."
      )
      .staticmethod("instance")
   ;
}
