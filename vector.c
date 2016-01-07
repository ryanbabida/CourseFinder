//Author: Ryan Babida

#include <stdio.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "vector.h"

void initialize_courses(Course **courses, int *courses_size)
{
  *courses = (Course *) malloc((*courses_size) * sizeof(Course)); 
} //end initialize_courses()


void resize_courses(Course **courses, int *courses_size, int count)
{
  int i;
  Course *temp; 

  if (*courses_size == count)
  {
    *courses_size *= 2; 
    temp = (Course *) malloc ((*courses_size) * sizeof(Course)); 
  
    for (i = 0; i < *courses_size / 2; i++)
    {
      temp[i] = (*courses)[i];
    } //end for
    
    free(*courses);
    *courses = temp;
  } //end if
} //end resize_courses()


void initialize_students(Student **students, int *students_size)
{
  *students = (Student *) malloc((*students_size) * sizeof(Student));
} //end initialize_students()


void resize_students(Student **students, int *students_size, int count)
{
  int i; 
  Student *temp; 

  if (*students_size == count)
  {
    *students_size *= 2; 
    temp = (Student *) malloc ((*students_size) * sizeof(Student)); 

    for (i = 0; i < *students_size / 2; i++)
    {
      temp[i] = (*students)[i];
    } //end for

    free (*students);
    *students = temp;
  } //end if
} //end resize_students()


void deallocate(Course *courses, Student *students, int students_size)
{
  int i;

  free(courses);

  for (i = 0; i < students_size; i++)
  {
    free(students[i].first_name);
    free(students[i].last_name);
  } //end for

  free(students);
} //end deallocate()



