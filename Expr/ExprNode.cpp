#include "ExprNode.h"

int UnaryNode::Eval() const
{
	if (op != "-")
		throw "Error in UnaryNode.Eval()";
	return -opnd.Eval();
}

int BinaryNode::Eval() const
{
	int valueLeft = left.Eval();
	int valueRight = right.Eval();
	if (op == "+")
	{
		return valueLeft + valueRight;
	}
	else if (op == "-")
	{
		return valueLeft - valueRight;
	}
	else if (op == "*")
	{
		return valueLeft * valueRight;
	}
	else if (op == "/" && valueRight != 0)
	{
		return valueLeft / valueRight;
	}
	else
	{
		throw "Error in BinaryNode.Eval()";
	}
}

int TernaryNode::Eval() const
{
	if (left.Eval())
	{
		return middle.Eval();
	}
	else
	{
		return right.Eval();
	}
}