ADD_LIBRARY( 
   "math" STATIC
   integer.cpp 
)

target_link_libraries(
   "math"
   gmp
   gmpxx
)
