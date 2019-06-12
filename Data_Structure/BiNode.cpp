
#include<iostream>

typedef struct BiNode{//链式结构定义
    int data;
    struct BiNode *lchild, *rchild;

}binode,;

void pre_order(binode *p);//先序遍历
void in_order(binode *p);//中序遍历
void post_order(binode *p);//后序遍历
void level_order(binode *p);//层次遍历
int Getdepth(binode *p);//树高
int GetLevelNodes(binode *p,int k)//求K层的节点数
BiNode FindLCA(binode *p,binode *target1,binode *target2)//Lowest Common Ancesto

void pre_order(binode *p){
    if(p!= null){
        printf('%d\t',p->data);
        printf(p->lchild);
        printf(p->rchild);

    }
}


void in_order(binode *p){
    if(p!= null){

        printf(p->lchild);
        printf('%d\t',p->data);
        printf(p->rchild);

    }
}

void post_order(binode *p){
    if(p!= null){

        printf(p->lchild);
        printf(p->rchild);
        printf('%d\t',p->data);

    }
}
//////////////////////////////////非递归写法/////////////////////////////////////////
void pre_order(binode *p){
    if(p==null)
        return;


    Stack<BiNode*>s;
    while(!s.empty()||p)
    {//棧非空且指针P指向非空
        if(p)
        {
            cout<<(setw4)<<p->data;//输出
            s.push(p);
            p=p->lchild;


        }
        else{
            p=s.top();
            s.pop();
            p=p->rchild;

        }

    }
    cout<<endl;

}



void in_order(binode *p){//中序遍历
    if (p==null)//树空
        return;

    Stack<BiNode*>s;
    while(!s.empty()||p)
    {
        while(p){//p非空，一直遍历到左子树最下端，边遍历边保存根结点到S棧中；
            s.push(p);
            p=p->lchild;
        }//p空，说明已经到树的最左端，此时需要出棧；
        if(!s.empty()){
            p=s.top();
            s.pop();
            cout<<setw(4)<<p-data;//输出
            //进入右子树，开始新的一轮左子树的遍历（这是递归的自我实现）       
            p=p->rchild;


        }


    }

}



void post_order(binode *p){//需要判断上次访问的节点是位于左子树，还是右子树。若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；
    // 若是位于右子树，则直接访问根节点
    if (p==null)
        return;
    stack<BiNode*>s;
    binode * PlastVisit=null;//PlastVisit 上次访问的节点
    while(p){//先把P移动到左子树最下面
        s.push(p);

        p=p->lchild;

    }
    while(!s.empty()){
        p=s.top();//走到这已经到达左子树最下端，出棧
        s.pop();
        if(p->rchild==null||p->rchild=PlastVisit)//根节点被访问的条件是无右子树或者右子树已经被访问了

        {
            cout<<setw(4)<<p->data;
            PlastVisit=p;

        }
        else{
            s.push(p);//根节点再次入棧
            p=p->rchild;//进入右子树，且肯定右子树一定不为空
            while(p){//进入右子树 重复左 右 根的访问
                s.push(p);
                p=p->lchild;
            }

        }


    }
    cout<<endl;


}



void level_order(binode *p){//只需要一个队列即可，先在队列中加入根结点。之后对于任意一个结点来说，在其出队列的时候，访问之。

    list<binode *> t;
    if(p!=null){
        t.push_back(p);
    }
    while(t.size>0){
        printf('%d\t',(t.front())->data);//若队不空，取队首元素
    }
    if (t.front()->lchild !=null){// 同时如果左孩子和右孩子有不为空的，入队列
        t.push_back(t.front()->lchild)
    }
    if (t.front()->rchild!=null){
        t.push_back((t.front())->rchild);
    }
    t.pop(t.front());//


}
int GetDepth(binode *p){
    if(p!=null){
        int leftDepth=GetDepth(p->lchild)+1;
        int rightDepth=GetDepth(p->rchild)+1;
        return leftDepth>rightDepth?leftDepth:rightDepth;


    }
    rerurn 0;
}
int GetLevelNodes(binode *p,int k){
    if(p==null||k<1)
        return 0;
    else if(k==1)
        return 1;//若此时层数==1，则表面该节点即为所在层
    else
        return( GetLevelNodes(p->lchild,k-1)+GetLevelNodes(p->rchild,k-1));//若K！=0，则返回根结点P的左右子节点的K-1层节点数

}

BiNode FindLCA(binode *p,binode *target1,binode *target2){//将跟节点与两个目标节点比较，若跟节点比两个节点都大，则LCA一定在左子树
    //否则一定在右子树上
    //直到找到第一个值是两个输入节点之间的值的节点，该节点就是两个节点的最近公共祖先节点

    if(p==null)
        return 0;
    if (p==target1||p==target2)
        return p;
    binode *lchild=FindLCA(p->lchild,target1,target2);
    binode *rchild=FindLCA(p->rchild,target1,target2);
    if (p->lchild&&p->rchild)//一个在左子树，一个在右子树
        return p;
    return lchild?lchild:rchild;

