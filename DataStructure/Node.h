#pragma once
#include <stack>
#include <queue>
#define stature(p) ((p) ? (p)->height_ : -1)
#include "node_macro.h"

template<typename T>
class Node
{
public:
	Node() : parent_(nullptr), left_(nullptr), right_(nullptr), height_(0) {}
	Node(const T& data, Node* parent = nullptr, Node *left = nullptr, Node *right = nullptr): \
		data_(data), parent_(parent), left_(left), right_(right), height_(0) {}

	Node* insert_as_left(const T& data) { return left_ = new Node(data, this); }
	Node* insert_as_right(const T& data) { return right_ = new Node(data, this); }
	Node* succ();

	template<typename VST> void trav_pre(VST& visit)
	{
		switch (rand() % 2)
		{
		case 0: trav_pre_i(this, visit); break;
		case 1: trav_pre_r(this, visit); break;
		default: break;
		}
	}
	template<typename VST> void trav_in(VST& visit)
	{
		switch (rand() % 2)
		{
		case 0:
			trav_in_i1(this, visit); break;
		case 1:
			trav_in_i2(this, visit); break;
		case 2:
			trav_in_r(this, visit); break;
		}
	}
	template<typename VST> void trav_post(VST& visit)
	{
		switch (rand() % 3)
		{
		case 0:
			trav_post_i1(this, visit); break;
		case 1:
			trav_post_r(this, visit); break;
		}
	}
	template<typename VST> void trav_level(VST& visit);

	T data_;
	Node* parent_;
	Node* left_;
	Node* right_;
	int height_;
protected:
};

template<typename T, typename VST>
void trav_pre_r(Node<T>* x, VST& visit)
{
	if (!x) return;
	visit(x->data_);
	trav_pre_r(x->left_, visit);
	trav_pre_r(x->right_, visit);
}

template<typename T, typename VST>
static void visit_along_left_branch(Node<T>* x, VST& visit, std::stack<Node<T>*>& s)
{
	while (x)
	{
		visit(x->data_);
		s.push(x->right_);
		x = x->left_;
	}
}

template<typename T, typename VST>
void trav_pre_i(Node<T>* x, VST& visit)
{
	std::stack<Node<T>*> s;
	while (true)
	{
		visit_along_left_branch(x, visit, s);
		if (s.empty()) break;
		x = s.top();
		s.pop();
	}
}

template<typename T, typename VST>
static void go_along_left_branch(Node<T>* x, std::stack<Node<T>*>& s)
{
	while (!x)
	{
		s.push(x);
		x = x->left_;
	}
}

template<typename T, typename VST>
void trav_in_i1(Node<T>* x, VST& visit)
{
	std::stack<Node<T>*> s;
	while (true)
	{
		go_along_left_branch(x, s);
		if (s.empty()) break;
		x = s.top(), s.pop();
		visit(x->data_);
		x = x->right_;
	}
}

template<typename T, typename VST>
void trav_in_i2(Node<T>* x, VST& visit)
{
	std::stack<Node<T>*> s;
	while (true)
	{
		if (x)
		{
			s.push(x);
			x = x->left_;
		}
		else if (!s.empty())
		{
			x = s.top(), s.pop();
			visit(x->data_);
			x = x->right_;
		}
		else
			break;
	}
}

template<typename T, typename VST>
void trav_in_r(Node<T>* x, VST& visit)
{
	if (!x)
		return;
	trav_in_r(x->left_, visit);
	visit(x->data_);
	trav_in_r(x->right_, visit);
}

template<typename T, typename VST>
void trav_post_r(Node<T>* x, VST& visit)
{
	if (!x)
		return;
	trav_post_r(x->left_, visit);
	trav_post_r(x->right_, visit);
	visit(x->data_);
}

template<typename T>
template<typename VST>
inline void Node<T>::trav_level(VST & visit)
{
	std::queue<Node<T>*> q;
	q.push(this);
	while (!q.empty())
	{
		Node<T>* x = q.top(), q.pop();
		visit(x->data_);
		if (x->left_) q.push(x->left_);
		if (x->right_) q.push(x->right_);
	}
}

template<typename T>
inline Node<T> * Node<T>::succ()
{
	Node<T>* p = this;
	if (p->right_)
	{
		p = p->right_;
		while (p->left_)
			p = p->left_;
	}
	else
	{
		while (p->parent_ && p == p->parent_->right_)
			p = p->parent_;
		p = p->parent_;
	}
	return p;
}
