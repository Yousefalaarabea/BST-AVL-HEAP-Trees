#ifndef ASSIGNMENT3_AVL_H
#define ASSIGNMENT3_AVL_H
#include "Node.h"



class AVL {
private:
    Node* Insert(Node* node, const Student& student);
    Node* Remove(Node* node, int id);
    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* SearchStudent(Node* node, int id);
    void countDepartments(Node* node, unordered_map<string, int>& departmentCounts);
    Node* findMin(Node* node);
    void inorderTraversal(Node* node, vector<Student>& students);
public:
    Node* root;
    AVL();
    void Insert(Student NewStudent);
    bool Remove(int id);
    bool Search(int id);
    void printAll();
    void printDepartmentcounter();


};


#endif //ASSIGNMENT3_AVL_H
