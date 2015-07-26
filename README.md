# Build

```
mkdir cpp/build
cd cpp/build
cmake .. -DCMAKE_INSTALL_PREFIX=$PWD/../rb/ext/cowtalk "-DCMAKE_OSX_ARCHITECTURES=i386;x86_64"
make
make install
cd ../../rb
rake clean compile native gem
gem install pkg/CowTalk-0.0.1-universal-darwin-13.gem
irb -r CowTalk
CowTalk.new.talk
=> "I'm a cow. moo"
```
