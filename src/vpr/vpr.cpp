/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * PyJuggler is (C) Copyright 2002-2004 by Patrick Hartling
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

// Include =====================================================================
#include <boost/python.hpp>

// Exports =====================================================================
void _Export_Interval();
void _Export_ReturnStatus();
void _Export_ObjectReader();
void _Export_ObjectWriter();
void _Export_ReadableObject();
void _Export_WriteableObject();
void _Export_SerializableObject();
void _Export_GUID();

// Module ======================================================================
BOOST_PYTHON_MODULE(vpr)
{
    _Export_Interval();
    _Export_ReturnStatus();
    _Export_ObjectReader();
    _Export_ObjectWriter();
    _Export_ReadableObject();
    _Export_WriteableObject();
    _Export_SerializableObject();
    _Export_GUID();
}
