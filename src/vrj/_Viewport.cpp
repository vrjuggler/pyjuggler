// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <jccl/Config/ConfigElement.h>
#include <vrj/Display/Viewport.h>
#include <vrj/Display/Display.h>
#include <vrj/Display/Projection.h>
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_Viewport_Wrapper : vrj::Viewport, wrapper<vrj::Viewport>
{
   vrj_Viewport_Wrapper()
      : vrj::Viewport()
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_Viewport_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void updateProjections(const float p0)
   {
      try
      {
         this->get_override("updateProjections")(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }
};

inline tuple vrj_Viewport_getOriginAndSize_wrapper(vrj::Viewport* vp)
{
   float xo, yo, xs, ys;
   vp->getOriginAndSize(xo, yo, xs, ys);
   return make_tuple(xo, yo, xs, ys);
}

}// namespace 


// Module ======================================================================
void _Export_Viewport()
{
   scope* vrj_Viewport_scope = new scope(
   class_<pyj::vrj_Viewport_Wrapper, vrj::ViewportPtr, boost::noncopyable>
      ("Viewport",
       "Base class for window viewports and all viewport data.  This\n"
       "stores projection data, viewport info, and relevant user."
       ,
       no_init
      )
      .def("updateProjections",
           pure_virtual(&vrj::Viewport::updateProjections),
           "updateProjections(positionScale)\n"
           "Updates the projection data for this viewport.  This uses the\n"
           "data from the head position for this viewport."
      )
      .def("getType", &vrj::Viewport::getType,
           "getType() -> vrj.Viewport.Type value\n"
           "Gets the type of this viewport."
      )
      .def("isSimulator", &vrj::Viewport::isSimulator,
           "isSimulator() -> Boolean\n"
           "Determines if this is a simulator viewport."
      )
      .def("isSurface", &vrj::Viewport::isSurface,
           "isSurface() -> Boolean\n"
           "Determines if this is a surface viewport."
      )
      .def("isActive", &vrj::Viewport::isActive,
           "isActive() -> Boolean\n"
           "Determines if this viewport is active."
      )
      .def("getName", &vrj::Viewport::getName,
           return_internal_reference<1>(),
           "getName() -> string object\n"
           "Gets the name of this viewport."
      )
      .def("inStereo", &vrj::Viewport::inStereo,
           "inStereo() -> Boolean\n"
           "Determines if this viewport is rendering in stereo."
      )
      .def("getView", &vrj::Viewport::getView,
           "getView() -> vrj.Viewport.View value\n"
           "Which view are we supposed to render?"
      )
      .def("getOriginAndSize", pyj::vrj_Viewport_getOriginAndSize_wrapper,
           "getOriginAndSize() -> (float, float, float, float)\n"
           "Returns the origin and size of this viewport as a tuple of\n"
           "floating-point values (xOrigin, yOrigin, width, height)."
      )
      .def("getConfigElement", &vrj::Viewport::getConfigElement,
           "getConfigElement() -> jccl.ConfigElement object\n"
           "gets the config element that configured this viewport."
      )
      .def("getUser", &vrj::Viewport::getUser,
           "getUser() -> vrj.User object\n"
           "Gets the user associated with this viewport."
      )
      .def("getDisplay", &vrj::Viewport::getDisplay,
           "getDisplay() -> vrj.Display object\n"
           "Gets the display contaning this viewprot."
      )
      .def("getLeftProj", &vrj::Viewport::getLeftProj,
           "getLeftProj() -> vrj.Projection object\n"
           "Gets the left projection."
      )
      .def("getRightProj", &vrj::Viewport::getRightProj,
           "getRightProj() -> vrj.Projection object\n"
           "Gets the right projection."
      )
//      .def(self_ns::str(self))
   );

   enum_<vrj::Viewport::Type>("Type")
      .value("SIM", vrj::Viewport::SIM)
      .value("UNDEFINED", vrj::Viewport::UNDEFINED)
      .value("SURFACE", vrj::Viewport::SURFACE)
   ;

   enum_<vrj::Viewport::View>("View")
      .value("LEFT_EYE", vrj::Viewport::LEFT_EYE)
      .value("NONE", vrj::Viewport::NONE)
      .value("STEREO", vrj::Viewport::STEREO)
      .value("RIGHT_EYE", vrj::Viewport::RIGHT_EYE)
   ;

   delete vrj_Viewport_scope;
}
