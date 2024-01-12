#include "Header.h";
int main()
{
	node* head = nullptr;
	node* tail = nullptr;
	head->insertAtTail(head, 1,tail);
	head->insertAtTail(head, 2,tail);
	head->insertAtTail(head, 3,tail);
	head->insertAtHead(head, 4,tail);
	head->insertAtAfter(head, 10, 2);
	head->insertAtBefore(head, 20, 1);
	head->removeAtEnd(head,tail);
	//head->display(head);
	int sum = 0;
	for (node::FIterator i = head->Fbegin(head); i != head->FEnd();i++)
	{
		//sum += *(i);
		cout << * (i) << "-----";
	}
}