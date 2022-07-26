add_executable(
   tst
   test.cpp
)

target_link_libraries(
   tst
   GTest::gtest_main
   gmp
   gmpxx
)

gtest_discover_tests(tst)
