#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

typedef struct Node *PtrToNode;
struct Node {
	int coef;
	int expon;
	PtrToNode Next;
};
typedef PtrToNode List;

List insert(int n,List l) {
	struct Node *p = (PtrToNode)malloc(sizeof(struct Node));
	for (int i = 0; i < n; i+=2) {
		scanf("%d", &p->coef);
		scanf("%d", &p->expon);
		p = p->Next;
	}
	return l;
};
struct Node Node1,Node2;
List L1 = &Node1,
L2 = &Node2;


int main()
{	
	int N;
	scanf("%d", &N);
	insert(N, L1);
	scanf("%d", &N);
	insert(N, L2);
	printf("%s", N);
	system("pause");
}