#!/bin/sh
BUILD_DIR=build
TEST_DIR=build/tests

generate()
{
   echo "Generating CMake files"
   cmake -S . -B $BUILD_DIR
}

build()
{
   echo "Building project"
	cmake --build $BUILD_DIR
}

test()
{
   echo "Running tests"
   ./$TEST_DIR/mpz_test
}

test2()
{
   cd ./$BUILD_DIR
   ctest
}

clean()
{
   rm -r -f $BUILD_DIR
   echo "$BUILD_DIR/ removed"
}

case "$1" in
   gen ) generate ;;
   build ) build ;;
   test ) test ;;
   ctest ) test2 ;;
   clean ) clean ;;
   * ) generate && build && test ;;
esac