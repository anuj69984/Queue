#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node* head;

void insertAtBeg(int x){
	node* newnode= new node;
	newnode->data=x;
	newnode->next=head;
	head=newnode;
}

// we can insert an element in O(1) i.e constant time by keeping record of
// last node.
// this implementation takes O(n) time.
void push(int x){
	if (head == NULL)
	{
		insertAtBeg(x);
	}
	else{
		node* temp=head;
		node* newnode=new node;
		newnode->data=x;
		newnode->next=NULL;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;		
	}
}

void pop(){
	node* temp=head;
	if (temp==NULL)
	{
		cout<<"Queue is Empty\n";
		return;
	}
	else{
		
		head=temp->next;
		delete(temp);
	}
}

void print(){
	node* temp=head;
	cout<<"List is : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int count(){
	if (head==NULL)
	{
		return 0;
	}
	else{
		node* temp=head;
		int cnt=0;
		while(temp !=NULL){
			cnt++;
			temp=temp->next;
		}
		return cnt;
	}
	
}

bool IsEmpty(){
	if (head==NULL)
		return true;
	return false;
}

int front(){
	if (head==NULL)
	{
		return 0;
	}
	else
		return (head->data);
}

int main(int argc, char const *argv[])
{
	head=NULL;
	insertAtBeg(3);
	insertAtBeg(2);
	insertAtBeg(1);
	print();
	cout<<"******************\n";
	push(4);
	push(5);
	push(6);
	cout<<"no of elements is : "<<count()<<endl;
	print();
	cout<<"************************\n";
	cout<<"front element is : "<<front()<<endl;
	cout<<IsEmpty()<<endl;
	cout<<"************************\n";
	pop();
	cout<<"no of elements is : "<<count()<<endl;
	print();
	cout<<"************************\n";
	pop();
	cout<<"no of elements is : "<<count()<<endl;
	print();

	return 0;
}