//Author: Ryan Babida

#ifndef VECTOR_H
  #define VECTOR_H

void initialize_courses(Course **courses, int *courses_size);

void resize_courses(Course **courses, int *courses_size, int count);

void initialize_students(Student **students, int *students_size);

void resize_students(Student **students, int *students_size, int count);

void deallocate(Course *courses, Student *students, int students_size);

#endif