#pragma once 
#include "bst.h"

template<typename T>
class AVL : public BST<T>
{
public:
	Node<T>* insert(const T& key);
	bool remove(const T& key);
};

template<typename T>
inline Node<T>* AVL<T>::insert(const T & key)
{
	Node<T>* x = search(key); if (x) return x;
	x = new Node(key, this->hot_); this->size_++; 
	for (Node<T>* g = x->parent_; g; g = g->parent_)
	{
		if (!AvlBalanced(x))
		{

		}
		else
			updateHeight(g);
	}
	return x;
}
