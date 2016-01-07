//Author: Ryan Babida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "course.h"
#include "student.h"
#include "vector.h"

void read_courses(char *filename, Course **courses, int *courses_size)
{
  int crn, count = 0;
  char temp[100], *ptr;
  FILE *fp = fopen(filename, "r");
  if(fp == NULL)
  {
    printf("File cannot be opened.\n");
    exit(1);
  }
  else
    {
    initialize_courses(courses, courses_size);
    while(fgets(temp, 100, fp) != NULL)
    {
      if (isdigit(temp[0]) && isdigit(temp[1]) && isdigit(temp[2]) 
        && isdigit(temp[3]) && isdigit(temp[4]))
      {
        resize_courses(courses, courses_size, count);
        ptr = strtok(temp, "\t");
        crn = atoi(ptr);
        (*courses)[count].crn = crn;
        ptr = strtok(NULL, "\t");
        if (strcmp(ptr, "^") == 0)
          ptr = strtok(NULL, "\t");
        strcpy((*courses)[count].subject, ptr);
        ptr = strtok(NULL, "\t");
        strcpy((*courses)[count].course_num, ptr);
        count++;
      } //end if
    } //end while
  } //end else
  *courses_size = count;
  fclose(fp);
} //end read_courses()


void find_CRN(Course *courses, Student *students, int courses_size, 
  int students_size)
{
  int crn, found, i, j, k;

  found = 0;
  printf("Please enter a CRN: ");
  scanf("%d", &crn);

  for (i = 0; i < courses_size; i++)
  {
    if (crn == courses[i].crn)
    {
      printf("%s %s\n", courses[i].subject, courses[i].course_num);
      for (j = 0; j < students_size; j++)
      {
        for (k = 0; k < students[j].class_count; k++)
        {
          if (crn == students[j].crns[k])
          {
            printf("%s %s\n", students[j].last_name, students[j].first_name);
          } //end if
        } //end for
      } //end for
      found = 1;
    } //end if
  } //end for
  if (found == 0)
  {
    printf("CRN %d not found.\n", crn);
  }  //end if
} //end find_CRN()


void find_subject(Course *courses, int courses_size)
{
  char input[SUBJ_SIZE];
  int i, found; 

  found = 0;
  printf("Please enter a subject: ");
  fgets(input, 4, stdin);
  for (i = 0; i < courses_size; i++)
  {
    if (strcmp(input, courses[i].subject) == 0)
    {
      printf("%d %s %s\n", courses[i].crn, courses[i].subject, 
        courses[i].course_num);
      found = 1;
    } //end if
  } //end for
  if (found == 0)
  {
    printf("No courses were found for %s.\n", input);
  }
} //end find_subject()


void add_course(Course *courses, Student *students, int courses_size, 
  int students_size)
{
  int found_crn, found_student, crn, i, j;
  char id[ID_SIZE];
  printf("Add Course\nPlease enter the SID of the student: ");
  fgets(id, 12, stdin);
  for (i = 0; i < students_size; i++)
  {
    if (strcmp(id, students[i].id) == 0)
    {
      found_student = 1;
      if (students[i].class_count == 5)
      {
        printf("You are already taking 5 courses.\n");
        found_crn = 1;
      }
      else
      {
        printf("Please enter CRN: "); 
        scanf("%d", &crn);
        for (j = 0; j < courses_size; j++)
        {
          if (crn == courses[j].crn)
          {
            found_crn = 1;
            students[i].crns[students[i].class_count] = crn;
            students[i].class_count++;
          } //end if
        } //end for
      } //end if else
    } //end if
  } //end for
  if (found_crn == 0)
    printf("There is no course with CRN #%d\n", crn);
} //end add_course()