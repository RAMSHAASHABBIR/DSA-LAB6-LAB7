#pragma once
#include <iostream>
#include <vector>
using namespace std;
// forward reverse general iterator
class node
{
public:
	int data;
	node* next;
	node* pre;
	node(int value)
	{
		data = value;
		next = nullptr;
		pre = nullptr;
	}

	class FIterator {
	private:
		node* iter;
	public:
		FIterator(node *n) {
			iter = n;
		}
		void operator ++(int) {
			iter = iter->next;
		}
		int operator *()
		{
			return iter->data;
		}
		bool operator != (FIterator i)
		{
			return iter != i.iter;
		}
		bool operator == (FIterator i)
		{
			return iter == i.iter;
		}
	};
	FIterator Fbegin(node *head)
	{
		return FIterator(head);
	}
	FIterator FEnd()
	{
		return FIterator(nullptr);
	}
	FIterator FendTail(node* head,node* tail)
	{
		return FIterator(tail);
	}
	//question 2
	//4
	void insertAtTail(node*& head, int val, node*& tail)
	{
		node* n = new node(val);
		if (head == nullptr)
		{
			head = n;
			tail = n;
			return;
		}
		node* temp = tail;
		n->pre = temp;
		temp->next = n;
		tail = n;
	}
	//3
	void insertAtHead(node* &head,int val,node* &tail)
	{
		node* n = new node(val);
		n->next = head;
		head->pre = n;
		head = n;
	}
	//2 a
	void insertAtAfter(node*& head, int val, int whereToInsert)
	{
		if (head == nullptr)
		{
			return;
		}
		node* n = new node(val);
		node* temp = head;
		for(node::FIterator i=head->Fbegin(head); i!=head->FEnd()&& temp->data != whereToInsert; i++)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			delete n;
			return;
		}
		n->next = temp->next;
		n->pre = temp;
		temp->next = n;
		n->next->pre = n;
	}
	//2 b
	void insertAtBefore(node*& head, int val, int whereToInsert)
	{
		if (head == nullptr)
		{
			return;
		}
		node* n = new node(val);
		node* temp = head;
		for (node::FIterator i = head->Fbegin(head); i != head->FEnd() && temp->data != whereToInsert;i++)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			delete n;
			return;
		}
		temp->pre->next = n;
		n->pre = temp->pre;
		n->next = temp;
		temp->pre = n;
		n->pre->next = n;
	}
	//5
	void removeAtEnd(node*& head,node* &tail)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		node* temp = tail;
		tail = tail->pre;
		tail->next = nullptr;
		delete temp;
	}
	//1
	bool isEmpty(node*& head)
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
};
//leetcode 
//1
//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//		ListNode* dummy = new ListNode(0);
//		ListNode* curr = dummy;
//		while (list1 != nullptr && list2 != nullptr)
//		{
//			if (list1->val <= list2->val)
//			{
//				curr->next = list1;
//				list1 = list1->next;
//			}
//			else
//			{
//				curr->next = list2;
//				list2 = list2->next;
//			}
//			curr = curr->next;
//		}
//		curr->next = list1 != nullptr ? list1 : list2;
//		return dummy->next;
//	}
//};

//3
//class Solution {
//public:
//	ListNode* swapPairs(ListNode* head) {
//		ListNode* dummy = new ListNode(-1);
//		ListNode* pre = dummy;
//		ListNode* current = head;
//		dummy->next = head;
//		while (current != nullptr && current->next != nullptr)
//		{
//			pre->next = current->next;
//			current->next = current->next->next;
//			pre->next->next = current;
//			current = current->next;
//			pre = pre->next->next;
//		}
//		return dummy->next;
//	}
//};

//5
//class Solution {
//public:
//	void revList(ListNode* prev, ListNode* curr, int right)
//	{
//		if (right == 0)return;
//		ListNode* next = curr->next;
//		curr->next = prev;
//		revList(curr, next, right - 1);
//	}
//	ListNode* reverseBetween(ListNode* head, int left, int right) {
//		if (left == right)return head;
//
//		ListNode* temp = head;
//		ListNode* temp1 = head;
//		ListNode* pre;
//		ListNode* pre1;
//		for (int i = 0;i < left - 2;i++) {
//			temp = temp->next;
//		}
//		for (int i = 0;i < right - 1;i++) {
//			temp1 = temp1->next;
//		}
//		pre = temp->next;
//		pre1 = temp1;
//		temp1 = temp1->next;
//
//		revList(nullptr, pre, right - left + 1);
//		temp->next = pre1;
//		pre->next = temp1;
//		return head;
//
//	}
//};
