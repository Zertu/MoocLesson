#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

typedef struct Node *PtrToNode;
struct Node {
	//系数
	int coef;
	//指数
	int expon;
	PtrToNode Next;
};
typedef PtrToNode List;

List insert(int n,List l) {
	List p = (List)malloc(sizeof(struct Node)*n);
	l->Next = p;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &((p + i)->coef), &((i + p)->expon));
		(p + 1)->Next= NULL;
	}
	(p + n - 1)->Next = NULL;
	return l;
};
struct Node Node1,Node2;
List L1 = &Node1,
L2 = &Node2;

void printlist(List l) {
	l = l->Next;
	while (l)
	{
		printf("%d-%d\n", l->coef, l->expon);
		l = l->Next;
	}
	return;
}

List mul(List a, List b) {
	List l = (List)malloc(sizeof(struct Node));
	l->Next = NULL;
	List n1 = a->Next, n2 = b->Next, p = l;
	while (n1) {
		while (n2) {
			p->Next = (PtrToNode)malloc(sizeof(struct Node));
			p = p->Next;
			p->expon = n1->expon + n2->expon;
			p->coef = n1->coef*n2->coef;
			p->Next = NULL;
			n2 = n2->Next;
		}
		n1 = n1->Next;
	}
	return l;
}
int main()
{	
	int N;
	scanf("%d", &N);
	insert(N, L1);
	scanf("%d", &N);
	insert(N, L2);
	mul(L1, L2);
	system("pause");
}