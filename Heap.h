#ifndef ASSIGNMENT3_HEAP_H
#define ASSIGNMENT3_HEAP_H
#include "Node.h"


class Heap {
private:
     vector<Student> students_;
    bool isMaxHeap_;
    bool compare(Student s1, Student s2);
public:
    // Constructor
    Heap(bool isMaxHeap) ;
    void insert(Student student);
    void printAll();



};


#endif
