struct Node LNode;
List Merge(List L1,List L2){
	List P=&LNode,P1=L1->Next,P2=L2->Next;
	P->Next=NULL;
	while(P1!=NULL && P2!=NULL){
		if(P1->Data>P2->Data){
			P->Next=P2;
			P2=P2->Next;
		}else{
			P->Next=P1;
			P1=P1->Next;
		}
		P=P->Next;
	}
	if(P1!=NULL)P->Next=P1;
	if(P2!=NULL)P->Next=P2;
	L1->Next=NULL;
	L2->Next=NULL;
	return &LNode;
}