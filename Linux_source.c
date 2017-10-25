/*
#include <stdio.h>
#include <stdlib.h>

void prt(int);

int main(){
    int n;
    scanf("%d", &n);
    prt(n);

    return 0;
}

void prt(int n){
    int i;
    for(i = 0; i < n; i++){
        if(i == n-1)
            printf("傻逼抽煙");
        else   
            printf("傻逼說");
    }
    printf("\n");
}
*/

/*
2017.10.14
1. 采用顺序存储实现栈的初始化、入栈、出栈操作。
2. 采用链式存储实现栈的初始化、入栈、出栈操作。
3. 写一个程序，将输入的十进制数据M转换为八进制数据M8，将其调试通过。
在其基础上修改程序，实现十进制数据M想N进制（二、八或十六进制）的转换。
    （1）采用顺序存储结构实现栈。
    （2）采用链表结构实现栈。
4. 将教材3-19转换得到的后缀表达式，利用顺序栈求表达式的值。
*/
/*
#include <stdio.h>

int main(){
    int choose; //用于循环中switch选择
    printf("1----Creat a sequence stack\n2----Creat a link stack\n3----Transform number\n4----Expression calculator\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                if(choose < 1 || choose > 4)
                    printf("Please input true number!\n");
        }
        printf("1----Creat a sequence stack\n2----Creat a link stack\n3----Transform number\n4----Expression calculator\n");
    }


    return 0;
}
*/

//1
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
    int choose;
    SqStack * s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    printf("1----Push element\n2----Pop element\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                Push(s);
                break;
            case 2:
                printf("Pop elements is ：%d\n", Pop(s));
                break;
        }
        printf("1----Push element\n2----Pop element\n");
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
    printf("Enter the element you want to inset： ");
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
    if(s->top == 0){
        printf("Empty stack!\nThe program will return -1!\n");
        return -1;
    }
    e = s->base[--s->top];

    return e;
}
*/

//2
/*
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode * next;
}LNode;

typedef struct LinkStack{
    struct LinkNode * front;
    struct LinkNode * rear;
}LStack;

void InitStack(LStack **);
void Push(LStack *);
ElemType Pop(LStack *);

int main(){
    LStack * s;
    int choose;

    InitStack(&s);
    printf("1----Push element\n2----Pop element\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                Push(s);
                break;
            case 2:
                printf("Pop elements is ：%d\n", Pop(s));
                break;
        }
        printf("1----Push element\n2----Pop element\n");
    }
    return 0;
}

void InitStack(LStack ** s){
    *s = (LStack *)malloc(sizeof(LStack)); 
}

void Push(LStack * s){
    LNode * p;
    
    p = (LNode *)malloc(sizeof(LNode));
    printf("Enter the element you want to insert:");
    scanf("%d", &p->data);
    p->next = NULL;
    if(s->front == NULL){
        s->front = s->rear = p;
        printf("Success!\n");
        return;
    }
    p->next = s->front;
    s->front = p;
    printf("Success!\n");
}

ElemType Pop(LStack * s){
    ElemType e;
    LNode * p;
    if(s->front == NULL){
        printf("Empty stack!\nThe program will return -1!\n");
        return -1;
    }
    e = s->front->data;
    p = s->front;
    if(s->front == s->rear){
        s->rear = NULL;
    }
    s->front = s->front->next;
    free(p);

    return e;
}
*/

//3
/*
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
    if(c >= 10){
        printf("Error, because i am lazy!\n");
        return 0;
    }
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
*/

//4
/*
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct{
    char optr[MAXSIZE];
    int top;
}OPTR;

typedef struct{
    int opnd[MAXSIZE];
    int top;
}OPND;

void InitStackTR(OPTR **);  //新建字符栈
void InitStackND(OPND **);  //新建数字栈
void PushTR(OPTR *, char);  //字符压栈
void PushND(OPND *, int);   //数字压栈
char PopTR(OPTR *); //字符出栈
int PopND(OPND *);  //数字出栈
char GetTop(OPTR *);    //区栈顶元素
char Precede(char, char);   //判断运算符优先级
int Operate(int, char, int);    //计算

int main(){
    int i = 0;  
    int count = 0;  //多位数字计算
    int mul = 1;    //辅助多位数字计算
    int a, b;   //暂存运算符两边运算数
    char theta; //暂存运算符
    char expression[100];
    OPTR * tr;
    OPND * nd;
    InitStackTR(&tr);
    InitStackND(&nd);
    printf("Enter the expression you want to calculation: ");
    for(i = 0; i < 100; i++){
        scanf("%c", &expression[i]);
        if(expression[i] == '=')
            break;
    }
    for(i = 0; expression[i] != '='; i++){
        if(expression[i] >= 48 && expression[i] <= 57){ //判断是否为数字
            count = count + (expression[i]-48)*mul;
            if(expression[i+1] >= 48 && expression[i+1] <= 57){
                mul = mul*10;
            }
            else{
                PushND(nd, count);
                count = 0;
                mul = 1;
            }
        }
        else{
            switch(Precede(GetTop(tr), expression[i])){
                case '<':    //栈顶元素优先级低
                    PushTR(tr, expression[i]);
                    break;
                case '=':    //脱括号并接受下一个字符
                    PopTR(tr);
                    break;
                case '>':
                    theta = PopTR(tr);
                    a = PopND(nd);
                    b = PopND(nd);
                    PushND(nd, Operate(a, theta, b));
                    break;
            }
        }
    }
    printf("%d\n", PopND(nd));
    return 0;
}

void InitStackTR(OPTR ** s){
    (*s) = (OPTR *)malloc(sizeof(OPTR));
    (*s)->top = 0;
}

void InitStackND(OPND ** s){
    (*s) = (OPND *)malloc(sizeof(OPND));
    (*s)->top = 0;
}

void PushTR(OPTR * s, char c){
    s->optr[s->top++] = c;
}
void PushND(OPND * s, int c){
    s->opnd[s->top++] = c;
}

char PopTR(OPTR * s){
    return s->optr[--s->top];
}
int PopND(OPND * s){
    return s->opnd[--s->top];
}

char GetTop(OPTR * s){
    return s->optr[s->top-1];
}

char Precede(char c1, char c2){
    int i, j;
    char JudgeC[6] = {'#', '(', '+', '-', '*', '/'};
    int JudgeN[6] = {-1, 0, 1, 1, 2, 2};
    for(i = 0; i < 6; i++){
        if(c1 == JudgeC[i])
            break;
    }
    for(j = 0; j < 6; j++){
        if(c2 == JudgeC[j])
            break;
    }
    if(c1 == '(' && c2 == ')')
        return '=';
    if(i < j)
        return '<';
    if(i >= j)
        return '>'; 
}

int Operate(int a, char c, int b){
    if(c == '+')
        a = a+b;
    if(c == '-')
        a = a-b;
    if(c == '*')
        a = a*b;
    if(c == '/')
        a = a/b;
    return a;
}
*/

/*
2017.10.15
1. 采用顺序存储实现循环队列的初始化、入队、出队操作。
2. 采用链式存储实现队列的初始化、入队、出队操作。
3. 编写一个程序，使用两个连队q1和q2，用来分别存储由计算机随机产生的20个100以内的奇数和偶数，然后每行输出q1和q2的一个值，即奇数和偶数配对
   输出，直到任一队列为空为止。
*/

//1
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 30

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue **);
void EnQueue(SqQueue *, ElemType);
ElemType DeQueue(SqQueue *);

int main(){
    int choose;
    int e;
    int i = 0, j = 0;
    SqQueue * q1, * q2;
    InitQueue(&q1);
    InitQueue(&q2);

    // printf("1----EnQueue\n2----DeQueue\n");
    // while(scanf("%d", &choose)){
    //     switch(choose){
    //         case 1:
    //             EnQueue(q);
    //             break;
    //         case 2:
    //             printf("DeQueue element is ：%d\n",DeQueue(q));
    //             break;
    //     }
    //     printf("1----EnQueue\n2----DeQueue\n");
    // }
    srand((unsigned)time(NULL));
    while(1){
        e = rand()%100;
        if(e % 2 == 1){
            EnQueue(q1, e);
            i++;
        }
        else{
            EnQueue(q2, e);
            j++;
        }
        if(i >= 20 && j >= 21)
            break;
    }
    
    // while(i < 20){
    //     e = rand()%100;
    //     if(e % 2 == 0){
    //         EnQueue(q2, e);
    //         i++;
    //     }
    // }

    for(i = 0; i < 20; i++){
        printf("%d:\t%d\t%d\n", i+1, DeQueue(q1), DeQueue(q2));
    }


    return 0;
}

void InitQueue(SqQueue ** q){
    (*q) = (SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front = 0;
    (*q)->rear = 0;
}

void EnQueue(SqQueue * q, ElemType e){
    if( (q->rear + 1) % MAXSIZE == q->front ){      //队满条件
        //printf("The queue is full!\n");
        return;
    }
    // printf("Enter the element you want to enqueue: ");
    // scanf("%d", &e);
    q->data[q->rear] = e;
    q->rear = (q->rear + 1)%MAXSIZE;
}

ElemType DeQueue(SqQueue * q){
    ElemType e;
    if(q->front == q->rear){    //队空条件
        printf("The queue is empty!\nThe function will return 0!\n");  
        return 0;
    }
    e = q->data[q->front];
    q->front = (q->front + 1)%MAXSIZE;
    return e;
}
*/

//2
/*
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QNode{
    ElemType data;
    struct QNode * next;
}QNode;

typedef struct Queue{
    struct QNode * front;
    struct QNode * rear;
}Queue;

void InitQueue(Queue **);
void EnQueue(Queue *);
ElemType DeQueue(Queue *);

int main(){
    int choose;
    Queue * q;
    InitQueue(&q);

    printf("1----EnQueue\n2----DeQueue\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                EnQueue(q);
                break;
            case 2:
                printf("DeQueue element is ：%d\n",DeQueue(q));
                break;
        }
        printf("1----EnQueue\n2----DeQueue\n");
    }
    return 0;
}

void InitQueue(Queue ** q){
    (*q) = (Queue *)malloc(sizeof(Queue));
    (*q)->front = (*q)->rear = NULL;
}

void EnQueue(Queue * q){
    QNode * p;
    if(q->rear == NULL){
        q->front = q->rear = (QNode *)malloc(sizeof(QNode));
        printf("Enter the element you want to enqueue: ");
        scanf("%d", &q->rear->data);
        return;
    }
    p = (QNode *)malloc(sizeof(QNode));
    printf("Enter the element you want to enqueue: ");
    scanf("%d", &p->data);
    q->rear->next = p;
    q->rear = q->rear->next;
}

ElemType DeQueue(Queue * q){
    QNode * p;
    ElemType e;
    if(q->front == NULL){
        printf("The queue is empty!\nThe function will return -1!\n");
        return -1;
    }
    e = q->front->data;
    p = q->front;
    q->front = q->front->next;
    free(p);
    return e;
}
*/

//3
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct QNode{   //节点结构体
    ElemType data;
    struct QNode * next;
}QNode;

typedef struct Queue{   //链队结构体
    struct QNode * front;
    struct QNode * rear;
}Queue;

void InitQueue(Queue **);   //初始化链队
void EnQueue(Queue *, int); //入队
ElemType DeQueue(Queue *);  //出队

int main(){
    //int choose;
    int judge;  //判断应该随机奇数还是偶数, 0为偶数， 1为奇数
    int i;  //循环计数
    Queue * q1, * q2;   //两个链队
    InitQueue(&q1);
    InitQueue(&q2);
    for(i = 0; i < 20; i++){
        EnQueue(q1, 0);
        EnQueue(q2, 1);
    }
    for(i = 0; i < 20; i++){
        printf("%d:\t%d\t%d\n", i+1, DeQueue(q1), DeQueue(q2));
    }
}

void InitQueue(Queue ** q){
    (*q) = (Queue *)malloc(sizeof(Queue));
    (*q)->front = (*q)->rear = NULL;
}

void EnQueue(Queue * q, int judge){
    QNode * p;
    ElemType e;
    if(q->front == NULL){   //假如不是头结点，那么就新建第一个节点
        q->front = q->rear = (QNode *)malloc(sizeof(QNode));
        srand((unsigned)time(NULL));
        if(judge == 0){     //偶数
            e = rand()%100;
            if(e % 2 == 1)
                e++;
        }
        if(judge == 1){     //奇数
            e = rand()%100;
            if(e % 2 == 0)
                e++;
        }
        q->rear->data = e;
        return;
    }
    p = (QNode *)malloc(sizeof(QNode)); //此处是第二个节点之后的节点
    if(judge == 0){     //偶数
        e = rand()%100;
        if(e % 2 == 1)
            e++;
    }
    if(judge == 1){     //奇数
        e = rand()%100;
        if(e % 2 == 0)
            e++;
    }
    p->data = e;
    q->rear->next = p;
    q->rear = q->rear->next;
    q->rear->next = NULL;
}

ElemType DeQueue(Queue * q){
    QNode * p;
    ElemType e;
    if(q->front == NULL){   //提示是空队
        printf("The queue is empty!\nThe function will return -1!\n");
        return -1;
    }
    e = q->front->data;
    p = q->front;
    q->front = q->front->next;
    free(p);
    return e;
}
*/

//数据结构（C语言描述） P71 - 三 - 1
/*
#define STACK_INIT_SIZE  10
#define STACKINCREMENT 10
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct Stack{
    ElemType * base;
    int top;
    int stacksize;
} SqStack;

void InitStack(SqStack *);
void Push(SqStack *, ElemType);
ElemType Pop(SqStack *);

int main()
{
    ElemType c;
    SqStack * s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    while((c = getchar()) != '@'){
        if(s->top == 0){
            Push(s, c);
            continue;
        }
        if(s->base[s->top-1] == c){
            Pop(s);
            continue;
        }
        Push(s, c);
    }
    if(s->top == 0){
        printf("Yes!\n");
    }
    else{
        printf("No!\n");
    }
    return 0;
}

void InitStack(SqStack * s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    s->top = 0;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack * s, ElemType e){
    if(s->top >= s->stacksize){
        s->base = (ElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
        s->top = s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    s->base[s->top++] = e;
}

ElemType Pop(SqStack * s){
    ElemType e;
    // if(s->top == 0){
    //     printf("Empty stack!\nThe program will return -1!\n");
    //     return -1;
    // }
    e = s->base[--s->top];

    return e;
}
*/

//数据结构（C语言描述） P71 - 三 - 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 5

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue **);
void EnQueue(SqQueue *);
// void EnQueue(SqQueue *, ElemType);
ElemType DeQueue(SqQueue *);

int main(){
    int choose;
    int e;
    int i = 0, j = 0;
    SqQueue * q;
    // SqQueue * q1, * q2;
    InitQueue(&q);
    // InitQueue(&q1);
    // InitQueue(&q2);

    printf("1----EnQueue\n2----DeQueue\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                EnQueue(q);
                break;
            case 2:
                printf("DeQueue element is ：%d\n",DeQueue(q));
                break;
        }
        printf("1----EnQueue\n2----DeQueue\n");
    }
    // srand((unsigned)time(NULL));
    // while(1){
    //     e = rand()%100;
    //     if(e % 2 == 1){
    //         EnQueue(q1, e);
    //         i++;
    //     }
    //     else{
    //         EnQueue(q2, e);
    //         j++;
    //     }
    //     if(i >= 20 && j >= 21)
    //         break;
    // }
    
    // while(i < 20){
    //     e = rand()%100;
    //     if(e % 2 == 0){
    //         EnQueue(q2, e);
    //         i++;
    //     }
    // }

    // for(i = 0; i < 20; i++){
    //     printf("%d:\t%d\t%d\n", i+1, DeQueue(q1), DeQueue(q2));
    // }


    return 0;
}

void InitQueue(SqQueue ** q){
    (*q) = (SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front = 0;
    (*q)->rear = 0;
}

void EnQueue(SqQueue * q){
    ElemType e;
    if( (q->rear + 1) % MAXSIZE == q->front ){      //队满条件
        printf("The queue is full!\n");
        return;
    }
    printf("Enter the element you want to enqueue: ");
    scanf("%d", &e);
    q->data[q->rear] = e;
    q->rear = (q->rear + 1)%MAXSIZE;
}

ElemType DeQueue(SqQueue * q){
    ElemType e;
    if(q->front == q->rear){    //队空条件
        printf("The queue is empty!\nThe function will return 0!\n");  
        return 0;
    }
    e = q->data[q->front];
    q->front = (q->front + 1)%MAXSIZE;
    return e;
}
*/

//数据结构（C语言描述） P71 - 三 - 3
/*
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct{
    char optr[MAXSIZE];
    int top;
}OPTR;

typedef struct{
    int opnd[MAXSIZE];
    int top;
}OPND;

void InitStackTR(OPTR **);  //新建字符栈
void InitStackND(OPND **);  //新建数字栈
void PushTR(OPTR *, char);  //字符压栈
void PushND(OPND *, int);   //数字压栈
char PopTR(OPTR *); //字符出栈
int PopND(OPND *);  //数字出栈
char GetTop(OPTR *);    //去栈顶元素
char Precede(char, char);   //判断运算符优先级
int Operate(int, char, int);    //计算

int main(){
    int i = 0;  
    int count = 0;  //多位数字计算
    int mul = 1;    //辅助多位数字计算
    int a, b;   //暂存运算符两边运算数
    char theta; //暂存运算符
    char expression[100];
    OPTR * tr;
    OPND * nd;
    InitStackTR(&tr);
    InitStackND(&nd);
    printf("Enter the expression you want to calculation: ");
    for(i = 0; i < 100; i++){
        scanf("%c", &expression[i]);
        if(expression[i] == '=')
            break;
    }
    //expression[i] = '\0';
    for(i = 0; expression[i] != '='; i++){
        if(expression[i] >= 48 && expression[i] <= 57){ //判断是否为数字
            count = count + (expression[i]-48)*mul;
            if(expression[i+1] >= 48 && expression[i+1] <= 57){
                mul = mul*10;
            }
            else{
                PushND(nd, count);
                count = 0;
                mul = 1;
            }
        }
        else{
            switch(Precede(GetTop(tr), expression[i])){
                case '<':    //栈顶元素优先级低
                    PushTR(tr, expression[i]);
                    break;
                case '=':    //脱括号并接受下一个字符
                    PopTR(tr);
                    break;
                case '>':
                    PushTR(tr, expression[i]);
                    theta = PopTR(tr);
                    a = PopND(nd);
                    b = PopND(nd);
                    PushND(nd, Operate(a, theta, b));
                    break;
            }
        }
    }
    theta = PopTR(tr);
    a = PopND(nd);
    b = PopND(nd);
    PushND(nd, Operate(a, theta, b));
    printf("%d\n", PopND(nd));
    return 0;
}

void InitStackTR(OPTR ** s){
    (*s) = (OPTR *)malloc(sizeof(OPTR));
    (*s)->top = 0;
}

void InitStackND(OPND ** s){
    (*s) = (OPND *)malloc(sizeof(OPND));
    (*s)->top = 0;
}

void PushTR(OPTR * s, char c){
    s->optr[s->top++] = c;
}
void PushND(OPND * s, int c){
    s->opnd[s->top++] = c;
}

char PopTR(OPTR * s){
    return s->optr[--s->top];
}
int PopND(OPND * s){
    return s->opnd[--s->top];
}

char GetTop(OPTR * s){
    if(s->top == 0) 
        return '#';
    return s->optr[s->top-1];
}

char Precede(char c1, char c2){
    int i, j;
    char JudgeC[6] = {'#', '(', '+', '-', '*', '/'};
    int JudgeN[6] = {-1, 0, 1, 1, 2, 2};
    for(i = 0; i < 6; i++){
        if(c1 == JudgeC[i])
            break;
    }
    for(j = 0; j < 6; j++){
        if(c2 == JudgeC[j])
            break;
    }
    if(c1 == '(' && c2 == ')')
        return '=';
    if(i >= j)
        return '>'; 
    else
        return '<';
    
}

int Operate(int a, char c, int b){
    if(c == '+')
        a = a+b;
    if(c == '-')
        a = a-b;
    if(c == '*')
        a = a*b;
    if(c == '/')
        a = a/b;
    return a;
}
*/


//数据结构（C语言描述） P71 - 三 - 4
/*
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, LinkList;

void InitCiQueue(LinkList **);
void EnCiQueue(LinkList **, ElemType);
int DeCiQueue(LinkList *, ElemType *);

int count = 0;
int main(){
    int choose;
    int f;
    ElemType e;
    LinkList * q;
    InitCiQueue(&q);
    printf("1--->Push\n2--->Pop\n");
    while(scanf("%d", &choose)){
        switch(choose){
            case 1:
                printf("Enter a number that you want to Push: ");
                scanf("%d", &e);
                EnCiQueue(&q, e);
                break;
            case 2:
                f = DeCiQueue(q, &e);
                if(f == 0){
                    printf("Queue is empty !\n");
                    break;
                }
                printf("Pop number is: %d\n", e);
                break;
            default:
                printf("Error !\n");
        }
        printf("1--->Push\n2--->Pop\n");
    }

    return 0;
}

void InitCiQueue(LinkList **q){
    (*q) = (LinkList *)malloc(sizeof(LNode));
    (*q)->next = (*q); 
    (*q)->data = 0;
}

void EnCiQueue(LinkList **q, ElemType e){
    LinkList * p;
    p = (LinkList *)malloc(sizeof(LNode));
    p->data = e;
    p->next = (*q)->next;
    (*q)->next = p;
    (*q) = p;
    count++;
}

int DeCiQueue(LinkList *q, ElemType *e){
    LinkList *p;
    if(count <= 0)
        return 0;
    p = q->next->next;
    *e = p->data;
    q->next->next = p->next;
    free(p);
    count--;
    return 1;
}
*/


//数据结构（C语言描述） P95 - 四 - 1
//(1)
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    char ch1, ch2;
    char ch[100];
    scanf("%s", ch);
    fflush(stdin);
    scanf("%c %c", &ch1, &ch2);
    while(ch[i] != '\0'){
        if(ch[i] == ch1){
            ch[i] = ch2;
        }
        i++;
    }
    printf("%s", ch);

    return 0;
}
*/

//(2)
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0, j = 0;
    char cache;
    char ch[100];

    scanf("%s", ch);
    while(ch[j] != '\0'){
        j++;
    }
    j--;
    while(i < j){
        cache = ch[i];
        ch[i] = ch[j];
        ch[j] = cache;
        i++, j--;
    }
    printf("%s", ch);
    return 0;
}
*/

//(3)
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k;
    char ch;
    char r[100];

    scanf("%s", r);
    fflush(stdin);
    scanf("%c", &ch);
    for(i = 0; r[i] != '\0'; i++){
        if(r[i] == ch){
            j = i+1;
            k = i;
            while(r[j] != '\0'){
                r[k] = r[j];
                k++, j++;
            }

r[k] = '\0';
        }
    }
    printf("%s", r);

    return 0;
}
*/

//数据结构（C语言描述） P95 - 四 - 2
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k;
    char ch[100];
    scanf("%s", ch);
    fflush(stdin);
    scanf("%d%d", &i, &j);
    i--;
    k = i+j;
    while(ch[k] != '\0'){
        ch[i] = ch[k];
        i++, k++;
    }
    ch[i] = '\0';
    printf("%s", ch);

    return 0;
}
*/

//数据结构（C语言描述） P95 - 四 - 3
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    int n = 0;
    int count = 0, mul = 1;
    int numbers[100];
    char ch[100];
    while((ch[i] = getchar()) != '\n'){
        i++;
    }
    ch[i] = '\0';
    while(i >= 0){
        if(ch[i] >= 48 && ch[i] <= 57){ //判断是否为数字
            count = count + (ch[i]-48)*mul;
            if(ch[i-1] >= 48 && ch[i-1] <= 57){
                mul = mul*10;
            }
            else{
                numbers[n] = count;
                n++;
                count = 0;
                mul = 1;
            }
        }
        i--;
    }
    for(i = 0; i < n; i++){
        printf("%d\n", numbers[i]);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

/*	//顺序栈 
typedef struct{
	ElemType elem[MAXSIZE];
	int top;
}Stack;
*/

typedef struct SNode{
	ElemType data;
	struct SNode *next;
}SNode;
typedef struct LinkStack{
	SNode *top;
}Stack;
/*	//顺序栈函数声明部分 
void InitStack(Stack **);	//初始化栈 
int Push(Stack *, ElemType);	//压栈 
int Pop(Stack *, ElemType *);	//出栈 
void Convert(Stack *);	//进制转换 
*/	//顺序栈函数声明结束

void InitStack(Stack *s);
void Push(Stack *, ElemType); 
int Pop(Stack *, ElemType *);
void Convert(Stack *);	//进制转换 

int main(){
	int choose; //菜单选择 
	int e;	//函数返回值 
	int f;	//判断函数是否正确执行 
	Stack s;
	InitStack(&s);
	printf("1----Push\n2----Pop\n3----Convert\n");
	while(scanf("%d", &choose)){
		switch(choose){
			case 1:
				scanf("%d", &e);
				Push(&s, e);	
				break;
			case 2:
				f = Pop(&s, &e);
				if(f == 1)	//判断函数是否执行正确 
					printf("Pop elemt is %d\n", e);
				else if(f == 0)
					printf("Error !\n");
				break;
			case 3:
				Convert(&s);
				break;
		}
		printf("1----Push\n2----Pop\n3----Convert\n");
	}
	return 0;
}
/* //顺序栈函数部分 
void InitStack(SqStack **s){
	(*s) = (Stack *)malloc(sizeof(Stack));
	(*s)->top = 0;
}

int Push(Stack *s, ElemType e){
	if(s->top >= MAXSIZE){	//判断栈是否满 
		printf("Stack is Full !\n");
		return 0;
	}
	s->elem[s->top++] = e;
	//printf("Success !\n");
	return 1;
}

int Pop(Stack *s, ElemType *e){
	if(s->top == 0){	//判断栈是否空 
		printf("Stack is empty !\n");
		return 0;
	}
	*e = s->elem[--s->top];
	//printf("Success !\n");
	return 1;
}

void Convert(Stack *s){
	int i, m, n;	//计数，源数字，需要转换的进制 
	int e;	//压栈使用的变量 
	printf("Enter a source decimal number: ");
	scanf("%d", &m);
	printf("Enter a end-on system number: ");
	scanf("%d", &n);
	while(m){	//计算并压栈 
		i = m%n;
		Push(s, i);
		m = m/n;
	}
	while(s->top != 0){	//出栈 
		Pop(s, &e);
		if(e == 10){
			printf("A");
			continue;
		}
		if(e == 11){
			printf("B");
			continue;
		}
		if(e == 12){
			printf("C");
			continue;
		}
		if(e == 13){
			printf("D");
			continue;
		}
		if(e == 14){
			printf("E");
			continue;
		}
		printf("%d", e);
	}
	printf("\n");
}
*/ //顺序栈函数结束部分 

void InitStack(Stack *s){
	s->top = NULL;
}
void Push(Stack *s, ElemType e){
	SNode *p;
	p = (SNode *)malloc(sizeof(SNode));
	p->data = e;
	if(s->top == NULL){
		p->next = NULL;
	}
	else{
		p->next = s->top;
	}
	s->top = p;
}

int Pop(Stack *s, ElemType *e){
	SNode *p;
	if(s->top == NULL) return 0;
	p = s->top;
	*e = p->data;
	s->top = s->top->next;
	free(p);
}

void Convert(Stack *s){
	int i, m, n;	//计数，源数字，需要转换的进制 
	int e;	//压栈使用的变量 
	printf("Enter a source decimal number: ");
	scanf("%d", &m);
	printf("Enter a end-on system number: ");
	scanf("%d", &n);
	while(m){	//计算并压栈 
		i = m%n;
		Push(s, i);
		m = m/n;
	}
	while(s->top != 0){	//出栈 
		Pop(s, &e);
		if(e == 10){
			printf("A");
			continue;
		}
		if(e == 11){
			printf("B");
			continue;
		}
		if(e == 12){
			printf("C");
			continue;
		}
		if(e == 13){
			printf("D");
			continue;
		}
		if(e == 14){
			printf("E");
			continue;
		}
		printf("%d", e);
	}
	printf("\n");
}
