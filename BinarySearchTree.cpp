#include<iostream>
using namespace std;

class Node
{
	public:
    Node *left;
    Node *right;
    int value;
    Node()
    {
    	left=NULL;
    	right=NULL;
	}
	Node(int d )
	{
		left=NULL;
		right=NULL;
		value=d;
	}
};
class BinaryTree
{
	public:
	Node *root;
    BinaryTree()
	{
		root=NULL;
	}
	void inorder(Node *root)
	{
		if(root!=NULL)
		{	
		inorder(root->left);
		cout<<root->value<<" ";
		inorder(root->right);
	    }
	    	
	}	
	void preorder(Node *root)
	{
		if(root!=NULL)
		{
			cout<<root->value<<" ";
			preorder(root->left);
			preorder(root->right);
		}
	}
	void postorder(Node *root)
	{
		if(root!=NULL)
        {
        	postorder(root->left);
        	postorder(root->right);
        	cout<<root->value<<" ";
    	} 	
	}
	Node* createNode(int value)
	{
	    Node *temp=new Node(value);
		return temp;	
	}
    Node* insert(Node *root,int value)
    {   
    	if(root==NULL)
    	{
    	  	//Node *temp=createNode(value);
    	  	//root=temp;
    	  	root=createNode(value);
    	  	return root;
		}
		else if(root->value > value)
		{
		    	root->left= insert(root->left,value);
		}
		else if(root->value < value)
		{
			root->right=insert(root->right,value);
	    }
	}
	bool search(Node *root,int value)
	{
		if(root==NULL)
		{
			return false;
		}
		
		
		if (root->value < value)
		{
			return search(root->right,value);
		}
		else if(root->value > value)
		{
			return search(root->left,value);
		}
		else //(root->value == value)
		{
			return true;
		}
		
		return false;
	}
	Node* minNode(Node *root)
	{
		while (root->left != NULL)
		{
			root=root->left;
		}
		return root;
	}
	Node* deletion(Node *root,int value)
	{
		if(root == NULL)
		{
			return NULL;
		}
		if(root->value > value)
		{
			root->left = deletion(root->left,value);
		}
		else if(root->value < value)
		{
			root->right = deletion(root->right,value);
		}
		else //(root->value == value)
		{
			//case 1 : node is leaf node
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}
			//case 2 : node has one node OR node has one NULL
			else if(root->left == NULL || root->right == NULL )
			{
				Node *temp=NULL;
				if(root->left == NULL)
				{
					temp=root->right;
					delete root;
					return temp;
				}
				else if (root->right == NULL)
				{
					temp=root->left;
					delete root;
					return temp;
				}
			}
			// case 3 : node has both children
			else // root->left!==NULL && root->right == NULL
			{
				Node *mNode=minNode(root->right);
				root->value = mNode->value;
				deletion(root->right,mNode->value);
			}
		}
	}
};

int main()
{
	BinaryTree bst;
//	bst.root=new Node(10);
//	bst.root->left=new Node(5);
//	bst.root->right=new Node(15);
//	bst.root->left->left=new Node(4);
//	bst.root->left->right=new Node(6);
//	bst.root->right->left=new Node(11);
//	bst.root->right->right=new Node(16);
	
//triversal
//	bst.inorder(bst.root);
//	cout<<endl;
//	bst.preorder(bst.root);
//	cout<<endl;
//	bst.postorder(bst.root);

bst.root=bst.insert(bst.root,10);
bst.insert(bst.root,5);
bst.insert(bst.root,6);
bst.preorder(bst.root);
//cout<<endl;
//	if(bst.search(bst.root,6))
//	{
//		cout<<"the number is present in the BST"<<endl;
//	}
//	else
//	{
//		cout<<"the number is not present in the BST"<<endl;
//	}
}

