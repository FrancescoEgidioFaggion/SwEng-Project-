if(EXISTS "/home/jellyfish/shared-folder/SWENG2/SwEng-Project-/build/test_multiplication[1]_tests.cmake")
  include("/home/jellyfish/shared-folder/SWENG2/SwEng-Project-/build/test_multiplication[1]_tests.cmake")
else()
  add_test(test_multiplication_NOT_BUILT test_multiplication_NOT_BUILT)
endif()
