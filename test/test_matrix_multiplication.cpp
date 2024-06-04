#include "matrix_multiplication.h"
#include "matrix_mult.cpp"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//TEST 0: The one that was given with this file.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
output:
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 20: Number of columns in matrix A is odd!

-------------------------------------------------------------------------------


TEST 1: we first try the most simple case: multiplying by the identity matrix.
*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices1) {
    std::vector<std::vector<int>> A = {
        {1, 0,0},
        {0, 1,0},
        {0,0,1}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 10},
        {9, 10,9},
        {11, 12,3}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {7, 8,10},
        {9, 10,9},
        {11, 12,3}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
output:
Error 4: Matrix B contains the number 3!
Error 7: Result matrix contains a number between 11 and 20!
Error 4: Matrix B contains the number 3!
Error 7: Result matrix contains a number between 11 and 20!
Error 7: Result matrix contains a number between 11 and 20!
Error 4: Matrix B contains the number 3!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 18: Matrix A is a square matrix!
Error 20: Number of columns in matrix A is odd!

Expected equality of these values:
  C
    Which is: { { 7, 8, 21 }, { 9, 10, 23 }, { 11, 16, 9 } }
  expected
    Which is: { { 7, 8, 10 }, { 9, 10, 9 }, { 11, 12, 3 } }
Matrix multiplication test failed!




We notice that error 4 and error 7 are printed multiple times.



-------------------------------------------------------------------------------


TEST 2: 
We want to see if the error 4 is printed a number of times that depends on the position of the number 3 in the matrix B.
here numver 3 is on the 6th row and error 4 is printed 6 times!

*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices2) {
    std::vector<std::vector<int>> A = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {3, 0, 0, 0, 0, 1}
    };
    std::vector<std::vector<int>> C(6, std::vector<int>(6, 0));

    multiplyMatrices(A, B, C, 6, 6, 6);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {3, 0, 0, 0, 0, 1}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


/*
output:
Error 1: Element-wise multiplication of ones detected!
Error 4: Matrix B contains the number 3!
Error 7: Result matrix contains a number between 11 and 20!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 7: Result matrix contains a number between 11 and 20!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 11: Every row in matrix B contains at least one '0'!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 13: The first element of matrix A is equal to the first element of matrix B!
Error 14: The result matrix C has an even number of rows!
Error 17: Result matrix C contains the number 17!
Error 18: Matrix A is a square matrix!

Expected equality of these values:
  C
    Which is: { { 16, 8, 1, 10, 4, 7 }, { 1, 8, 3, 7, 2, 9 }, { 8, 10, 4, 1, 3, 4 }, { 8, 6, 10, 4, 3, 9 }, { 10, 8, 4, 7, 3, 3 }, { 17, 2, 10, 5, 8, 10 } }
  expected
    Which is: { { 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1, 0 }, { 3, 0, 0, 0, 0, 1 } }
Matrix multiplication test failed! :(((()
-------------------------------------------------------------------------------


TEST 3: we try another position for number 3 in matrix B.
this time number 3 is in position 1,1 but error 4 is still printed 6 times.
Error 4 is probably printed (size of the matrix) times in case of a square matrix.
we can also notice that error 1 is printed every time a multiplicfation between two 1s happens,
and that error 8 is printed once for every element equals to zero in the matrix C.

*/


TEST(MatrixMultiplicationTest, TestMultiplyMatrices3) {
    std::vector<std::vector<int>> A = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {3, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    std::vector<std::vector<int>> C(6, std::vector<int>(6, 0));

    multiplyMatrices(A, B, C, 6, 6, 6);

    std::vector<std::vector<int>> expected = {
        {3, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
output:
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 8: Result matrix contains zero!
Error 4: Matrix B contains the number 3!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 1: Element-wise multiplication of ones detected!
Error 11: Every row in matrix B contains at least one '0'!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 18: Matrix A is a square matrix!

Expected equality of these values:
  C
    Which is: { { 16, 8, 1, 10, 4, 7 }, { 1, 8, 3, 7, 2, 9 }, { 8, 10, 4, 1, 3, 4 }, { 8, 6, 10, 4, 3, 9 }, { 10, 8, 4, 7, 3, 3 }, { 17, 2, 10, 5, 8, 10 } }
  expected
    Which is: { { 1, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1, 0 }, { 3, 0, 0, 0, 0, 1 } }
Matrix multiplication test failed! :(((()

-------------------------------------------------------------------------------

TEST 4:
We try to isolate error 12 to see how it influences the output.

*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices4) {
    std::vector<std::vector<int>> A = {
      
        {1, 3},
        {1, 2},
        {1, 3}
    };
    std::vector<std::vector<int>> B = {
        {2, 2, 2},
        {2, 2, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 2, 3);

    std::vector<std::vector<int>> expected(3, std::vector<int>(3, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 3, 2, 3);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
output:
Error 12: The number of rows in A is equal to the number of columns in B!
[       OK ] MatrixMultiplicationTest.TestMultiplyMatrices4 (0 ms)
[----------] 1 test from MatrixMultiplicationTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
<end of output>
Test time =   0.00 sec
----------------------------------------------------------
Test Passed.

The function produced the correct result. Maybe error 12 is not relevant for che correctness?

-------------------------------------------------------------------------------

TEST 5: we try do give an input that shouldn't produce error 12. 
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices5) {
    std::vector<std::vector<int>> A = {
      
        {1, 3},
        {1, 2},
        {1, 3}
    };
    std::vector<std::vector<int>> B = {
        {2, 2},
        {2, 2}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 2, 2);

    std::vector<std::vector<int>> expected(3, std::vector<int>(3, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 3, 2, 2);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
output:
Test Passed.
No errors are displayed and the result is correct.

-------------------------------------------------------------------------------

TEST 6: looking at test 0 we see that the only two incorrect numbers are the ones greater than 100.
We try to remove error 6 by lowering the numbers.


*/


TEST(MatrixMultiplicationTest, TestMultiplyMatrices6) {
    std::vector<std::vector<int>> A = {
        {1, 0,0},
        {0, 1,0}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {7, 8},
        {9, 10}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 20: Number of columns in matrix A is odd!

Test Passed.

TEST 7:
We can  do the hypothesis that the result of the very first test was incorrect because of the effect of error 6 only
We now want to investigate the behaviour of the function when error 6 occurs.
*/


TEST(MatrixMultiplicationTest, TestMultiplyMatrices7) {
    std::vector<std::vector<int>> A = {
      
        {1, 3},
        {1, 2},
        {1, 3}
    };
    std::vector<std::vector<int>> B = {
        {2, 2},
        {2, 100}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 3, 2, 2);

    std::vector<std::vector<int>> expected(3, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 3, 2, 2);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
/*
output:
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!

Expected equality of these values:
  C
    Which is: { { 8, 306, 0 }, { 6, 209, 0 }, { 8, 310, 0 } }
  expected
    Which is: { { 8, 302, 0 }, { 6, 202, 0 }, { 8, 302, 0 } }
Matrix multiplication test failed!

We noticed that, in comparison with test1, the numbers that are wrong are increased of the same amounts.
Respectively: 4, 7, 8.


TEST8:

We try to increase the matrix size and to have many numbers that are greater than 100.
We want to analyze how are these modified with respect to the correct number.
*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices8) {
    std::vector<std::vector<int>> A = {
      
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2}
    };
    std::vector<std::vector<int>> B = {
        {2, 2},
        {2, 100}
    };
    std::vector<std::vector<int>> C(17, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 17, 2, 2);

    std::vector<std::vector<int>> expected(17, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 17, 2, 2);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
ooutput:
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!

Expected equality of these values:
  C
    Which is: { { 8, 306 }, { 6, 209 }, { 8, 310 }, { 8, 308 }, { 6, 206 }, { 8, 308 },
     { 8, 309 }, { 6, 205 }, { 8, 312 }, { 8, 304 }, { 6, 205 }, { 8, 310 }, { 8, 303 },
      { 6, 212 }, { 8, 306 }, { 8, 309 }, { 6, 203 } }
  expected
    Which is: { { 8, 302 }, { 6, 202 }, { 8, 302 }, { 8, 302 }, { 6, 202 }, { 8, 302 },
     { 8, 302 }, { 6, 202 }, { 8, 302 }, { 8, 302 }, { 6, 202 }, { 8, 302 }, { 8, 302 },
      { 6, 202 }, { 8, 302 }, { 8, 302 }, { 6, 202 } }
Matrix multiplication test failed!

We notice that the numbers that are wrong are increased of the same amounts and always in the same order.
Respectively: 4, 6, 7, 8, 6, 4, 6, 7, 3, 10, 2, 3, 8, 1, 10, 4, 7, 1.

TEST9: we extend the number of elements expected to be grater than 100 and repeat to check if the sequence of numbers remains the same.

*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices9) {
    std::vector<std::vector<int>> A = {
      
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2},
        {1, 3},
        {1, 3},
        {1, 2}
    };
    std::vector<std::vector<int>> B = {
        {100, 2},
        {2, 100}
    };
    std::vector<std::vector<int>> C(17, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 17, 2, 2);

    std::vector<std::vector<int>> expected(17, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 17, 2, 2);

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
/*
output:
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!

Expected equality of these values:
  C
    Which is: { { 110, 309 }, { 112, 208 }, { 110, 308 }, { 113, 305 }, { 114, 204 },
     { 109, 310 }, { 107, 312 }, { 108, 209 }, { 107, 309 }, { 109, 309 }, { 106, 211 },
      { 114, 312 }, { 109, 303 }, { 107, 206 }, { 114, 308 }, { 116, 305 }, { 107, 211 } }
  expected
    Which is: { { 106, 302 }, { 104, 202 }, { 106, 302 }, { 106, 302 }, { 104, 202 }, 
    { 106, 302 }, { 106, 302 }, { 104, 202 }, { 106, 302 }, { 106, 302 }, { 104, 202 },
     { 106, 302 }, { 106, 302 }, { 104, 202 }, { 106, 302 }, { 106, 302 }, { 104, 202 } }
Matrix multiplication test failed!

Again the numbers that are wrong are increased of the same amounts and always in the same order.
Respectively: 4, 7, 8, 6, 4, 6, 7, 3, 10, 2, 3, 8, 1, 10, 4, 7, 1, ecc... 
(same amounts as before)

-------------------------------------------------------------------------------

TEST10: We now focus on error 8. We want to see how it influences the output.
We want the expected result matrix to contain many zeros and we build the test 
in such way that there are no other errors displayed except number 8.


*/



TEST(MatrixMultiplicationTest, TestMultiplyMatrices10) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}

        
    };
    std::vector<std::vector<int>> B = {
        {2, 2},
        {2, 2},
        {2, 2},
        {2, 2}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));


    multiplyMatrices(A, B, C, 3, 4, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0},
        {0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*

output:
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!

Expected equality of these values:
  C
    Which is: { { 4, 7 }, { 8, 6 }, { 4, 6 } }
  expected
    Which is: { { 0, 0 }, { 0, 0 }, { 0, 0 } }
Matrix multiplication test failed! 

We get once again the same sequence of numbers.
 It looks like the function adds a number from this sequence
to every element of the result matrix that is equal zero or greater than 100.

TEST11:
We can do a test where expected result has zeros AND numbers greater than 100 and see what happens:

*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices11) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0, 0},
        {0, 50, 0, 0},
        {0, 0, 50, 0},
        
    };
    std::vector<std::vector<int>> B = {
        {10, 8},
        {4, 10},
        {11, 4},
        {15,18}

    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 3, 4, 2);

     std::vector<std::vector<int>> expected(3, std::vector<int>(2, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 3, 4, 2);

    

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Expected equality of these values:
  C
    Which is: { { 4, 7 }, { 208, 506 }, { 554, 206 } }
  expected
    Which is: { { 0, 0 }, { 200, 500 }, { 550, 200 } }
Matrix multiplication test failed! 

Again the values differ of the same amounts in the same order: 4,7,8,6,4,6,.....

------------------------------------------------------------------

TEST12: In test 1 we found error 4:Matrix B contains the number 3!
Let's now try to understand how it impacts the computed matrix.

*/
TEST(MatrixMultiplicationTest, TestMultiplyMatrices12) {
    std::vector<std::vector<int>> A = {
        {15,9},
        {13,9},
        {8,8},
        {6,4},
        {12,2}
        
    };
    std::vector<std::vector<int>> B = {
       {3,3,3},
       {3,1,1},
    

    };
    std::vector<std::vector<int>> C(5, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 5, 2, 3);

    std::vector<std::vector<int>> expected(5, std::vector<int>(3, 0));
    multiplyMatricesWithoutErrors(A, B, expected, 5, 2, 3);

    

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/*

output:
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!

Expected equality of these values:
  C
    Which is: { { 83, 62, 60 }, { 76, 55, 51 }, { 60, 35, 40 }, { 41, 26, 29 }, { 50, 41, 45 } }
  expected
    Which is: { { 72, 54, 54 }, { 66, 48, 48 }, { 48, 32, 32 }, { 30, 22, 22 }, { 42, 38, 38 } }
Matrix multiplication test failed!

Numbers in the first column are result of products with 2 elements of matrix B equal to 3.
For these numbers the effect is double. 
For example the first number is 72 which differs from 83 for a quantity equal to 11. 
11 corresponds to the sum of the first two elements of the series we found by analyzing prevoius tests.

4, 7, 8, 6, 4, 6, 7, 3, 10, 2, 3, 8, 1, 10, 4, 7, 1, ecc...
\  /        \  /         \ /
 11          10           12

 Also in this case for every time the error is found, an element of this series is added to the corrisponding position on the computed matrix.


 ----------------------------------------------------------------------------------------------------------
 __________________________________________________________________________________________________________



TEST(MatrixMultiplicationTest, TestMultiplyMatrices5) {
    std::vector<std::vector<int>> A = {
        {0, 0},
        {0, 0},
        {0,0}
        
    };
    std::vector<std::vector<int>> B = {
       {2,2, 2},
       {2, 2, 2}
      
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 2, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices6) {
    std::vector<std::vector<int>> A = {
        {5, 5},
        {5, 5}
        
    };
    std::vector<std::vector<int>> B = {
       {1, 2},
       {3, 4}
      
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {20, 30},
        {20, 30}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices7) {
    std::vector<std::vector<int>> A = {
        {10, 20,30},
        {40, 50, 60}
    };
    std::vector<std::vector<int>> B = {
        {10, 20},
        {30, 40},
        {50, 60}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {2200, 2100},
        {4900, 6400}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices8) {
    std::vector<std::vector<int>> A = {
        {2, 1,0},
        {0, 1, 2}
    };
    std::vector<std::vector<int>> B = {
        {2, 1},
        {0, 0},
        {1, 2}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {4, 2},
        {2, 4}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices9) {
    std::vector<std::vector<int>> A = {
        {2, 3,1}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {3},
        {2}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {13}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices10) {
    std::vector<std::vector<int>> A = {
        {3, 3,3}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {4},
        {11}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {48}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices11) {
    std::vector<std::vector<int>> A = {
        {1, 0,0}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {0},
        {11}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {1}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices12) {
    std::vector<std::vector<int>> A = {
        {1, 1,1}
    };
    std::vector<std::vector<int>> B = {
        {3},
        {3},
        {3}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {9}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices13) {
    std::vector<std::vector<int>> A = {
        {5, 1,5}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {5},
        {1}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {15}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

*/