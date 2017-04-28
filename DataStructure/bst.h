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
	Node<T>* hot_;  //�����С��ڵ�ĸ���
	Node<T>* connect34( // ���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
		Node<T>*, Node<T>*, Node<T>*,
		Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	Node<T>* rotate_at(Node<T>* x); //��x���丸�ס��游��ͳһ��ת����
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

template<typename T>
inline Node<T>* BST<T>::connect34(Node<T>* a, Node<T>* b, Node<T>* c, \
	Node<T>* T0, Node<T>* T1, Node<T>* T2, Node<T>* T3)
{
	a->left_ = T0; if (T0) T0->parent_ = a;
	a->right_ = T1; if (T1) T1->parent_ = a; updateHeight(a);
	c->left_ = T2; if (T2) T2->parent_ = c; 
	c->right_ = T3; if (T3) T3->parent_ = c; updateHeight(c);
	b->left_ = a; a->parent_ = b;
	b->right_ = c; c->parent_ = b; updateHeight(b);
	return b;//�������µĸ��ڵ�
}

template<typename T>
inline Node<T>* BST<T>::rotate_at(Node<T>* v) // grandparent - parent - vertex
{
	Node<T>* p = v->parent_, g = p->parent_; // grandp, parent
	if (IsLChild(p)) // zig
	{
		if (IsLChild(v)) // zig-zig
		{
			p->parent_ = g->parent_; // ��������
			return this->connect34(v, p, g, v->left_, v->right_, p->right_, g->right_);
		}
		else // zig-zag
		{
			v->parent_ = g->parent_; // ��������
			return this->connect34(p, v, g, p->left_, v->left_, v->right_, g->right_);
		}
	}
	else // zag
	{
		if (IsLChild(v)) // zag-zig
		{
			v->parent_ = g->parent_; // ��������
			return this->connect34(g, v, p, g->left_, v->left_, v->right_, p->right_);
		}
		else // zag-zag
		{
			p->parent_ = g->parent_; // ��������
			return this->connect34(g, p, v, g->left_, p->left_, v->left_, v->right_);
		}
	}
}
