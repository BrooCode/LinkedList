#include <iostream>
using namespace std;

// Rahul Kumar Agrahari

void creat();
void display();
void removeFirstNode();
void removeLastNode();
void insertFirst(int x);
void insertLast(int x);
void insertSomewhere(int x,int pos);
void removeSomewhere(int x,int pos);
void sort();


struct node{
    int data ;
    struct node *next;
}*head;


int main() {
	int n,x,y;
	cin>>n>>x>>y;
	head=NULL;
	for(int i=0;i<n;i++)
	{
	    creat();
	}
// 	removeLastNode();
    // insertFirst(x);
    // insertLast(x);
    insertSomewhere(x,y);
	display();
	return 0;
}

void sort()
{
    node* temp = head; 
  
    while (temp) { 
        node* min = temp; 
        node* r = temp->next; 
  
        while (r) { 
            if (min->data > r->data) 
                min = r; 
  
            r = r->next; 
        } 
  
        int x = temp->data; 
        temp->data = min->data; 
        min->data = x; 
        temp = temp->next; 
    } 
}

void display()
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        cout<<"-->"<<t->data;
        t=t->next;
    }
}



void creat()
{
    struct node *t;
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    cin>>new_node->data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        t=head;
        while(t->next!=NULL)
        t=t->next;
        t->next=new_node;
    }
}



void insertLast(int x)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data=x;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        struct node *temp;
        while(temp->next!=NULL)
        {
             temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
}



void insertFirst(int x)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data=x;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}

void rev()
{
	struct node *t1,*t;
  t1=NULL;
  while(head->next!=NULL)
  {
    t=head;
    head=head->next;
    t->next=t1;
    t1=t;
  }
  head->next=t;	
}

void insertSomewhere(int x,int pos)
{
    struct node *new_node,*prev_ptr,*cur_ptr;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    cur_ptr=head;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
        prev_ptr=cur_ptr;
        cur_ptr = cur_ptr->next;
        }
        prev_ptr->next = new_node;
        new_node->next = cur_ptr;
    }
}




void removeLastNode() 
{ 
    if (head == NULL){ 
        cout<<"already empty";
    }
  else
    {
        struct node *temp1=head,*temp2;
        while(temp1->next!=NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next=NULL;
        delete temp1;
    }
}



void removeFirstNode() 
{ 
    if (head == NULL){ 
        cout<<"already empty";
    }
  else
    {
        struct node *temp = head;
        if(head->next == NULL)
        {
        delete temp;
        }
        else
        {
        head = temp->next;
        delete temp;
        }
    }
}



void removeSomewhere(int x,int pos)
{
    struct node *new_node,*prev_ptr,*cur_ptr;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    cur_ptr=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev_ptr=cur_ptr;
            cur_ptr = cur_ptr->next;
        }
        
    }
}

