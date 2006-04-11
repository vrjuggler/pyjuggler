// PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Display/SimViewport.h>
#include <vrj/Display/Display.h>
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_SimViewport_Wrapper : vrj::SimViewport
{
   vrj_SimViewport_Wrapper(PyObject* self_)
      : vrj::SimViewport()
      , self(self_)
   {
      /* Do nothing. */ ;
   }

   vrj_SimViewport_Wrapper(PyObject* self_, const vrj::SimViewport& p0)
      : vrj::SimViewport(p0)
      , self(self_)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_SimViewport_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void updateProjections(const float p0)
   {
      try
      {
         call_method<void>(self, "updateProjections", p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateProjections(const float p0)
   {
      vrj::SimViewport::updateProjections(p0);
   }

   PyObject* self;
};

inline tuple vrj_SimViewport_getOriginAndSize_wrapper(vrj::SimViewport* vp)
{
   float xo, yo, xs, ys;
   vp->getOriginAndSize(xo, yo, xs, ys);
   return make_tuple(xo, yo, xs, ys);
}

}// namespace 


// Module ======================================================================
void _Export_SimViewport()
{
   class_<vrj::SimViewport, bases<vrj::Viewport>, pyj::vrj_SimViewport_Wrapper>
      ("SimViewport", init<>())
      .def(init<const vrj::SimViewport&>())
      .def("updateProjections", &vrj::SimViewport::updateProjections,
           &pyj::vrj_SimViewport_Wrapper::default_updateProjections,
           "updateProjections(positionScale)\n"
           "Updates the projections.\n\n"
           "Arguments:\n"
           "positionScale -- Floating-point scale value for converting\n"
           "                 from Juggler units (meters) to the display\n"
           "                 units."
      )
      .def("getDrawSimInterface", &vrj::SimViewport::getDrawSimInterface,
           return_internal_reference<1>())
   ;
}
