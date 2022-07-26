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

gtest_discover_tests(mpz_test)
