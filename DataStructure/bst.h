#pragma once 
#include "binary_tree.h"

template<typename T>
class BST : public BinTree<T>
{
public:
	virtual Node<T>* search(const T&);
	virtual Node<T>* insert(const T&);
	virtual bool remove(const T&);
};