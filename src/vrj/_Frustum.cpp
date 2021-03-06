// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Display/Frustum.h>
#include <vrj-helpers.h>
#include <container_conversions.h>

// Using =======================================================================
using namespace boost::python;

/*
namespace vrjHelpers
{
   template void setArrayElement(vrj::Frustum*, const unsigned, float);
}
*/

// Module ======================================================================
void _Export_Frustum()
{
   scope* vrj_Frustum_scope = new scope(
   class_<vrj::Frustum>("Frustum", "A frustum object.  This is a frustum.",
                        init<>())
      .def(init<const vrj::Frustum&>())
      .def("setBottomLeftTopRight", &vrj::Frustum::setBottomLeftTopRight)
      .def("setNearFar", &vrj::Frustum::setNearFar)
      .def("set", &vrj::Frustum::set)
      .def("getValues", &vrj::Frustum::getValues,
           return_value_policy<copy_const_reference>())
      .def("__getitem__",
           (const float& (vrj::Frustum::*)(unsigned int) const) &vrj::Frustum::operator[],
           return_value_policy<copy_const_reference>())
//      .def(self_ns::str(self))
   );

   enum_<vrj::Frustum::entry>("entry")
      .value("VJ_TOP", vrj::Frustum::VJ_TOP)
      .value("VJ_BOTTOM", vrj::Frustum::VJ_BOTTOM)
      .value("VJ_LEFT", vrj::Frustum::VJ_LEFT)
      .value("VJ_FAR", vrj::Frustum::VJ_FAR)
      .value("VJ_NEAR", vrj::Frustum::VJ_NEAR)
      .value("VJ_RIGHT", vrj::Frustum::VJ_RIGHT)
   ;

   delete vrj_Frustum_scope;

   pyj::copyable_to_python<std::vector<float>, tuple>();
}
