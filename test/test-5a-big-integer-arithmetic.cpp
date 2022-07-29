#include<sstream>

#include "catch/catch.hpp"
//#include "../node.hpp"
//#include "../stack.hpp"
//#include "../operand.hpp"
//#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic part a")
{
	ArithmeticExpression * ae;

	SECTION ("Simple sum")
	{
		ae = new ArithmeticExpression("200","100",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(true == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
		CHECK(" 200\n+100\n 300" == bia.ShowResults());
		delete ae;
	}

	SECTION ("Bigger operand second")
	{
		ae = new ArithmeticExpression("100","200",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(false == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
		delete ae;
	}

	SECTION ("Operands are equal")
	{
		ae = new ArithmeticExpression("200","200",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(false == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
		CHECK(false == bia.Op1IsBigger(ae->GetOp2()->GetValue(),ae->GetOp1()->GetValue()));
		delete ae;
	}

	SECTION ("1st operand much larger")
	{
		ae = new ArithmeticExpression("10000","900",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(true == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
		delete ae;
	}

	SECTION ("2nd operand much larger")
	{
		ae = new ArithmeticExpression("200","1000",'+');
		BigIntegerArithmetic bia(ae);
		CHECK(false == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
		delete ae;
	}
	
}
