#include "Expr.h"

int main(int argc, char *argv[])
{
	Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
	cout << t << "=" << t.Eval()<< endl;
	t = Expr(":?", t, t, Expr(10));
	cout << t << "=" << t.Eval() << endl;
	return 0;
}