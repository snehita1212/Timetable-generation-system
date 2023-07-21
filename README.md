# Timetable-generation-system
A timetable generator for Institute schedule using C++

-There are a variety of courses offered in the institute, namely Institute Cores (ICs), Department Cores (DCs) along with Lab courses. The faculty members teaching these courses and the classrooms available are limited. Therefore, a timetable generator is essential for proper schedule planning by professors and students.

-This project aims to automate the process of timetable scheduling

-There can be no overlap
 * No teacher can teach two classes at the same time
 * No group can listen to two classes at the same time
 * No classroom can receive two classes at the same time

-Classroom is assigned based on the strength of the students taking that course

-Inputs required:
 * File containing courses offered corresponding to required information 
 * File containing classroom information

-Algorithm creates an array for each batch

-To allocate time slot to a course:
 * check if slot is free
 * check if prof is available
 * check if classroom of required capacity is available

-To deploy
 * run ds.h file
 * run maincode.cpp file
 * enter lunch slot timings
