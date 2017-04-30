#pragma once 
#include "binary_tree.h"

template<typename T>
class BST : public BinTree<T>
{
public:
	BST(): BinTree<T>(), hot_(nullptr) {}
	virtual Node<T>* search(const T&);
	virtual Node<T>* insert(const T&);
	virtual bool remove(const T&);
protected:
	Node<T>* hot_;  //“命中”节点的父亲
	Node<T>* connect34( // 按照“3 + 4”结构，联接3个节点及四棵子树
		Node<T>*, Node<T>*, Node<T>*,
		Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	Node<T>* rotate_at(Node<T>* x); //对x及其父亲、祖父做统一旋转调整
	Node<T>* remove_at(Node<T>*& x);
};

template<typename T>
inline Node<T>* BST<T>::search(const T &key)
{
	Node<T>* p = this->root_;
	while (p && p->data_ != key)
	{
		hot_ = p; // 先记录当前（非空）节点，再深入
		p = (key < p->data_) ? p->left_ : p->right_;
	}
	return p;
}

template<typename T>
inline Node<T>* BST<T>::insert(const T &key)
{
	Node<T>*& x = search(key);
	if (x) return x;
	x = new Node<T>(key, hot_);
	size_++;
	this->updata_height_above(x);
	return x;
}

template<typename T>
inline bool BST<T>::remove(const T &)
{
	Node<T>*& x = search(key);
	if (!x) return false;
	remove_at(x); 
	size_--;
	this->updata_height_above(hot_);
	return true;
}

template<typename T>
inline Node<T>* BST<T>::connect34(Node<T>* a, Node<T>* b, Node<T>* c, \
	Node<T>* T0, Node<T>* T1, Node<T>* T2, Node<T>* T3)
{
	a->left_ = T0; if (T0) T0->parent_ = a;
	a->right_ = T1; if (T1) T1->parent_ = a; 
	HeightUpdated(a);
	c->left_ = T2; if (T2) T2->parent_ = c; 
	c->right_ = T3; if (T3) T3->parent_ = c; 
	HeightUpdated(c);
	b->left_ = a; a->parent_ = b;
	b->right_ = c; c->parent_ = b; 
	HeightUpdated(b);
	return b;//该子树新的根节点
}

template<typename T>
inline Node<T>* BST<T>::rotate_at(Node<T>* v) // grandparent - parent - vertex
{
	Node<T>* p = v->parent_, g = p->parent_; // grandp, parent
	if (IsLChild(p)) // zig
	{
		if (IsLChild(v)) // zig-zig
		{
			p->parent_ = g->parent_; // 向上连接
			return this->connect34(v, p, g, v->left_, v->right_, p->right_, g->right_);
		}
		else // zig-zag
		{
			v->parent_ = g->parent_; // 向上连接
			return this->connect34(p, v, g, p->left_, v->left_, v->right_, g->right_);
		}
	}
	else // zag
	{
		if (IsLChild(v)) // zag-zig
		{
			v->parent_ = g->parent_; // 向上连接
			return this->connect34(g, v, p, g->left_, v->left_, v->right_, p->right_);
		}
		else // zag-zag
		{
			p->parent_ = g->parent_; // 向上连接
			return this->connect34(g, p, v, g->left_, p->left_, v->left_, v->right_);
		}
	}
}

template<typename T>
inline Node<T>* BST<T>::remove_at(Node<T>*& x)
{
	Node<T>* w = x; //实际被摘除的节点，初值同x
	Node<T>* succ = nullptr; //实际被删除节点的接替者
	if (!HasLChild(x)) //若*x的左子树为空，则可
		succ = x = x->right_; //直接将*x替换为其右子树
	else if (!HasRChild(x)) //若右子树为空，则可
		succ = x = x->left_; //对称地处理——注意：此时succ != NULL
	else  //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
	{
		w = w->succ(); //（在右子树中）找到*x的直接后继*w
		std::swap(x->data_, w->data_); 
		Node<T>* u = w->parent_;
		((u == x) ? u->right_ : u->left_) = succ = w->right_; //隔离节点*w
	}
	hot_ = w->parent_; //记录实际被删除节点的父亲
	if (succ) succ->parent_ = hot_; //并将被删除节点的接替者与hot相联
	delete w; // release(w->data); release(w);
	return succ; //释放被摘除节点，返回接替者
}
