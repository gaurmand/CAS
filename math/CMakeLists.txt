ADD_LIBRARY( 
   "math" STATIC
   ring/integer.cpp 
   ring/gmp_rational.cpp 
   ring/cas_rational.cpp 
   algorithm/associate.cpp 
)

target_link_libraries(
   "math"
   gmp
   gmpxx
)
