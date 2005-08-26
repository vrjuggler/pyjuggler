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
#include <vpr/IO/SerializableObject.h>
#include <vpr/IO/ObjectWriter.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vpr_WriteableObject_Wrapper
   : vpr::WriteableObject
   , wrapper<vpr::WriteableObject>
{
   virtual ~vpr_WriteableObject_Wrapper() throw ()
   {
      /* Do nothing. */ ;
   }

   void writeObject(vpr::ObjectWriter* p0) throw (vpr::IOException)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vpr_WriteableObject_Wrapper::writeObject()\n",
                               "vpr_WriteableObject_Wrapper::writeObject() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         this->get_override("writeObject")(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }
};


}// namespace pyj


// Module ======================================================================
void _Export_WriteableObject()
{
   class_<pyj::vpr_WriteableObject_Wrapper, boost::noncopyable>
      ("WriteableObject", no_init)
      .def("writeObject", pure_virtual(&vpr::WriteableObject::writeObject),
           "writeObject(writer) -> PyJuggler.vpr.ReturnStatus object\n"
           "Template method for writing this object to the given stream.\n"
           "<b>Post condition:</b> All object data is written to the writer."
      )
   ;
}
