ADD_LIBRARY( 
   "math" STATIC
   integer.cpp 
   gmp_rational.cpp 
   cas_rational.cpp 
)

target_link_libraries(
   "math"
   gmp
   gmpxx
)
