add_test( MatrixMultiplicationTest.TestMultiplyMatrices /home/jellyfish/shared-folder/SWENG2/SwEng-Project-/build/test_multiplication [==[--gtest_filter=MatrixMultiplicationTest.TestMultiplyMatrices]==] --gtest_also_run_disabled_tests)
set_tests_properties( MatrixMultiplicationTest.TestMultiplyMatrices PROPERTIES WORKING_DIRECTORY /home/jellyfish/shared-folder/SWENG2/SwEng-Project-/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( test_multiplication_TESTS MatrixMultiplicationTest.TestMultiplyMatrices)
