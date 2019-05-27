enum RBTcolor={red,black};//红黑树
template<class T>
class RBTNode{
public:
    RBTcolor color;
    RBTNode *left;
    RBTNode *right;
    RBTNode *parent;
    RBTNode key;

};


template <class T>//左旋
void RBTNode:: Left_rotate(RBTNode<T>*&root,RBTNode<T> *x){
    RBTNode<T> *y=x->right;
    x->right=y->left;
    if(y->left!=nil)
        y->left.parent=x;
    y.parent=x.parent;
    if (x.parent==null) {
        root = y;
        else if x = x.parent->left//x是左孩子
        x.parent->left = y;

        else    x.parent->right = y;
    }
    y->left=x;
    x->parent=y;



}
template<class T>//插入
void RBTNode:: RBInsert(T,z)
{
    y=T.nil;//y用于记录当前扫描节点的双亲；
    x=Y.root;//从根结点开始扫描
    while(x!=T.nil){
        y=x;
        if z.key<x.key;
        x=x.left;
        else
            x=x.right;

    }
   z.parent=y;//y是Z的双亲；
   if y==T.nil;
       T.root=z;

   elseif
     z.key<y.key;
   y.left=z;//Z是y 的左子树插入
   else
       y.right=z;
   z.left=T.nil;
   z.right=T.nil;
   z.color=RED;
   RB_Insert_fixup(T,z);//保持红黑性质


}

