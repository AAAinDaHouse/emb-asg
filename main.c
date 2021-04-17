#include <stdio.h>
#include <stdlib.h>


struct student
{
    char std_name[30];
    int std_id, std_day, std_month, std_year, std_lastscore;

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

int main()
{
printf("Welcome to the student system...\n\n\n");

    return 0;
}
