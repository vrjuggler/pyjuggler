// PyJuggler is (C) Copyright 2002-2005 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <vrj/Draw/OSG/OpenSGApp.h>
#include <vrj/Kernel/Kernel.h>
#include <pyjutil/InterpreterGuard.h>
#include <pyjutil/Debug.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace pyj
{

struct vrj_OpenSGApp_Wrapper : vrj::OpenSGApp
{
   vrj_OpenSGApp_Wrapper(PyObject* self_, vrj::Kernel* p0 = NULL)
      : vrj::OpenSGApp(p0)
      , self(self_)
   {
      /* Do nothing. */ ;
   }

   virtual ~vrj_OpenSGApp_Wrapper()
   {
      /* Do nothing. */ ;
   }

   void initScene()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::initScene()\n",
                               "vrj_OpenSGApp_Wrapper::initScene() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "initScene");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   osg::Group* getScene()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::getScene()\n",
                               "vrj_OpenSGApp_Wrapper::getScene() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<osg::Group*>(self, "getScene");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return NULL;
   }

   void draw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::draw()\n",
                               "vrj_OpenSGApp_Wrapper::draw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "draw");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_draw()
   {
      vrj::OpenSGApp::draw();
   }

   void init()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::init()\n",
                               "vrj_OpenSGApp_Wrapper::init() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "init");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_init()
   {
      vrj::OpenSGApp::init();
   }

   void contextInit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::contextInit()\n",
                               "vrj_OpenSGApp_Wrapper::contextInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "contextInit");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextInit()
   {
      vrj::OpenSGApp::contextInit();
   }

   void contextClose()
   {
      vpr::DebugOutputGuard og(
      	pyjDBG_CXX, vprDBG_VERB_LVL,
        "vrj_OpenSGApp_Wrapper::contextClose()\n",
        "vrj_OpenSGApp_Wrapper::contextClose() done.\n"
     );
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "contextClose");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextClose()
   {
      vrj::OpenSGApp::contextClose();
   }

   void contextPreDraw()
   {
      vpr::DebugOutputGuard og(
      	pyjDBG_CXX, vprDBG_VERB_LVL,
        "vrj_OpenSGApp_Wrapper::contextPreDraw()\n",
        "vrj_OpenSGApp_Wrapper::contextPreDraw() done.\n"
     );
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "contextPreDraw");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPreDraw()
   {
      vrj::OpenSGApp::contextPreDraw();
   }

   void bufferPreDraw()
   {
      vpr::DebugOutputGuard og(
      	pyjDBG_CXX, vprDBG_VERB_LVL,
        "vrj_OpenSGApp_Wrapper::bufferPreDraw()\n",
        "vrj_OpenSGApp_Wrapper::bufferPreDraw() done.\n"
     );
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "bufferPreDraw");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_bufferPreDraw()
   {
      vrj::OpenSGApp::bufferPreDraw();
   }

   void pipePreDraw()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::pipePreDraw()\n",
                               "vrj_OpenSGApp_Wrapper::pipePreDraw() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "pipePreDraw");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_pipePreDraw()
   {
      vrj::OpenSGApp::pipePreDraw();
   }

   void contextPostDraw()
   {
      vpr::DebugOutputGuard og(
      	pyjDBG_CXX, vprDBG_VERB_LVL,
        "vrj_OpenSGApp_Wrapper::contextPostDraw()\n",
        "vrj_OpenSGApp_Wrapper::contextPostDraw() done.\n"
     );
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "contextPostDraw");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_contextPostDraw()
   {
      vrj::GlApp::contextPostDraw();
   }

   void apiInit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::apiInit()\n",
                               "vrj_OpenSGApp_Wrapper::apiInit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "apiInit");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_apiInit()
   {
      vrj::App::apiInit();
   }

   void exit()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::exit()\n",
                               "vrj_OpenSGApp_Wrapper::exit() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "exit");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_exit()
   {
      vrj::App::exit();
   }

   void preFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::preFrame()\n",
                               "vrj_OpenSGApp_Wrapper::preFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "preFrame");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_preFrame()
   {
      vrj::App::preFrame();
   }

   void latePreFrame()
   {
      vpr::DebugOutputGuard og(
      	pyjDBG_CXX, vprDBG_VERB_LVL,
        "vrj_OpenSGApp_Wrapper::latePreFrame()\n",
        "vrj_OpenSGApp_Wrapper::latePreFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "latePreFrame");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_latePreFrame()
   {
      vrj::OpenSGApp::latePreFrame();
   }

   void intraFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::intraFrame()\n",
                               "vrj_OpenSGApp_Wrapper::intraFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "intraFrame");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_intraFrame()
   {
      vrj::App::intraFrame();
   }

   void postFrame()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::postFrame()\n",
                               "vrj_OpenSGApp_Wrapper::postFrame() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "postFrame");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_postFrame()
   {
      vrj::App::postFrame();
   }

   void reset()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OpenSGApp_Wrapper::reset()\n",
                               "vrj_OpenSGApp_Wrapper::reset() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "reset");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_reset()
   {
      vrj::App::reset();
   }

   void focusChanged()
   {
      vpr::DebugOutputGuard og(
      	  pyjDBG_CXX, vprDBG_VERB_LVL,
          "vrj_OpenSGApp_Wrapper::focusChanged()\n",
          "vrj_OpenSGApp_Wrapper::focusChanged() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         call_method<void>(self, "focusChanged");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }
   }

   void default_focusChanged()
   {
      vrj::App::focusChanged();
   }

   float getDrawScaleFactor()
   {
      vpr::DebugOutputGuard og(
      	 pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_OpenSGApp_Wrapper::getDrawScaleFactor()\n",
         "vrj_OpenSGApp_Wrapper::getDrawScaleFactor() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<float>(self, "getDrawScaleFactor");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return vrj::App::getDrawScaleFactor();
   }

   float default_getDrawScaleFactor()
   {
      return vrj::App::getDrawScaleFactor();
   }

   bool configCanHandle(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(
      	 pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_OpenSGApp_Wrapper::configCanHandle()\n",
         "vrj_OpenSGApp_Wrapper::configCanHandle() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<bool>(self, "configCanHandle", p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configCanHandle(jccl::ConfigElementPtr p0)
   {
      return vrj::App::configCanHandle(p0);
   }

   bool depSatisfied()
   {
      vpr::DebugOutputGuard og(
      	 pyjDBG_CXX, vprDBG_VERB_LVL,
         "vrj_OpenSGApp_Wrapper::depSatisfied()\n",
         "vrj_OpenSGApp_Wrapper::depSatisfied() done.\n"
      );
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<bool>(self, "depSatisfied");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return true;
   }

   bool default_depSatisfied()
   {
      return vrj::App::depSatisfied();
   }

   bool configAdd(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OsgApp_Wrapper::configAdd()\n",
                               "vrj_OsgApp_Wrapper::configAdd() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<bool>(self, "configAdd", p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configAdd(jccl::ConfigElementPtr p0)
   {
      return vrj::App::configAdd(p0);
   }

   bool configRemove(jccl::ConfigElementPtr p0)
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OsgApp_Wrapper::configRemove()\n",
                               "vrj_OsgApp_Wrapper::configRemove() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<bool>(self, "configRemove", p0);
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return false;
   }

   bool default_configRemove(jccl::ConfigElementPtr p0)
   {
      return vrj::App::configRemove(p0);
   }

   int configProcessPending()
   {
      vpr::DebugOutputGuard og(pyjDBG_CXX, vprDBG_VERB_LVL,
                               "vrj_OsgApp_Wrapper::configProcessPending()\n",
                               "vrj_OsgApp_Wrapper::configProcessPending() done.\n");
      PyJuggler::InterpreterGuard guard;

      try
      {
         return call_method<int>(self, "configProcessPending");
      }
      catch (error_already_set)
      {
         PyErr_Print();
      }

      return 0;
   }

   int default_configProcessPending()
   {
      return vrj::App::configProcessPending();
   }

   PyObject* self;
};


}// namespace pyj


// Module ======================================================================
void _Export_OsgApp()
{
   class_<vrj::OsgApp, bases<vrj::GlApp>, boost::noncopyable,
          pyj::vrj_OsgApp_Wrapper>
      ("OsgApp",
       "vrj.OsgApp encapsulates an Open Scene Graph (OSG) application.\n"
       "This defines the base class from which OSG-based application\n"
       "objects should be derived.  It makes use of the OpenGL Draw\n"
       "Manager.\n\n"
       "To use OSG with Python and this class, use PyOSG.  PyOSG is also\n"
       "written using Boost.Python, so instances of PyOSG objects can be\n"
       "passed into methods of this class without compatibility problems.\n\n"
       "See: vrj.GlApp"
       ,
       init< optional<vrj::Kernel*> >(
          "__init__()\n"
          "Default constructor.  Uses vrj.Kernel.instance().\n\n"
          "__init__(kernel)\n"
          "Arguments:\n"
          "kernel -- The vrj.Kernel instance that is active (so the\n"
          "          application has easy access to the kernel)."
       )
      )
      .def_readwrite("mKernel", &vrj::App::mKernel)
      .def_readwrite("mHaveFocus", &vrj::App::mHaveFocus)
      .def("initScene", pure_virtual(&vrj::OsgApp::initScene),
           "initScene()\n"
           "Initializes the scene.  Called by init() to initialize the\n"
           "scene."
      )
      .def("getScene", pure_virtual(&vrj::OsgApp::getScene),
           return_internal_reference<1>(), 
           "getScene() -> osg.Group object\n"
           "Gets the root fo the scene to render.  Called each frame to\n"
           "get teh current scene to render."
      )
      .def("configSceneView", &vrj::OsgApp::configSceneView,
           &pyj::vrj_OsgApp_Wrapper::default_configSceneView,
           "configSceneView(newSceneVeiwer)\n"
           "Configures newly created scene viewers.  This is called\n"
           "immediately after a new scene viewer is created for a context.\n"
           "This is the place to configure application background colors\n"
           "and other viewer-specific information.\n\n"
           "Arguments:\n"
           "newSceneViewer -- An osgUtil.SceneView object that is the\n"
           "                  newly created scene view."
      )
      .def("draw", &vrj::OsgApp::draw, &pyj::vrj_OsgApp_Wrapper::default_draw,
           "draw()\n"
           "Function to draw the scene.  Override this method with great\n"
           "create.  All the logic to handle multi-pipe rendering and\n"
           "other VR Juggler features happens here.\n\n"
           "Pre-conditions:\n"
           "OpenGL state has correct transformation and buffer selected.\n\n"
           "Post-conditions:\n"
           "The current sceen has been drawn."
      )
      .def("init", &vrj::OsgApp::init, &pyj::vrj_OsgApp_Wrapper::default_init,
           "init()\n"
           "Application initialization function.  Execute any\n"
           "initialization needed before the graphics API is started.  If\n"
           "this method is overridden, it must be called by the overriding\n"
           "version.  This calls initScene(), which is used to set up this\n"
           "application object's scene graph.\n\n"
           "Note:\n"
           "Derived classes MUST call the base class version of this\n"
           "method."
      )
      .def("contextInit", &vrj::OsgApp::contextInit,
           &pyj::vrj_OsgApp_Wrapper::default_contextInit,
           "contextInit()\n"
           "Function that is called immediately after a new context is\n"
           "created.  Use this function to create context-specific data\n"
           "structures such as display lists and texture objects that are\n"
           "known to be required when the context is created.\n\n"
           "Pre-condition:\n"
           "The OpenGL context has been set to the new context.\n\n"
           "Post-condition:\n"
           "The application has completed context-specific initialization."
      )
      .def("contextClose", &vrj::OsgApp::contextClose,
           &pyj::vrj_OsgApp_Wrapper::default_contextClose,
           "contextClose()\n"
           "Function that is called immediately before a context is closed.\n"
           "Use this function to clean up any context-specific data\n"
           "structures."
      )
      .def("contextPreDraw", &vrj::OsgApp::contextPreDraw,
           &pyj::vrj_OsgApp_Wrapper::default_contextPreDraw,
           "contextPreDraw()\n"
           "Function that is called upon entry into the context before\n"
           "rendering begins.  This can be used to allocate\n"
           "context-specific data dynamically.\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditins:\n"
           "The application object has executed any commands that need to\n"
           "be executed only once per context, per frame.\n\n"
           "This function can be used for things that need to happen every\n"
           "frame but only once per context."
      )
      .def("bufferPreDraw", &vrj::OsgApp::bufferPreDraw,
           &pyj::vrj_OsgApp_Wrapper::default_bufferPreDraw,
           "bufferPreDraw()\n"
           "Function that is called once for each frame buffer of an\n"
           "OpenGL context.  This function is executed after contextInit()\n"
           "(if neede) but before contextPreDraw().  It is called once\n"
           "per frame buffer (see note below).\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing.\n\n"
           "Post-conditions:\n"
           "The application object has executed any commands that need to\n"
           "be executed once per context, per buffer, per frame.\n\n"
           "Note:\n"
           "This function is designed to be used when some task must be\n"
           "performed only once per frame buffer (i.e., once for the left\n"
           "tbuffer, once for the right buffer).  For example, the OpenGL\n"
           "clear color should be defined and glClear(GL_COLOR_BUFFER_BIT)\n"
           "should be called in this method."
      )
      .def("pipePreDraw", &vrj::OsgApp::pipePreDraw,
           &pyj::vrj_OsgApp_Wrapper::default_pipePreDraw,
           "pipePreDraw()\n"
           "Function that is called at the beginning of the drawing of eacn\n"
           "pipe.\n\n"
           "Pre-conditions:\n"
           "The library is preparing to render all windows on a given\n"
           "pipe.\n\n"
           "Post-conditions:\n"
           "Any pre-pipe user calls have been done.\n\n"
           "Note:\n"
           "Currently the OpenGL context is not set when this function is\n"
           "called.  This is a TEST function.  USE AT YOUR OWN RISK!"
      )
      .def("contextPostDraw", &vrj::GlApp::contextPostDraw,
           &pyj::vrj_OsgApp_Wrapper::default_contextPostDraw,
           "contextPostDraw()\n"
           "Function that is called upon exit of the context after\n"
           "rendering\n\n"
           "Pre-conditions:\n"
           "The OpenGL context has been set to the context for drawing."
      )
      .def("apiInit", &vrj::App::apiInit,
           &pyj::vrj_OsgApp_Wrapper::default_apiInit,
           "apiInit()\n"
           "Application graphics API initialization function.  Execute any\n"
           "initialization needed after the graphics API is started but\n"
           "before the Draw Manager starts the rendering loop(s)."
      )
      .def("exit", &vrj::App::exit, &pyj::vrj_OsgApp_Wrapper::default_exit,
           "exit()\n"
           "Executes any final clean-up needed for the application before\n"
           "exiting."
      )
      .def("preFrame", &vrj::App::preFrame,
           &pyj::vrj_OsgApp_Wrapper::default_preFrame,
           "preFrame()\n"
           "Function called before the Juggler frame starts.  This is\n"
           "called after input device updates but before the start of a\n"
           "new frame."
      )
      .def("latePreFrame", &vrj::OsgApp::latePreFrame,
           &pyj::vrj_OsgApp_Wrapper::default_latePreFrame,
           "latePreFrame()\n"
           "Function called after preFrame() and application-specific data\n"
           "synchronization (in a cluster conifguration) but before the\n"
           "start of a new frame.\n\n"
           "Note:\n"
           "This is required because we cannot update data during the\n"
           "rendering process since it might be using multiple threads."
      )
      .def("intraFrame", &vrj::App::intraFrame,
           &pyj::vrj_OsgApp_Wrapper::default_intraFrame,
           "intraFrame()\n"
           "Function called during the application's drawing time."
      )
      .def("postFrame", &vrj::App::postFrame,
           &pyj::vrj_OsgApp_Wrapper::default_postFrame,
           "postFrame()\n"
           "Function alled before updating input devices but after the\n"
           "frame is complete."
      )
      .def("reset", &vrj::App::reset,
           &pyj::vrj_OsgApp_Wrapper::default_reset,
           "reset()\n"
           "Resets the application.  This is used when the kernel (or\n"
           "applications would like this application to reset to its\n"
           "initial state."
      )
      .def("focusChanged", &vrj::App::focusChanged,
           &pyj::vrj_OsgApp_Wrapper::default_focusChanged,
           "focusChanged()\n"
           "Called when the focus state changes."
      )
      .def("getDrawScaleFactor", &vrj::App::getDrawScaleFactor,
           &pyj::vrj_OsgApp_Wrapper::default_getDrawScaleFactor,
           "getDrawScaleFactor() -> float\n"
           "Returns the scale factor to convert from Juggler units\n"
           "(meters) to application units.  Internally, VR Juggler stores\n"
           "and processes all position values in meterrs.  The scale\n"
           "factor returned by this method is used by VR Juggler to scale\n"
           "the rendering state from meters to whatever units this\n"
           "application wants to use.  For example, to render in feet,\n"
           "return 3.28 (gadget.PositionUnitConversion.ConvertToFeet)."
      )
      .def("configCanHandle", &vrj::App::configCanHandle,
           &pyj::vrj_OsgApp_Wrapper::default_configCanHandle,
           "configCanHandle(element) -> Boolean\n"
           "Defaults to handling nothing.\n\n"
           "Arguments:\n"
           "element -- An instance of jccl.ConfigElement."
      )
      .def("depSatisfied", &vrj::App::depSatisfied,
           &pyj::vrj_OsgApp_Wrapper::default_depSatisfied,
           "depSatisfied() -> Boolean\n"
           "Are any application dependencies satisified?  If this\n"
           "application requires anything special of the system for\n"
           "successful initialization, check it here.  If the return value\n"
           "is False, then this application will not be started yet.  If\n"
           "the return value is True, this application will be allowed to\n"
           "enter the system."
      )
      .def("configProcessPending",
           &jccl::ConfigElementHandler::configProcessPending,
           &pyj::vrj_OsgApp_Wrapper::default_configProcessPending,
           "configProcessPending() -> int\n"
           "Inherited from jccl.ConfigElementHandler and not overridden."
      )
      .def("haveFocus", &vrj::App::haveFocus,
           "haveFocus() -> Boolean\n"
           "Does this application currently have focus?  If an application\n"
           "has focus, the user may be attempting to interact with it, so\n"
           "the application should process input.  If not, the user is\n"
           "not interacting with it, so ignore all input.  However, the\n"
           "user may still be viewing the application, so render, update\n"
           "animations, etc.  This is akin to the way that a user can only\n"
           "interact with a GUI window that has focus."
      )
      .def("setFocus", &vrj::App::setFocus,
           "setFocus(newState)\n"
           "Sets the focus state.\n\n"
           "Post-condition:\n"
           "If the focus state has changed, then focusChanged() is\n"
           "called.\n\n"
           "Arguments:\n"
           "newState -- A Boolean value indicating whether this application\n"
           "            now has focus."
      )
   ;
}