// 广义表的头尾链表存储表示
typedef enum={Atom,list} ElemTag;//atom=0 原子，list=1子表
typedef struct GLNode{
    ElemTag tag;
    union{
        AtomType atom;
        struct{
            struct GLNode GLNode *hp, *tp;
        }Ptr;
    }a;

}*GList, GLNode;

