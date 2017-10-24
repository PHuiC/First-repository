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
            printf("ɵ�Ƴ韟");
        else   
            printf("ɵ���f");
    }
    printf("\n");
}
*/

/*
2017.10.14
1. ����˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ������
2. ������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ������
3. дһ�����򣬽������ʮ��������Mת��Ϊ�˽�������M8���������ͨ����
����������޸ĳ���ʵ��ʮ��������M��N���ƣ������˻�ʮ�����ƣ���ת����
    ��1������˳��洢�ṹʵ��ջ��
    ��2�����������ṹʵ��ջ��
4. ���̲�3-19ת���õ��ĺ�׺����ʽ������˳��ջ�����ʽ��ֵ��
*/
/*
#include <stdio.h>

int main(){
    int choose; //����ѭ����switchѡ��
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
                printf("Pop elements is ��%d\n", Pop(s));
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
    printf("Enter the element you want to inset�� ");
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
                printf("Pop elements is ��%d\n", Pop(s));
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
    int n;  // Դ����
    int c;  // Դ���ֽ���
    int b;  // �ݴ�����
    int d = 0;  // ת����ɵ�ʮ��������
    int r = 0;  //λȨ
    SqStack * s;
    s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    printf("����Դ���ֽ��ƣ� ");
    scanf("%d", &c);
    if(c >= 10){
        printf("Error, because i am lazy!\n");
        return 0;
    }
    printf("�������֣� ");
    scanf("%d", &n);
    if(c != 10){
        while(n){
            b = n%10;
            d += b * pow(c, r);
            r++;
            n /= 10;
        }
        printf("ʮ���ƣ� %d\n", d);
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
        printf("�˽��ƣ� ");
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
        printf("�����ƣ� ");
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
        printf("ʮ�����ƣ� ");
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

void InitStackTR(OPTR **);  //�½��ַ�ջ
void InitStackND(OPND **);  //�½�����ջ
void PushTR(OPTR *, char);  //�ַ�ѹջ
void PushND(OPND *, int);   //����ѹջ
char PopTR(OPTR *); //�ַ���ջ
int PopND(OPND *);  //���ֳ�ջ
char GetTop(OPTR *);    //��ջ��Ԫ��
char Precede(char, char);   //�ж���������ȼ�
int Operate(int, char, int);    //����

int main(){
    int i = 0;  
    int count = 0;  //��λ���ּ���
    int mul = 1;    //������λ���ּ���
    int a, b;   //�ݴ����������������
    char theta; //�ݴ������
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
        if(expression[i] >= 48 && expression[i] <= 57){ //�ж��Ƿ�Ϊ����
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
                case '<':    //ջ��Ԫ�����ȼ���
                    PushTR(tr, expression[i]);
                    break;
                case '=':    //�����Ų�������һ���ַ�
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
1. ����˳��洢ʵ��ѭ�����еĳ�ʼ������ӡ����Ӳ�����
2. ������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ�����
3. ��дһ������ʹ����������q1��q2�������ֱ�洢�ɼ�������������20��100���ڵ�������ż����Ȼ��ÿ�����q1��q2��һ��ֵ����������ż�����
   �����ֱ����һ����Ϊ��Ϊֹ��
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
    //             printf("DeQueue element is ��%d\n",DeQueue(q));
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
    if( (q->rear + 1) % MAXSIZE == q->front ){      //��������
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
    if(q->front == q->rear){    //�ӿ�����
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
                printf("DeQueue element is ��%d\n",DeQueue(q));
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

typedef struct QNode{   //�ڵ�ṹ��
    ElemType data;
    struct QNode * next;
}QNode;

typedef struct Queue{   //���ӽṹ��
    struct QNode * front;
    struct QNode * rear;
}Queue;

void InitQueue(Queue **);   //��ʼ������
void EnQueue(Queue *, int); //���
ElemType DeQueue(Queue *);  //����

int main(){
    //int choose;
    int judge;  //�ж�Ӧ�������������ż��, 0Ϊż���� 1Ϊ����
    int i;  //ѭ������
    Queue * q1, * q2;   //��������
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
    if(q->front == NULL){   //���粻��ͷ��㣬��ô���½���һ���ڵ�
        q->front = q->rear = (QNode *)malloc(sizeof(QNode));
        srand((unsigned)time(NULL));
        if(judge == 0){     //ż��
            e = rand()%100;
            if(e % 2 == 1)
                e++;
        }
        if(judge == 1){     //����
            e = rand()%100;
            if(e % 2 == 0)
                e++;
        }
        q->rear->data = e;
        return;
    }
    p = (QNode *)malloc(sizeof(QNode)); //�˴��ǵڶ����ڵ�֮��Ľڵ�
    if(judge == 0){     //ż��
        e = rand()%100;
        if(e % 2 == 1)
            e++;
    }
    if(judge == 1){     //����
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
    if(q->front == NULL){   //��ʾ�ǿն�
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

//���ݽṹ��C���������� P71 - �� - 1
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

//���ݽṹ��C���������� P71 - �� - 2
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
                printf("DeQueue element is ��%d\n",DeQueue(q));
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
    if( (q->rear + 1) % MAXSIZE == q->front ){      //��������
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
    if(q->front == q->rear){    //�ӿ�����
        printf("The queue is empty!\nThe function will return 0!\n");  
        return 0;
    }
    e = q->data[q->front];
    q->front = (q->front + 1)%MAXSIZE;
    return e;
}
*/

//���ݽṹ��C���������� P71 - �� - 3
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

void InitStackTR(OPTR **);  //�½��ַ�ջ
void InitStackND(OPND **);  //�½�����ջ
void PushTR(OPTR *, char);  //�ַ�ѹջ
void PushND(OPND *, int);   //����ѹջ
char PopTR(OPTR *); //�ַ���ջ
int PopND(OPND *);  //���ֳ�ջ
char GetTop(OPTR *);    //ȥջ��Ԫ��
char Precede(char, char);   //�ж���������ȼ�
int Operate(int, char, int);    //����

int main(){
    int i = 0;  
    int count = 0;  //��λ���ּ���
    int mul = 1;    //������λ���ּ���
    int a, b;   //�ݴ����������������
    char theta; //�ݴ������
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
        if(expression[i] >= 48 && expression[i] <= 57){ //�ж��Ƿ�Ϊ����
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
                case '<':    //ջ��Ԫ�����ȼ���
                    PushTR(tr, expression[i]);
                    break;
                case '=':    //�����Ų�������һ���ַ�
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


//���ݽṹ��C���������� P71 - �� - 4
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


//���ݽṹ��C���������� P95 - �� - 1
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

//���ݽṹ��C���������� P95 - �� - 2
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

//���ݽṹ��C���������� P95 - �� - 3
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
        if(ch[i] >= 48 && ch[i] <= 57){ //�ж��Ƿ�Ϊ����
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
