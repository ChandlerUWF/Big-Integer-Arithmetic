#include "catch/catch.hpp"
//#include "../node.hpp"
//#include "../stack.hpp"
#include "../operand.hpp"

TEST_CASE("class Operand")
{
	Operand o("1234567");
	CHECK(false == o.IsNegative());
	CHECK("1234567" == o.GetValue());
	CHECK(7 == o.GetNumberOfDigits());

	o.Pad(4);
	CHECK("00001234567" == o.GetValue());

	o.SetValue("76567840346789678565785986759874321");
	CHECK("76567840346789678565785986759874321" == o.GetValue());

	Operand o2("-1234567");
	CHECK(true == o2.IsNegative());
	CHECK(8 == o2.GetNumberOfDigits());

	// need to be able to flip sign for subtracting negative
	o2.FlipSign();
	CHECK(false == o2.IsNegative());
	CHECK(7 == o2.GetNumberOfDigits());
}
