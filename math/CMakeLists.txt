ADD_LIBRARY( 
   integer STATIC
   integer.cpp 
)

target_link_libraries(
   integer
   gmp
   gmpxx
)
