// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Include =====================================================================
#include <boost/python.hpp>
#include <vrj/Util/Version.h>

// Exports =====================================================================
void _Export_Kernel();
void _Export_App();
void _Export_Projection();
void _Export_Display();
void _Export_Viewport();
void _Export_SimViewport();
void _Export_Frustum();
void _Export_CameraProjection();
void _Export_User();

// Module ======================================================================
BOOST_PYTHON_MODULE(__vrj)
{
   // Create and acquire the global interpreter lock.
   PyEval_InitThreads();

   boost::python::scope().attr("__doc__") =
      "PyJuggler.__vrj is an extension module written in Boost.Python that\n"
      "exposes some C++ classes from the VR Juggler library.  The symbols\n"
      "of this module are imported into the PyJuggler.vrj namespace for\n"
      "use in the authoring of VR Juggler application objects.  The exposed\n"
      "classes are those that tend to be of the most value for writing VR\n"
      "Juggler application objects.  Some accomodations are made for\n"
      "writing simulator plug-ins in Python, but that capability is not the\n"
      "focus of this extension module.\n\n"
      "Refer to the VR Juggler 2.0 C++ documentation for general usage\n"
      "details:\n"
      "   http://www.vrjuggler.org/vrjuggler/docs.php"
   ;
   boost::python::def("getVersionString", vrj::getVersionString,
                      "Returns the full VR Juggler version number as a "
                      "string in the form\n"
                      "'v<major>.<minor>.<patch>-<build> [...]\n"
                      "The regular expression to extract the version number\n"
                      "components is r'^v(\\d+)\\.(\\d+)\\.(\\d+)-(\\d+)'");
   boost::python::def("getVersionNumber", vrj::getVersionNumber,
                      "Returns the 9-digit VR Juggler version integer. This\n"
                      "form provides three digits for each of the major,\n"
                      "minor, and patch numbers with no leading zeros");

   _Export_App();
   _Export_Kernel();
   _Export_Projection();
   _Export_Display();
   _Export_Viewport();
   _Export_SimViewport();
   _Export_Frustum();
   _Export_CameraProjection();
   _Export_User();
}
