//Author: Ryan Babida

#ifndef STUDENT_H
  #define STUDENT_H

void read_students(char *filename, Student **students, int *students_size);

void read_CRN(char temp[80], Student **students, int count);

void remove_course(Student *students, int students_size);

#endif