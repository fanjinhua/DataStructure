#pragma once 
#include "binary_tree.h"

template<typename T>
class BST : public BinTree<T>
{
public:
	virtual Node<T>* search(const T&);
	virtual Node<T>* insert(const T&);
	virtual bool remove(const T&);
protected:
	Node<T>* hot_;  //“命中”节点的父亲
	Node<T>* rotate_at(Node<T>* x); //对x及其父亲、祖父做统一旋转调整
};

template<typename T>
inline Node<T>* BST<T>::search(const T &key)
{
	Node<T>* p = this->root_;
	while (!p && p->data_ != key)
	{
		hot_ = p;
		if (key < p->data_)
			p = p->left_;
		else
			p = p->right_;
	}
	return p;
}

template<typename T>
inline Node<T>* BST<T>::insert(const T &key)
{
	Node<T>* x = search(key);
	if (x) return x;
	x = new Node<T>(key, hot_);
	size_++;
	this->updata_height_above(x);
	return x;
}

template<typename T>
inline bool BST<T>::remove(const T &)
{
	Node<T>* x = search(key);
	if (!x) return false;
	remove_at(x, hot_); 
	size_--;
	this->updata_height_above(hot_);
	return true;
}
