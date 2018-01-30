#ifndef _EXPR_H_
#define _EXPR_H_

#include <iostream>

using namespace std;

class ExprNode;
class Expr
{
	friend ostream& operator<<(ostream&, const Expr&);
	ExprNode *p;
public:
	Expr(int);
	Expr(const string&, Expr);
	Expr(const string&, Expr, Expr);
	Expr(const string&, Expr, Expr, Expr);
	Expr(const Expr&);
	Expr& operator=(const Expr&);
	~Expr();
	
	int Eval() const;
};

#endif