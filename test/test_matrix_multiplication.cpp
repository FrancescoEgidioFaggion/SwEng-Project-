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
