//#include<iostream>
#include <stdio.h>
#include<stdlib.h>

/*
changes from C++ linkedList code
1. change new to malloc
2. change delete to free 
3. change class name to struct (as C dont have classes)
4. [IMP] struct dont have contructor/desturctor hence assign next to null while creating new Node
*/

//using namespace std;
//class Node 
struct Node
{    
	//public:
	Node *next;
	int value;	
//	Node() 
//	{
//		next=NULL;
//	}
//	Node(int d)
//	{
//		next=NULL;
//		value=d;
//	}
//	~Node()
//	{
//		//cout<<"deleted"<<endl;
//		printf("deleted\n");
//	}
};

//class linkedlist
struct linkedlist
{
	
	public:
	Node *head;
	linkedlist()
	{
		head=NULL;
	}
	void display()
	{
  		Node *current;
  		current=head;
  		while(current!=NULL)
  		{
  			//cout<<current->value<<"->";
  			printf("%d -> ",current->value);
  			current=current->next;
		  }
		  //cout<<"NULL"<<endl;
		  printf("NULL\n");
	}
	void insertAtLast(int value)
	{
		//Node *temp=new Node(value);
		Node *temp = (Node*)malloc(sizeof(Node));
		// exmp : int *i=(int*)malloc(sizeof(int));
		temp->value = value;
		temp->next = NULL;
		
		if(head==NULL)
		{
			head=temp;
			return;
		}
		
		Node *current=head;
		
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
	void insert(int value,int index)
	{
		
		//Node *temp=new Node(value);
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->value = value;
		temp->next = NULL;
		
		if(index==0)
		{
			temp->next=head;
			head=temp;
			return;
		}
        
		int i=0;
		Node *current =head;
		while(current!=NULL && i<index-1)
		{
			current =current->next;
			i++;
		}
		if(current==NULL) 
        {
        	return;
		}
		temp->next=current->next;
		current->next=temp;	
	}
	
	void deletebyIndex(int index)
	{
		Node *current=head;
		if(index==0)
		{
			Node *temp=current;
			head=current->next;
			free(temp);
			//delete temp;
			return;
		}
		int i=0;
		while(current!=NULL && i<index-1)
		{
			current=current->next;
			i++;
		}
		if(current==NULL || current->next==NULL)
		{
			return;
		}
		Node *temp=current->next;
		current->next=temp->next;
	    //delete temp;
	    free(temp);
	}
	void deleteByValue(int value)
	{
		Node *current=head;
		
		while(current!=NULL && current->value==value)
		{
			Node *temp=current;
			current=current->next;
			head=current;
			free(temp);
			//delete temp;
		}
		
		while(current!=NULL )
		{
			if(current->next!=NULL && current->next->value==value)
			{
				Node *temp=current->next;
				current->next=temp->next;
				//delete temp;
				free(temp);
	    	}
	    	else
	    	{
	    		current =  current->next;
	    	}
		}
	}
	
};

int main()
{
	linkedlist ll;
	ll.insertAtLast(10);
//	ll.insertAtLast(10);
//	ll.insertAtLast(10);
//	ll.insertAtLast(20);
//	ll.insertAtLast(20);
	ll.insertAtLast(20);
	ll.insertAtLast(30);
	ll.insertAtLast(40);
	ll.insertAtLast(50);
	ll.display();
//	ll.deleteByValue(20);
//	ll.display();
ll.insert(60,4);
ll.display();
}
