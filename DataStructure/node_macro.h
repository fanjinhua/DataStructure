#pragma once
#include <algorithm>

#define IsRoot(x) (!((x)->parent_))
#define IsLChild(x) (!IsRoot(x) && ( (x) == (x)->parent_->left_ ))
#define IsRChild(x) (!IsRoot(x) && ( (x) == (x)->parent_->right_ ))
#define HasParent(x) (!IsRoot(x))
#define Hasleft_hild(x) ( (x)->left_ )
#define Hasright_hild(x) ( (x)->right_ )
#define HasChild(x) ( Hasleft_hild(x) || Hasright_hild(x) ) //����ӵ��һ������
#define HasBothChild(x) ( Hasleft_hild(x) && Hasright_hild(x) ) //ͬʱӵ����������
#define IsLeaf(x) ( ! HasChild(x) )

#define sibling(p) /*�ֵ�*/ \
   ( IsLChild(p) ? (p)->parent_->right_ : (p)->parent_->left_ )

#define uncle(x) /*����*/ \
   ( IsLChild( (x)->parent_ ) ? (x)->parent_->parent_->right_ : (x)->parent_->parent_->left_ )

#define FromParentTo(x) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? root_ : ( IsLChild(x) ? (x)->parent_->left_ : (x)->parent_->right_ ) )


// avl part 
#define HeightUpdated(x) /*�߶ȸ��³�������*/ \
        ( (x)->height_ == 1 + std::max( stature( (x)->left_ ), stature( (x)->right_ ) ) )
#define Balanced(x) ( stature( (x)->left_ ) == stature( (x)->right_ ) ) //����ƽ������
#define BalFac(x) ( stature( (x)->left_ ) - stature( (x)->right_ ) ) //ƽ������
#define AvlBalanced(x) ( ( -2 < BalFac(x) ) && ( BalFac(x) < 2 ) ) //AVLƽ������

#define tallerChild(x) ( \
			stature((x)->left_) > stature((x)->right_) ? (x)->left_ : ( /*���*/ \
			stature((x)->left_) < stature((x)->right_) ? (x)->right_: ( /*�Ҹ�*/ \
			IsLChild(x) ? (x)->left_ : (x)->right_  /* �ȸߣ��и���xͬ���ߣ�zig-zig or zag-zag������*/)))
