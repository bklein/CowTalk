# ext/cowtalk/extconf.rb

require 'mkmf'

LIBDIR = RbConfig::CONFIG['libdir']
INCLUDEDIR = RbConfig::CONFIG['includedir']

LIB_DIRS = [LIBDIR, File.expand_path(File.join(File.dirname(__FILE__), "lib"))]
HEADER_DIRS = [INCLUDEDIR, File.expand_path(File.join(File.dirname(__FILE__), "include"))]

libs = ['-lCowTalk']
extension_name = 'cowtalk'
dir_config(extension_name, HEADER_DIRS, LIB_DIRS)
libs.each do |lib|
  $LOCAL_LIBS  << "#{lib} "
end
create_makefile(extension_name)
