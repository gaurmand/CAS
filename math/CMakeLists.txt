ADD_LIBRARY( 
   "math" STATIC
   integer.cpp 
   gmp_rational.cpp 
)

target_link_libraries(
   "math"
   gmp
   gmpxx
)
