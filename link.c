#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pNode
{
	struct pNode *next;
	int data;
} Node;
typedef struct ptrNode
{
	struct pNode **next;
} Head;
Node *init(int data) {
	Node *temp = NULL;
	temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void insert(int data, Node *head) {
	Node *temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	Node *a = init(data);
	temp->next = a;
}

int del(int index, Node **head) {
	int i = 0;
	Node* temp = *head;
	if (index == 0) {
		*head = temp->next;
		return 1;
	}
	while (i < index-1&&temp->next) {
		i++;
		if (temp->next) {
			temp = temp->next;
		}
		else{
			return 0;
		}
	}
	Node *next = temp->next;
	if (next->next) {
		temp->next = next->next;
		free(next);
		return 1;
	}
	else {
		temp->next = NULL;
		return 1;
	}
}
void printList(Node *list) {
	if (!list) {
		return;
	}
	else {
		Node *head = list;
		while (head)
		{
			printf("%d\n", head->data);
			head = head->next;
		}
	}
}

int main() {
	Node *simple = NULL;
	simple = init(1);
	Node **head = &simple;
	insert(2, simple);
	insert(3, simple);
	del(0, head);
	printList(simple);
}