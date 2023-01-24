#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head=NULL;
void createList(int n)
{
	int val;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the value of node";
		cin>>val;
		Node *newNode=(Node*)malloc(sizeof(Node*));
		newNode->data=val;
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
			//cout<<"The address of head is"<<head<<endl;
		}
		else{
			Node* temp=head;
			while(temp->next!=NULL)
			{
				
				temp=temp->next;
				
			}
			temp->next=newNode;
			//cout<<"the value of newNode is"<<newNode<<endl;
			
		}
		
	}
}
//count the number of nodes
int countnode(Node *ptr)
{
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}
void display()
{
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"LInked List is Empty";
		
	}
	else{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	
}
void insertAtbig()
{
	Node* nN=(Node*)malloc(sizeof(Node*));
	int nval;
	cout<<"enter the value of new node"<<endl;
	cin>>nval;
	nN->data=nval;
	nN->next=NULL;
	if(head==NULL)
	{
		head=nN;
		
	}
	else{
			nN->next=head;
			head=nN;
	}
}
void delAtbig()
{
	Node* temp;
	if(head==NULL)
	{
		cout<<"The Linked List is Empty"<<endl;
		
	}
	else{
			temp=head;
			head=temp->next;
			
			cout<<"The address of temp is"<<temp<<endl;
			free(temp);
			//temp=head->next;
			//cout<<"The address of temp is"<<temp<<endl;
			
			
	}
}
void delAtend()
{
	Node* temp,*curr;
	if(head==NULL)
	{
		cout<<"The Linked List is Empty"<<endl;
		
	}
	else{
			temp=head;
			curr=head;
			while(temp->next!=NULL)
			{
				curr=temp;
				temp=temp->next;
				
			}
			curr->next=NULL;
		}
		free(temp);
}

void insertAtEnd()
{
	Node *prev;
	int n;
	Node* nNew=(Node*)malloc(sizeof(Node*));
	cout<<"Enter the value which is going to insert at the End";
	cin>>n;
	nNew->data=n;
	nNew->next=NULL;
	if(head==NULL)
	{
		cout<<"Linked List is Empty"<<endl;
		head=nNew;
		
	}
	else{
		prev=head;
		while(prev->next!=NULL)
		{
			prev=prev->next;
		}
		prev->next=nNew;
		
	}
	
}
void insert_at_mid()
{
	Node*temp, *prev;
	int pos, ctr = 1,n,nodectr;
	//newnode = getnode();
	Node* node=(Node*)malloc(sizeof(Node*));
	cout<<"\n Enter the value"<<endl;
	cin>>n;
	node->data=n;
	node->next=NULL;
	cout<<"\n Enter the position: ";
	cin>>pos;
	nodectr = countnode(head);
	temp = prev = head;
	if(pos>1 && pos<nodectr)
	{
		while(ctr < pos)
		{
			prev = temp;
			temp = temp -> next;
			ctr++;
			//cout<<"the value of ctr is"<<ctr<<endl;
		}
		prev -> next = node;
		node -> next = temp;

	}
	else{
		cout<<"the position is invalid";
	}
	
}


void delete_at_mid()
{
	int ctr = 1, pos, nodectr;
	Node *temp, *prev;
	if(head == NULL)
	{
		printf("\n Empty List..");
		return ;
	}
	else
	{
		cout<<"\n Enter position of node to delete: ";
		cin>>pos;
		nodectr = countnode(head);
		if(pos > nodectr)
		{
			cout<<"\nThis node doesnot exist";
		}
		if(pos > 1 && pos < nodectr)
		{
			temp = prev = head;
			while(ctr < pos)
			{
				prev = temp;
				temp = temp -> next;
				ctr ++;
			}
			prev -> next = temp -> next;
			free(temp);
			cout<<"\n Node deleted..";

		}
		else
		{
			cout<<"Invalid Position";
		}

}
}
void insertPos(Node** current, int pos, int data)
{

    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
        while (pos--) {
  
            if (pos == 0) {
  
                Node* temp = getNode(data);
  
                temp->next = *current;
  
                *current = temp;
            }
            else
              current = &(*current)->next;
        }
        size++;
    }
}
	
int main()
{
	
	createList(3);
	display();
	//insertAtbig();
	//display();
	//delAtbig();
	//delAtbig();
	//delAtbig();
	//delAtend();
	//display();
	insert_at_mid();
	//insertAtEnd();
	display();
	return 0;
}
