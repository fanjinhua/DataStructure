#pragma once 
#include "bst.h"

template<typename T>
class AVL : public BST<T>
{
public:
	Node<T>* insert(const T& key);
	bool remove(const T& key);
protected:
	
};

template<typename T>
inline Node<T>* AVL<T>::insert(const T & key)
{
	Node<T>*& x = search(key); if (x) return x;
	Node<T>* xx = x = new Node(key, this->hot_); this->size_++; 
	for (Node<T>* g = hot_; g; g = g->parent_)
	{
		if (!AvlBalanced(x))
		{
			FromParentTo(g) = rotate_at(tallerChild(tallerChild(g)));
			break;
		}
		else
			HeightUpdated(g);
	}
	return xx;
}

template<typename T>
inline bool AVL<T>::remove(const T & key)
{

	return false;
}
