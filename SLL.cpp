#include<bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node *next;

	Node(int key)	{
		val = key;
		next = NULL;
	}
};

void InsertAtHead(Node *&head, int key)	{
	if(!head)	{
		head = new Node(key);
		return;
	}
	Node *temp = new Node(key);
	temp->next = head;
	head = temp;
}

void InsertAtTail(Node *&head, int key)	{
	if(!head)	{
		head = new Node(key);
		return;
	}
	Node *temp = head;
	while(temp->next)	{
		temp = temp->next;
	}
	temp->next = new Node(key);
}

int length(Node *head)	{
	int l = 0;
	while(head)	{
		++l, head = head->next;
	}
	return l;
}

void InsertAtPos(Node *&head, int key, int pos)	{
	if(pos==0 or !head)	{
		InsertAtHead(head, key);
	}
	else if(pos>length(head))	{
		InsertAtTail(head, key);
	}
	else	{
		Node *temp = head;
		while(--pos)	{
			temp = temp->next;
		}
		Node *dummy = new Node(key);
		dummy->next = temp->next;
		temp->next = dummy;
	}
}

void Delete(Node *&head, int pos)	{
	if(pos>=length(head) or !head)	return;
	if(pos==0)	{
		Node *temp = head->next;
		delete(head);
		head = temp;
		return;
	}
	Node *temp = head;
	while(--pos)	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

int Search(Node *head, int key)	{
	int pos = 0;
	while(head and head->val!=key)	{
		pos++;
		head = head->next;		
	}
	if(!head)	return -1;
	else return pos;
}

Node *takeInput()	{
	int d;
	Node *head=NULL;
	while(cin>>d)	{
		InsertAtTail(head, d);
	}
	return head;
}

void printLL(Node *head)	{
	while(head)	{
		cout<<head->val<<" -> ";
		head = head->next;
	}
	cout<<endl;
}

void reverse(Node *&head)	{
	Node* prev=NULL, *next;
	while(head)	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
}


//Operator Overloading
ostream &operator<<(ostream &os, Node *head)	{
	printLL(head);
	return os;
}

istream &operator>>(istream &is, Node *&head)	{
	head = takeInput();
	return is;
}


int main()	{
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif

    	Node *head = NULL, *head1=NULL;
    	InsertAtHead(head, 0);
    	InsertAtHead(head, 1);
    	InsertAtHead(head, 2);
    	InsertAtHead(head, 3);
    	InsertAtTail(head, 69);
    	InsertAtPos(head, 42, 0);
    	Delete(head, 6);
    	cout<<head;
    	Delete(head, 1);
    	cout<<"Found at index "<<Search(head, 3)<<endl;

    	//Using Operator Overloading
    	cin>>head1;
    	cout<<head1<<head;
    	reverse(head1);
    	cout<<head1;
    	return 0;
}