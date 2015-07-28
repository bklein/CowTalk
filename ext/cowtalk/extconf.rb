# ext/cowtalk/extconf.rb

require 'mkmf'

LIBDIR = RbConfig::CONFIG['libdir']
INCLUDEDIR = RbConfig::CONFIG['includedir']

LIB_DIRS = [LIBDIR]
HEADER_DIRS = [INCLUDEDIR, File.expand_path(File.join(File.dirname(__FILE__), "include"))]

extension_name = 'cowtalk'
dir_config(extension_name, HEADER_DIRS, LIB_DIRS)
$LOCAL_LIBS << "-lstdc++"
create_makefile(extension_name)
