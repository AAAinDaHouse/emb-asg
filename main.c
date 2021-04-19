#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//creating a student structure to hold student data
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


int num_of_elements=0;                                   //creates integer responsible for saving the size of dynamic array
struct student* array_of_students;                       //creates a pointer to the dynamic array
struct student* create_array(int num);
void add_at_first();
void add_at_last();
void add_at_middle(int index);

void get_data(struct student *std);

void Linked_list(int N);
void InsertAtFirst();
void InsertAtMiddle(int index);
void InsertAtEnd();
struct node*head=NULL,*tail=NULL;                        /*creating the head and tail pointers and initializing them to NULL*/
int Number_of_nodes=0;


void compare_InsertAtFirst(int N);
void compare_InsertAtMiddle(int N);
void compare_InsertAtEnd(int N);


int main()
{
printf("Welcome to the student system...\n\n\n");
//calculating the size taken by the structure and one node in memory.
printf("the size taken by the structure in memory: %d \n",sizeof(struct student));
printf("the size taken by the node in memory: %d \n\n",sizeof(struct node));

//comparison for a small value of N:
printf("for a small value of N: \n");
compare_InsertAtFirst(5000);
compare_InsertAtMiddle(5000);
compare_InsertAtEnd(5000);
//comparison for a medium value of N:
printf("for a middle value of N: \n");
compare_InsertAtFirst(50000);
compare_InsertAtMiddle(50000);
compare_InsertAtEnd(50000);
//comparison for a large value of N:
printf("for a large value of N: \n");
compare_InsertAtFirst(1000000);
compare_InsertAtMiddle(1000000);
compare_InsertAtEnd(1000000);

    return 0;
}

void get_data(struct student *std)                       //this function takes the student's data from user
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


struct student* create_array(int num)                   //this function creates a dynamic array for user taking its size as an argument
{
 struct student *array=(struct student*) malloc(num*sizeof(struct student));
 num_of_elements=num;
 return array;                                          //the function returns a pointer to array of structures to be saved
}

void add_at_first()                                     //this function is used to add an element in the beginning of array
{
  num_of_elements++;
  struct student *array=(struct student*) malloc((num_of_elements)*sizeof(struct student));
  for (int i=0;i<num_of_elements-1;i++)                 //this loop is to transfer data from old array to the new one
  {
    array[i+1]=array_of_students[i];
  }

  free(array_of_students);                              //the old version of data is freed
  array_of_students=array;                              //the new modified version of data is saved in the dynamic array
}

void add_at_last()                                      //this function is used to add an element in the beginning of array
{
  num_of_elements++;
  struct student *array=(struct student*) malloc((num_of_elements)*sizeof(struct student));
  for (int i=0;i<num_of_elements-1;i++)
  {
    array[i]=array_of_students[i];
  }

  free(array_of_students);
  array_of_students=array;
}

void add_at_middle(int index)                           //this function is used to add an element in the beginning of array
{
  while(index<1||index>=num_of_elements)                 //this loop is to make sure user is entering suitable index to add element in it
  {
    printf("wrong integer for insertion, try an integer between 1 and %d",num_of_elements-1);
    scanf("%d",&index);
  }
  num_of_elements++;
  struct student *array=(struct student*) malloc((num_of_elements)*sizeof(struct student));
  for (int i=0;i<index;i++)                             //this loop transfer all data before index from old array to new one
  {
    array[i]=array_of_students[i];
  }

  for (int i=index+1;i<num_of_elements;i++)               //this loop transfer all data after index from old array to new one
  {
    array[i]=array_of_students[i-1];
  }

  free(array_of_students);
  array_of_students=array;
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
/*A function that compares the insertion at the beginning of a linked list and a dynamic array of N elements
------------------------------------------------------------------------------------------------------------*/
void compare_InsertAtFirst(int N)
{
    Linked_list(N);
    array_of_students=create_array(N);

    double t;
    //the next part captures two clocks before and after using the function. Calculating the difference between them gives the execution time.
    t=clock();
    InsertAtFirst();
    t=clock()-t;
    printf("The time taken to insert at first in linked list: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);

    t=clock();
    add_at_first();
    t=clock()-t;
    printf("The time taken to insert at first in array: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);
    //freeing the created dynamic array and linked list.
    free(array_of_students);
    struct node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
/*A function that compares the insertion at the middle of a linked list and a dynamic array of N elements
------------------------------------------------------------------------------------------------------------*/
void compare_InsertAtMiddle(int N)
{

    Linked_list(N);
    array_of_students=create_array(N);

    double t;

    t=clock();
    InsertAtMiddle(N/2);
    t=clock()-t;
    printf("The time taken to insert at middle in linked list: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);

    t=clock();
    add_at_middle(N/2);
    t=clock()-t;
    printf("The time taken to insert at middle in array: %lf ms \n", (double)(t/CLOCKS_PER_SEC)*1000);

    free(array_of_students);
    struct node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
/*A function that compares the insertion at the end of a linked list and a dynamic array of N elements
------------------------------------------------------------------------------------------------------------*/
void compare_InsertAtEnd(int N)
{
    Linked_list(N);
    array_of_students=create_array(N);

    double t;

    t=clock();
    InsertAtEnd();
    t=clock()-t;
    printf("The time taken to insert at end in linked list: %lf ms \n", (double)(t/CLOCKS_PER_SEC)*1000);

    t=clock();
    add_at_last();
    t=clock()-t;
    printf("The time taken to insert at end in array: %lf ms \n\n\n", (double)(t/CLOCKS_PER_SEC)*1000);

    free(array_of_students);
    struct node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}



