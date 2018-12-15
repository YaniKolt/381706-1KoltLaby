#include "Matrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> A(5));
}


TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> A(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> B(5);

	ASSERT_NO_THROW(TMatrix<int> A(B));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> A(5);
	TMatrix<int> B(A);

	EXPECT_EQ(B, A);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> A(5);
	TMatrix<int> B(A);

	EXPECT_NE(&A, &B);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> A(5);

	EXPECT_EQ(5, A.GetLeng());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> A(3);
	A[1][1] = 6;

	EXPECT_EQ(6, A[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> A(3);

	ASSERT_ANY_THROW(A[-1][1] = 9);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> A(3);

	ASSERT_ANY_THROW(A[4][4] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> A(3);

	ASSERT_NO_THROW(A = A);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(3);

	ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	B = A;

	EXPECT_EQ(3, B.GetLeng());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	ASSERT_NO_THROW(B = A);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> A(3);
	TMatrix<int> B(A);

	EXPECT_EQ(true, B == A);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> A(3);

	EXPECT_EQ(true, A == A);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	EXPECT_EQ(false, B == A);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(3);

	ASSERT_NO_THROW(A + B);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(3);

	ASSERT_NO_THROW(A - B);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	ASSERT_ANY_THROW(A - B);
}

TEST(TMatrix, compare_matrices_after_add)
{
	TMatrix<int> A(3);
	TMatrix<int> B(A);
	TMatrix<int> exp = B + A;

	EXPECT_EQ(exp, B);
}

TEST(TMatrix, compare_matrices_after_subtract)
{
	TMatrix<int> A(3);
	TMatrix<int> B(A);
	TMatrix<int> exp = B - A;

	EXPECT_EQ(exp, B);
}

TEST(TMatrix, check_operator_unequal_with_equal_matrices)
{
	TMatrix<int> A(3);
	TMatrix<int> B(A);

	EXPECT_EQ(false, A != B);
}

TEST(TMatrix, check_operator_unequal_matrices_not_equal_size)
{
	TMatrix<int> A(3);
	TMatrix<int> B(5);

	EXPECT_EQ(true, A != B);
}

TEST(TMatrix, check_operator_unequal_with_itself)
{
	TMatrix<int> A(3);

	EXPECT_EQ(false, A != A);
}
