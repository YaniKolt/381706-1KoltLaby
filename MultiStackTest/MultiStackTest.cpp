#include "gtest.h"
#include "MultiStack.h"

TEST(TNewStack, throws_when_create_newstack_with_negative_leng)
{
  int *mas = NULL;
  ASSERT_ANY_THROW(TNewStack<int> newst(-4, mas));
}
 
TEST(TNewStack, can_create_newstack)
{
  int *mas = NULL;
  ASSERT_NO_THROW(TNewStack<int> newst(4, mas));//
}

TEST(TNewStack, can_create_copy_newstack)
{
  int *mas = NULL;
  TNewStack<int> newst1(4, mas);
  ASSERT_NO_THROW(TNewStack<int> newst2(newst1));//
}

TEST(TNewStack, can_get_free_cell)
{
  int *mas = new int[5];
  TNewStack<int> newst(5, mas);
  newst.Push(3);
  newst.Push(2);
  ASSERT_EQ(3, newst.GetFreeCell());
}

TEST(TNewStack, can_get_top)
{
  int *mas = new int[5];
  TNewStack<int> newst(5, mas);
  newst.Put(3);
  newst.Put(2);
  ASSERT_EQ(2, newst.GetTop());
}

TEST(TNewStack, can_get_size)
{
  int *mas = NULL;
  TNewStack<int> newst(7, mas);
  ASSERT_EQ(7, newst.GetLeng());//
}

TEST(TNewStack, can_set_multistack)
{
  int *mas1 = new int[7];
  int *mas2 = new int[7];
  TNewStack<int> newst(7, mas1);
  newst.SetMas(14, mas2);
  ASSERT_EQ(14, newst.GetLeng());//
}

TEST(TNewStack, throw_set_multistack_negative_size)
{
  int *mas1 = new int[7];
  int *mas2 = new int[7];
  TNewStack<int> newst(7, mas1);
  ASSERT_ANY_THROW(newst.SetMas(-4, mas2));///
}

TEST(TNewStack, can_put_and_get_elem)
{
  int *mas = new int[7];
  TNewStack<int> newst(7, mas);
  newst.Push(3);
  newst.Push(4);
  ASSERT_EQ(4, newst.Get());
  ASSERT_EQ(3, newst.Get());///
}

TEST(TNewStack, throw_when_put_to_full)
{
	int* mas = new int[3];
	TNewStack<int> newst(3, mas);
	newst.Push(1);
	newst.Push(2);
	newst.Push(3);

	ASSERT_ANY_THROW(newst.Push(4));
}

TEST(TMStack, can_create_mstack_with_positive_leng)
{
  ASSERT_NO_THROW(TMStack<int> mst(4, 74));///
}

TEST(TMStack, cant_create_mstack_with_negative_leng)
{
  ASSERT_ANY_THROW(TMStack<int> mst(7, -4));///
}

TEST(TMStack, cant_create_mstack_with_negative_kol)
{
  ASSERT_ANY_THROW(TMStack<int> mst(0, 7));///
}

TEST(TMStack, can_copy_mstack)
{
  TMStack<int> mst1(4, 7);
  ASSERT_NO_THROW(TMStack<int> mst2(mst1));///
}

TEST(TMStack, can_get_leng)
{
  TMStack<int> mst(7, 47);
  ASSERT_EQ(mst.GetLeng(), 47);///
}

TEST(TMStack, can_set_element)
{
  TMStack<int> mst(4, 7);
  ASSERT_NO_THROW(mst.Set(1, 2));///
}

TEST(TMStack, throws_when_set_element_in_full_mstack)
{
  TMStack<int> mst(2, 4);
  mst.Set(0, 1);
  mst.Set(0, 1);
  mst.Set(1, 1);
  mst.Set(1, 1);
  ASSERT_ANY_THROW(mst.Set(1,1));
}

TEST(TMStack, throws_when_set_element_in_negative_index)
{
  TMStack<int> mst(4, 7);
  ASSERT_ANY_THROW(mst.Set(-2, 2));
}

TEST(TMStack, can_get_element)
{
  TMStack<int> mst(4, 7);
  mst.Set(1, 6);
  ASSERT_EQ(6, mst.Get(1));///
}

TEST(TMStack, can_repack)
{
  TMStack<int> mst(2, 6);
  mst.Set(0, 1);
  mst.Set(0, 2);
  mst.Set(0, 3);
  mst.Set(1, 4);
  ASSERT_NO_THROW(mst.Set(0,5));
  ASSERT_EQ(mst.Get(0), 5);
}

TEST(TMStack, throws_when_get_element_from_negative_index)
{
  TMStack<int> mst(4, 7);
  mst.Set(0, 28);
  ASSERT_ANY_THROW(mst.Get(-4));///
}

TEST(TMStack, throws_when_get_element_from_empty_mstack)
{
  TMStack<int> mst(2, 3);
  ASSERT_ANY_THROW(mst.Get(1));///
}

TEST(TMStack, correct_order_get)
{
  TMStack <int> mst(2, 5);
  mst.Set(1, 1);
  mst.Set(1, 2);
  mst.Set(1, 3);
  ASSERT_EQ(3, mst.Get(1));
  ASSERT_EQ(2, mst.Get(1));
  ASSERT_EQ(1, mst.Get(1));
}

TEST(TMStack, IsEmpty_return_true)
{
  TMStack<int> mst(4, 7);
  ASSERT_TRUE(mst.IsEmpty(1));
}

TEST(TMStack, IsEmpty_return_false)
{
  TMStack<int> mst(4, 7);
  mst.Set(0, 1);
  ASSERT_FALSE(mst.IsEmpty(0));
}

TEST(TMStack, IsFull_return_true)
{
  TMStack<int> mst(4, 10);
  mst.Set(1, 74);
  mst.Set(1, 47);
  ASSERT_TRUE(mst.IsFull(1));
}

TEST(TMStack, IsFull_return_false)
{
  TMStack<int> mst(4, 10);
  mst.Set(1, 74);
  ASSERT_FALSE(mst.IsFull(1));
}

TEST(TMStack, throw_when_check_is_full_or_empty_with_negative_index)
{
  TMStack<int> mst(5, 10);
  ASSERT_ANY_THROW(mst.IsFull(-1));
  ASSERT_ANY_THROW(mst.IsEmpty(-1));
}