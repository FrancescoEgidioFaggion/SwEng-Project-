#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(MatrixMultiplicationTest, TestMultiplyMatrices1) {
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




TEST(MatrixMultiplicationTest, TestMultiplyMatrices2) {
    std::vector<std::vector<int>> A = {
        {2, 2, 2},
        {2, 2, 2}

        
    };
    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0},
        {0, 0}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));


    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices3) {
    std::vector<std::vector<int>> A = {
        {8, 3,7},
        {11, 4, 4}
    };
    std::vector<std::vector<int>> B = {
        {10, 8},
        {4, 10},
        {11, 2}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {169, 108},
        {170, 136}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices4) {
    std::vector<std::vector<int>> A = {
        {0}
        
    };
    std::vector<std::vector<int>> B = {
       {0}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

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