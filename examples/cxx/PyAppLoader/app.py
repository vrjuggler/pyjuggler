# PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

import sys
from OpenGL.GL import *

# NOTE: If you import the individual modules from PyJuggler, make sure to
# import PyJuggler.vrj first.
from PyJuggler import *
from PyJuggler import vrj.opengl
import gmtl


class SimpleGlApp(vrj.opengl.App):
   mButton0 = gadget.DigitalInterface()
   mButton1 = gadget.DigitalInterface()
   mButton2 = gadget.DigitalInterface()
   mWand    = gadget.PositionInterface()
   mHead    = gadget.PositionInterface()

   mGrabbed = 0

   def __init__(self):
      vrj.opengl.App.__init__(self)

   def init(self):
      self.mButton0.init("VJButton0")
      self.mButton1.init("VJButton1")
      self.mButton2.init("VJButton2")
      self.mWand.init("VJWand")
      self.mHead.init("VJHead")

   def contextInit(self):
      self.initGLState()

   def preFrame(self):
      if self.mButton0.getData() == gadget.Digital.State.ON:
         self.mGrabbed = 1
      elif self.mButton0.getData() == gadget.Digital.State.TOGGLE_ON:
         self.mGrabbed = 1
      else:
         self.mGrabbed = 0

   def bufferPreDraw(self):
      glClearColor(0.0, 0.0, 0.0, 0.0)
      glClear(GL_COLOR_BUFFER_BIT)

   def draw(self):
      box_offset = gmtl.Vec3f(0.0, 6.0, 0.0)
      box_rotate = gmtl.EulerAngleXYZf(0.0, 0.0, 0.0)
#      box_transform = gmtl.makeTransMatrix44(gmtl.Vec3f(0.0, 6.0, 0.0))

      # Move the box to the wand's position if the box is grabbed.
      if self.mGrabbed:
         wand_transform = self.mWand.getData()
         box_offset     = gmtl.makeTransVec3(wand_transform)
         box_rotate     = gmtl.makeRotEulerAngleXYZ(wand_transform)

      glClear(GL_DEPTH_BUFFER_BIT)
      glPushMatrix()
      glTranslatef(box_offset[0], box_offset[1], box_offset[2])
      glRotatef(gmtl.Math.rad2Deg(box_rotate[0]), 1.0, 0.0, 0.0)
      glRotatef(gmtl.Math.rad2Deg(box_rotate[1]), 0.0, 1.0, 0.0)
      glRotatef(gmtl.Math.rad2Deg(box_rotate[2]), 0.0, 0.0, 1.0)
#      glMultMatrixf(box_transform.mData)
      self.drawbox(-0.5, 0.5, -0.5, 0.5, -0.5, 0.5, GL_QUADS)
      glPopMatrix()

   def drawbox(self, x0, x1, y0, y1, z0, z1, type):
      n = [ [-1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [1.0, 0.0, 0.0],
            [0.0, -1.0, 0.0], [0.0, 0.0, 1.0], [0.0, 0.0, -1.0] ]
      faces = [ [0, 1, 2, 3], [3, 2, 6, 7], [7, 6, 5, 4],
                [4, 5, 1, 0], [5, 6, 2, 1], [7, 4, 0, 3] ]

      if x0 > x1:
         tmp = x0
         x0 = x1
         x1 = tmp
      if y0 > y1:
         tmp = y0
         y0 = y1
         y1 = tmp
      if z0 > z1:
         tmp = z0
         z0 = z1
         z1 = tmp

      v = [ [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0],
            [0, 0, 0], [0, 0, 0], [0, 0, 0], [0, 0, 0] ]
      v[0][0] = v[1][0] = v[2][0] = v[3][0] = x0
      v[4][0] = v[5][0] = v[6][0] = v[7][0] = x1
      v[0][1] = v[1][1] = v[4][1] = v[5][1] = y0
      v[2][1] = v[3][1] = v[6][1] = v[7][1] = y1
      v[0][2] = v[3][2] = v[4][2] = v[7][2] = z0
      v[1][2] = v[2][2] = v[5][2] = v[6][2] = z1

      for i in range(6):
         glBegin(type)
         glNormal3d(n[i][0], n[i][1], n[i][2])
         glVertex3d(v[faces[i][0]][0], v[faces[i][0]][1], v[faces[i][0]][2])
         glNormal3d(n[i][0], n[i][1], n[i][2])
         glVertex3d(v[faces[i][1]][0], v[faces[i][1]][1], v[faces[i][1]][2])
         glNormal3d(n[i][0], n[i][1], n[i][2])
         glVertex3d(v[faces[i][2]][0], v[faces[i][2]][1], v[faces[i][2]][2])
         glNormal3d(n[i][0], n[i][1], n[i][2])
         glVertex3d(v[faces[i][3]][0], v[faces[i][3]][1], v[faces[i][3]][2])
         glEnd()

   def initGLState(self):
      light0_ambient  = [ 0.1, 0.1, 0.1, 1.0 ]
      light0_diffuse  = [ 0.8, 0.8, 0.8, 1.0 ]
      light0_specular = [ 1.0, 1.0, 1.0, 1.0 ]
      light0_position = [ 0.0, 0.75, 0.75, 0.0 ]

#      mat_ambient   = [ 0.7, 0.7, 0.7, 1.0 ]
#      mat_diffuse   = [ 1.0, 0.5, 0.8, 1.0 ]
#      mat_specualr  = [ 1.0, 1.0, 1.0, 1.0 ]
#      mat_shininess = [ 50.0 ]
#      no_mat        = [ 0.0, 0.0, 0.0, 1.0 ]

      glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient)
      glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse)
      glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular)
      glLightfv(GL_LIGHT0, GL_POSITION, light0_position)

#      glMaterialfv(GL_LIGHT0, GL_AMBIENT, mat_ambient)
#      glMaterialfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse)
#      glMaterialfv(GL_LIGHT0, GL_SPECULAR, mat_specular)
#      glMaterialfv(GL_LIGHT0, GL_SHININESS, mat_shininess)
#      glMaterialfv(GL_LIGHT0, GL_EMISSION, no_mat)

      glEnable(GL_DEPTH_TEST)
      glEnable(GL_NORMALIZE)
      glEnable(GL_LIGHTING)
      glEnable(GL_LIGHT0)
#      glEnable(GL_COLOR_MATERIAL)
      glShadeModel(GL_SMOOTH)

#def vrjInit():
#   return SimpleGlApp()
