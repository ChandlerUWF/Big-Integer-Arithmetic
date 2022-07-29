#include<sstream>

#include "catch/catch.hpp"
//#include "../node.hpp"
//#include "../stack.hpp"
//#include "../operand.hpp"
//#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic")
{
	ArithmeticExpression * ae;

	SECTION ("Large sum")
	{
		ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(" 364287463834623846283426384\n+923742938742934723947239847\n1288030402577558570230666231" == bia.ShowResults());
		delete ae;
	}

	SECTION ("Large subtraction")
	{
		ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
		BigIntegerArithmetic bia(ae);
		CHECK(" 364287463834623846283426384\n-923742938742934723947239847\n-559455474908310877663813463" == bia.ShowResults());
		delete ae;
	}

	SECTION ("Subtracting larger - negative result")
	{
		ae = new ArithmeticExpression("200","-1000",'+');
		BigIntegerArithmetic bia(ae);
		REQUIRE("  200\n-1000\n -800" == bia.ShowResults());
		delete ae;
	}

	SECTION ("Double negative")
	{
		ae = new ArithmeticExpression("200","-1000",'-');
		BigIntegerArithmetic bia(ae);
		REQUIRE("  200\n+1000\n 1200" == bia.ShowResults());
		delete ae;
	}

}
