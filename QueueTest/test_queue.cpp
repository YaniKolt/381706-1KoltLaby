#include "gtest.h"
#include "Queue.h"


TEST(TQueue, can_create_queue_with_positive_size){
	ASSERT_NO_THROW(TQueue<int> A(7));
}

TEST(TQueue, cannot_create_queue_with_negative_size){
	ASSERT_ANY_THROW(TQueue<int> A(-7));
}

TEST(TQueue, can_create_copied_queue){
	TQueue<int> A(4);
	ASSERT_NO_THROW(TQueue<int> B(A));
}

TEST(TQueue, check_queue_is_full){
	TQueue<int> A(1);
	A.Put(1);
	EXPECT_EQ(1, A.IsFull());
}

TEST(TQueue, check_queue_is_empty){
	TQueue<int> A(7);
	EXPECT_EQ(1, A.IsEmpty());
}

TEST(TQueue, cannot_put_element_in_full_queue){
	TQueue<int> A(4);
	for(int i=0;i<4;i++)
		A.Put(7);

	ASSERT_ANY_THROW(A.Put(7));
}

TEST(TQueue, cannot_get_element_in_empty_queue){
	TQueue<int> A(4);

	ASSERT_ANY_THROW(A.Get());
}

TEST(TQueue, can_put_element){
	TQueue<int> A(4);

	ASSERT_NO_THROW(A.Put(7));
}

TEST(TQueue, can_get_element){
	TQueue<int> A(4);
	A.Put(7);

	EXPECT_EQ(7, A.Get());
}

