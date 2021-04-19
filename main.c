#include <stdio.h>
#include <stdlib.h>


struct student
{
    char std_name[30];
    int std_id, std_day, std_month, std_year, std_lastscore;

};
//creates a structure that contains the data of student

int num_of_elements=0;                                   //creates integer responsible for saving the size of dynamic array
struct student* array_of_students;                       //creates a pointer to the dynamic array
void get_data(struct student *std);
struct student* create_array(int num);
void add_at_first();
void add_at_last();
void add_at_middle(int index);

int main()
{
    printf("Welcome to the student system...\n\n\n");

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
  while(index<1||index>num_of_elements)                 //this loop is to make sure user is entering suitable index to add element in it
  {
    printf("wrong integer for insertion, try an integer between 1 and %d",num_of_elements);
    scanf("%d",&index);
  }
  num_of_elements++;
  struct student *array=(struct student*) malloc((num_of_elements)*sizeof(struct student));
  for (int i=0;i<index;i++)                             //this loop transfer all data before index from old array to new one
  {
    array[i]=array_of_students[i];
  }

  for (int i=index;i<num_of_elements;i++)               //this loop transfer all data after index from old array to new one
  {
    array[i]=array_of_students[i-1];
  }

  free(array_of_students);
  array_of_students=array;
}


