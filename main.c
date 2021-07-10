#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

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

struct student* create_array(int* N);
void Insert_In_Array(int* N ,struct student**Array,int index,struct student DATA);

void get_data(struct student *std);
void display_data(struct student *std);

void Linked_list(int* N,struct node**head,struct node**tail);
void Insert_In_List(int*N,struct node**head,struct node**tail,int index,struct student DATA);

void COMPARE(int N); //function used to compare time taken by linked list & dynamic array

void ignore()
{
char dumb[1];
gets(dumb);
}


int main()
{
printf("\n\n   ...Welcome to the student system...\n\n\n");
struct node* head=NULL;
struct node* tail=NULL;
int n_list=0;
int n_array=0;
struct student* array=NULL;
struct student data;
int choice=-1;


while(1)
{
    printf("\nUtilize an array or linked list,compare time complexity,and exit:(array=0,linked list=1,complexity comparison=2,exit=3)\n");
    scanf("%d",&choice);
    switch (choice)
{
    case 0:
    {
    if (n_array==0)
    {
    printf("please, enter number of students.\n");
    scanf("%d",&n_array);
    ignore();
    array=create_array(&n_array);
    for(int j=0;j<n_array;j++)
      {
        get_data(array+j);
      }
    }

    else
    {
    printf("do you want to display a student or insert new student: (insert=0, display=1)");
    scanf("%d",&choice);
    ignore();
    if (choice==0)
    {
        printf("please, enter the data of the student.\n");
        get_data(&data);
        printf("please, enter the index of the student.\n");
        int i;
        scanf("%d",&i);
        Insert_In_Array(&n_array ,&array ,i,data);
    }
    else if(choice==1)
    {
        printf("please, enter the index of the student.\n");
        int i;
        scanf("%d",&i);
        if(i>=n_array){printf("no info!\n");}
        else {display_data(&array[i]);}
    }
    else {printf("WRONG CHOICE!\n");}
    }

    choice=0;
break;

}

case 1:
    {

      if (n_list==0)
    {
    printf("please, enter number of students.\n");
    scanf("%d",&n_list);
    ignore();
    Linked_list(&n_list,&head,&tail);
    struct node* temp=head;
    for(int j=0;j<n_list;j++)
      {
        get_data(&(temp->data));
        temp=temp->next;
      }
    }
    else
    {
    printf("do you want to display a student or insert new student: (insert=0, display=1)");
    scanf("%d",&choice);
    ignore();
    if (choice==0)
    {
        printf("please, enter the data of the student.\n");
        get_data(&data);
        printf("please, enter the index of the student.\n");
        int i;
        scanf("%d",&i);
        Insert_In_List(&n_list,&head,&tail,i,data);
    }
    else if(choice==1)
    {
        printf("please, enter the index of the student.\n");
        int i;
        scanf("%d",&i);
        if(i>=n_list){printf("no info!\n");}
        else{
        struct node* temp=head;
        for(int j=0;j<i;j++)
        {
            temp=temp->next;
        }
        display_data(&(temp->data));
        }
    }
    else {printf("WRONG CHOICE!\n");}
    }
    choice=1;

    break;
    }


case 2:
    {
        printf("\n Comparison of time complexity of array and linked list: \n");
        printf("For small number of elements:\n");
        COMPARE(100);
        printf("\nFor medium number of elements:\n");
        COMPARE(100000);
        printf("\nFor large number of elements:\n");
        COMPARE(1000000);
        break;
    }

case 3:
    {
        return 0;
    }
default:
    {
        printf("WRONG CHOICE!\n");
    }
}

}

return 0;
}

void get_data(struct student *std)                  //this function takes the student's data from user
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
    ignore();
}

void display_data(struct student *std)
{
    printf ("student name: ");
    printf("%s\n",std->std_name);
    printf("student ID: ");
    printf("%d\n",std->std_id);
    printf("student date of birth: ");
    printf("%d/",std->std_day);
    printf("%d/",std->std_month);
    printf("%d/\n",std->std_year);
    printf("student last score: ");
    printf("%d\n",std->std_lastscore);

}


struct student* create_array(int* N)                   //this function creates a dynamic array for user taking its size as an argument
{
 struct student *array=(struct student*) malloc((*N)*sizeof(struct student));
 return array;                                       //the function returns a pointer to array of structures to be saved
}


void Insert_In_Array(int* N, struct student**Array,int index,struct student DATA)        //this function is used to add an element in the beginning of array
{
  while(index<0||index>*N)                 //this loop is to make sure user is entering suitable index to add element in it
  {
    printf("wrong integer for insertion, try an integer between 0 and %d",*N);
    scanf("%d",&index);
  }
  (*N)++;
  struct student *array=(struct student*) malloc((*N)*sizeof(struct student));
  strcpy(array[index].std_name,DATA.std_name);
  array[index].std_id=DATA.std_id;
  array[index].std_day=DATA.std_day;
  array[index].std_lastscore=DATA.std_lastscore;
  array[index].std_month=DATA.std_month;
  array[index].std_year=DATA.std_year;
  //insertion at the beginning:
  if(index==0)
  {
  for (int i=1;i<(*N);i++)                 //this loop is to transfer data from old array to the new one
  {
    array[i]=(*Array)[i-1];
  }

  free(*Array);                              //the old version of data is freed
  *Array=array;
  }
  //insertion at the end:
  else if(index==*N)
  {
  for (int i=0;i<(*N)-1;i++)
  {
    array[i]=(*Array)[i];
  }

  free(*Array);
  *Array=array;
  }
  //insertion at the middle:
  else
  {
  for (int i=0;i<index;i++)                             //this loop transfer all data before index from old array to new one
  {
    array[i]=(*Array)[i];
  }

  for (int i=index+1;i<*N;i++)               //this loop transfer all data after index from old array to new one
  {
    array[i]=(*Array)[i-1];
  }

  free(*Array);
  *Array=array;
  }
}

/*defining a function that creates a linked list of N elements
---------------------------------------------------------------*/

void Linked_list(int*N,struct node**head,struct node**tail)
{   struct node *New; /*A pointer that holds the address of each new node we create in the heap*/
    *head=(struct node*)malloc(sizeof(struct node)); /*creating the first node and pointing to it with head*/
    struct node *current=*head;
    for(int k=1;k<*N;k++)
    {
        New=(struct node*)malloc(sizeof(struct node));
        current->next=New;
        current=current->next;
    }
    /*pointing with the tail pointer to the last created node and assigning its next to NULL*/
    *tail=New;
    (*tail)->next=NULL;
}


void Insert_In_List(int*N,struct node**head,struct node**tail,int index,struct student DATA)
{  /*ensuring that index is in the available range*/
    while(index>*N || index<0)
         {
            printf("wrong index for insertion.Try an integer between 0 and %d \n",*N);
            scanf("%d",&index);
         }
    struct node* New=(struct node*)malloc(sizeof(struct node));
    New->data.std_day=DATA.std_day;
    New->data.std_id=DATA.std_id;
    New->data.std_lastscore=DATA.std_lastscore;
    New->data.std_month=DATA.std_month;
    New->data.std_year=DATA.std_year;
    strcpy(New->data.std_name,DATA.std_name);
    //insertion at beginning:
    if(index==0)
      {
            New->next=*head;
            *head=New;
            (*N)++;
      }
    //insertion at end:
    else if(index==*N)
      {
           (*tail)->next=New;
            *tail=New;
           (*tail)->next=NULL;
           (*N)++;

      }
    //insertion at middle:
    else
      {
         struct node *temp;
         temp=*head;
         for(int i=1;i<index;i++) /*A loop that updates p until it points at the next pointer of the node preceding our new node */
             temp=temp->next;
         New->next=temp->next;
         temp->next=New;
         (*N)++;
      }

}

/*a function that compares the time complexity of insertion in a linked list and an array at different positions*/
void COMPARE(int N)
{
   int N_array=N;
   int N_list=N;
   struct student* array=NULL;
   struct node* head=NULL;
   struct node* tail=NULL;
   struct student data;
   double t;
    array=create_array(&N_array);
    Linked_list(&N_list,&head,&tail);
    printf("N=%d:\n",N);
    printf("size of the linked list: %lu bytes\n",N_list*sizeof(struct node));
    //insertion in list
    t=clock();
    Insert_In_List(&N_list,&head,&tail,0,data);
    t=clock()-t;
    printf("The time taken to insert at first in linked list: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);
    t=clock();
    Insert_In_List(&N_list,&head,&tail,N_list/2,data);
    t=clock()-t;
    printf("The time taken to insert at middle in linked list: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);
    t=clock();
    Insert_In_List(&N_list,&head,&tail,N_list,data);
    t=clock()-t;
    printf("The time taken to insert at end in linked list: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);

    printf("size of the array: %lu bytes\n",N_array*sizeof(struct student));
    //insertion in array
    t=clock();
    Insert_In_Array(&N_array,&array,0,data);
    t=clock()-t;
    printf("The time taken to insert at first in array: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);
    t=clock();
    Insert_In_Array(&N_array,&array,N_array/2,data);
    t=clock()-t;
    printf("The time taken to insert at middle in array: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);
    t=clock();
    Insert_In_Array(&N_array,&array,N_array,data);
    t=clock()-t;
    printf("The time taken to insert at end in array: %lf ms \n",(double)(t/CLOCKS_PER_SEC)*1000);

    free(array);
    struct node*temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}

