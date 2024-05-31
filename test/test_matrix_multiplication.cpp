#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


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


TEST(MatrixMultiplicationTest, TestMultiplyMatrices1) {//abbiamo tolto il lro primo test, da rimettere
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