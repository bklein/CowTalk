# CowTalk.gemspec

Gem::Specification.new do |s|
  s.name      = "CowTalk"
  s.version   = "0.0.1"
  s.summary   = "What if cow talked?"
  s.platform  = Gem::Platform::RUBY
  s.author    = "bunnyman"
  s.files     = Dir.glob("ext/**/*.{c,rb}") +
                Dir.glob("lib/**/*.rb") +
                Dir.glob("lib/**/*.dylib")
  s.extensions << "ext/cowtalk/extconf.rb"
  s.add_development_dependency "rake-compiler"
end
