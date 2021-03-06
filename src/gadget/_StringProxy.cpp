// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/StringProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_StringProxy_Wrapper
   : gadget::StringProxy
   , wrapper<gadget::StringProxy>
{
   gadget_StringProxy_Wrapper()
      : gadget::StringProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_StringProxy_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void updateData()
   {
      try
      {
         if ( override updateData = this->get_override("updateData") )
         {
            updateData();
         }
         else
         {
            gadget::StringProxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::StringProxy::updateData();
   }

   const vpr::Interval& getTimeStamp() const
   {
      try
      {
         if ( override getTimeStamp = this->get_override("getTimeStamp") )
         {
            return getTimeStamp();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::StringProxy::getTimeStamp();
   }

   const vpr::Interval& default_getTimeStamp() const
   {
      return gadget::StringProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::StringProxy::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::StringProxy::config(p0);
   }

   void set(const std::string& p0, const gadget::StringPtr& p1,
            const boost::optional<int>& p2 = boost::optional<int>())
   {
      try
      {
         if ( override set = this->get_override("set") )
         {
            set(boost::ref(p0), boost::ref(p1), boost::ref(p2));
         }
         else
         {
            gadget::StringProxy::set(p0, p1, p2);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, const gadget::StringPtr& p1,
                    const boost::optional<int>& p2 = boost::optional<int>())
   {
      gadget::StringProxy::set(p0, p1, p2);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         return gadget::StringProxy::refresh();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::StringProxy::refresh();
   }

   const std::string& getDeviceName() const
   {
      try
      {
         if ( override getDeviceName = this->get_override("getDeviceName") )
         {
            return getDeviceName();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::StringProxy::getDeviceName();
   }

   const std::string& default_getDeviceName() const
   {
      return gadget::StringProxy::getDeviceName();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::StringProxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::StringProxy::isStupefied();
   }

   virtual const std::string getData() const
   {
      try
      {
         if ( override getData = this->get_override("getData") )
         {
            return getData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return gadget::StringProxy::getData();
   }

   const std::string default_getData() const
   {
      return gadget::StringProxy::getData();
   }
};

}// namespace 


// Module ======================================================================
void _Export_StringProxy()
{
   class_<pyj::gadget_StringProxy_Wrapper
        , gadget::StringProxyPtr
        , boost::noncopyable
        >
      (
       "StringProxy",
       "A proxy class to string devices used by the Input Manager.\n\n"
       "A string proxy always points to a string device and a unit number\n"
       "within that device.  The Input Manager can therefore keep an array\n"
       "of these around and treat them as string devices that only return a\n"
       "single sub-device's amount of data (one string)."
       ,
       no_init
      )
      .def("create", &gadget::StringProxy::create)
      .def("updateData", &gadget::StringProxy::updateData,
           &pyj::gadget_StringProxy_Wrapper::default_updateData,
           "updateData()\n"
           "Updates the cached data copy from the device."
      )
      .def("updateDataIfNeeded", &gadget::Proxy::updateDataIfNeeded,
           "updateDataIfNeeded()\n"
      )
      .def("resetData", &gadget::Proxy::resetData,
           "resetData()\n"
      )
      .def("getTimeStamp", &gadget::StringProxy::getTimeStamp,
           &pyj::gadget_StringProxy_Wrapper::default_getTimeStamp,
           return_value_policy<copy_const_reference>(),
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::StringProxy::config,
           &pyj::gadget_StringProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      // TODO: Expose boost::optional to Python...
      /*
      .def("set", &gadget::StringProxy::set,
           &pyj::gadget_StringProxy_Wrapper::default_set,
           "set(devName, devPtr)\n"
           "Sets the proxy to point to the given type-specific device.\n"
           "Pre-condition:\n"
           "devPtr must be a valid device of type gadget.String\n"
           "Post-condition:\n"
           "The proxy now references the given device.  The device name we\n"
           "are proxying is set to devPtr.getInstanceName().\n"
           "Arguments:\n"
           "devName -- The name of the device at which we are pointing.\n"
           "devPtr  -- Pointer to the device.  For gadget.StringProxy,\n"
           "           this points to an instance of gadget.String.\n"
      )
      */
      .def("refresh", &gadget::StringProxy::refresh,
           &pyj::gadget_StringProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::StringProxy::getDeviceName,
           &pyj::gadget_StringProxy_Wrapper::default_getDeviceName,
           return_value_policy<copy_const_reference>(),
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_StringProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getData", &gadget::StringProxy::getData,
           &pyj::gadget_StringProxy_Wrapper::default_getData,
           "getData() -> float\n"
           "Gets the current string data value."
      )
      .def("getTypedInputDevice", &gadget::StringProxy::getTypedInputDevice,
           "getTypedInputDevice() -> gadget.String object\n"
      )
      .def("getUnit", &gadget::StringProxy::getUnit,
           "getUnit() -> int\n"
           "Returns the unit index into the analog device from which this\n"
           "proxy is reading data."
      )
      .def("getElementType", &gadget::StringProxy::getElementType,
           "getElementType() -> string object"
      )
      .def("getName", &gadget::Proxy::getName,
           return_value_policy<copy_const_reference>(),
           "getName() -> string object\n"
           "Gets the name of the proxy."
      )
      .def("setName", &gadget::Proxy::setName,
           "setName(name)\n"
           "Sets the name of the proxy.\n"
           "Arguments:\n"
           "name -- The name for this proxy as a string object."
      )
      .def("stupefy", &gadget::Proxy::stupefy,
           "stupefy(newState = True)\n"
           "Sets the stupefication state of this proxy.\n"
           "Keyword arguments:\n"
           "newState -- The new state of stupefication."
      )
      .staticmethod("create")
      .staticmethod("getElementType")
   ;
}
