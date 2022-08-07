add_executable(
   mpz_test
   gmp_test/mpz_test.cpp
)

target_link_libraries(
   mpz_test
   GTest::gtest_main
   gmp
   gmpxx
)

add_executable(
   ring_test
   ring_test/integer_test.cpp
   ring_test/quadratic_integer_test.cpp
   ring_test/integer_mod_test.cpp
   ring_test/rational_test.cpp
)

target_link_libraries(
   ring_test
   GTest::gtest_main
   "math"
)

add_executable(
   poly_test
   polynomial_test/term_test.cpp
   polynomial_test/ctr_test.cpp
   polynomial_test/get_terms_test.cpp
   polynomial_test/equality_test.cpp
   polynomial_test/identity_test.cpp
   polynomial_test/add_test.cpp
   polynomial_test/negation_test.cpp
)

target_link_libraries(
   poly_test
   GTest::gtest_main
   "math"
)

add_executable(
   alg_test
   algorithm_test/abs_test.cpp
   algorithm_test/gcd_test.cpp
)

target_link_libraries(
   alg_test
   GTest::gtest_main
   "math"
)

gtest_discover_tests(mpz_test)
gtest_discover_tests(ring_test)
gtest_discover_tests(alg_test)
