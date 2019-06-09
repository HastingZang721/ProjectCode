//huffman 树的结构
typedef struct
{
    unsigned int weight;
    unsigned int parent;
    unsigned int lchild;
    unsigned int rchild;

}node ,*HuffmanTree;

typedef char* HuffmanCode;
/*
/选择两个parent为0，且weight最小的结点s1和s2的方法实现
//n 为叶子结点的总数，s1和 s2两个指针参数指向要选取出来的两个权值最小的结点*/

void select(HuffmanCode * huffmanTree,int n,int *s1,int *s2)
{
    int i=0;
    int min;
    for(i=1,i<=n;i++)//找出所有的单节点
    {
        找出[i].parent==0;
        min=i;
        break;
    }
    for(i=0;i<=n;i++)
    {
        while([i].parent==0){
            if((* huffmanTree)[i].weight<(*huffmanTree)[min].weight)
            {
                min=i;
            }


        }
    }
    * s1=min;//找出最小值并指向S1
    for(i=0;i<=n;i++)
    {
        while([i].parent==0&& i !=(*s1)){
            if((* huffmanTree)[i].weight<(*huffmanTree)[min].weight)
            {
                min=i;
            }


        }
    }
    * s2=min;//s2 指向次小值




}


//建造huffman树
void CreateHuffmanTree(HuffmanTree * huffmanTree,char ch[],int w[],int n)
{
    int m=2*n-1；//叶子总节点数
    int s1,s2;
    int i;
    *huffmanTree=(HuffmanTree)malloc((m+1)*sizeof(Node));
    for(i=1;i<=n;i++)
    {
        (*huffmanTree)[i].weight=w[i];
        (*huffmanTree)[i].ch=ch[i];



    }
    for(int k=n+1;k<=m;k++)
    {//在(*huffmanTree)[1]~(*huffmanTree)[i-1]的范围内选择两个parent为0
         //且weight最小的结点，其序号分别赋值给s1、s2
        select(huffmanTree,k-1,&s1,&s2);//找出权值最小的两个节点
        //从选择的两权值最小的节点组成一个根为K的二叉树
        (* huffmanTree)[s1].parent=k;
        (*huffmanTree)[s2].parent=k;
        (* huffmanTree)[i].lchild=s1;
        (* huffmanTree)[i].rchild=s2;
        (* huffmanTree)[k].weight=(* huffmanTree)[s1].weight+(* huffmanTree)[s2].weight;
        
 

    }

}
 void huffmancode(huffmanTree[],int n)
 //霍夫曼编码
 int j;
 {
    while(HuffmanTree[j].parent !=-1)//存在双亲
        if(j==HuffmanTree[k].lchild)
            s=s+"0";
        else 
            s=s+"1";
        
        
 }
