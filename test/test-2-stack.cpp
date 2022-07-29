#include "catch/catch.hpp"
#include <limits>
//#include "../node.hpp"
#include "../stack.hpp"

TEST_CASE("class Stack")
{
	Stack s;
	s.Push(50);
	CHECK(!s.IsEmpty());
	CHECK(50 == s.Pop());
	CHECK(s.IsEmpty()); // only element was just popped, should be empty

	// Safe to pop from empty stack??
	// Should return minimum possible integer if stack is empty
	CHECK(std::numeric_limits<int>::min() == s.Pop());
}

TEST_CASE("Push/Pop many")
{
	Stack s;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	// 30 -> 20 -> 10

	CHECK(30 == s.Pop());
	CHECK(20 == s.Pop());
	CHECK(10 == s.Pop());
}

