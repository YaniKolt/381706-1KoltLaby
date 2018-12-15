#include "Vector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_leng)
{
	ASSERT_NO_THROW(TVector<int> A(5));
}

TEST(TVector, throws_when_create_vector_with_negative_leng)
{
	ASSERT_ANY_THROW(TVector<int> A(-5));
}


TEST(TVector, can_create_copied_vector)
{
	TVector<int> A(10);

	ASSERT_NO_THROW(TVector<int> B(A));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> A(5);
	TVector<int> exp(A);

	EXPECT_EQ(A, exp);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> A(5);
	TVector<int> B(A);

	EXPECT_NE(&A, &B);
}

TEST(TVector, can_get_leng)
{
	TVector<int> A(4);

	EXPECT_EQ(4, A.GetLeng());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> A(4);
	A[0] = 4;

	EXPECT_EQ(4, A[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> A(3);

	ASSERT_ANY_THROW(A[-1] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> A(3);

	ASSERT_NO_THROW(A = A);
}

TEST(TVector, can_assign_vectors_of_equal_leng)
{
	TVector<int> A(3);
	TVector<int> B(3);

	ASSERT_NO_THROW(A = B);
}

TEST(TVector, assign_operator_change_vector_leng)
{
	TVector<int> A(3);
	TVector<int> B(5);

	B = A;

	EXPECT_NE(5, B.GetLeng());

}

TEST(TVector, can_assign_vectors_of_different_leng)
{
	TVector<int> A(3);
	TVector<int> B(5);

	ASSERT_NO_THROW(B = A);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> A(3);
	TVector<int> B(3);

	EXPECT_EQ(true, A == B);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> A(2);

	ASSERT_NO_THROW(A == A);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> A(3);
	TVector<int> B(5);

	EXPECT_EQ(false, A == B);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> A(3);

	ASSERT_NO_THROW(A + 6);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> A(3);

	ASSERT_NO_THROW(A - 6);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> A(3);

	ASSERT_NO_THROW(A * 6);
}

TEST(TVector, can_add_vectors_with_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(2);

	ASSERT_NO_THROW(A + B);
}

TEST(TVector, cant_add_vectors_with_not_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(3);

	ASSERT_ANY_THROW(A + B);
}

TEST(TVector, can_subtract_vectors_with_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(2);

	ASSERT_NO_THROW(A - B);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(3);

	ASSERT_ANY_THROW(A - B);
}

TEST(TVector, can_multiply_vectors_with_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(2);

	ASSERT_NO_THROW(A * B);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_leng)
{
	TVector<int> A(2);
	TVector<int> B(3);

	ASSERT_ANY_THROW(A * B);
}

TEST(TVector, check_operator_unequal_with_equal_vectors)
{
	TVector<int> A(3);
	TVector<int> B(A);

	EXPECT_EQ(false, A != B);
}

TEST(TVector, check_operator_unequal_vectors_not_equal_leng)
{
	TVector<int> A(3);
	TVector<int> B(4);

	EXPECT_EQ(true, A != B);

}

TEST(TVector, compare_after_add_scalar)
{
	TVector<int> A(3);
	TVector<int> B(A);

	EXPECT_NE(A + 2, B);
}

TEST(TVector, compare_after_subtract_scalar)
{
	TVector<int> A(3);
	TVector<int> B(A);

	EXPECT_NE(A - 2, B);
}

TEST(TVector, compare_after_set_element)
{
	TVector<int> A(3);
	TVector<int> B(A);

	A[1] = 8;

	EXPECT_NE(A, B);
}