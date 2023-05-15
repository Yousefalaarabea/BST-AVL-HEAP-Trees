#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H

#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id = 0 ;
    string name, department;
    float gpa;

    void AddStudentToStruct(int i, string n, string dep , float g)
    {
        id = i;
        name = n;
        gpa = g;
        department = dep;
    }
};

class Node {
public:
    Student s;
    int height = 1 ;
    Node* left, * right;
    Node();
};


#endif //ASSIGNMENT3_NODE_H
