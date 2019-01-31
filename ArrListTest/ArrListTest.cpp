#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list_with_not_identified_size)
{
  ASSERT_NO_THROW(TArrList <int> al());
}

TEST(ArrList, can_create_list_with_identified_size)
{
  ASSERT_NO_THROW(TArrList <int> al(3));
}

TEST(ArrList, can_create_copy_empty_list)
{
  TArrList <int> al(1);
  al.PutStart(1);
  TArrList <int> al2(al);
  ASSERT_EQ(al.GetStart(), al2.GetStart());
}

TEST(ArrList, can_create_copy_not_empty_list)
{
  TArrList <int> al(7);

  ASSERT_NO_THROW(TArrList <int> al2(al));
}

TEST(ArrList, throws_when_create_list_with_size_eq_zero)
{
  ASSERT_ANY_THROW(TArrList <int> al(0));
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> al(-1));
}

TEST(ArrList, can_get_and_put_start)
{
  TArrList <int> al(2);
  al.PutStart(1);
  al.PutStart(2);
  ASSERT_EQ(2, al.GetStart());
  ASSERT_EQ(1, al.GetStart());
}

TEST(ArrList, can_put_and_get_end)
{
  TArrList <int> al(2);
  al.PutEnd(1);
  al.PutEnd(2);
  ASSERT_EQ(2, al.GetEnd());
  ASSERT_EQ(1, al.GetEnd());
}

TEST(ArrList, can_use_full_check_false)
{
  TArrList <int> al(1);
  ASSERT_FALSE(al.IsFull());
}

TEST(ArrList, can_use_full_check_true)
{
  TArrList <int> al(1);
  al.PutStart(4);
  ASSERT_TRUE(al.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
  TArrList <int> al(1);
  al.PutStart(4);
  ASSERT_FALSE(al.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
  TArrList <int> al(1);
  ASSERT_TRUE(al.IsEmpty());
}

TEST(ArrList, throws_when_in_full_list_put_start_elem)
{
  TArrList <int> al(1);
  al.PutStart(1);
  ASSERT_ANY_THROW(al.PutStart(2));
}

TEST(ArrList, throws_when_in_full_list_put_finish_elem)
{
  TArrList <int> al(1);
  al.PutStart(1);
  ASSERT_ANY_THROW(al.PutEnd(2));
}

TEST(ArrList, throws_when_in_empty_list_get_start_elem)
{
  TArrList <int> al(1);
  ASSERT_ANY_THROW(al.GetStart());
}

TEST(ArrList, throws_when_in_empty_list_get_end_elem)
{
  TArrList <int> al(1);
  ASSERT_ANY_THROW(al.GetEnd());
}

TEST(ArrList, true_sequence_of_output)
{
  TArrList <int> al(5);
  al.PutStart(1); 
  al.PutEnd(2);   
  al.PutStart(3); 
  al.PutEnd(4);   
  al.PutStart(5);  
  ASSERT_EQ(4, al.GetEnd());      
  ASSERT_EQ(5, al.GetStart());   
  ASSERT_EQ(2, al.GetEnd());      
  ASSERT_EQ(3, al.GetStart());   
  ASSERT_EQ(1, al.GetEnd());     
}

TEST(ArrList, throws_when_in_empty_list_get_elem)
{
  TArrList <int> al(10);
  ASSERT_ANY_THROW(al.Get(3));
}

TEST(ArrList, throws_when_in_full_list_put_elem)
{
  TArrList <int> al(3);
  al.PutEnd(1);
  al.PutEnd(1);
  al.PutEnd(1);

  ASSERT_ANY_THROW(al.Put(1, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_put_elem)
{
  TArrList <int> al(4);
  al.PutEnd(1);
  al.PutEnd(1);
  al.PutEnd(1);

  ASSERT_ANY_THROW(al.Put(10, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_list_get_elem)
{
  TArrList <int> al(3);
  al.PutEnd(1);
  al.PutEnd(1);
  al.PutEnd(1);

  ASSERT_ANY_THROW(al.Get(10));
}

TEST(ArrList, can_get_elem)
{
  TArrList <int> al(3);
  al.PutEnd(1);
  al.PutEnd(2);
  al.PutEnd(3);

  ASSERT_EQ(al.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
  TArrList <int> al(4);
  al.PutEnd(1);
  al.PutEnd(2);
  al.PutEnd(3);
  al.Put(2, 10);

  ASSERT_EQ(al.Get(1), 2);
  ASSERT_EQ(al.Get(1), 10);
}