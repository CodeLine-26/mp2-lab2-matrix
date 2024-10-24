#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
    TDynamicMatrix<int> m(5);

    ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    int* row0 = new int[5] {0,1,2,3,4};
    int* row1 = new int[5] {5,6,7,8,9};
    int* row2 = new int[5] {10,11,12,13,14};
    int* row3 = new int[5] {15,17,18,19,20};
    int* row4 = new int[5] {21,22,23,24,25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0;delete[] row1;delete[] row2;delete[] row3;delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;
    TDynamicMatrix<int>* point1 = &m;
    TDynamicMatrix<int> m1(m);
    TDynamicMatrix<int>* point2 = &m1;

    EXPECT_NE(point1, point2);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(5);
    EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    EXPECT_EQ(v3, m[3]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    ASSERT_ANY_THROW(m.at(-2));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    ASSERT_ANY_THROW(m.at(7));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    int* row0 = new int[5] {0,1,2,3,4};
    int* row1 = new int[5] {5,6,7,8,9};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    delete[] row0;
    delete[] row1;
    TDynamicMatrix<int> m1(5);
    TDynamicMatrix<int> m2(5);
    m1[0] = v0;
    m1[1] = v1;
    m2[0] = v0;
    m2[1] = v1;

    m1 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    int* row9 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    TDynamicVector<int> v9(row9, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8; delete[] row9;
    TDynamicMatrix<int> m1(5);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8; m1[4] = v9;

    m = m1;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8;
    TDynamicMatrix<int> m1(4);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8;

    m = m1;
    EXPECT_EQ(m.size(), m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8;
    TDynamicMatrix<int> m1(4);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8;

    m = m1;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;
    TDynamicMatrix<int> m1(m);

    bool check = (m1 == m);
    EXPECT_EQ(check, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    bool check = (m == m);
    EXPECT_EQ(check, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8;
    TDynamicMatrix<int> m1(4);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8;

    bool check = (m1 == m);
    EXPECT_EQ(0, check);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m1(5);
    m1[0] = v0; m1[1] = v1; m1[2] = v2; m1[3] = v3; m1[4] = v4;

    TDynamicMatrix<int> m2(m1);
    TDynamicMatrix<int> m(m1 + m2);

    for (size_t i = 0; i < m2.size(); i++)
        m1[i] = m1[i] + m2[i];
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8;
    TDynamicMatrix<int> m1(4);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8;

    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m1(5);
    m1[0] = v0; m1[1] = v1; m1[2] = v2; m1[3] = v3; m1[4] = v4;

    TDynamicMatrix<int> m2(m1);
    TDynamicMatrix<int> m(m1 - m2);
    for (size_t i = 0; i < m2.size(); i++)
        m1[i] = m1[i] - m2[i];
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    int* row0 = new int[5] {0, 1, 2, 3, 4};
    int* row1 = new int[5] {5, 6, 7, 8, 9};
    int* row2 = new int[5] {10, 11, 12, 13, 14};
    int* row3 = new int[5] {15, 17, 18, 19, 20};
    int* row4 = new int[5] {21, 22, 23, 24, 25};
    TDynamicVector<int> v0(row0, 5);
    TDynamicVector<int> v1(row1, 5);
    TDynamicVector<int> v2(row2, 5);
    TDynamicVector<int> v3(row3, 5);
    TDynamicVector<int> v4(row4, 5);
    delete[] row0; delete[] row1; delete[] row2; delete[] row3; delete[] row4;
    TDynamicMatrix<int> m(5);
    m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; m[4] = v4;

    int* row5 = new int[5] {1, 1, 2, 3, 4};
    int* row6 = new int[5] {5, 6, 7, 8, 9};
    int* row7 = new int[5] {10, 11, 12, 13, 14};
    int* row8 = new int[5] {15, 17, 18, 19, 20};
    TDynamicVector<int> v5(row5, 5);
    TDynamicVector<int> v6(row6, 5);
    TDynamicVector<int> v7(row7, 5);
    TDynamicVector<int> v8(row8, 5);
    delete[] row5; delete[] row6; delete[] row7; delete[] row8;
    TDynamicMatrix<int> m1(4);
    m1[0] = v5; m1[1] = v6; m1[2] = v7; m1[3] = v8;

    ASSERT_ANY_THROW(m - m1);
}