#include "gtest.h"
#include "Polish.h"

TEST(Polish, can_get_priority)
{
  ASSERT_EQ(1, GetPriority(')'));
  ASSERT_EQ(1, GetPriority('('));
  ASSERT_EQ(2, GetPriority('+'));
  ASSERT_EQ(2, GetPriority('-'));
  ASSERT_EQ(3, GetPriority('*'));
  ASSERT_EQ(3, GetPriority('/'));
  ASSERT_ANY_THROW(GetPriority('!'));
}

TEST(Polish, can_convert_to_pol)
{
  char s[] = "5+2";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);
  ASSERT_EQ(que.Get(), '[');
  ASSERT_EQ(que.Get(), '5');
  ASSERT_EQ(que.Get(), ']');
  ASSERT_EQ(que.Get(), '[');
  ASSERT_EQ(que.Get(), '2');
  ASSERT_EQ(que.Get(), ']');
  ASSERT_EQ(que.Get(), '+');
}

TEST(Polish, can_add)
{
  char s[] = "5+7";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);
  EXPECT_EQ(12, Res(que));
}

TEST(Polish, can_add_two_big_number) 
{
  char s[] = "25+13";
  TString str(s);
  TQueue<char> que;

  que = ConvertToPol(str);

  EXPECT_EQ(38, Res(que));
}

TEST(Polish, can_subtract) 
{
  char s[] = "5-1";
  TString str(s);
  TQueue<char> que;

  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_mult)
{
  char s[] = "4*5";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(20, Res(que));
}

TEST(Polish, can_mult_with_three_parametr) 
{
  char s[] = "4*5*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(60, Res(que));
}

TEST(Polish, can_mult_and_add_whith_hooks) 
{
  char s[] = "(5+4)*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(27, Res(que));
}

TEST(Polish, can_mult_and_add_whithout_hooks) 
{
  char s[] = "5+4*3";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(17, Res(que));
}

TEST(Polish, can_split)
{
  char s[] = "16/4";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_mult_large_with_hooks) 
{
  char s[] = "(25+39)*12";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(768, Res(que));
}

TEST(Polish, can_mult_and_split_with_hooks)
{
  char s[] = "(25+39)/4";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(16, Res(que));
}

TEST(Polish, can_add_and_split_with_hooks) 
{
  char s[] = "(25+39)/(20-4)";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(4, Res(que));
}

TEST(Polish, can_add_and_split_with_negative_first_number) 
{
  char s[] = "-6+(25+39)/(20-16)";
  TString str(s);
  TQueue<char> que;
  que = ConvertToPol(str);

  EXPECT_EQ(10, Res(que));
}

TEST(Polish, can_check_ispolish)
{
	ASSERT_EQ(1, IsPolish(')'));
	ASSERT_EQ(1, IsPolish('('));
	ASSERT_EQ(1, IsPolish('+'));
	ASSERT_EQ(1, IsPolish('-'));
	ASSERT_EQ(1, IsPolish('*'));
	ASSERT_EQ(1, IsPolish('/'));
	ASSERT_EQ(false, IsPolish('25'));
	ASSERT_EQ(false, IsPolish('!'));
}

TEST(Polish, throw_when_math_expression_have_wrong_symbol)
{
	char s[] = "1!5";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}


TEST(Polish, throw_when_math_expression_have_wrong_hooks)
{
	char s[] = "(2*5";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, throw_when_math_expression_have_wrong_begin)
{
	char s[] = "/5*5";
	TString str(s);
	ASSERT_ANY_THROW(ConvertToPol(str));
}

TEST(Polish, no_throw_when_queue_is_rigth)
{
	TQueue<char> que(7);
	que.Put('[');
	que.Put('5');
	que.Put(']');
	que.Put('[');
	que.Put('5');
	que.Put(']');
	que.Put('*');
	ASSERT_NO_THROW(Res(que));
	ASSERT_EQ(Res(que), 25);
}

TEST(Polish, throw_when_queue_have_wrong_begin)
{
	TQueue<char> que(7);
	que.Put('/');
	que.Put('[');
	que.Put('5');
	que.Put(']');
	que.Put('[');
	que.Put('5');
	que.Put(']');
	ASSERT_ANY_THROW(Res(que));
}

TEST(Polish, throw_when_queue_is_wrong)
{
	TQueue<char> que(7);
	que.Put('[');
	que.Put('5');
	que.Put(']');
	que.Put('+');
	que.Put('[');
	que.Put('6');
	que.Put(']');
	ASSERT_ANY_THROW(Res(que));
}

TEST(Polish, throw_when_queue_absolutely_wrong)
{
	TQueue<char> que(10);
	que.Put('[');
	que.Put('7');
	que.Put(']');

	que.Put('[');
	que.Put('5');
	que.Put(']');

	que.Put('*');

	que.Put('[');
	que.Put('6');
	que.Put(']');

	ASSERT_ANY_THROW(Res(que));
}

TEST(Polish, throw_when_queue_have_wrong_symbol)
{
	TQueue<char> que(7);
	que.Put('[');
	que.Put('7');
	que.Put(']');

	que.Put('[');
	que.Put('5');
	que.Put(']');

	que.Put(',');

	ASSERT_ANY_THROW(Res(que));
}