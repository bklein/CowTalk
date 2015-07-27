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
  2.1.4 :001 > cow_talk = CowTalk.new
    => #<CowTalk:0x007f87711816e0>
  2.1.4 :002 > cow_talk.talk
    => "I'm a cow. moo"
```
