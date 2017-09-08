 /*
 8.11
    先序建立二叉树
 */
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
}   BiT;

BiT * CreateBiTree(BiT *);
void PreOrderTraverse(BiT *);

int main(){
    BiT * t;
    t = CreateBiTree(t);
    PreOrderTraverse(t);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
    }
    return t;
}

void PreOrderTraverse(BiT * t){
    if(t){
        printf("%c", t->date);
        PreOrderTraverse(t->lift);
        PreOrderTraverse(t->right);
    }
}
*/

/*
6.33
    假定用两个一维数组L[n+1]和R[n+1]作为有n个结点的二叉树的存储结构，L[i]和R[i]分别指示结点i(i = 1,2,……,n)的左孩子
    和右孩子，0表示空。
    试写一个算法判别结点u是否为结点v的子孙。
*/
/*
#include <stdio.h>

int main(){
    int n;
    int i;
    int c = 0;
    printf("输入结点数： ");
    scanf("%d",&n);
    int L[n+1];
    int R[n+1];
    L[0] = 0;
    R[0] = 0;
    for(i = 0; i <= n; i++){
        L[i] = 0;
        R[i] = 0;
    }
    i = 1;
    L[i] = i;
    while(i <= n){
        c = i*2;
        L[c] = c;
        R[c+1] = c+1;
        i++;
    }
    printf("亲子鉴定\n输入祖先结点：");
    scanf("%d", &i);
    printf("输入子孙结点：");
    scanf("%d", &c);
    while(c > i){
        c = c/2;
    }
    if(c == i) printf("为祖先子孙关系");
    else printf("不是祖先子孙关系");
    return 0;
}
*/

/*
6.35
    假设二叉树中左分支的标号为“0”，右分支的标号为“1”，并对二叉树增设一个头结点，令根节点为其右孩子，
    则从头结点到树中任一结点所经分支的序列为一个二进制序列，可认作是某个十进制数的二进制表示。
    例如，右图所示二叉树中，和结点 A 对应的二进制序列为“110”，即十进制整数6的二进制表示。
    已知一颗非空二叉树以顺序存储结构表示，试写一尽可能简单的算法，求出与在树的顺序存储结构中下标为i的结点对应的十进制整数。
*/
/*
#include <stdio.h>
#include <math.h>

int main(){
    int i;
    int n;
    int sum = 0;
    printf("输入结点数： ");
    scanf("%d", &n);
    int Tree[n];
    int Stack[n];
    int top = 0;
    for(i = 0; i <= n; i++){
        Tree[i] = i;
    }
    printf("输入查找的结点下标： ");
    scanf("%d", &n);
    do{
        Stack[top++] = n%2;
        n = n/2;
    }while(n != 0);
    for(i = 0; i < top; i++){
        sum += Stack[i] * pow(2,i);
    }
    printf("%d", sum);

    return 0;
}
*/

/*
6.37
    试利用栈的基本操作写出先序遍历的非递归形式的算法
*/
/*
#define STACK_MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef struct _TNode{
    int date;
    struct _TNode * LChild;
    struct _TNode * RChild;
}   TNode;

typedef struct{
    TNode * t[STACK_MAX_SIZE];
    int top;
}   Stack;

void InitStack(Stack *);
void CreateBiTree(Stack *);

int main(){
    Stack * s = (Stack *)malloc(sizeof(Stack));
    InitStack(s);
    CreateBiTree(s);

    return 0;
}

void InitStack(Stack * s){
    s->top = 0;
}

void CreateBiTree(Stack * s){
    int num;
    int flag = 0;
    do{
        flag = 0;
        scanf("%d", &num);
        fflush(stdin);
        if(num == 32) {
            s->t[s->top] = NULL;
            if(s->top == 0) return;
            else s->top--;
            if(s->top % 2 == 0)  s->t[s->top]->LChild = NULL;
            else s->t[s->top]->RChild = NULL;
            while(s->t[s->top]->LChild == NULL || s->t[s->top]->RChild == NULL){
                if(s->t[s->top]->RChild == NULL){
                    s->top--;
                    if(s->top == 0) return;
                }
                else if(s->t[s->top]->LChild == NULL){
                    s->t[s->top]->RChild = (TNode *)malloc(sizeof(TNode));
                    s->top++;
                    s->t[s->top] = s->t[s->top-1]->RChild;
                    flag = 1;
                }
            }
        }
        if(flag == 1) continue;
        if(s->top == 0) s->t[s->top] = (TNode *)malloc(sizeof(TNode));
        s->t[s->top]->date = num;
        s->t[s->top]->LChild = (TNode *)malloc(sizeof(TNode));
        s->top++;
        s->t[s->top] = s->t[s->top-1]->LChild;
    }while(s->top);
}
*/


/*
6.39
    假设在二叉链表的节点中增设两个域：双亲域（parent）以指示其双亲结点；
    标识域（mark取值0..2）以区分在遍历过程中到达该结点时应继续向左或向右或访问该结点。
    试以此存储结构编写不用栈进行后序遍历的递推形式的算法。
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
    struct BiTNode * parent;
    struct BiTNode * brother;
    int mark;
}   BiT;

BiT * CreateBiTree(BiT *);
void PreOrderTraverse(BiT *);
BiT * run(BiT *);
BiT * visit(BiT *);

int main(){
    BiT * t;
    t = CreateBiTree(t);
    PreOrderTraverse(t);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
        if(t->lift != NULL){
            t->lift->brother = t->right;
            t->lift->parent = t;
            t->lift->mark = 0;
        }
        if(t->right != NULL){
            t->right->brother = t->lift; 
            t->right->parent = t;
            t->right->mark = 2;
        }
    }
    return t;
}
void PreOrderTraverse(BiT * t){
    BiT * root = t;
    int flag = 0;
    t = run(t);
    do{
        printf("%c ", t->date);
        // if(t->brother != NULL){
        //     t = t->brother;
        //     t = run(t);
        // }
        if(t->mark == 0 && t->brother != NULL){
            t = t->brother;
            t = run(t);
        }
        else t = t->parent;
        if(t == root) printf("%c ", t->date);
    }while(t != root);
}

BiT * run(BiT * t){
    while(t->lift != NULL && t->right != NULL){
        if(t->lift != NULL) t = t->lift;
        else if(t->right != NULL) t = t->right;
    }
    return t;
}
*/

/*
6.42
    编写递归算法，计算二叉树中叶子结点的数目。
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
}   BiT;

BiT * CreateBiTree(BiT *);
void CntLeaf(BiT *, int *);

int main(){
    int cnt = 0;
    BiT * t;
    t = CreateBiTree(t);
    CntLeaf(t, &cnt);
    printf("%d", cnt);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
    }
    return t;
}

void CntLeaf(BiT * t, int * cnt){
    if(t->lift != NULL)
        CntLeaf(t->lift, cnt);
    if(t->right != NULL)
        CntLeaf(t->right, cnt);
    if(t->lift == NULL && t->right == NULL)
        *cnt += 1;
}
*/

/*
6.43
    编写递归算法，将二叉树中所有结点的左右子树相互交换。
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
}   BiT;

BiT * CreateBiTree(BiT *);
void ElemChange(BiT *);
void PreOrderTraverse(BiT *);

int main(){
    BiT * t;
    t = CreateBiTree(t);
    ElemChange(t);
    PreOrderTraverse(t);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
    }
    return t;
}

void ElemChange(BiT * t){
    BiT * temp;
    temp = t->lift;
    t->lift = t->right;
    t->right = temp;
    if(t->lift != NULL) ElemChange(t->lift);
    if(t->right != NULL) ElemChange(t->right);
}

void PreOrderTraverse(BiT * t){
    if(t){
        printf("%c", t->date);
        PreOrderTraverse(t->lift);
        PreOrderTraverse(t->right);
    }
}
*/

/*
6.45
    编写递归算法：对于二叉树中每一个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
}   BiT;

BiT * CreateBiTree(BiT *);
void PreOrderTraverse(BiT *);
void Find(BiT *, char);
void DelSubTree(BiT *);

int main(){
    BiT * t;
    //BiT * FindResult;
    char x;
    t = CreateBiTree(t);
    //PreOrderTraverse(t);
    printf("输入结点 X： ");
    scanf("%c", &x);
    Find(t, x);
    //FindResult = Find(t, x);
    //printf("%c", FindResult->date);
    PreOrderTraverse(t);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
    }
    return t;
}

void PreOrderTraverse(BiT * t){
    if(t){
        printf("%c", t->date);
        PreOrderTraverse(t->lift);
        PreOrderTraverse(t->right);
    }
}

void Find(BiT * t, char x){
    if(t->date == x){
        if(t->lift != NULL){
            DelSubTree(t->lift);
            t->lift = NULL;
        } 
        if(t->right != NULL){
            DelSubTree(t->right);
            t->right = NULL;
        }
    }
    if(t->lift != NULL) Find(t->lift, x);
    if(t->right != NULL) Find(t->right, x);
}

void DelSubTree(BiT * t){
    if(t->lift != NULL) DelSubTree(t->lift);
    t->lift = NULL;
    if(t->right != NULL) DelSubTree(t->right);
    t->right = NULL;
    if(t->lift == NULL && t->right == NULL){
        free(t);
    }
}
*/

/*
6.47
    编写按层次顺序（同一层自左至右）遍历二叉树的算法
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
}   BiT;

struct Queue{
    BiT ** q;
    int top;
    int lenth;
    int Addloc;
}   * s;

BiT * CreateBiTree(BiT *);
void LevelOrderTraverse(struct Queue *);
void InitQueue(struct Queue *);

int main(){
    BiT * t;
    t = CreateBiTree(t);
    s = (struct Queue *)malloc(sizeof(struct Queue));
    InitQueue(s);
    s->q[s->top] = t;
    LevelOrderTraverse(s);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
    }
    return t;
}

void InitQueue(struct Queue * s){
    s->q = (BiT **)malloc(sizeof(BiT *));
    s->top = 0;
    s->lenth = 1;
    s->Addloc = 0;
}

void LevelOrderTraverse(struct Queue * s){
    do{
        printf("%c ", s->q[s->top]->date);
        if(s->q[s->top]->lift != NULL){
            s->q = (BiT **)realloc(s->q, (++s->lenth)*sizeof(BiT *));
            s->q[++s->Addloc] = s->q[s->top]->lift;
        }
        if(s->q[s->top]->right != NULL){
            s->q = (BiT **)realloc(s->q, (++s->lenth)*sizeof(BiT *));
            s->q[++s->Addloc] = s->q[s->top]->right;
        }
        s->top++;
    }while(s->top != s->Addloc+1);
}
*/

/*
6.48    
    已知在二叉树中，*root为根节点，*p 和 *q 为二叉树中两个结点
    试编写求距离他们最近的共同祖先的算法
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
    struct BiTNode * parent;
    struct BiTNode * brother;
}   BiT;

BiT * CreateBiTree(BiT *);
BiT * Find(BiT *, char);
BiT * run(BiT *);
void Compare(BiT *, BiT *, BiT *);

int main(){
    BiT * t;
    BiT * root;
    BiT * p = NULL;
    BiT * q = NULL;
    char x;
    t = CreateBiTree(t);
    root = t;
    printf("输入p： ");
    scanf("%c", &x);
    fflush(stdin);
    p = Find(t, x);
    printf("输入q： ");
    scanf("%c", &x);
    fflush(stdin);
    q = Find(t, x);
    Compare(p, q, root);

    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
        if(t->lift != NULL){
            t->lift->parent = t;
            t->lift->brother = t->right;
        }
        if(t->right != NULL){
            t->right->parent = t;
            t->right->brother = NULL;
        }
    }
    return t;
}

BiT * Find(BiT * t, char x){
    BiT * root = t;
    t = run(t);
    do{      
        if(t->date == x) return t;
        if(t->brother != NULL){
            t = t->brother;
            t = run(t);
        }
        else t = t->parent;
    }while(t != root);
    if(t->date == x) return t;
}

BiT * run(BiT * t){
    while(t->lift != NULL || t->right != NULL){
        if(t->lift != NULL) t = t->lift;
        else if(t->right != NULL) t = t->right;
    }
    return t;
}

void Compare(BiT * p, BiT * q, BiT * root){
    BiT * pc = p;
    while(pc->date != q->date){
        pc = pc->parent;
        if(pc == q && q == root) break;
        if(pc == root){
            pc = p;
            q = q->parent;
        }
    }
    printf("p和q共同祖先：%c", q->date);
}
*/
/*
6.49
    编写算法判定给定二叉树是否为完全二叉树
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char date;
    struct BiTNode * lift;
    struct BiTNode * right;
    struct BiTNode * parent;
    struct BiTNode * brother;
}   BiT;

BiT * CreateBiTree(BiT *);
int run(BiT *);
void judge(BiT *);

int main(){
    BiT * t;
    t = CreateBiTree(t);
    judge(t);
    return 0;
}

BiT * CreateBiTree(BiT * t){
    char ch;
    printf("根：");
    scanf("%c", &ch);
    fflush(stdin);
    if(ch == 32) {
        t = NULL;
    }
    else{
        t = (BiT *)malloc(sizeof(BiT));
        t->date = ch;
        printf("进入左");
        t->lift = CreateBiTree(t->lift);
        printf("进入右");
        t->right = CreateBiTree(t->right);
        if(t->lift != NULL){
            t->lift->parent = t;
            t->lift->brother = t->right;
        }
        if(t->right != NULL){
            t->right->parent = t;
            t->right->brother = NULL;
        }
    }
    return t;
}

int run(BiT * t){
    int cnt = 1;
    while(t->lift != NULL){
        t = t->lift;
        cnt++;
    }
    return cnt;
}

void judge(BiT * t){
    int cnt = run(t);
    
}
*/
/*
6.50
    假设以三元组（F,C,L/R）的形式输入一颗二叉树的诸边（其中 F 表示双亲结点的标识， C 表示孩子结点标识，
    L/R 表示 C 为 F 的左孩子还是右孩子），且在输入的三元组序列中，C 是按层次顺序出现的。
    设结点的标识是字符类型。F = ‘^’ 时 C 为根节点标识，若 C 也为‘^’，则表示输入结束。
*/


#include <stdio.h>
int main(){
    printf("Hello World!");

    return 0;
}
