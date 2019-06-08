#include<iostream>
using namespace std;

class Node
{
	public:
	Node *next;
	int value;
	Node()
	{
		next=NULL;
	
		
	}
	Node(int d)
	{
		next=NULL;
		value=d;
	}
	
	~Node()
	{
		cout<<"Deleted"<<endl;	
	}
	
};
class  linkedlist
{
	public:
		Node *head;
    	linkedlist()
    	{
    		head=NULL;
		}
		
		void insertAtLast(int value)
		{
			Node *temp=new Node();
			temp->value=value;
			if(head == NULL)
			{
				head=temp;
			}
			else
			{
				//head->next=temp;
				Node *p=head;
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=temp;
				
			}
		}
		void display()
		{
			Node *p=head;
			while(p!=NULL)
			{
				cout<<p->value<<"->";
				p=p->next;
			}
			cout<<"NULL"<<endl;
		}
		
		void deletebyIndex(int index)
		{
			
			if(index <= 0)
			{
				return;
			}
			if(index==1)
			{
				Node*temp=head;
				head=head->next;
				delete temp;
				return;
			}
			else
			{
				Node *current=head;
				int ind=1;
				while(current!=NULL && (ind+1)<index)
				{
					current=current->next;
					ind++;
				}
				if(current==NULL || current->next==NULL)
				{
					return;
				}
				Node*temp=current->next;
				current->next=temp->next;
				delete temp;
				//current.next=current.next.next;
		}
	}
	
	void deletebyValue(int value)
	{
		while(head!=NULL && head->value==value )	
		//	if(head!=NULL && head->value==value )
		{
			Node *temp=head;
			head=head->next;
			delete temp;	
		}
		
		Node *current=head;
		while(current!=NULL)
		{
			if(current->next!=NULL && current->next->value==value)
			{
				Node *temp=current->next;
				current->next=temp->next;
				delete temp;
			}
			else
			current=current->next;
		}
	}
	void insertAtIndex(int index,int value)
	{
		if(index<=0)
		return;
		
		Node *new_node=new Node(value);
		if(index==1)
		{
			new_node->next=head;
			head=new_node;
			return;
		}
		
		Node *current=head;
		int i=1;
		while(current!=NULL && i<index-1)
		{
			current=current->next;
			i++;
			
		}
		
		if(current==NULL)
		{
			if(i<index)
			cout<<"index not avilable"<<endl;
			return;
		}
		new_node->next=current->next;
	    current->next=new_node;
	}
	
};




int main()
{
	linkedlist ll;
	//insert into list
	ll.insertAtLast(10);
//	ll.insertAtLast(10);
//	ll.insertAtLast(10);
	ll.insertAtLast(20);
	ll.insertAtLast(30);
	ll.insertAtLast(40);
	ll.insertAtLast(50);
	
//	ll.insertAtLast(10);
//	ll.insertAtLast(20);
//	ll.insertAtLast(30);
//	ll.insertAtLast(40);
//	ll.insertAtLast(50);
//	ll.insertAtLast(50);
//	ll.insertAtLast(50);
	ll.display();
	
	//delete from list
//	ll.deletebyIndex(3);
//	ll.display();
//	ll.deletebyIndex(1);
//	ll.display();
//	ll.deletebyIndex(5);
//	ll.display();
//	ll.deletebyIndex(7);
//	ll.deletebyValue(40);
//	ll.display();

ll.insertAtIndex(7,60);
ll.display();

	
	return 0;	
}
