// PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <gadget/Type/AnalogProxy.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct gadget_AnalogProxy_Wrapper
   : gadget::AnalogProxy
   , wrapper<gadget::AnalogProxy>
{
   gadget_AnalogProxy_Wrapper()
      : gadget::AnalogProxy()
   {
      /* Do nothing. */ ;
   }

   virtual ~gadget_AnalogProxy_Wrapper()
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
            gadget::AnalogProxy::updateData();
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_updateData()
   {
      gadget::AnalogProxy::updateData();
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

     return gadget::AnalogProxy::getTimeStamp();
   }

   const vpr::Interval& default_getTimeStamp() const
   {
      return gadget::AnalogProxy::getTimeStamp();
   }

   bool config(jccl::ConfigElementPtr p0)
   {
      try
      {
         if ( override config = this->get_override("config") )
         {
            return config(p0);
         }
         return gadget::AnalogProxy::config(p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_config(jccl::ConfigElementPtr p0)
   {
      return gadget::AnalogProxy::config(p0);
   }

   void set(const std::string& p0, const gadget::AnalogPtr& p1,
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
            gadget::AnalogProxy::set(p0, p1, p2);
         }
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_set(const std::string& p0, const gadget::AnalogPtr& p1,
                    const boost::optional<int>& p2 = boost::optional<int>())
   {
      gadget::AnalogProxy::set(p0, p1, p2);
   }

   bool refresh()
   {
      try
      {
         if ( override refresh = this->get_override("refresh") )
         {
            return refresh();
         }
         return gadget::AnalogProxy::refresh();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_refresh()
   {
      return gadget::AnalogProxy::refresh();
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

      return gadget::AnalogProxy::getDeviceName();
   }

   const std::string& default_getDeviceName() const
   {
      return gadget::AnalogProxy::getDeviceName();
   }

   bool isStupefied() const
   {
      try
      {
         if ( override isStupefied = this->get_override("isStupefied") )
         {
            return isStupefied();
         }
         return gadget::AnalogProxy::isStupefied();
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_isStupefied() const
   {
      return gadget::AnalogProxy::isStupefied();
   }

   virtual const float getData() const
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

      return gadget::AnalogProxy::getData();
   }

   const float default_getData() const
   {
      return gadget::AnalogProxy::getData();
   }
};

}// namespace 


// Module ======================================================================
void _Export_AnalogProxy()
{
   class_<pyj::gadget_AnalogProxy_Wrapper
       , gadget::AnalogProxyPtr
       , boost::noncopyable
       >
      (
       "AnalogProxy",
       "A proxy class to analog devices used by the Input Manager.\n\n"
       "An analog proxy always points to an analog device and a unit\n"
       "number within that device.  The Input Manager can therefore keep\n"
       "an array of these around and treat them as analog devices that\n"
       "only return a single sub-device's amount of data (one float)."
       ,
       no_init
      )
      .def("create", &gadget::AnalogProxy::create)
      .def("updateData", &gadget::AnalogProxy::updateData,
           &pyj::gadget_AnalogProxy_Wrapper::default_updateData,
           "updateData()\n"
           "Updates the cached data copy from the device and the normalized\n"
           "form of that data."
      )
      .def("updateDataIfNeeded", &gadget::Proxy::updateDataIfNeeded,
           "updateDataIfNeeded()\n"
      )
      .def("resetData", &gadget::Proxy::resetData,
           "resetData()\n"
      )
      .def("getTimeStamp", &gadget::AnalogProxy::getTimeStamp,
           &pyj::gadget_AnalogProxy_Wrapper::default_getTimeStamp,
           return_value_policy<copy_const_reference>(),
           "getTimeStamp() -> vpr.Interval object\n"
           "Returns the time of the last update."
      )
      .def("config", &gadget::AnalogProxy::config,
           &pyj::gadget_AnalogProxy_Wrapper::default_config,
           "config(element) -> Boolean\n"
           "Configures this proxy using the given jccl.ConfigElement\n"
           "instance."
      )
      // TODO: Expose boost::optional to Python...
      /*
      .def("set", &gadget::AnalogProxy::set,
           &pyj::gadget_AnalogProxy_Wrapper::default_set,
           "set(devName, devPtr)\n"
           "Sets the proxy to point to the given type-specific device.\n"
           "Pre-condition:\n"
           "devPtr must be a valid device of type gadget.Analog\n"
           "Post-condition:\n"
           "The proxy now references the given device.  The device name we\n"
           "are proxying is set to devPtr.getInstanceName()."
           "Arguments:\n"
           "devName -- The name of the device at which we are pointing.\n"
           "devPtr  -- Pointer to the device.  For gadget.AnalogProxy,\n"
           "           this points to an instance of gadget.Analog.\n"
           "unitNum -- "
      )
      */
      .def("refresh", &gadget::AnalogProxy::refresh,
           &pyj::gadget_AnalogProxy_Wrapper::default_refresh,
           "refresh() -> Boolean\n"
           "Refreshes the proxy.  This attempts to lookup the device that\n"
           "we are proxying.  If the lookup fails, then we become\n"
           "stupefied.  If not, then the proxy is pointed at this\n"
           "potentially new device."
      )
      .def("getDeviceName", &gadget::AnalogProxy::getDeviceName,
           &pyj::gadget_AnalogProxy_Wrapper::default_getDeviceName,
           return_value_policy<copy_const_reference>(),
           "getDeviceName() -> string object\n"
           "Gets the name of the device that we are proxying."
      )
      .def("isStupefied", &gadget::Proxy::isStupefied,
           &pyj::gadget_AnalogProxy_Wrapper::default_isStupefied,
           "isStupefied() -> Boolean\n"
           "Is the proxy currently stupefied?\n"
           "If the device we are proxying does not exist, then this will\n"
           "return True."
      )
      .def("getData", &gadget::AnalogProxy::getData,
           &pyj::gadget_AnalogProxy_Wrapper::default_getData,
           "getData() -> float\n"
           "Gets the current normalized analog data value. This value will\n"
           "be in the range [0.0,1.0]."
      )
      .def("getRawData", &gadget::AnalogProxy::getRawData,
           return_value_policy<copy_const_reference>(),
           "getData() -> float\n"
           "Gets the current raw analog data value. This is the value read\n"
           "direcctly from the device without perfomring any normalization."
      )
      .def("getTypedInputDevice", &gadget::AnalogProxy::getTypedInputDevice,
           "getTypedInputDevice() -> gadget.Analog object\n"
      )
      .def("getUnit", &gadget::AnalogProxy::getUnit,
           "getUnit() -> int\n"
           "Returns the unit index into the analog device from which this\n"
           "proxy is reading data."
      )
      .def("getElementType", &gadget::AnalogProxy::getElementType,
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
      .def("stupefy", &gadget::Proxy::stupefy, (args("newState") = true),
           "stupefy(newState = True)\n"
           "Sets the stupefication state of this proxy.\n"
           "Keyword arguments:\n"
           "newState -- The new state of stupefication."
      )
      .staticmethod("create")
      .staticmethod("getElementType")
   ;
}
