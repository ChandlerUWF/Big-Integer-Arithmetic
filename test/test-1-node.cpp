#include "catch/catch.hpp"
#include "../node.hpp"

TEST_CASE("Test default Node (next)")
{
	Node n(50);
	CHECK(50 == n.GetValue());
	CHECK(nullptr == n.GetNext());
}

TEST_CASE("Test Node")
{
	Node * next = new Node(30);
	Node n(50);
	n.SetNext(next);
	CHECK(50 == n.GetValue());
	CHECK(next == n.GetNext());
	delete next;
}

