#python

# PyJuggler is (C) Copyright 2002-2012 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

import glob
import os
import re
import shutil
import sys
import time
import traceback

python_ver_re = re.compile(r'(\d+)\.(\d+)')
python_pkg_dir = ''

def setVars():
   global python_pkg_dir

   def processInput(optionDict, envVar, inputDesc, required = False):
      default_value = optionDict[envVar]
      print "    Enter %s [%s]: " % (inputDesc, default_value),
      input_str = sys.stdin.readline().strip(" \n")

      if input_str == '':
         if required and (default_value is None or default_value == ''):
            print "ERROR: %s value required" % inputDesc
            os.exit(1)
         else:
            value_str = default_value
      else:
         value_str = input_str

      optionDict[envVar] = value_str
      os.environ[envVar] = value_str

      return value_str

   options = {
      # Default values for required settings.
      'VJ_BASE_DIR'    : os.getenv('VJ_BASE_DIR', ''),
      'VJ_DEPS_DIR'    : os.getenv('VJ_DEPS_DIR', ''),
      'BOOST_VERSION'  : os.getenv('BOOST_VERSION', '1_32'),
      'BOOST_TOOL'     : os.getenv('BOOST_TOOL', 'vc71'),
      'PYTHON_ROOT'    : os.getenv('PYTHON_ROOT', ''),
      'PYTHON_VERSION' : os.getenv('PYTHON_VERSION', sys.version[:3]),
      'prefix'         : r'C:\PyJuggler',

      # Default values for optional settings.
      'OSGHOME'        : os.getenv('OSGHOME', ''),
      'OSGROOT'        : os.getenv('OSGROOT', '')
   }

   # If there are cached options, read them in.
   cache_file = os.path.join(pyj_dir, 'options.cache')
   if os.path.exists(cache_file):
      execfile(cache_file)

   print "+++ Required Settings"
   processInput(options, 'prefix', 'installation prefix')
   processInput(options, 'VJ_BASE_DIR', 'VR Juggler installation directory')
   processInput(options, 'VJ_DEPS_DIR',
                'VR Juggler dependency installation directory')
   processInput(options, 'BOOST_VERSION', 'Boost C++ version')
   processInput(options, 'BOOST_TOOL',
                'the Boost.Build toolset used to compile Boost C++')
   processInput(options, 'PYTHON_ROOT', 'Python installation directory')

   py_ver = processInput(options, 'PYTHON_VERSION', 'Python version')
   python_pkg_dir = os.path.join('lib', 'python' + py_ver, 'site-packages')

   print "\n+++ Optional Settings"
   processInput(options, 'OSGHOME', 'Open Scene Graph installation directory',
                False)
   processInput(options, 'OSGROOT', 'OpenSG installation directory', False)

   # Check for Boost 1.32 Visual C++ toolset names.
   match = re.compile(r'vc-(\d)_(\d)').match(options['BOOST_TOOL'])

   if match is not None:
      os.environ['BOOST_TOOL'] = 'vc%s%s' % (match.group(1), match.group(2))

   cache_file = open(cache_file, 'w')
   for k, v in options.iteritems():
      output = "options['%s'] = r'%s'\n" % (k, v)
      cache_file.write(output)
   cache_file.close()

   return options

def doInstall(prefix):
   makeTree(prefix)
   installDist(prefix)
   installLibs(prefix)
   installMods(prefix)
   installHeaders(prefix)
   installExamples(prefix)

def mkinstalldirs(dir):
   if not os.path.exists(dir):
      (head, tail) = os.path.split(dir)
      mkinstalldirs(head)
      os.mkdir(dir)

def makeTree(prefix):
#   mkinstalldirs(os.path.join(prefix, 'include'))
   mkinstalldirs(os.path.join(prefix, 'lib'))
   mkinstalldirs(os.path.join(prefix, python_pkg_dir))
   mkinstalldirs(os.path.join(prefix, 'share', 'pyjuggler'))
   mkinstalldirs(os.path.join(prefix, 'include'))

def installDir(startDir, destDir, allowedExts = None, disallowedExts = None,
               disallowedFiles = None):
   cwd = os.getcwd()
   mkinstalldirs(destDir)

   os.chdir(startDir)
   contents = os.listdir(startDir)

   if disallowedExts is None:
      disallowedExts = []

   if disallowedFiles is None:
      disallowedFiles = []

   # Add some extensions that should always be disallowed.  This relieves the
   # caller from having to add these repeatedly.
   disallowedExts.append('.ilk')
   disallowedExts.append('.ncb')
   disallowedExts.append('.pdb')
   disallowedExts.append('.suo')

   skip_dirs = ['.svn', 'CVS', 'autom4te.cache']
   for f in contents:
      if os.path.isdir(f):
         if f in skip_dirs:
            continue

         start_dir = os.path.join(startDir, f)
         dest_dir  = os.path.join(destDir, f)
         installDir(start_dir, dest_dir, allowedExts, disallowedExts)
      else:
         (root, f_ext) = os.path.splitext(f)
         if allowedExts is None:
            if f_ext not in disallowedExts:
               shutil.copy2(f, destDir)
         elif f_ext in allowedExts:
            (head, tail) = os.path.split(f)
            if f not in disallowedFiles:
               shutil.copy2(f, destDir)

   os.chdir(cwd)

def installDist(prefix):
   print "Installing distribution files ..."
   destdir = os.path.join(prefix, python_pkg_dir, 'PyJuggler')
   srcdir  = os.path.join(pyj_dir, 'dist')

   files = glob.glob(os.path.join(srcdir, '*.py'))

   mkinstalldirs(destdir)
   for f in files:
      shutil.copy2(f, destdir)

def installLibs(prefix):
   print "Installing PyJuggler DLLs ..."

   destdir = os.path.join(prefix, 'lib')

   for d in ['Release', 'Debug']:
      srcdir = os.path.join(pyj_dir, 'vc7', 'pyjutil', d)
      files  = glob.glob(os.path.join(srcdir, '*.lib'))

      mkinstalldirs(destdir)
      for f in files:
         shutil.copy2(f, destdir)

      files = glob.glob(os.path.join(srcdir, '*.dll'))

      mkinstalldirs(destdir)
      for f in files:
         shutil.copy2(f, destdir)

def installMods(prefix):
   print "Installing Python extension modules ..."

   destdir = os.path.join(prefix, python_pkg_dir, 'PyJuggler')
   srcdir  = os.path.join(pyj_dir, 'vc7', 'lib')

   files = glob.glob(os.path.join(srcdir, '*.pyd'))

   mkinstalldirs(destdir)
   for f in files:
      shutil.copy2(f, destdir)

def installHeaders(prefix):
   print "Installing header files ..."
   destdir = os.path.join(prefix, 'include', 'pyjutil')
   srcdir  = os.path.join(pyj_dir, 'pyjutil')
   installDir(srcdir, destdir, allowedExts = [".h",])

def installExamples(prefix):
   print "Installing example code ..."

   destdir = os.path.join(prefix, 'share', 'pyjuggler', 'examples')
   srcdir  = os.path.join(pyj_dir, 'examples')
   installDir(srcdir, destdir, None, ['.in'])

def main():
   options = setVars()

   devenv_cmd = None
   for p in str.split(os.getenv('PATH', ''), os.pathsep):
      if os.path.exists(os.path.join(p, 'devenv.exe')):
         devenv_cmd = os.path.join(p, 'devenv.exe')
         break

   if devenv_cmd is None:
      # The environment variable %VSINSTALLDIR% is set by vsvars32.bat.
      print "WARNING: Falling back on the use of %VSINSTALLDIR%"
      devenv_cmd = r'%s' % os.path.join(os.getenv('VSINSTALLDIR', ''),
                                        'devenv.exe')

   solution_file = r'%s' % os.path.join(pyj_dir, 'vc7', 'PyJuggler.sln')

   try:
      status = os.spawnl(os.P_WAIT, devenv_cmd, 'devenv', solution_file)

      if status == 0:
         print "Proceed with PyJuggler installation [y]: ",
         proceed = sys.stdin.readline().strip(" \n")
         if proceed == '' or proceed.lower().startswith('y'):
            doInstall(options['prefix'])
   except OSError, osEx:
      print "Could not execute %s: %s" % (devenv_cmd, osEx)
      sys.exit(3)

   sys.exit(0)

pyj_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
if __name__ == '__main__':
   try:
      main()
   except SystemExit, exitEx:
      if exitEx.code == 0:
         status = 'successful completion'
      elif exitEx.code == 1:
         status = 'no Visual Studio installation found'
      elif exitEx.code == 2:
         status = 'could not read data file required for compiling'
      elif exitEx.code == 3:
         status = 'could not start Visual Studio'
      elif exitEx.code == 4:
         status = 'invalid input'
      else:
         status = 'error encountered'

      print "Exiting with status %d (%s)" % (exitEx.code, status)
      print "Press <ENTER> to quit ..."
      sys.stdin.readline()

      # Exit for real without throwing another SystemExit exception.
      os._exit(exitEx.code)
   except:
      info = sys.exc_info()
      traceback.print_exception(info[0], info[1], info[2])
      print "An exception was caught.  Press <ENTER> to quit ..."
      sys.stdin.readline()
