heapstudents: mainheap.o student.o address.o  date.o 
	g++ mainheap.o student.o address.o date.o -o heapstudents
mainheap.o: mainheap.cpp student.h address.h date.h
	g++ -c mainheap.cpp
student.o: student.cpp student.h address.h date.h
	g++ -c student.cpp
address.o: address.cpp address.h date.h
	g++ -c address.cpp

date.o: date.cpp  date.h
	g++ -c date.cpp
clean:
	rm *.o
	rm heapstudents
run: heapstudents
	./heapstudents
debug: heapstudents
	gdb -tui ./heapstudents
valgrind: heapstudents
	valgrind --leak-check=yes ./heapstudents

