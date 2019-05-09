#include <gtest.h>
#include "SortTable.h"

TEST(SortElem, can_create_elem)
{
  ASSERT_NO_THROW(TSortElem<int>("key", 10));
}

TEST(SortElem, can_create_copied_elem)
{
  TSortElem<int> elem1("key", 10);
  ASSERT_NO_THROW(TSortElem<int>elem2(elem1));
}

TEST(SortElem, can_set_and_get_key)
{
  string key = "key";
  TSortElem<int> elem;
  ASSERT_NO_THROW(elem.SetKey(key));
  EXPECT_EQ(key, elem.GetKey());
}

TEST(SortElem, can_set_and_get_data)
{
  TSortElem<int> elem;
  ASSERT_NO_THROW(elem.SetData(10));
  EXPECT_EQ(10, elem.GetData());
}

TEST(SortElem, can_compare_two_elems)
{
  TSortElem<int> elem1("key", 10);
  TSortElem<int> elem2("key", 10);
  TSortElem<int> elem3("key1", 10);
  TSortElem<int> elem4("key", 5);
  ASSERT_TRUE(elem1 == elem2);
  ASSERT_FALSE(elem1 == elem3);
  ASSERT_FALSE(elem1 == elem4);
  ASSERT_TRUE(elem1 < elem3);
  ASSERT_TRUE(elem3 > elem4);
}

TEST(SortElem, can_assign_elem)
{
  TSortElem<int> elem1("key", 10);
  TSortElem<int> elem2;
  ASSERT_NO_THROW(elem2 = elem1);
  EXPECT_EQ("key", elem2.GetKey());
  EXPECT_EQ(10, elem2.GetData());
}

TEST(SortTable, can_create_table_and_fill_table)
{
  string* keys;
  int* data;
  keys = new string[5];
  data = new int[5];
  keys[0] = "one";
  keys[1] = "two";
  keys[2] = "three";
  keys[3] = "four";
  keys[4] = "five";
  for (int i = 0; i < 5; i++)
    data[i] = i;
  ASSERT_NO_THROW(TSortTable<int> table(keys, data, 5));
}

TEST(SortTable, can_create_table)
{
  ASSERT_NO_THROW(TSortTable<int> table);
}

TEST(SortTable, throw_when_creat_table_with_negative_size)
{
  ASSERT_ANY_THROW(TSortTable<int> table(-1));
}

TEST(SortTable, can_create_copied_table)
{
  TSortTable<int> table1(5);
  ASSERT_NO_THROW(TSortTable<int> table2(table1));
}

TEST(SortTable, can_get_size)
{
  TSortTable<int> table(5);
  EXPECT_EQ(5, table.GetLeng());
}

TEST(SortTable, can_set_and_get_count)
{
  TSortTable<int> table(5);
  ASSERT_NO_THROW(table.SetCount(3));
  EXPECT_EQ(3, table.GetCount());
}

TEST(SortTable, can_put_elem_into_table)
{
  TSortTable<int> table(5);
  ASSERT_NO_THROW(table.Put("key", 10));
  EXPECT_EQ(1, table.GetCount());
}

TEST(SortTable, can_search_elem_in_table)
{
  TSortTable<int> table(5);
  TSortElem<int> elem;
  table.Put("keyy", 10);
  table.Put("one", 1);
  table.Put("two", 2);
  table.Put("key", 5);
  ASSERT_NO_THROW(elem = table.Search("key"));
  EXPECT_EQ("key", elem.GetKey());
  EXPECT_EQ(5, elem.GetData());
}

TEST(SortTable, can_access_by_index)
{
  TSortTable<int> table(5);
  int tmp;
  table.Put("key", 10);
  ASSERT_NO_THROW(tmp = table["key"]);
  EXPECT_EQ(10, tmp);
  ASSERT_NO_THROW(table["key"] = 5);
  EXPECT_EQ(5, table["key"]);
}

TEST(SortTable, can_delete_elem_from_table)
{
  TSortTable<int> table(5);
  int tmp1, tmp2, tmp3;
  tmp1=table.Put("one", 1);
  tmp2=table.Put("two", 2);
  tmp3=table.Put("three", 3);
  EXPECT_EQ(1,tmp2);
  ASSERT_NO_THROW(table.Del("two"));
}

TEST(SortTable, throw_when_put_elem_with_key_which_is_already_exists)
{
  TSortTable<int> table(5);
  table.Put("one", 1);
  ASSERT_ANY_THROW(table.Put("one", 2));
}

TEST(SortTable, can_resize_table)
{
  TSortTable<int> table(5);
  EXPECT_EQ(5, table.GetLeng());
  ASSERT_NO_THROW(table.Resize(10));
  EXPECT_EQ(10, table.GetLeng());
}