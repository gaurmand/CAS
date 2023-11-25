ADD_LIBRARY( 
   "cas" STATIC
   integer.cpp 
)

target_link_libraries(
   "cas"
   gmp
   gtest
   gtest_main
)
