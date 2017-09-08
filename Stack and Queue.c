/*
2017.8.5
简单的压栈、出栈
*/
/*
#define STACK_INIT_SIZE  10
#define STACKINCREMENT 10
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int * base;
    int top;
    int stacksize;
} SqStack;

void InitStack(SqStack *);
void Push(SqStack *);
int Pop(SqStack *);

int main()
{
    int select;
    SqStack * s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    while(scanf("%d", &select)){
        switch(select){
            case 1:
                printf("压栈\n");
                Push(s);
                break;
            case 2:
                printf("出栈\n");
                printf("出栈元素为：%d\n", Pop(s));
                break;
        }
    }

    return 0;
}

void InitStack(SqStack * s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    s->top = 0;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack * s){
    int e;
    printf("输入要插入的元素： ");
    scanf("%d", &e);
    if(s->top >= s->stacksize){
        s->base = (int *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(int));
        s->top = s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    s->base[s->top++] = e;
}

int Pop(SqStack * s){
    int e;
    if(s->top == 0) return -1;
    e = s->base[--s->top];

    return e;
}

*/

/*
2017.8.5
数制转换
*/

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack{
    int * base;
    int top;
    int stacksize;
}   SqStack;

void InitStack(SqStack *);
void Push(SqStack *, int n);
void Pop(SqStack *);
void Translation(SqStack *, int, int);

int main(){
    int n;  // 源数字
    int c;  // 源数字进制
    int b;  // 暂存数字
    int d = 0;  // 转换完成的十进制数字
    int r = 0;  //位权
    SqStack * s;
    s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    printf("输入源数字进制： ");
    scanf("%d", &c);
    printf("输入数字： ");
    scanf("%d", &n);
    if(c != 10){
        while(n){
            b = n%10;
            d += b * pow(c, r);
            r++;
            n /= 10;
        }
        printf("十进制： %d\n", d);
    }
    else d = n;
    Translation(s, d, c);
    return 0;
}

void Translation(SqStack * s, int n, int c){
    int z;
    z = n;
    if(c != 8){
        while(n){
            Push(s, n%8);
            n = n/8;
        }
        printf("八进制： ");
        while(s->top){
            Pop(s);
        }
        printf("\n");
    }
    n = z;
    if(c != 2){
        while(n){
            Push(s, n%2);
            n = n/2;
        }
        printf("二进制： ");
        while(s->top){
            Pop(s);
        }
        printf("\n");
    }
    n = z;
    if(c != 16){
        while(n){
            Push(s, n%16);
            n = n/16;
        }
        printf("十六进制： ");
        while(s->top){
            Pop(s);
        }
        printf("\n");
    }
}

void InitStack(SqStack * s){
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    s->top = 0;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack * s, int n){
    if(s->top >= s->stacksize){
        s->base = (int *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(int));
        s->top = s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    s->base[s->top++] = n;
}

void Pop(SqStack * s){
    if(s->base[s->top-1] >= 10){
        switch(s->base[--s->top]){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
        }
    }
    else printf("%d", s->base[--s->top]);
}


/*
2017.8.5
判断括号是否正确
*/
/*
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * base;
    int top;
    int stacksize;
}   SqStack;

void InitStack(SqStack *);
void Compare(SqStack *);

int main(){
    SqStack * s;
    s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    printf("输入括号： ");
    while((s->base[s->top++]  = getchar()) != '\n'){
        Compare(s);
    }
    s->top--;
    if(s->top == 0) printf("ture");
    else printf("false");
    return 0;
}

void InitStack(SqStack * s){
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    s->top = 0;
    s->stacksize = STACK_INIT_SIZE;
}

void Compare(SqStack * s){
    if(s->top >= 2){
        if(s->base[s->top-1] == ')' && s->base[s->top-2] == '(' || s->base[s->top-1] == ']' && s->base[s->top-2] == '[')
            s->top -= 2;
    }
}
*/

/*
2017.8.5
行编辑程序
*/
/*
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * base;
    int top;
    int stacksize;
}   SqStack;

void InitStack(SqStack *);
void Compare(SqStack *);
void Pop(SqStack *);

int main(){
    SqStack * s;
    s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    while((s->base[s->top++] = getchar()) != '\n'){
        Compare(s);
    }
    s->top--;
    Pop(s);
    return 0;
}

void InitStack(SqStack * s){
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    s->top = 0;
    s->stacksize = STACK_INIT_SIZE;
}

void Compare(SqStack * s){
    if(s->top != 0 && s->base[s->top-1] == '#') s->top--;
    if(s->base[s->top-1] == '@') s->top = 0;
}

void Pop(SqStack * s){
    while(s->top){
        printf("%c", s->base[--s->top]);
    }
}
*/

/*
表达式计算
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct OPTR{
    char * base;
    int top;
}   OptrStack;

typedef struct OPND{
    int * base;
    int top;
}   OpndStack;

void InitStackT(OptrStack *);
void InitStackN(OpndStack *);
void PushT(OptrStack *, char);
void PushN(OpndStack *, int);
char PopT(OptrStack *);
int PopN(OpndStack *);

int main(){
    char ch;
    OptrStack * t;
    OpndStack * n;
    t = (OptrStack *)malloc(sizeof(OptrStack));
    n = (OpndStack *)malloc(sizeof(OpndStack));
    InitStackT(t);
    InitStackN(n);
    while((ch = getche()) != '='){
        if(ch >= 48 && ch <= 57) PushN(n, ch-48);
        else PushT(t, ch);
    }
    return 0;
}

void InitStackT(OptrStack * t){
    t->base = (char *)malloc(10 * sizeof(char));
    t->top = 0;
}

void InitStackN(OpndStack * n){
    n->base = (int *)malloc(10 * sizeof(int));
    n->top = 0;
}

void PushT(OptrStack * t, char ch){
    t->base[t->top++] = ch;
}

void PushN(OpndStack * n, int ch){
    n->base[n->top++] = ch;
}

char PopT(OptrStack * t){
    return t->base[--t->top];
}

int PopN(OpndStack * n){
    return n->base[--n->top];
}
*/

/*
3.15
    假设以顺序存储结构实现一个双向栈，即在一维数组的存储空间中存在着两个栈，它们的栈底分别设在数组的两个端点。
    试编写实现这个双向栈tws的三个操作：初始化initstack(tws)、入栈push(tws, i, x)和出栈pop(tws, i)的算法，
    其中i为0或1，用以分别指示设在数组两端的两个栈，并讨论按过程（正/误状态变量可设为变参）或函数设计这些操作算法各有什么优缺点。
*/
/*
#define STACKINCREMENT 10

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * stack;
    int front;
    int behind;
}   Tws;

void InitStack(Tws *);
void Push(Tws *);
int Pop(Tws *);


int main(){
    Tws * s;
    int sele;
    s = (Tws *)malloc(STACKINCREMENT * sizeof(Tws));
    InitStack(s);
    printf("0：压栈\n1：出栈\n");
    while(scanf("%d", &sele)){
        switch(sele){
            case 0:
                fflush(stdin);
                Push(s);
                printf("0：压栈\n1：出栈\n");
                break;
            case 1:
                fflush(stdin);
                printf("%d\n", Pop(s));
                printf("0：压栈\n1：出栈\n");
                break;
            default:
                printf("0：压栈\n1：出栈\n");
        }
    }
    return 0;
}

void InitStack(Tws * s){
    s->stack = (int *)malloc(STACKINCREMENT * sizeof(int));
    s->front = 0;
    s->behind = STACKINCREMENT;
}

void Push(Tws * s){
    int sele;
    int e;
    if(s->behind == s->front){
        printf("栈满");
        return;
    }
    printf("有 0 | 1 两栈\n");
    printf("输入栈号： ");
    scanf("%d", &sele);
    fflush(stdin);
    printf("输入数据： ");
    scanf("%d", &e);
    switch(sele){
        case 0:
            s->stack[s->front++] = e;
            printf("栈0：%d个元素\n", s->front);
            break;
        case 1:
            s->stack[--s->behind] = e;
            printf("栈1：%d个元素\n", STACKINCREMENT - s->behind);
            break;
        default:
            printf("栈号输入错误！\n");
    }
}

int Pop(Tws * s){
    int sele;
    printf("有 0 | 1 两栈\n");
    printf("输入栈号： ");
    scanf("%d", &sele);
    switch(sele){
        case 0:
            if(s->front == 0){
                printf("空栈，返回-1\n");
                return -1;
            }
            return s->stack[--s->front];
        case 1:
            if(s->behind == STACKINCREMENT){
                printf("空栈，返回-1\n");
                return -1;
            }
            return s->stack[s->behind++];
        default:
            printf("栈号输入错误！");
    }
}
*/

/*
3.17
    试写一算法，识别依次读入的一个以@为结束符的字符序列是否为形如 ‘序列1 & 序列2’ 模式的序列。
    其中 序列1 和 序列2 中都不含字符 ‘&’ ，且 序列2 是 序列1 的逆序列。
    例如 ‘a+b & b+a’ 是属该模式的字符序列，而 ‘1+3 & 3-1’ 则不是。  
*/
/*
#define STACKINCREMENT 10

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char * stack;
    int top;
}   SqStack;

void InitStack(SqStack *);
void Push(SqStack *, char);
char Pop(SqStack *);

int main(){
    SqStack * s1;
    char s2[STACKINCREMENT];
    char ch;
    int i = 0;
    s1 = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s1);
    printf("输入字符串1： ");
    while((ch = getchar()) != '\n'){
        Push(s1, ch);
    }
    printf("输入字符串2： ");
    scanf("%s", &s2);
    while(s1->top){
        if(Pop(s1) != s2[i++]){
            printf("false");
            break;
        }
    }
    if(!s1->top) printf("true");

    return 0;
}

void InitStack(SqStack * s){
    s->stack = (char *)malloc(STACKINCREMENT * sizeof(char));
    s->top = 0;
}

void Push(SqStack * s, char ch){
    s->stack[s->top++] = ch;
}

char Pop(SqStack * s){
    return s->stack[--s->top];
}
*/

/*
3.21
    假设表达式由单字母变量和双目四则运算算符构成。
    试写一算法，将一个通常书写形式且书写正确的表达式转换为逆波兰式。
*/
/*
#define STACKSIZE 20

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char * stack;
    int top;
}   SqStack;

void InitStack(SqStack *);
void Push(SqStack *, char);
char Pop(SqStack *);
void Compare(SqStack *, SqStack *, char);
void Del(int *);

int main(){

    int i = 0;
    int j = 0;
    int flag = 0;
    char Expression[20];
    SqStack * Poland_c;
    SqStack * ReversPoland;

    Poland_c = (SqStack *)malloc(sizeof(SqStack));
    ReversPoland = (SqStack *)malloc(sizeof(SqStack));

    InitStack(Poland_c);
    InitStack(ReversPoland);

    printf("输入表达式： ");
    scanf("%s", &Expression);
    
    while(Expression[i] != '\0'){
        if(Expression[i] >= 48 && Expression[i] <= 57) Push(ReversPoland, Expression[i]);
        else Compare(Poland_c, ReversPoland, Expression[i]);
        i++;
    }
    while(Poland_c->top){
        Push(ReversPoland, Pop(Poland_c));
    }
    while(j < ReversPoland->top){
        printf("%c ", ReversPoland->stack[j++]);
    }
    printf("\n");
    for(j = -1, i = 0; i < ReversPoland->top; i++){
        if(ReversPoland->stack[i] == '+'){
            if(j == -1) j = i-2;
            if(ReversPoland->stack[i-1] >= 48 && ReversPoland->stack[i-1] <= 57){
                if(!flag) ReversPoland->stack[j] -= 48;
                ReversPoland->stack[i-1] -= 48;
                ReversPoland->stack[j] += ReversPoland->stack[i-1];
            }
            else{
                if(j != -1) j--;
                ReversPoland->stack[j] -= 48;
                ReversPoland->stack[j] += ReversPoland->stack[j+1];
            }
            flag++;
        }
        if(ReversPoland->stack[i] == '-'){
            if(j == -1) j = i-2;
            if(ReversPoland->stack[i-1] >= 48 && ReversPoland->stack[i-1] <= 57){
                if(!flag) ReversPoland->stack[j] -= 48;
                ReversPoland->stack[i-1] -= 48;
                ReversPoland->stack[j] -= ReversPoland->stack[i-1];
            }
            else{
                if(j != -1) j--;
                ReversPoland->stack[j] -= 48;
                ReversPoland->stack[j] -= ReversPoland->stack[j+1];
            }
            flag++;
        }
        if(ReversPoland->stack[i] == '*'){
            if(j == -1) j = i-2;
            if(ReversPoland->stack[i-1] >= 48 && ReversPoland->stack[i-1] <= 57){
                if(!flag) ReversPoland->stack[j] -= 48;
                ReversPoland->stack[i-1] -= 48;
                ReversPoland->stack[j] *= ReversPoland->stack[i-1];
            }
            else{
                if(j != -1) j--;
                ReversPoland->stack[j] -= 48;
                ReversPoland->stack[j] *= ReversPoland->stack[j+1];
            }
            flag++;
        }
        if(ReversPoland->stack[i] == '/'){
            if(j == -1) j = i-2;
            if(ReversPoland->stack[i-1] >= 48 && ReversPoland->stack[i-1] <= 57){
                if(!flag) ReversPoland->stack[j] -= 48;
                ReversPoland->stack[i-1] -= 48;
                ReversPoland->stack[j] /= ReversPoland->stack[i-1];
            }
            else{
                if(j != -1) j--;
                ReversPoland->stack[j] -= 48;
                ReversPoland->stack[j] /= ReversPoland->stack[j+1];
            }
            flag++;
        }
    }
    printf("%d", ReversPoland->stack[0]);

    return 0;
}


void InitStack(SqStack * s){
    s->stack = (char *)malloc(STACKSIZE * sizeof(char));
    s->top = 0;
}

void Push(SqStack * s, char ch){
    s->stack[s->top++] = ch;
}

char Pop(SqStack * s){
    return s->stack[--s->top];
}

void Compare(SqStack * s, SqStack * p, char ch){    //s符号暂存，p后缀表达式
    if(s->top == 0) Push(s, ch);
    else{
        if(ch == '('){
            Push(s, ch);
            return;
        }
        if(ch == ')'){
            while(s->stack[s->top-1] != '('){
                Push(p, Pop(s));
            }
            s->top--;
            return;
        }
        if(ch == '-' || ch == '+'){
            while(s->stack[s->top-1] != '(' && s->top != 0){
                Push(p, Pop(s));
            }
            Push(s, ch);
            return;
        }
        if(ch == '*' || ch == '/'){
            while(s->stack[s->top-1] == '*' || s->stack[s->top-1] == '/'){
                Push(p, Pop(s));
            }
            Push(s, ch);
        }
    } 
}
*/

/*
3.28
    假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针）
    试编写相应的队列初始化、入队列和出队列的算法。
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
    int date;
    struct QNode * next;
}   Node;

struct Queue{
    Node * head;
    Node * tail;
    Node * EnLocation;
    Node * Delocation;
    int lenth;
    int number;
}   * s;

void InitQueue(struct Queue *);
void EnQueue(struct Queue *);
int DeQueue(struct Queue *);

int main(){
    int sele;
    s = (struct Queue *)malloc(sizeof(struct Queue));
    InitQueue(s);
    printf("0：入队 | 1：出队\n");
    while(scanf("%d", &sele)){
        switch(sele){
            case 0:
                EnQueue(s);
                break;
            case 1:
                printf("%d\n", DeQueue(s));
                break;
        }
        printf("0：入队 | 1：出队\n");
    }

    return 0;
}

void InitQueue(struct Queue * s){
    Node * front;
    Node * behind;
    int i;
    s->head = (Node *)malloc(sizeof(Node));
    s->tail = (Node *)malloc(sizeof(Node));
    s->EnLocation = s->head;
    s->Delocation = s->head;
    printf("输入循环链表长度： ");
    scanf("%d", &s->lenth);
    s->number = 0;
    front = s->head;
    front->date = -1;
    for(i = 1; i < s->lenth; i++){
        behind = (Node *)malloc(sizeof(Node));
        behind->date = -1;
        front->next = behind;
        front = front->next;
    }
}

void EnQueue(struct Queue * s){
    if(s->number == s->lenth){
        printf("循环队列已满\n");
        return;
    }
    printf("输入元素： ");
    scanf("%d", &s->EnLocation->date);
    s->EnLocation = s->EnLocation->next;
    s->number++;
    if(s->Delocation != s->head && s->EnLocation == s->tail){
        s->EnLocation = s->head;
    }
}

int DeQueue(struct Queue * s){
    int re;
    if(s->number == 0){
        printf("循环队列为空，返回 -1\n");
        s->Delocation = s->head;
        return -1;
    }
    re = s->Delocation->date;
    s->number--;
    if(s->Delocation == s->tail){
        s->Delocation = s->head;
        return re;
    }
    else{
        s->Delocation = s->Delocation->next;
        return re;
    }   
}
*/

/*
3.32
    试利用循环队列编写求K阶斐波那契序列中前 n+1 项的算法
    要求满足：fn <= max 而 f(n+1) > max，其中max为某个约定的常数。
    注意：本题所用循环队列的容量仅为k，则在算法执行结束时，留在循环队列中的元素应是所求 k 阶斐波那契序列中的最后 k 项。
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * date;
    int flag;
    int k;
    int Location;
}   Queue;

void InitQueue(Queue *);
int Calc(Queue *, int);

int main(){
    int max;
    Queue * s;
    s = (Queue *)malloc(sizeof(Queue));
    InitQueue(s);
    printf("输入max： ");
    scanf("%d", &max);
    printf("%d", Calc(s, max));

    return 0;
}

void InitQueue(Queue * s){
    printf("输入阶数： ");
    scanf("%d", &s->k);
    s->date = (int *)malloc(s->k * sizeof(int));
    s->flag = 0;
    s->Location = 0;
}

int Calc(Queue * s, int max){
    int j, c = 0;
    while(s->Location < s->k-1){
        s->date[s->Location++] = 0;
    }
    s->date[s->Location] = 1;
    s->Location++;
    while(c <= max){
        if(s->Location == s->k) s->Location = 0;
        c = 0;
        for(j = 0; j < s->k; j++){
            c += s->date[j];
        }
        s->date[s->Location] = c;
        s->Location++;
    }
    return s->date[--s->Location];
}
*/
