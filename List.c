/* 2.12
?? A = (a1,????,am) ?? B = (b1,????,bn) 锟斤拷为顺锟斤拷????
A'锟斤拷B'锟街憋拷为A锟斤拷B??锟斤拷去锟斤拷锟酵?前缀锟斤拷锟斤拷??
??A' = B' = 锟秸憋拷锟斤拷 A = B??
?? A' = 锟秸憋拷?? 锟斤拷B' != 锟秸憋拷锟斤拷锟斤拷锟斤拷锟竭撅拷锟斤拷为锟秸憋拷锟斤拷A'?????元小锟斤拷B'?????元锟斤拷锟斤拷A<B锟斤拷锟斤拷锟斤拷A>B??
锟斤拷写一??锟饺斤拷A锟斤拷B锟斤拷小锟斤拷锟斤拷??
*/


#include <stdio.h>
int main()
{
    int m, n;                           //锟街憋拷为A锟斤拷B锟侥筹拷??
    int i;                              //????锟斤拷锟斤拷
    printf("锟斤拷锟斤拷A锟斤拷B锟斤拷锟介长锟饺ｏ拷\n");
    scanf("%d %d", &m, &n);             //锟斤拷锟斤拷锟斤拷锟介长锟斤拷
    char a[m];
    char b[n];
    printf("锟斤拷锟斤拷A锟斤拷锟斤拷元锟截ｏ拷\n");
    fflush(stdin);
    for(i = 0; i < m; i++)
        scanf("%c", &a[i]);             //锟斤拷锟斤拷锟斤拷锟斤拷A锟斤拷元??
    fflush(stdin);
    printf("锟斤拷锟斤拷B锟斤拷锟斤拷元锟截ｏ拷\n");
    for(i = 0; i < n; i++)
        scanf("%c", &b[i]);             //锟斤拷锟斤拷锟斤拷锟斤拷B锟斤拷元??
    for(i = 0; i <= m || i <= n; i++)
    {
        if(i == m && i == n)
        {
            printf("A = B");
            break;
        }
        else
        {
            if(i == m)
            {
                printf("A < B");
                break;
            }
            else if(i == n)
            {
                printf("A > B");
                break;
            }
        }
        if(a[i] != b[i])
        {
            if(a[i] > b[i])
                printf("A > B");
            else
                printf("A < B");
            break;
        }
    }
    return 0;
}


/* 2.19
    锟斤拷知锟斤拷锟皆憋拷??锟斤拷元锟斤拷锟斤拷值?????锟斤拷锟斤拷锟斤拷锟叫ｏ拷锟斤拷锟皆碉拷锟斤拷锟斤拷锟斤拷锟芥储锟斤拷????
    锟斤拷写一锟斤拷效锟姐法锟斤拷删锟斤拷锟斤拷??锟斤拷锟斤拷值锟斤拷锟斤拷mink锟斤拷小锟斤拷maxk锟斤拷元锟截ｏ拷锟斤拷锟???锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷元锟截ｏ拷同时锟酵凤拷??删锟节碉拷锟???
    锟斤拷锟斤拷锟斤拷锟斤拷惴?锟斤拷时?????锟接度ｏ拷注锟解：mink锟斤拷maxk??锟斤拷锟斤拷锟斤拷锟斤拷??锟轿憋拷锟斤拷锟斤拷锟斤拷锟角碉拷值锟斤拷锟皆和憋拷锟叫碉拷元锟斤拷锟斤拷同锟斤拷也锟斤拷锟皆诧拷同锟斤拷
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct LinkList{
    int date;
    struct LinkList *next;
};
void LinkList_del(struct LinkList *head, int count);
void LinkList_show(struct LinkList *head);
int main()
{
    struct LinkList *head;
    struct LinkList *p;
    struct LinkList *q;
    int i;
    int count;
    printf("锟斤拷锟诫单锟斤拷锟斤拷锟饺ｏ拷\n");
    scanf("%d", &count);
    head = (struct LinkList *)malloc(sizeof(struct LinkList));
    p = (struct LinkList *)malloc(sizeof(struct LinkList));
    head->next = p;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟捷ｏ拷\n");
    scanf("%d", &(p->date));
    for(i = 0; i < count-1; i++)
    {
        q = (struct LinkList *)malloc(sizeof(struct LinkList));
        scanf("%d", &(q->date));
        p->next = q;
        p = q;
    }
    p->next = NULL;
    LinkList_show(head);
    LinkList_del(head, count);
    return 0;
}

void LinkList_del(struct LinkList *head, int count)
{
    int mink = 0;
    int maxk = 0;
    struct LinkList *mink_p;
    struct LinkList *maxk_p;
    struct LinkList *head_next;
    struct LinkList *element_del1;
    struct LinkList *element_del2;
    head_next = head->next;
    int i;
    printf("锟斤拷锟斤拷要删锟斤拷锟斤拷锟斤拷锟戒：\n");
    scanf("%d%d", &mink, &maxk);
    for(i = 0; i < count; i++)
    {
        if(head_next->date <= mink)
        {
            mink_p = head_next;
            head_next = head_next->next;
        }
        else
            break;
    }
    for(i = 0; i < count; i++)
    {
        if(head_next->date <= maxk)
        {
            maxk_p = head_next;
            head_next = head_next->next;
        }
        else
            break;
    }
    element_del1 = mink_p->next;
    element_del2 = element_del1->next;
    do{
        free(element_del1);
        element_del1 = element_del2;
        element_del2 = element_del1->next;
    }while(element_del1 != maxk_p);
    mink_p->next = maxk_p;
    LinkList_show(head);
}

void LinkList_show(struct LinkList *head)
{
    struct LinkList *p;
    p = head->next;
    while(p)
    {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}
*/


/* 2.21
    锟斤拷写一锟姐法锟斤拷实锟斤拷顺锟斤拷锟侥就碉拷锟斤拷锟斤拷
*/
/*
#include <stdio.h>
int main()
{
    int i, j;
    printf("锟斤拷锟斤拷顺锟斤拷锟斤拷龋锟?");
    scanf("%d", &i);
    int numbers[i];
    printf("锟斤拷锟斤拷顺锟斤拷锟皆?锟截ｏ拷");
    for(j = 0; j < i; j++)
    {
        scanf("%d", &numbers[j]);
    }
    printf("\n");
    for(j = 0; j < i/2; j++)
    {
        numbers[j] += numbers[i-j-1];
        numbers[i-j-1] = numbers[j] - numbers[i-j-1];
        numbers[j] = numbers[j] - numbers[i-j-1];
    }
    for(j = 0; j < i; j++)
    {
        printf("%d ", numbers[j]);
    }

    return 0;
}
*/

/* 2.22
    锟斤拷写一锟姐法?????锟斤拷锟斤拷锟斤拷实锟街就碉拷锟斤拷锟斤拷
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int date;
    struct LNode* next;
} * Link;
struct _linklist{
    Link head, tail;
    int len;
} * LinkList;

void inverse(struct _linklist* LinkList);
void LinkList_show(struct _linklist* LinkList);

int main()
{
    int i;
    Link front;
    Link behind;
    LinkList  = (struct _linklist *)malloc(sizeof(struct _linklist));
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟饺ｏ拷");
    scanf("%d", &LinkList->len);
    fflush(stdin);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷诘悖?");
    LinkList->head = (Link)malloc(sizeof(Link));
    front = LinkList->head;
    scanf("%d", &front->date);
    for(i = 1; i < LinkList->len; i++)
    {
        behind = (Link)malloc(sizeof(Link));
        scanf("%d", &behind->date);
        front->next = behind;
        front = behind;
    }
    front->next = NULL;
    LinkList->tail = front;
    LinkList_show(LinkList);
    inverse(LinkList);
    LinkList_show(LinkList);
    return 0;
}

void inverse(struct _linklist* LinkList)
{
    int i;
    int j;
    int count;
    count = LinkList->len;
    Link front;
    Link behind;
    front = LinkList->head;
    for(i = 0; i < LinkList->len/2; i++)
    {
        behind = front;
        for(j = 1; j < count-i*2; j++)
        {
            behind = behind->next;
        }
        front->date += behind->date;
        behind->date = front->date - behind->date;
        front->date = front->date - behind->date;
        front = front->next;
    }
}

void LinkList_show(struct _linklist* LinkList)
{
    Link front;
    int i;
    front = LinkList->head;
    for(i = 0; i < LinkList->len; i++)
    {
        printf("%d ", front->date);
        front = front->next;
    }
    printf("\n");
}
*/

/* 2.24
    ?????锟斤拷锟斤拷??锟斤拷元锟斤拷?????锟斤拷锟斤拷锟斤拷锟叫碉拷锟斤拷锟皆憋拷A锟斤拷B锟斤拷锟斤拷锟皆碉拷锟斤拷锟斤拷锟斤拷锟芥储锟斤拷??
    锟斤拷锟叫达拷惴?锟斤拷A锟斤拷锟紹锟斤拷椴?锟斤拷一??锟斤拷元锟斤拷值锟捷硷拷锟斤拷锟斤拷锟斤拷锟叫碉拷锟斤拷锟皆憋拷
    要锟斤拷锟斤拷锟斤拷原锟斤拷慕诘愎癸拷锟紺??
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkList{
    int date;
    struct _LinkList* next;
} * LinkList;

void InsertElem(LinkList s, int len);
void conflation(LinkList a, LinkList b, LinkList c, int len);
void LinkList_show(LinkList c);
void inverse(LinkList c, int len);

int main()
{
    LinkList a, b;
    LinkList c = NULL;
    int len_a;
    int len_b;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? a 锟侥筹拷锟饺ｏ拷");
    scanf("%d", &len_a);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? a 锟斤拷元锟截ｏ拷");
    a = (LinkList)malloc(sizeof(LinkList));
    scanf("%d", &a->date);
    InsertElem(a, len_a);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? b 锟侥筹拷锟饺ｏ拷");
    scanf("%d", &len_b);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? b 锟斤拷元锟截ｏ拷");
    b = (LinkList)malloc(sizeof(LinkList));
    scanf("%d", &b->date);
    InsertElem(b, len_b);
    conflation(a, b, c, len_a+len_b);
    return 0;
}

void InsertElem(LinkList s, int len)
{
    int i;
    LinkList front;
    LinkList behind;
    front = s;
    for(i = 1; i < len; i++)
    {
        behind = (LinkList)malloc(sizeof(LinkList));
        scanf("%d", &behind->date);
        front->next = behind;
        front = behind;
    }
    front->next = NULL;
}

void conflation(LinkList a, LinkList b, LinkList c, int len)
{
    LinkList tempa;
    LinkList tempb;
    LinkList _c;
    if(a->date <= b->date)
    {
         c = a;
         a = a->next;
    }
    else
    {
        c = b;
        b = b->next;
    }
    _c = c;
    tempa = a->next;
    tempb = b->next;
    while(a && b)
    {
        if(a->date <= b->date)
        {
            c->next = a;
            c = c->next;
            a = tempa;
            if(tempa)
            {
                tempa = tempa->next;
            }
            else
            {
                continue;
            }
        }
        else
        {
            c->next = b;
            c = c->next;
            b = tempb;
            if(tempb)
            {
                tempb = tempb->next;
            }
            else
            {
                continue;
            }
        }
    }
    while(a)
    {
        c->next = a;
        c = c->next;
        a = tempa;
        if(tempa)
        {
            tempa = tempa->next;
        }
        else
        {
            continue;
        }
    }
    while(b)
    {
        c->next = b;
        c = c->next;
        b = tempb;
        if(tempb)
        {
            tempb = tempb->next;
        }
        else
        {
            continue;
        }
    }
    c = _c;
    LinkList_show(c);
    inverse(c, len);
    LinkList_show(c);
}

void LinkList_show(LinkList c)
{
    LinkList front;
    int i;
    front = c;
    while(front)
    {
        printf("%d ", front->date);
        front = front->next;
    }
    printf("\n");
}

void inverse(LinkList c, int len)
{
    int i;
    int j;
    int count;
    count = len;
    LinkList front;
    LinkList behind;
    front = c;
    for(i = 0; i < len/2; i++)
    {
        behind = front;
        for(j = 1; j < count-i*2; j++)
        {
            behind = behind->next;
        }
        front->date += behind->date;
        behind->date = front->date - behind->date;
        front->date = front->date - behind->date;
        front = front->next;
    }
}
*/


/* 2.25
    ?????锟斤拷锟斤拷??元锟斤拷锟斤拷值?????锟斤拷锟斤拷锟斤拷锟叫碉拷锟斤拷锟皆憋拷 A ?? B 锟街憋拷锟绞撅拷锟斤拷锟斤拷锟斤拷希锟斤拷锟酵?一锟斤拷锟叫碉拷元锟斤拷值锟斤拷锟斤拷锟斤拷同锟斤拷锟斤拷锟斤拷要锟斤拷锟斤拷倏占涔癸拷锟揭???锟斤拷锟皆憋拷C
    锟斤拷元锟斤拷为 A ?? B ??元锟截的斤拷锟斤拷锟斤拷锟揭憋拷C??锟斤拷元锟斤拷也锟斤拷值?????锟斤拷锟斤拷锟斤拷锟叫★拷锟皆讹拷顺锟斤拷锟斤拷写锟斤拷C锟斤拷锟斤拷??
*/
/*
#include <stdio.h>

void InsertElem(int numbers[], int s);
void conflation(int numbersA[], int numbersB[], int numbersC[], int a, int b);
void ShowElem(int numbersC[], int c);

int main()
{
    int a, b;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? A 锟斤拷元锟截革拷锟斤拷锟斤拷");
    scanf("%d", &a);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? B 锟斤拷元锟截革拷锟斤拷锟斤拷");
    scanf("%d", &b);
    int numbersA[a];
    int numbersB[b];
    int numbersC[a];
    InsertElem(numbersA, a);
    InsertElem(numbersB, b);
    conflation(numbersA, numbersB, numbersC, a, b);

    return 0;
}

void InsertElem(int numbers[], int s)
{
    int i;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷元锟截ｏ拷\n");
    for(i = 0; i < s; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void conflation(int numbersA[], int numbersB[], int numbersC[], int a, int b)
{
    int i_a = 0;
    int i_b = 0;
    int i = 0;
    while(i_a < a && i_b < b)
    {
        if(numbersA[i_a] < numbersB[i_b])
        {
            i_a++;
        }
        else if(numbersA[i_a] > numbersB[i_b])
        {
            i_b++;
        }
        else
        {
            numbersC[i] = numbersA[i_a];
            i_a++;
            i_b++;
            i++;
        }
    }
    ShowElem(numbersC, i);
}

void ShowElem(int numbersC[], int c)
{
    int i;
    for(i = 0; i < c; i++)
    {
        printf("%d ", numbersC[i]);
    }
}
*/
/* 2.27
    ??2.25锟斤拷锟斤拷锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷锟斤拷薷模锟斤拷锟剿筹拷锟斤拷锟斤拷锟铰憋拷写锟斤拷锟??? C 锟斤拷锟斤拷??
    ??1?? ?????锟斤拷同一??锟斤拷A ?? B锟斤拷锟斤拷??锟杰达拷锟斤拷值锟斤拷同锟斤拷元锟截ｏ拷锟斤拷要锟斤拷锟斤拷锟斤拷锟缴碉拷?? C ??锟斤拷元锟斤拷值锟斤拷锟斤拷锟斤拷????
    ??2?? 锟斤拷锟斤拷 A 锟斤拷占锟斤拷锟紺
*/

/*
#include <stdio.h>

void InsertElem(int numbers[], int s);
void conflation(int numbersA[], int numbersB[], int a, int b);
void ShowElem(int numbersC[], int c);
void compare(int numbers[], int c);

int main()
{
    int a, b;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? A 锟斤拷元锟截革拷锟斤拷锟斤拷");
    scanf("%d", &a);
    printf("锟斤拷锟斤拷锟斤拷锟斤拷?? B 锟斤拷元锟截革拷锟斤拷锟斤拷");
    scanf("%d", &b);
    int numbersA[a];
    int numbersB[b];
    InsertElem(numbersA, a);
    InsertElem(numbersB, b);
    conflation(numbersA, numbersB, a, b);
    return 0;
}

void InsertElem(int numbers[], int s)
{
    int i;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷元锟截ｏ拷\n");
    for(i = 0; i < s; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void conflation(int numbersA[], int numbersB[], int a, int b)
{
    int i_a = 0;
    int i_b = 0;
    int i = 0;
    int j = 0;
    while(i_a < a && i_b < b)
    {
        if(numbersA[i_a] < numbersB[i_b])
        {
            for(i = i_a, j = i_a+1; j < a; i++, j++)
            {
                numbersA[i] = numbersA[j];
            }
            if(numbersA[i_a] < numbersB[i_b] && i_a == a-1)
            {
                break;
            }
            if(i_a+1 == a-1 && numbersA[i_a] < numbersB[i_b])
            {
                break;
            }
        }
        else if(numbersA[i_a] > numbersB[i_b])
        {
            i_b++;
        }
        else
        {
            i_a++;
            i_b++;
        }
    }
    compare(numbersA, i_a);
}

void ShowElem(int numbersC[], int c)
{
    int i;
    for(i = 0; i < c; i++)
    {
        printf("%d ", numbersC[i]);
    }
    printf("\n");
}

void compare(int numbers[], int c)
{
    int i;
    int j;
    int i_i;
    int i_j;
    for(i = 0, j = i+1; j < c; i++, j++)
    {
        if(numbers[i] == numbers[j])
        {
            for(i_i = i, i_j = j; i_j < c; i_i++, i_j++)
            {
                numbers[i_i] = numbers[i_j];
            }
            c--;
        }
    }
    ShowElem(numbers, c);
}

*/


/* 2.28
    ??2.25锟斤拷锟斤拷锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷锟斤拷薷模锟斤拷缘锟斤拷锟斤拷锟斤拷锟斤拷卤锟叫达拷锟斤拷?? C 锟斤拷锟斤拷??
    ??1?? ?????锟斤拷同一??锟斤拷A ?? B锟斤拷锟斤拷??锟杰达拷锟斤拷值锟斤拷同锟斤拷元锟截ｏ拷锟斤拷要锟斤拷锟斤拷锟斤拷锟缴碉拷?? C ??锟斤拷元锟斤拷值锟斤拷锟斤拷锟斤拷????
    ??2?? 锟斤拷锟斤拷原锟斤拷A 锟斤拷锟? B ??锟斤拷锟叫的斤拷愎癸拷锟斤拷C锟斤拷锟斤拷锟酵凤拷A锟斤拷锟叫碉拷锟斤拷锟矫斤拷锟斤拷??
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{   //锟斤拷锟斤拷
    int date;
    struct LNode* next;
} * Link;
struct _linklist{       //锟斤拷锟酵凤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
    Link head;
    int len;
} * LinkListA, * LinkListB;

void CreatList(struct _linklist *);
void ShowElem(struct _linklist *);
void Compare(struct _linklist *, struct _linklist *);

int main()
{
    LinkListA = (struct _linklist *)malloc(sizeof(struct _linklist));
    LinkListB = (struct _linklist *)malloc(sizeof(struct _linklist));
    CreatList(LinkListA);
    CreatList(LinkListB);
    Compare(LinkListA, LinkListB);
    ShowElem(LinkListA);

    return 0;
}

void CreatList(struct _linklist * LinkList)
{
    Link a;
    Link front;
    Link behind;
    int i;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟饺ｏ拷 ");
    scanf("%d", &LinkList->len);
    a = (Link)malloc(sizeof(Link));
    LinkList->head = a;
    front = a;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷???? ");
    scanf("%d", &a->date);
    for(i = 1; i < LinkList->len; i++)
    {
        behind = (Link)malloc(sizeof(Link));
        scanf("%d", &behind->date);
        front->next = behind;
        front = behind;
    }
    front->next = NULL;
}

void ShowElem(struct _linklist * LinkList)
{
    int i;
    Link p;
    p = LinkList->head;
    for(i = 0; i < LinkList->len; i++)
    {
        printf("%d ", p->date);
        p = p->next;
    }
    printf("\n");
}

void Compare(struct _linklist * LinkListA, struct _linklist * LinkListB)
{
    Link a;
    Link b;
    Link temp;
    int i;
    int count = 0;
    int len;
    a = LinkListA->head;
    b = LinkListB->head;
    while(a && b)
    {
        if(a->date != b->date)
        {
            temp = a;
            a = a->next;
            free(temp);
            if(!count) LinkListA->head = a;
            LinkListA->len--;
        }
        else
        {
            a = a->next;
            b = b->next;
            count++;
        }
    }
    if(LinkListA->len > count)
    {
        len = LinkListA->len-count;
        for(i = 0; i < len; i++)
        {
            temp = a;
            a = a->next;
            free(temp);
            LinkListA->len--;
        }
    }
}

*/


/* 2.29
    锟斤拷知 A, B ?? C 为锟斤拷???????锟斤拷锟斤拷锟斤拷锟斤拷员锟斤拷锟揭?锟斤拷?? A 锟斤拷锟斤拷锟斤拷锟铰诧拷锟斤拷??
    删去锟斤拷些锟斤拷锟斤拷 B 锟斤拷锟叫筹拷锟斤拷锟斤拷锟斤拷 C锟斤拷锟叫筹拷锟街碉拷元????
    ?????顺锟斤拷锟斤拷写实锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟姐法锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷惴?锟斤拷时锟斤拷???锟斤拷??
*/

/*
#include <stdio.h>
#include <stdlib.h>

struct numbers{
    int lenth;
    int * date;
} *a, *b, *c;

void InsertElem(struct numbers *);
void ShowElem(struct numbers *);
int Find(struct numbers *, int n);
void Compare(struct numbers *, struct numbers *, struct numbers *);
void DelElem(struct numbers *);

int main()
{
    a = (struct numbers *)malloc(sizeof(struct numbers));
    b = (struct numbers *)malloc(sizeof(struct numbers));
    c = (struct numbers *)malloc(sizeof(struct numbers));
    InsertElem(a);
    InsertElem(b);
    InsertElem(c);
    Compare(a, b, c);
    return 0;
}

void InsertElem(struct numbers * a)
{
    int i;
    printf("锟斤拷锟斤拷锟斤拷锟斤拷锟介长锟饺ｏ拷 ");
    scanf("%d", &a->lenth);
    a->date = (int *)malloc(sizeof(int) * a->lenth);
    for(i = 0; i < a->lenth; i++)
    {
        scanf("%d", &a->date[i]);
    }
}

void ShowElem(struct numbers * a)
{
    int i;
    for(i = 0; i < a->lenth; i++)
    {
        if(a->date[i] == -1)
        {
            continue;
        }
        else
        {
            printf("%d ", a->date[i]);
        }
    }
    printf("\n");
}
int Find(struct numbers * a, int n)
{
    int NotFind = -1;
    int lef = 0;
    int rig = a->lenth-1;
    int mid;
    while(lef < rig)
    {
        mid  = ( lef + rig ) / 2;
        if((mid == lef || mid == rig) && n != a->date[mid])  return NotFind;
        else if( n < a->date[mid] ) rig = mid;
        else if( n > a->date[mid] ) lef = mid;   
        else
            return 1;
    }
    return NotFind;
}

void Compare(struct numbers * a, struct numbers * b, struct numbers * c)
{
    int i;
    for(i = 0; i < a->lenth; i++)
    {
        if(Find(b, a->date[i]) == 1 && Find(c, a->date[i]) == 1)
        {
            a->date[i] = -1;
        }
    }
    //DelElem(a);
    ShowElem(a);
}
*/
/*
void DelElem(struct numbers * a)
{
    int i;
    int j;
    int k;
    for(i = 0; i < a->lenth; i++)
    {
        if(a->date[i] == -1)
        {
            for(j = i, k = i+1; k < a->lenth; j++, k++)
            {
                a->date[j] = a->date[k];
            }
            a->lenth--;
        }
    }
}
*/


/* 2.29
    要锟斤拷?? 2.29 ????
    ?????锟斤拷锟斤拷锟斤拷锟叫达拷惴?锟斤拷??????? A 锟斤拷锟叫碉拷锟斤拷锟矫斤拷锟斤拷????
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{
    int date;
    struct LinkNode * next;
}   * Link;
struct LinkList{
    Link hear;
    int lenth;
} *a, *b, *c ;

void InsertElem(struct LinkList *);
void ShowElem(struct LinkList *);
void Compare(struct LinkList *, struct LinkList *);
void DelElem(struct LinkList *, struct LinkList *);

int main()
{
    a = (struct LinkList *)malloc(sizeof(struct LinkList));
    b = (struct LinkList *)malloc(sizeof(struct LinkList));
    c = (struct LinkList *)malloc(sizeof(struct LinkList));
    InsertElem(a);
    InsertElem(b);
    InsertElem(c);
    Compare(b, c);
    DelElem(a, b);
    ShowElem(a);
    return 0;
}

void InsertElem(struct LinkList * s)
{   
    int i;
    Link front, behind;
    printf("输入链表长度： ");
    scanf("%d", &s->lenth);
    s->hear = (Link)malloc(sizeof(Link));
    front = s->hear;
    scanf("%d", &front->date);
    for(i = 1; i < s->lenth; i++)
    {
        behind = (Link)malloc(sizeof(Link));
        scanf("%d", &behind->date);
        front->next = behind;
        front = behind;
    }
    front->next = NULL;
}

void ShowElem(struct LinkList * s)
{
    int i;
    Link z;
    z = s->hear;
    for(i = 0; i < s->lenth; i++)
    {
        printf("%d ", z->date);
        z = z->next;
    }
    printf("\n");
}

void Compare(struct LinkList * s, struct LinkList * v)
{
    Link cs;
    Link cv;
    Link temp;
    Link csHN;
    int flag = 0;
    cs = s->hear;
    cv = v->hear;
    csHN = s->hear;
    while(cs && cv)
    {
        if(cs->date < cv->date)
        {
            temp = cs;
            cs = cs->next;
            free(temp);
            s->lenth--;
        }
        else if(cs->date > cv->date)
        {
            cv = cv->next;
        }
        else
        {
            if(!flag)
            {
                s->hear = cs;
                csHN = s->hear;
                flag = 1;
            }
            else
            {
                csHN->next = cs;
                csHN = csHN->next;
            }
            cs = cs->next;
            cv = cv->next;
        }
    }
    csHN->next = NULL;
}

void DelElem(struct LinkList * s, struct LinkList * v)
{
    Link cs;
    Link cv;
    Link temp;
    Link tempTwo;
    int cnt = 0;
    cs = s->hear;
    cv = v->hear;
    while(cs && cv)
    {
        if(cs->date < cv->date)
        {
            temp = cs;
            cs = cs->next;
        }
        else if(cs->date > cs->date)
        {
            cv = cv->next;
        }
        else
        {
            if(cnt == 0)
            {
                temp = cs;
                cs = cs->next;
                s->hear = cs;
                free(temp);
                cv = cv->next;
                s->lenth--;
            }
            else
            {
                temp->next = cs->next;
                tempTwo = cs;
                cs = cs->next;
                cv = cv->next;
                free(tempTwo);
                s->lenth--;
            }
        }
        cnt++;
    }
}
*/
/*
    锟斤拷某锟斤拷锟揭?锟斤拷锟斤拷锟揭筹拷$GPRMC锟斤拷洌?锟斤拷锟斤拷校锟斤拷停锟斤拷页锟斤拷锟斤拷锟叫ｏ拷锟斤拷锟饺凤拷锟斤拷锟斤拷锟斤拷侄锟?2锟斤拷示锟窖讹拷位锟斤拷锟斤拷洌?
    锟斤拷锟叫硷拷锟斤拷锟绞憋拷洌?锟斤拷锟斤拷杀锟斤拷锟绞憋拷洹Ｒ伙拷锟斤拷锟斤拷锟斤拷谢锟斤拷锟斤拷锟斤拷锟斤拷$GPRMC锟斤拷洌?锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷玫锟斤拷谋锟斤拷锟绞憋拷锟斤拷锟轿?锟斤拷锟斤拷锟斤拷锟斤拷
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Compare(char * s);
void UTCTransformBJ(char * s);

int main()
{
    char * s1 = NULL;
    char * s2 = NULL;
    s1 = (char *)malloc(sizeof(char) * 72);
    s2 = (char *)malloc(sizeof(char) * 72);
    do{
        scanf("%s", s2);
        if(Compare(s2))
        {
            strcpy(s1, s2);
        }
    }while(strcmp("END", s2) != 0);
    UTCTransformBJ(s1);
    free(s1);
    free(s2);

    return 0;
}

int Compare(char * s)
{
    int i = 2;
    int j;
    int cache = s[1];
    char n1[3];
    char * n2;
    if(s[5] != 'C')
        return 0;
    if(s[14] != 'A' && s[18] != 'A')
        return 0;
    if(s[0] == 'E')
        return 0;
    while(s[i] != '*')
    {
        cache = cache^s[i];
        i++;
    }
    sprintf(n1, "%x", cache);
    if(n1[1] == '\0')
    {
        n1[1] = n1[0];
        n1[0] = 48;
        n1[2] = '\0';
    }
    n2 = strrchr(s, '*')+1;
    if(n1[0] >= 97) n1[0] -= 32;
    if(n1[1] >= 97) n1[1] -= 32;
    printf("%c%c\n", n1[0], n1[1]);
    printf("%c%c\n", n2[0], n2[1]);
    if(strcmp(n1, n2) == 0)
        return 1;
    return 0;
}

void UTCTransformBJ(char * s)
{
    int i;
    int cache;
    if(s[7] >= 48 && (s[8] >= 50 || s[8] == 48) )
    {
        cache = (s[7] - 48) * 10;
        cache += s[8] - 48 + 8;
        cache %= 24;
        if(cache < 10)
            printf("0");
        printf("%d:", cache);
    }
    else if(s[7] == 48 && s[8] <= 49)
    {
        printf("%d", s[7] - 48);
        printf("%d:", s[8] -40);
    }
    for(i = 9; i < 13; i++)
    {
        printf("%d", s[i] - 48);
        if(i % 2 == 0 && i < 12)
        {
            printf(":");
        }
    }
}
*/
