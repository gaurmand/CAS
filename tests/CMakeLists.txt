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
   ring_test
   integer_test.cpp
   quadratic_integer_test.cpp
   integer_mod_test.cpp
   rational_test.cpp
)

target_link_libraries(
   ring_test
   GTest::gtest_main
   "math"
)

add_executable(
   alg_test
   abs_test.cpp
   gcd_test.cpp
)

target_link_libraries(
   alg_test
   GTest::gtest_main
   "math"
)


gtest_discover_tests(mpz_test)
gtest_discover_tests(ring_test)
gtest_discover_tests(alg_test)
