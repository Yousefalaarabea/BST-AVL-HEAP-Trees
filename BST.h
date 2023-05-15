#ifndef ASSIGNMENT3_BST_H
#define ASSIGNMENT3_BST_H
#include "Node.h"

class BST {
private:
    Node* Insert(Node* r, int item, string n,float  g,string dep);
    Node* Search(Node* r, int key);
    Node* removeNode(Node* root, int id);
    void printDepartmentcounter(Node* node,  unordered_map< string, int>& departmentCounts);
public:
    Node* root;
    Student* root_ = nullptr;
    BST();
    void Insert(Student sn);
    bool Search(int key);

    bool Remove (int key);
    void printDepartmentcounter(BST& bst);
    void Printall(Node* r);
    //void Remove (int key);

};


#endif //ASSIGNMENT3_BST_H
