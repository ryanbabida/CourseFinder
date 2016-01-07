#Ryan Babida


rsvp.out: rsvp.o course.o vector.o student.o
	gcc -Wall -g -o rsvp.out rsvp.o course.o student.o vector.o 

rsvp.o: rsvp.c course.h vector.h student.h
	gcc -Wall -g -c rsvp.c

course.o: course.c course.h student.h vector.h
	gcc -Wall -g -c course.c

student.o: student.c student.h course.h vector.h
	gcc -Wall -g -c student.c

vector.o: vector.c vector.h student.h course.h
	gcc -Wall -g -c vector.c

clean:
	rm -rf rsvp.o vector.o course.o student.o rsvp.out rsvp
