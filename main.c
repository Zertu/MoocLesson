#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 4096

typedef struct Node *PtrNode;
struct Node {
	int coef;
	int expon;
	PtrNode Next;
};

typedef PtrNode List;

PtrNode gnode(int coef, int expon) {
	PtrNode p = (PtrNode)malloc(sizeof(struct Node));
	if (p == NULL) {
		return NULL;//assert (p != NULL);
	}
	p->coef = coef;
	p->expon = expon;
	p->Next = NULL;
	return p;
}

char* gnum(char*cptr, char *word, size_t n) {
	for (int i = 0; i<n - 1 && *cptr; i++) {
		if (isdigit(*cptr) || *cptr == '-') {
			*word++ = *cptr++;
		}
	}
	if (*cptr)
		cptr++;
	*word = 0;
	return cptr;
}

List gpoly(List *l) {
	struct Node **p = l;
	int coef, expon;
	int n;
	char bline[MAXLINE];
	char word[MAXLINE];

	char *cptr = bline;
	fgets(bline, sizeof(bline), stdin);
	cptr = gnum(cptr, word, MAXLINE);
	n = atoi(word);
	for (int i = 0; i<n; i++) {
		//scanf("%d", &coef);
		//scanf("%d", &expon);
		cptr = gnum(cptr, word, MAXLINE);
		coef = atoi(word);
		cptr = gnum(cptr, word, MAXLINE);
		expon = atoi(word);
		*p = gnode(coef, expon);
		(*p)->Next = NULL;
		p = &(*p)->Next;
	}
	return *l;
}

List list_insert(List *l, int coef, int expon) {
	PtrNode *p = l;

	for (; *p;) {
		if ((*p)->expon == expon) {
			(*p)->coef += coef;
			return *l;
		}
		else if ((*p)->expon > expon) {
			p = &(*p)->Next;
		}
		else {
			PtrNode n = gnode(coef, expon);
			n->Next = *p;
			*p = n;
			return *l;
		}
	}
	if (*p == NULL) {
		*p = gnode(coef, expon);
		return *l;
	}

	return *l;
}

List list_mul(List l1, List l2) {
	List l3 = NULL;
	int coef, expon;
	for (PtrNode n1 = l1; n1; n1 = n1->Next) {
		for (PtrNode n2 = l2; n2; n2 = n2->Next) {
			coef = n1->coef * n2->coef;
			expon = n1->expon + n2->expon;
			if (coef != 0)
				list_insert(&l3, coef, expon);
		}
	}
	return l3;
}

List list_add(List l1, List l2) {
	return NULL;
}

int main(int argc, char *argv[])
{
	List l1, l2;
	gpoly(&l1);
	for (PtrNode p = l1; p; p = p->Next) {
		printf("%d x^%d + ", p->coef, p->expon);
	}
	printf("\n\n\n");
	gpoly(&l2);
	for (PtrNode p = l2; p; p = p->Next) {
		printf("%d x^%d + ", p->coef, p->expon);
	}
	printf("\n");
	printf("---------------------------\n");
	List l3 = list_mul(l1, l2);
	for (PtrNode p = l3; p; p = p->Next) {
		printf("%d x^%d + ", p->coef, p->expon);
	}
	printf("\n");
	return 0;
}