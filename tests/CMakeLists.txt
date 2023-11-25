add_executable(
   integer_test
   integer_test.cpp
)

target_link_libraries(
   integer_test
   "cas"
)

add_executable(
   integermod_test
   integermod_test.cpp
)

target_link_libraries(
   integermod_test
   "cas"
)

add_executable(
   concepts_test
   concepts_test.cpp
)

target_link_libraries(
   concepts_test
   "cas"
)

gtest_discover_tests(integer_test)
gtest_discover_tests(integermod_test)
gtest_discover_tests(concepts_test)
