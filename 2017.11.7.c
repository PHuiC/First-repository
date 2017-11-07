#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct	Node{
	ElemType data;
	struct Node *lchild, *rchild;
}BTNode, *BTree;

void CreatBTree1(BTree *t, char *str){
	BTree St[100];
	BTree p = NULL;
	char ch;
	int top = -1;
	int k;
	int j = 0;
	ch = str[j];
	*t = NULL;
	while(ch != '\0'){
		switch(ch){
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTree)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if(*t == NULL)
				*t = p;
			else{
				switch(k){
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void PreOrder(BTree T){
	if(T){
		printf("%3c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		
	}
}
void InOrder(BTree T){
	if(T){
		InOrder(T->lchild);
		printf("%3c", T->data);
		InOrder(T->rchild);
	}
}
void PostOrder(BTree T){
	if(T){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%3c", T->data);
	}
}
void DispBTree(BTree T){
	if(T){
		printf("%c", T->data);
		if(T->lchild || T->rchild){
			printf("(");
			DispBTree(T->lchild);
			if(T->rchild){
				printf(",");
			}
			DispBTree(T->rchild);
			printf(")");
		}
	}
}
BTree CreatBTree2(){
	int i, j;
	char ch;
	BTree T = NULL, s[40], q;
	printf("\nPlease Enter i, x: ");
	scanf("%d, %c", &i, &ch);
	while(i){
		q = (BTree)malloc(sizeof(BTNode));
		q->data = ch;
		q->lchild = q->rchild = NULL;
		s[i] = q;
		if(i == 1)
			T = q;
		else{
			j = i / 2;
			if(i % 2 == 0)
				s[j]->lchild = q;
			else
				s[j]->rchild = q;
		}
		printf("\nPlease Enter i, x: ");
		scanf("%d, %c", &i, &ch);
	}
	return T;
}
int main(){
	BTree T =  CreatBTree2();
	//char str[] = "A(B(D(,E(,F(G)))),C)";
	//CreatBTree1(&T,str);
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T);
	printf("\n");
	DispBTree(T);
	printf("\n");
	return 0;
}

