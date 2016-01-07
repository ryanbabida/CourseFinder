//Author: Ryan Babida

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "vector.h"


//prototype functions
int get_choice(); 
void display_info();


int main(int argc, char *argv[])
{
  int courses_size = 100;
  int students_size = 10;
  Course *courses;
  Student *students;

  read_courses(argv[1], &courses, &courses_size);
  read_students(argv[2], &students, &students_size);
  display_info(courses, students, courses_size, students_size);
  deallocate(courses, students, students_size);

  return 0;
} //end main


int get_choice()
{
  int choice;

  do
  {
    printf("\nRSVP Menu\n");
    printf("0. Done.\n1. Find by CRN.\n2. Find by subject.\n");
    printf("3. Add course.\n4. Remove course.\n");
    printf("Your choice (0 - 4): ");
    scanf("%d", &choice);
    fgetc(stdin);
    if (choice != 0 && choice != 1 && choice != 2 && choice != 3 
      && choice != 4)
    {
      printf("Your choice is outside the acceptable range. "
        "Please try again.\n");
    } //end if
  } while(choice != 0 && choice != 1 && choice != 2 && choice != 3 
      && choice != 4); //end do while
  return choice;
} //end get_choice()


void display_info(Course *courses, Student *students, int courses_size, int students_size)
{
  int choice = -1; 
  
  while(choice != 0)
  {
    choice = get_choice(); 
    if (choice == 1)
    {
      find_CRN(courses, students, courses_size, students_size);
    } //end if
    else
      if (choice == 2)
      {
        find_subject(courses, courses_size); 
      } //end else if
    else
      if (choice == 3)
      {
        add_course(courses, students, courses_size, students_size); 
      } //end else if
    else
      if (choice == 4)
      {
        remove_course(students, students_size); 
      } //end else if
  } //end while
} //end display_info()