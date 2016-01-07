//Author: Ryan Babida

//macro constants
#define ID_SIZE 12
#define CRN_SIZE 5
#define SUBJ_SIZE 4
#define COURSE_NUM 6

#ifndef COURSE_H
  #define COURSE_H

typedef struct
{
  char *first_name;
  char *last_name;
  char id[ID_SIZE];
  int crns[CRN_SIZE];
  int class_count;
} Student;

typedef struct
{
  int crn;
  char subject[SUBJ_SIZE];
  char course_num[COURSE_NUM];
} Course;

void read_courses(char *filename, Course **courses, int *courses_size);

void find_CRN(Course *courses, Student *students, int courses_size, int 
  students_size);

void find_subject(Course *courses, int courses_size);

void add_course(Course *courses, Student *students, int courses_size, 
  int students_size); 

#endif