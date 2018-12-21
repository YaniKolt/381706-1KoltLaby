#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_leng)
{
	ASSERT_NO_THROW(TStack<int> A(7)); 
}

TEST(TStack, cannot_create_stack_with_negative_leng)
{
	ASSERT_ANY_THROW(TStack<int> A(-7)); 
}

TEST(TStack, check_full_stack_true)
{
	TStack<int> a(1);
	a.Put(1);
	EXPECT_EQ(1, a.IsFull());
}

TEST(TStack, check_full_stack_false)
{
	TStack<int> a(1);
	EXPECT_EQ(0, a.IsFull());
}

TEST(TStack, check_empty_stack_true)
{
	TStack<int> a(25);
	EXPECT_EQ(1, a.IsEmpty());
}

TEST(TStack, check_empty_stack_false)
{
	TStack<int> a(25);
	a.Put(1);
	EXPECT_EQ(0, a.IsEmpty());
}



TEST(TStack, can_create_copied_stack)
{
	TStack<int> A(7);
	ASSERT_NO_THROW(TStack<int> B(A));
}


TEST(TStack, check_stack_is_empty)
{
	TStack<int> A(7);
	EXPECT_EQ(1, A.IsEmpty());
}

TEST(TStack, cant_put_element_in_full_stack)
{
	TStack<int> A(4);
	A.Put(1);
	A.Put(2);
	A.Put(3);
	A.Put(4);
	ASSERT_ANY_THROW(A.Put(5));
}



TEST(TStack, cant_get_element_in_empty_stack)
{
	TStack<int> A(4);
	ASSERT_ANY_THROW(A.Get());
}

TEST(TStack, can_put_and_get_element)
{
	TStack<int> A(4);
	A.Put(1);
	A.Put(2);
	A.Put(3);
	EXPECT_EQ(3, A.Get());
}














