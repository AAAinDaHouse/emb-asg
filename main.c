#include <stdio.h>
#include <stdlib.h>

struct student
{
    char std_name[30];
    int std_id, std_day, std_month, std_year, std_lastscore;
};
/*creating a node structure that contains both data of type structure student and a pointer to node */
struct node
{
struct student data;
struct node* next;
};


void get_data(struct student *std)
{
    printf ("Enter student name: ");
    gets(std->std_name);
    printf("Enter student ID: ");
    scanf("%d",&(std->std_id));
    printf("Enter student date of birth(dd mm yyyy): ");
    scanf("%d",&(std->std_day));
    scanf("%d",&(std->std_month));
    scanf("%d",&(std->std_year));
    printf("Enter student last score: ");
    scanf("%d",&(std->std_lastscore));
}



void Linked_list(int N);
void InsertAtFirst();
void InsertAtMiddle(int index);
void InsertAtEnd();
struct node*head=NULL,*tail=NULL; /*creating the head and tail pointers and initializing them to NULL*/
int Number_of_nodes=0;

int main()
{
printf("Welcome to the student system...\n\n\n");

    return 0;
}

/*defining a function that creates a linked list of N elements
---------------------------------------------------------------*/
void Linked_list(int N)
{   struct node *New; /*A pointer that holds the address of each new node we create in the heap*/
    struct node **p;  /*A pointer that points at the next pointer in each new node we create*/
    head=(struct node*)malloc(sizeof(struct node)); /*creating the first node and pointing to it with head*/
    p=&(head->next); /*pointing to the next pointer of the first node with the pointer p*/
    for(int k=1;k<N;k++)
    {
        New=(struct node*)malloc(sizeof(struct node));
        *p=New;
        p=&((*p)->next);
    }
    /*pointing with the tail pointer to the last created node and assigning its next to NULL*/
    tail=New;
    tail->next=NULL;
    Number_of_nodes=N;
}

/*defining a function that inserts a new node at the beginning of our list.
--------------------------------------------------------------------------*/
void InsertAtFirst()
{
    struct node* New=(struct node*)malloc(sizeof(struct node));
    New->next=head;
    head=New;
    Number_of_nodes++;
}

/*defining a function that inserts a new node at middle of our list.
this function takes the variable index that determines where the new node is to be inserted.
index should takes a value from 1,2,...,Number_of_nodes-1.
-------------------------------------------------------------------------------------------*/
void InsertAtMiddle(int index)
{  /*ensuring that index is in the available range*/
   label:if(index>=Number_of_nodes || index<=0)
           {printf("wrong index for insertion.Try an integer between 1 and ");
            printf("%d",Number_of_nodes-1);
            printf("\n");
            scanf("%d",&index);
            goto label;
           }
     else  {
         struct node* New=(struct node*)malloc(sizeof(struct node));
         struct node **p;
         p=&(head->next);   /*pointing with p at the next pointer of the first node*/
         for(int i=1;i<=index-1;i++) /*A loop that updates p until it points at the next pointer of the node preceding our new node */
             p=&((*p)->next);
         New->next=*p;
         *p=New;
         Number_of_nodes++;
           }
}

/*defining a function that inserts a new node at the end of our list.
--------------------------------------------------------------------*/
void InsertAtEnd()
{
    struct node* New=(struct node*)malloc(sizeof(struct node));
    tail->next=New;
    tail=New;
    tail->next=NULL;
    Number_of_nodes++;
}
