//Author: Ryan Babida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "course.h"
#include "student.h"
#include "vector.h"

void read_students(char *filename, Student **students, int *students_size)
{
  char temp[100], *ptr; 
  int count = 0;
  FILE *fp = fopen(filename, "r");
  if(fp == NULL)
  {
    exit(1);
  }
  else
  {
    initialize_students(students, students_size);
    while (fgets(temp, 100, fp) != NULL)
    {
      resize_students(students, students_size, count);
      ptr = strtok(temp, ",");
      (*students)[count].last_name = (char *)malloc((strlen(ptr) + 1) * 
        sizeof(char));
      strcpy((*students)[count].last_name, ptr);
      ptr = strtok(NULL, ",");
      (*students)[count].first_name = (char *) malloc ((strlen(ptr) + 1)* 
        sizeof(char));
      strcpy((*students)[count].first_name, ptr);
      ptr = strtok(NULL, ",");
      strcpy((*students)[count].id, ptr);
      ptr = strtok(NULL, "\n");
      strcpy(temp, ptr);
      read_CRN(temp, students, count);
      count++;
    } //end while
  } //end if
  *students_size = count; 
  fclose(fp);
} //end read_student()

void read_CRN(char temp[80], Student **students, int count)
{
  int comma_count = 0;
  int i = 0;
  char *ptr; 

  for (i = 0; i < strlen(temp) - 1; i++)
  {
    if (temp[i] == ',')
      comma_count++; 
  } //end for
  (*students)[count].class_count = comma_count + 1;
  ptr = strtok(temp, ",");
  (*students)[count].crns[0] = atoi(ptr);
  for (i = 1; i < (*students)[count].class_count; i++)
  {
    ptr = strtok(NULL, ",");
    (*students)[count].crns[i] = atoi(ptr);
  } //end for
} //read_CRN()

void remove_course(Student *students, int students_size)
{
  char id[ID_SIZE];
  int i, j, k, crn;

  printf("Remove Course\n");
  printf("Please enter the SID of the student: ");
  fgets(id, 12, stdin);
  for (i = 0; i < students_size; i++)
  {
    if (strcmp(id, students[i].id) == 0)
    {
      printf("Current course: ");
      for (j = 0; j < students[i].class_count; j++)
      {
        printf("%d ", students[i].crns[j]);
      } //end for
      printf("\nPlease enter the CRN: ");
      scanf("%d", &crn);
      for (k = 0; k < students[i].class_count; k++)
      {
        if (crn == students[i].crns[k])
        {
          students[i].crns[k] = students[i].crns[students[i].class_count - 1];
          students[i].crns[students[i].class_count - 1] = 0;
          students[i].class_count--;
        } //end if
      } //end for
    } //end if
  } //end for
} //end remove_course()




