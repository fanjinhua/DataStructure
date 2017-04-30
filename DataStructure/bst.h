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
	Node<T>* hot_;  //�����С��ڵ�ĸ���
	Node<T>* connect34( // ���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
		Node<T>*, Node<T>*, Node<T>*,
		Node<T>*, Node<T>*, Node<T>*, Node<T>*);
	Node<T>* rotate_at(Node<T>* x); //��x���丸�ס��游��ͳһ��ת����
	Node<T>* remove_at(Node<T>*& x);
};

template<typename T>
inline Node<T>* BST<T>::search(const T &key)
{
	Node<T>* p = this->root_;
	while (p && p->data_ != key)
	{
		hot_ = p; // �ȼ�¼��ǰ���ǿգ��ڵ㣬������
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

template<typename T>
inline Node<T>* BST<T>::remove_at(Node<T>*& x)
{
	Node<T>* w = x; //ʵ�ʱ�ժ���Ľڵ㣬��ֵͬx
	Node<T>* succ = nullptr; //ʵ�ʱ�ɾ���ڵ�Ľ�����
	if (!HasLChild(x)) //��*x��������Ϊ�գ����
		succ = x = x->right_; //ֱ�ӽ�*x�滻Ϊ��������
	else if (!HasRChild(x)) //��������Ϊ�գ����
		succ = x = x->left_; //�ԳƵش�����ע�⣺��ʱsucc != NULL
	else  //���������������ڣ���ѡ��x��ֱ�Ӻ����Ϊʵ�ʱ�ժ���ڵ㣬Ϊ����Ҫ
	{
		w = w->succ(); //�����������У��ҵ�*x��ֱ�Ӻ��*w
		std::swap(x->data_, w->data_); 
		Node<T>* u = w->parent_;
		((u == x) ? u->right_ : u->left_) = succ = w->right_; //����ڵ�*w
	}
	hot_ = w->parent_; //��¼ʵ�ʱ�ɾ���ڵ�ĸ���
	if (succ) succ->parent_ = hot_; //������ɾ���ڵ�Ľ�������hot����
	delete w; // release(w->data); release(w);
	return succ; //�ͷű�ժ���ڵ㣬���ؽ�����
}
