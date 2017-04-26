#pragma once 
#include "Node.h"
#include <algorithm>
#define BinNode Node<T>*;

template<typename T>
class BinTree
{
public:
	BinTree() {}

	int size() const { return size_; }
	void updata_height_above(Node<T>* x) { while (x) { update_height(x); x = x->parent_; } }
	Node<T>* insert_as_left(Node<T>* x, const T& data)
	{
		x->insert_as_left(data);
		updata_height_above(x);
		size_++;
		return x->left_;
	}
	Node<T>* insert_as_right(Node<T>* x, const T& data)
	{
		x->insert_as_right(data);
		updata_height_above(x);
		size_++;
		return x->right_;
	}
protected:
	Node<T>* root_;
	int size_;
	virtual int update_height(BinNode x)
	{
		return x->height = 1 + std::max(stature(x->left_), stature(x->right_));
	}
};

