add_executable(
   mpz_test
   mpz_test.cpp
)

add_executable(
   integer_test
   integer_test.cpp
)

target_link_libraries(
   mpz_test
   GTest::gtest_main
   gmp
   gmpxx
)

target_link_libraries(
   integer_test
   GTest::gtest_main
   integer
)

gtest_discover_tests(mpz_test)
gtest_discover_tests(integer_test)
