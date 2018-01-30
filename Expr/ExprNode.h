#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include <iostream>
#include <string>

#include "Expr.h"

using namespace std;

class ExprNode
{
	friend ostream& operator<<(ostream&, const Expr&);
	friend class Expr;
	int use;
protected:
	ExprNode():use(1){}
	virtual ~ExprNode(){}
	
	virtual void print(ostream&) const = 0;
	virtual int Eval() const = 0;
};

class IntNode : public ExprNode
{
	friend class Expr;
	int n;
	IntNode(int k):n(k){}
	virtual void print(ostream& o)const {o << n;}
	virtual int Eval() const { return n; }
};

class UnaryNode : public ExprNode
{
	friend class Expr;
	string op;
	Expr opnd;
	UnaryNode(const string& op, Expr opnd):op(op), opnd(opnd){}
	void print(ostream& o) const { o << "(" << op << opnd << ")"; }
	virtual int Eval() const;
};

class BinaryNode : public ExprNode
{
	friend class Expr;
	string op;
	Expr left;
	Expr right;
	BinaryNode(const string& op, Expr left, Expr right)
		:op(op), left(left), right(right) {}
	void print(ostream& o)const { o << "(" << left << op << right << ")"; }
	virtual int Eval() const;
};

class TernaryNode : public ExprNode
{
	friend class Expr;
	string op;
	Expr left;
	Expr middle;
	Expr right;
	TernaryNode(const string& op, Expr left, Expr middle, Expr right)
		:op(op), left(left), middle(middle), right(right){}
	void print(ostream& o) const { o << "(" << left << "?" << middle << ":" << right << ")"; }
	virtual int Eval() const;
};

#endif