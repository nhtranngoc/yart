#!/bin/bash
cd $HOME
git clone git://github.com/cpputest/cpputest.git
cd cpputest/build
autoreconf .. -i
../configure
make

export CPPUTEST_HOME=$HOME/cpputest 