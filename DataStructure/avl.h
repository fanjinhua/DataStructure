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
	Node<T>*& x = search(key); if (!x) return false; //确认目标存在（留意_hot的设置）
	this->remove_at(x); size_--; //先按BST规则删除之（此后，原节点之父_hot及其祖先均可能失衡）
	for (Node<T>* g = hot_; g; g = g->parent_) //从_hot出发向上，逐层检查各代祖先g
	{
		if (!AvlBalanced(g)) //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡，并将该子树联至
			g = FromParentTo(g) = rotate_at(tallerChild(tallerChild(g))); //原父亲
		HeightUpdated(g); //并更新其高度（注意：即便g未失衡，高度亦可能降低）
	} //可能需做Omega(logn)次调整——无论是否做过调整，全树高度均可能降低
	return true;
}
