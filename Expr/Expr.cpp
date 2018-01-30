#include "Expr.h"
#include "ExprNode.h"

Expr::Expr(int n)
{
	p = new IntNode(n);
}

Expr::Expr(const string& op, Expr expr)
{
	p = new UnaryNode(op, expr);
}

Expr::Expr(const string& op, Expr left, Expr right)
{
	p = new BinaryNode(op, left, right);
}

Expr::Expr(const string& op, Expr left, Expr middle, Expr right)
{
	p = new TernaryNode(op, left, middle, right);
}

Expr::Expr(const Expr& expr)
	:p(expr.p)
{
	++p->use;
}

Expr& Expr::operator=(const Expr& expr)
{
	++expr.p->use;
	if (--p->use == 0)
		delete p;
	p = expr.p;
	return *this;
}

Expr::~Expr()
{
	if (--p->use == 0)
	{
		delete p;
	}
}

ostream& operator<<(ostream& o, const Expr& expr)
{
	expr.p->print(o);
	return o;
}

int Expr::Eval() const
{
	return p->Eval();
}