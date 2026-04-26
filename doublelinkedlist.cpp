//double linked list
#include <stdio.h>
#include <stdlib.h>
void creation();
void insert_beg();
void insert_last();
void display();
void insert_posi();
void delete_first();
void delete_last();
void delete_posi();

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;
int main()
{
	int ch;
	while(1)
	{
printf("\n1.creation\n2.display\n3.insert_begin\n4.insert_last\n");
printf("5.insert_atposi\n6.del_first\n7.del_last\n8.del_posi\n9.exit\n");
printf("enter your choice");
	scanf("%d",&ch);
		switch(ch)
		{
	case 1:	creation();break;
	case 2:display();break;
	case 3:insert_beg();break;
	case 4:insert_last();break;
	case 5:insert_posi();break;
	case 6:delete_first();break;
	case 7:delete_last();break;
	case 8:delete_posi();break;
	case 9:exit(0);
        }
    }
	return 0;
}
//creation
void creation()
{
	struct node *new_node,*t;
	int ele;
	printf("enter element\n -999 to stop\n");
	scanf("%d",&ele);
	while(ele!=-999)
	{
new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=ele;
		new_node->next=NULL;
		new_node->prev=NULL;
		if(head==NULL)
		{
		head=new_node;
		t=new_node;
	    }
		else
		{
			t->next=new_node;
			new_node->prev=t;
			t=new_node;
		}
		scanf("%d",&ele);
	}
}
//display
void display()
{
	int i;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->next;
	}
}
//insert element at beginning
void insert_beg()
{
	struct node *new_node;
	int ele;
new_node=(struct node*)malloc(sizeof(struct node));
printf("enter element to be inserted\n");
	scanf("%d",&ele);
	new_node->data=ele;
	new_node->prev=NULL;
	new_node->next=head;
	head->prev=new_node;
	head=new_node;
}

//insertion at last
void insert_last()
{
	struct node *new_node,*temp;
	int ele;
	temp=head;
printf("enter element to be inserted\n");
	scanf("%d",&ele);
	new_node->data=ele;
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head==NULL)
	head=new_node;
	else
	{
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
    }
}

//insertion at given position
void insert_posi()
{
   int ele,posi,i=1;
	struct node *temp=head,*new_node;
new_node=(struct node*)malloc(sizeof(struct node));
printf("enter element to be inserted\n");
	scanf("%d",&ele);
	printf("enter position \n");
	scanf("%d",&posi);
	new_node->data=ele;
	new_node->next=NULL;
	new_node->prev=NULL;
	while(i<posi-1 && temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(temp->next!=NULL)
	{
	new_node->next=temp->next;
	temp->next->prev=new_node;
	temp->next=new_node;
	new_node->prev=temp;
    }
}
//delete first element
void delete_first()
{
	struct node *temp;
	temp=head;
	if (head!=NULL)
	{
    head=head->next;
    head->prev=NULL;
    }
free(temp);	
}
//delete last element
void delete_last()
{
	struct node *temp,*t;
	temp=head;
	if (head!=NULL)
	{
	while(temp->next->next!=NULL)
    temp=temp->next;
    }
    t=temp->next;
    temp->next=NULL;
free(t);	
}
//delete at given position
void delete_posi()
{
	struct node *temp,*t;
	int posi,i=1;
	temp=head;
	printf("Enter the position");
	scanf("%d",&posi);
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(i<posi-1 && temp->next!=NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp->next==NULL)
		{
		printf("position not found\n");
			return;
		}
		t=temp->next;
		temp->next=t->next;
		t->next->prev=temp;
		free(t);
	}
}
