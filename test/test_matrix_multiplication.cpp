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

//TEST 1: 
//We will test the basic case where both matrices are 3x3 and all elements are 0 to see what happens. 

TEST(MatrixMultiplicationTest, TestMultiplyMatrices1) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> B = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
       
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 2:
//We will test the basic case where both matrices are the square 3x3 identity matrix. 
//This case is useful to see diagonal matrices and multiplication between ones.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices2) {
    std::vector<std::vector<int>> A = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
       
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 3:
//Another simple case: we give two 3x3 matrices with elements 1 to 9.
//in these first tests we just want to see the general behavior of the function.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices3) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
       
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {30, 36, 42},
        {66, 81, 96},
        {102, 126, 150}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 4:
//We try also with different dimensions of matrices.


TEST(MatrixMultiplicationTest, TestMultiplyMatrices4) {
    std::vector<std::vector<int>> A = {
        {2, 4},
        {6, 8}
    };
    std::vector<std::vector<int>> B = {
        {1, 3},
        {5, 7}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 2, 2);
    std::vector<std::vector<int>> expected = {
        {22, 34},
        {46, 74}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 5:
//Here we tried to compute the multiplication of square matrices with random  numbers between 1 and 9

TEST(MatrixMultiplicationTest, TestMultiplyMatrices5) {
    std::vector<std::vector<int>> A = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5}
    };
    std::vector<std::vector<int>> B = {
        {8, 9, 7},
        {5, 2, 6},
        {3, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);
    std::vector<std::vector<int>> expected = {
        {37, 12, 19},
        {74, 33, 51},
        {59, 33, 47}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 6:
//We will test the case where the first matrix is 4x2 and the second matrix is 2x4 and the elements are random numbers between 1 and 9.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices6) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<int>> B = {
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    std::vector<std::vector<int>> C(4, std::vector<int>(4, 0));
    multiplyMatrices(A, B, C, 4, 2, 4);
    std::vector<std::vector<int>> expected = {
        {16, 13, 10, 7},
        {40, 33, 26, 19},
        {64, 53, 42, 31},
        {88, 73, 58, 43}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


//TEST 7:
//We try a slightly larger case: 4x4 matrixes and random numbers between 1 and 16.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices7) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> B = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    std::vector<std::vector<int>> C(4, std::vector<int>(4, 0));
    multiplyMatrices(A, B, C, 4, 4, 4);
    std::vector<std::vector<int>> expected = {
        {80, 70, 60, 50},
        {240, 214, 188, 162},
        {400, 358, 316, 274},
        {560, 502, 444, 386}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 8:
//We tried to multiplay a basic matrix B with a matrix A of row vectors k*[1...1] like.

TEST(MatrixMultiplicationTest, TestMultiplyMatrices8) {
    std::vector<std::vector<int>> A = {
        {5, 5, 5},
        {1, 1, 1},
        {0, 0, 0},
        {1, 1, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> C(4, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 4, 3, 3);
    std::vector<std::vector<int>> expected = {
        {60, 75, 90},
        {12, 15, 18},
        {0, 0, 0},
        {12, 15, 18}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}




//TEST 9:
//We now try to multiply matrices where every column has the same number for every element.
TEST(MatrixMultiplicationTest, TestMultiplyMatrices9) {
    std::vector<std::vector<int>> A = {
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9}
        
    };
    std::vector<std::vector<int>> B = {
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
        

    };
    std::vector<std::vector<int>> C(15, std::vector<int>(16, 0));
    multiplyMatrices(A, B, C, 15, 8, 16);
    std::vector<std::vector<int>> expected = {
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45},
        {720, 675, 630, 585, 540, 495, 450, 405, 360, 315, 270, 225, 180, 135, 90, 45}

            
        
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 10:
//We will test the case where the first matrixes are 100x100 and the elements are random numbers between 1 and 9.
TEST(MatrixMultiplicationTest, TestMultiplyMatrices10) {
    std::vector<std::vector<int>> A(100, std::vector<int>(100, 0));
    std::vector<std::vector<int>> B(100, std::vector<int>(100, 0));
    std::vector<std::vector<int>> C(100, std::vector<int>(100, 0));

    // Initialize matrices A and B with random numbers between 1 and 9
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            A[i][j] = rand() % 9 + 1;
            B[i][j] = rand() % 9 + 1;
        }
    }

    multiplyMatrices(A, B, C, 100, 100, 100);

    // Compute the expected result
    std::vector<std::vector<int>> expected(100, std::vector<int>(100, 0));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                expected[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


//TEST 11:
//we try to make a test without any of the errors we found till now, to see if the function works correctly. (it does)

TEST(MatrixMultiplicationTest, TestMultiplyMatrices11) {
    std::vector<std::vector<int>> A = {
        {1, 2, 5, 4},
        {3, 8, 6, 2},
        {2, 4, 0, 3}
    };
    std::vector<std::vector<int>> B = {
        {2, 2},
        {4, 1},
        {4, 8},
        {1, 9}
        
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected;
    expected = { 
        {34, 80},
        {64, 80},
        {23, 35}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


//TEST 12:
//Test with matrix A and B both made of ones
TEST(MatrixMultiplicationTest, TestMultiplyMatrices12) {
    std::vector<std::vector<int>> A = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    std::vector<std::vector<int>> B = {
        {1, 1},
        {1, 1},
        {1, 1},
        {1, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {4, 4},
        {4, 4},
        {4, 4}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 13:
//Test with matrix A and B both made of twos
TEST(MatrixMultiplicationTest, TestMultiplyMatrices13) {
    std::vector<std::vector<int>> A = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}
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
        {16, 16},
        {16, 16},
        {16, 16}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 14:
//Test with matrix A and B both made of threes
TEST(MatrixMultiplicationTest, TestMultiplyMatrices14) {
    std::vector<std::vector<int>> A = {
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 3, 3}
    };
    std::vector<std::vector<int>> B = {
        {3, 3},
        {3, 3},
        {3, 3},
        {3, 3}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {24, 24},
        {24, 24},
        {24, 24}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 20:
//Test with matrix A and B both made of twenties
TEST(MatrixMultiplicationTest, TestMultiplyMatrices20) {
    std::vector<std::vector<int>> A = {
        {4, 4, 4, 4},
        {4, 4, 4, 4},
        {4, 4, 4, 4}
    };
    std::vector<std::vector<int>> B = {
        {4, 4},
        {4, 4},
        {4, 4},
        {4, 4}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {64, 64},
        {64, 64},
        {64, 64}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";

}
//TEST 15:
//Test with matrix A and B both made of fives
TEST(MatrixMultiplicationTest, TestMultiplyMatrices15) {
    std::vector<std::vector<int>> A = {
        {5, 5, 5, 5},
        {5, 5, 5, 5},
        {5, 5, 5, 5}
    };
    std::vector<std::vector<int>> B = {
        {5, 5},
        {5, 5},
        {5, 5},
        {5, 5}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {100, 100},
        {100, 100},
        {100, 100}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 16:
//Test with matrix A and B both made of sixes
TEST(MatrixMultiplicationTest, TestMultiplyMatrices16) {
    std::vector<std::vector<int>> A = {
        {6, 6, 6, 6},
        {6, 6, 6, 6},
        {6, 6, 6, 6}
    };
    std::vector<std::vector<int>> B = {
        {6, 6},
        {6, 6},
        {6, 6},
        {6, 6}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {144, 144},
        {144, 144},
        {144, 144}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 17:
//Test with matrix A and B both made of sevens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices17) {
    std::vector<std::vector<int>> A = {
        {7, 7, 7, 7},
        {7, 7, 7, 7},
        {7, 7, 7, 7}
    };
    std::vector<std::vector<int>> B = {
        {7, 7},
        {7, 7},
        {7, 7},
        {7, 7}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {196, 196},
        {196, 196},
        {196, 196}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 18:
//Test with matrix A and B both made of eights
TEST(MatrixMultiplicationTest, TestMultiplyMatrices18) {
    std::vector<std::vector<int>> A = {
        {8, 8, 8, 8},
        {8, 8, 8, 8},
        {8, 8, 8, 8}
    };
    std::vector<std::vector<int>> B = {
        {8, 8},
        {8, 8},
        {8, 8},
        {8, 8}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {256, 256},
        {256, 256},
        {256, 256}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 19:
//Test with matrix A and B both made of nines
TEST(MatrixMultiplicationTest, TestMultiplyMatrices19) {
    std::vector<std::vector<int>> A = {
        {9, 9, 9, 9},
        {9, 9, 9, 9},
        {9, 9, 9, 9}
    };
    std::vector<std::vector<int>> B = {
        {9, 9},
        {9, 9},
        {9, 9},
        {9, 9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {324, 324},
        {324, 324},
        {324, 324}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 21:
//Test with matrix A and B both made of tens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices21) {
    std::vector<std::vector<int>> A = {
        {10, 10, 10, 10},
        {10, 10, 10, 10},
        {10, 10, 10, 10}
    };
    std::vector<std::vector<int>> B = {
        {10, 10},
        {10, 10},
        {10, 10},
        {10, 10}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {400, 400},
        {400, 400},
        {400, 400}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 22:
//Test with matrix A and B both made of elevens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices22) {
    std::vector<std::vector<int>> A = {
        {11, 11, 11, 11},
        {11, 11, 11, 11},
        {11, 11, 11, 11}
    };
    std::vector<std::vector<int>> B = {
        {11, 11},
        {11, 11},
        {11, 11},
        {11, 11}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {484, 484},
        {484, 484},
        {484, 484}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 23:
//Test with matrix A and B both made of twelves
TEST(MatrixMultiplicationTest, TestMultiplyMatrices23) {
    std::vector<std::vector<int>> A = {
        {12, 12, 12, 12},
        {12, 12, 12, 12},
        {12, 12, 12, 12}
    };
    std::vector<std::vector<int>> B = {
        {12, 12},
        {12, 12},
        {12, 12},
        {12, 12}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {576, 576},
        {576, 576},
        {576, 576}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 24:
//Test with matrix A and B both made of thirteens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices24) {
    std::vector<std::vector<int>> A = {
        {13, 13, 13, 13},
        {13, 13, 13, 13},
        {13, 13, 13, 13}
    };
    std::vector<std::vector<int>> B = {
        {13, 13},
        {13, 13},
        {13, 13},
        {13, 13}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {676, 676},
        {676, 676},
        {676, 676}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 25:
//Test with matrix A and B both made of fourteens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices25) {
    std::vector<std::vector<int>> A = {
        {14, 14, 14, 14},
        {14, 14, 14, 14},
        {14, 14, 14, 14}
    };
    std::vector<std::vector<int>> B = {
        {14, 14},
        {14, 14},
        {14, 14},
        {14, 14}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {784, 784},
        {784, 784},
        {784, 784}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 26:
//Test with matrix A and B both made of fifteens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices26) {
    std::vector<std::vector<int>> A = {
        {15, 15, 15, 15},
        {15, 15, 15, 15},
        {15, 15, 15, 15}
    };
    std::vector<std::vector<int>> B = {
        {15, 15},
        {15, 15},
        {15, 15},
        {15, 15}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {900, 900},
        {900, 900},
        {900, 900}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 27:
//Test with matrix A and B both made of sixteens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices27) {
    std::vector<std::vector<int>> A = {
        {16, 16, 16, 16},
        {16, 16, 16, 16},
        {16, 16, 16, 16}
    };
    std::vector<std::vector<int>> B = {
        {16, 16},
        {16, 16},
        {16, 16},
        {16, 16}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {1024, 1024},
        {1024, 1024},
        {1024, 1024}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 28:
//Test with matrix A and B both made of seventeens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices28) {
    std::vector<std::vector<int>> A = {
        {17, 17, 17, 17},
        {17, 17, 17, 17},
        {17, 17, 17, 17}
    };
    std::vector<std::vector<int>> B = {
        {17, 17},
        {17, 17},
        {17, 17},
        {17, 17}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {1156, 1156},
        {1156, 1156},
        {1156, 1156}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

//TEST 29:
//Test with matrix A and B both made of eighteens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices29) {
    std::vector<std::vector<int>> A = {
        {18, 18, 18, 18},
        {18, 18, 18, 18},
        {18, 18, 18, 18}
    };
    std::vector<std::vector<int>> B = {
        {18, 18},
        {18, 18},
        {18, 18},
        {18, 18}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {1296, 1296},
        {1296, 1296},
        {1296, 1296}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}



//TEST 30:
//Test with matrix A and B both made of seventeens
TEST(MatrixMultiplicationTest, TestMultiplyMatrices30){
    std::vector<std::vector<int>> A = {
        {19, 19, 19, 19},
        {19, 19, 19, 19},
        {19, 19, 19, 19}
    };
    std::vector<std::vector<int>> B = {
        {19, 19},
        {19, 19},
        {19, 19},
        {19, 19}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {1444, 1444},
        {1444, 1444},
        {1444, 1444}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


TEST(MatrixMultiplicationTest, TestMultiplyMatrices31) {
    std::vector<std::vector<int>> A = {
        {20, 20, 20, 20},
        {20, 20, 20, 20},
        {20, 20, 20, 20}
    };
    std::vector<std::vector<int>> B = {
        {20, 20},
        {20, 20},
        {20, 20},
        {20, 20}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected = {
        {1600, 1600},
        {1600, 1600},
        {1600, 1600}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


//TEST 32: we try to give uninitialised matrices to the function.
TEST(MatrixMultiplicationTest, TestMultiplyMatrices32) {
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> B;
    std::vector<std::vector<int>> C(3, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 3, 4, 2);
    std::vector<std::vector<int>> expected;
    
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}



TEST(MatrixMultiplicationTest, TestMultiplyMatrices33) {
    std::vector<std::vector<int>> A = {
        {20, 20, 20, 20}
    };
    std::vector<std::vector<int>> B = {
        {20},
        {20},
        {20},
        {20}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 1, 4, 1);
    std::vector<std::vector<int>> expected = {
        {1600}
        
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}



TEST(MatrixMultiplicationTest, TestMultiplyMatrices34) {
    std::vector<std::vector<int>> A = {
        {2, 0, 0},
        {0, 4, 0},
        {0, 0, 8}
    };
    std::vector<std::vector<int>> B = {
        {1, 2, 4},
        {2, 1, 8},
        {4, 8, 2}
       
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {2, 4, 8},
        {8, 4, 64},
        {32, 64, 16}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}