/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * PyJuggler is (C) Copyright 2002, 2003 by Patrick Hartling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile$
 * Date modified: $Date$
 * Version:       $Revision$
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/

// Includes ====================================================================
#include <boost/python.hpp>
#include <vrj/Kernel/User.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================


namespace  {


struct vrj_User_Wrapper: vrj::User
{
    vrj_User_Wrapper(PyObject* self_):
        vrj::User(), self(self_) {}


    PyObject* self;
};



}// namespace 


// Module ======================================================================
void _Export_User()
{
    class_< vrj::User, boost::noncopyable, vrj_User_Wrapper >("User", init<  >())
        .def("getId", &vrj::User::getId)
        .def("getName", &vrj::User::getName)
        .def("getHeadUpdateTime", &vrj::User::getHeadUpdateTime)
        .def("getInterocularDistance", &vrj::User::getInterocularDistance)
    ;

}