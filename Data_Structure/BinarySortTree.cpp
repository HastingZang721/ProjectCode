#include<iostream>

typedef struct BiNode{//链式结构定义
    int data;
    struct BiNode *lchild, *rchild;

}*node,binode;

int search_value(node root,double a,node *p){//查找
    if(root==null){
        return 0;//查找不成功
    }
    if(a==root->data){
        return 1;//树中已存在
    }
    else if(a< root->data) {
        *p = root;//记录父节点
        return search_value(root->rchild, a, p);//查找左子树
    }
    else if(a> root->data){
        *p =root;
        return search_value(root->lchild,a,p);//查重右子树

    }

}

int insert(node *root,double a){//若二叉排序树中存在该值，则不做任何操作;//若二叉排序树中不存在该值，则插入
    node p=*root;
    node q=null;
    printf("insert:%lf\n",a);
    if (search_value(* root,a,&p)==0){//树中无此节点a
        q=(binode *)malloc(sizeof(binode));//申请节点空间
        q->data=a;
        q->lchild=q->rchild=null;
        if(root==null){
            *root=p;

        }else {
            if (a<  p->data){
                p->lchild=q;//插入左子树
            }
            else
                p->lchild=q;
        }


    }

}
int delete_node(node *root,double a){
    node *p=root;
    if(search_value(*root,a,&p)==1){
        //已经存在a
        //开始删除。p指向要删除节点的父节点
        node q=null;//q指向要删除的节点
        if(a< p->data){
            q=p->lchild;

        }
        else{
            q=p->rchild;

        }
        if (q->Lchild==null&&q->rchild==null)//若q是叶子节点则直接删除{}
        {
            if (a < p->data)//a是p的左节点
                p->lchild == null;
            else
                p->rchild == null;
        }
        else if((p->lchild==null&&p->rchild!=null)||(p->lchild!=null&&p->rchild==null)){
            //只有左子树或者只有右子树
            node r=(q->lchild=null?q->rchild:q->lchild);//指向不为空的子树
            if(a<p->lchild)//a 是p 的左子树节点
                p->lchild=r;
            else
                p->rchild=r;
        }
        else{//q既有左子树也有右子树
            //这里选择左子树上最大的节点作为替代p的节点（新的父节点）
            node r=q->lchild;
            if(r->rchild==null){//判断r de lchild 是否为空
                p->lchild=r;
                r->lchild=q->lchild;

            }
            else{//右子树不为空
                node r1;
                node r1_father;
                while(r1->rchild!=NULL){
                    r1_father=r1;
                    r1=r1->rchild;

                }r1_father->rchild=r1->lchild;
                r1->lchild=r;
                r1=p->rchild;
                r1->rchild=q->rchild;


            }

        }
        free(q);
        q=null;
        return 0;

    }
    return 1;
    

}
