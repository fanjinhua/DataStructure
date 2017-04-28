#pragma once
#include <algorithm>

#define IsRoot(x) (!((x)->parent_))
#define Isleft_hild(x) (!IsRoot(x) && ( (x) == (x)->parent_->left_ ))
#define Isright_hild(x) (!IsRoot(x) && ( (x) == (x)->parent_->right_ ))
#define HasParent(x) (!IsRoot(x))
#define Hasleft_hild(x) ( (x)->left_ )
#define Hasright_hild(x) ( (x)->right_ )
#define HasChild(x) ( Hasleft_hild(x) || Hasright_hild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( Hasleft_hild(x) && Hasright_hild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )

#define sibling(p) /*兄弟*/ \
   ( Isleft_hild(p) ? (p)->parent_->right_ : (p)->parent_->left_ )

#define uncle(x) /*叔叔*/ \
   ( Isleft_hild( (x)->parent_ ) ? (x)->parent_->parent_->right_ : (x)->parent_->parent_->left_ )

#define FromParentTo(x) /*来自父亲的引用*/ \
   ( IsRoot(x) ? root_ : ( Isleft_hild(x) ? (x)->parent_->left_ : (x)->parent_->right_ ) )


// avl part 
#define HeightUpdated(x) /*高度更新常规条件*/ \
        ( (x)->height_ == 1 + std::max( stature( (x)->left_ ), stature( (x)->right_ ) ) )
#define Balanced(x) ( stature( (x)->left_ ) == stature( (x)->right_ ) ) //理想平衡条件
#define BalFac(x) ( stature( (x)->left_ ) - stature( (x)->right_ ) ) //平衡因子
#define AvlBalanced(x) ( ( -2 < BalFac(x) ) && ( BalFac(x) < 2 ) ) //AVL平衡条件
