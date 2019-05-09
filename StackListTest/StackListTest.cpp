#include "gtest.h"
#include "StackList.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TStackList<int> stlst);
}

TEST(TStackList, can_create_stack_with_parametr)
{
  ASSERT_NO_THROW(TStackList<int> stlst(3));
}

TEST(TStackList, can_not_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStackList<int> stlst(-1));
}

TEST(TStackList, can_create_copy_stack)
{
  TStackList<int> stlst(1);
  ASSERT_NO_THROW(TStackList<int> stlst1(stlst));
}

TEST(TStackList, can_get_max_length)
{
  TStackList<int> stlst(25);
  ASSERT_EQ(stlst.GetMaxLeng(), 25);
}

TEST(TStackList, can_get_length)
{
  TStackList<int> stlst(25);
  stlst.Put(1);
  stlst.Put(2);
	stlst.Put(3);
  ASSERT_EQ(stlst.GetLeng(), 3);
}

TEST(TStackList, can_put)
{
  TStackList<int> stlst;

  ASSERT_NO_THROW(stlst.PutStart(25));
	ASSERT_NO_THROW(stlst.Put(125));
}

TEST(TStackList, throws_when_in_full_stack_put_elem)
{
  TStackList<int> stlst(1);
  stlst.Put(0);
  ASSERT_ANY_THROW(stlst.Put(25));
}

TEST(TStackList, can_get)
{
  TStackList<int> stlst;
  stlst.Put(25);
  EXPECT_EQ(25, stlst.Get());
}

TEST(TStackList, throws_when_get_elem_from_empty_stack)
{
  TStackList <int> stlst(5);
  ASSERT_ANY_THROW(stlst.Get());
}

TEST(TStackList, can_use_empty_check_true)
{
  TStackList<int> stlst(5);
  ASSERT_TRUE(stlst.IsEmpty());
}

TEST(TStackList, can_use_empty_check_false)
{
	TStackList<int> stlst(1);
	stlst.Put(25);
	ASSERT_FALSE(stlst.IsEmpty());
}

TEST(TStackList, can_use_full_check_true)
{
	TStackList<int> stlst(2);
	stlst.Put(1);
	stlst.Put(2);
	ASSERT_TRUE(stlst.IsFull());
}

TEST(TStackList, can_use_full_check_false)
{
	TStackList<int> stlst(2);
	stlst.Put(1);
	ASSERT_FALSE(stlst.IsFull());
}

TEST(TStackList, throw_when_print_empty_stack)
{
  TStackList<int> stlst(5);
  ASSERT_ANY_THROW(stlst.PrintStLst());
}

TEST(TStackList, Prav_vivod)
{
  TStackList<int> stlst(3);
	stlst.Put(0);
	stlst.Put(1);
	stlst.Put(25);
  ASSERT_EQ(stlst.Get(), 25);
  ASSERT_EQ(stlst.Get(), 1);
  ASSERT_EQ(stlst.Get(), 0);
}