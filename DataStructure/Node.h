#pragma once
#include <stack>
#define stature(p) ((p) ? (p)->height_ : -1)
typedef enum { RB_RED, RB_BLACK } RBColort;

template<typename T>
class Node
{
public:
	Node() : parent_(nullptr), left_(nullptr), right_(nullptr), height_(0) {}
	Node(const T& data, Node* parent = nullptr, Node *left = nullptr, Node *right = nullptr): \
		data_(data), parent_(parent), left_(left), right_(right), height_(0) {}

	Node* insert_as_left(const T& data) { return left_ = new Node(data, this); }
	Node* insert_as_right(const T& data) { return right_ = new Node(data, this); }
	
	template<typename VST> void trav_pre(VST& visit)
	{
		switch (rand() % 2)
		{
		case 0: trav_pre_i(this, visit); break;
		case 1: trav_pre_r(this, visit); break;
		default: break;
		}
	}
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
