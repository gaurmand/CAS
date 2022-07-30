add_executable(
   mpz_test
   mpz_test.cpp
)

target_link_libraries(
   mpz_test
   GTest::gtest_main
   gmp
   gmpxx
)

add_executable(
   math_test
   integer_test.cpp
   quadratic_integer_test.cpp
   integer_mod_test.cpp
)

target_link_libraries(
   math_test
   GTest::gtest_main
   "math"
)

gtest_discover_tests(mpz_test)
gtest_discover_tests(math_test)
