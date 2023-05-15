#include "BST.h"

BST :: BST()
{
    root = NULL;
}

Node* BST :: Insert(Node* r, int item, string n,float  g,string dep)
{
    if (r == NULL)
    {
        Node* newnode = new Node;
        r = newnode;
        newnode->s.id=item;
        newnode->s.name = n;
        newnode->s.gpa = g;
        newnode->s.department = dep;

    }

    else if (item < r->s.id)
        r->left = Insert(r->left, item, n, g, dep);
    else
        r->right = Insert(r->right, item, n, g, dep);

    return r;
}

Node*  BST :: Search(Node* r, int key)
{
    if (r == NULL)
        return NULL;
    else if (r->s.id == key)
        return r;
    else if (key < r->s.id)
        return	Search(r->left, key);
    else
        return Search(r->right, key);
}

Node* BST:: removeNode(Node* root, int id) {
    // If the root is null, return null
    if (root == nullptr) {
        return nullptr;
    }

    // If the ID is less than the root's ID, search in the left subtree
    if (id < root->s.id) {
        root->left = removeNode(root->left, id);
    }
        // If the ID is greater than the root's ID, search in the right subtree
    else if (id > root->s.id) {
        root->right = removeNode(root->right, id);
    }
        // If the ID is equal to the root's ID, remove the node
    else {
        // If the node has no children or only one child, remove it
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
            // If the node has two children, find the smallest node in the right subtree
        else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            // Replace the root's data with the smallest node's data
            root->s = temp->s;
            // Remove the smallest node from the right subtree
            root->right = removeNode(root->right, temp->s.id);
        }
    }
    return root;
}

void  BST :: Insert (Student sn)
{
    root = Insert(root,sn.id,sn.name,sn.gpa,sn.department);
}

bool  BST :: Search(int key) {
   root = Search(root, key);

    if (root == NULL) {
        cout << "Student is not found \n";
        return false ;
    } else {
        cout << "Student is found. \n";
        cout << "[" << root->s.id << "," << root->s.name << "," << root->s.gpa << "," << root->s.department
             << "]";
        return true ;
    }
}

bool  BST :: Remove (int key) {
    if(Search(key)== true) {
        root = removeNode(root, key);
        return true;
    } else
        return false;
}

void  BST :: printDepartmentcounter(Node* node, unordered_map< string, int>& departmentCounts) {
    if (node == nullptr) {
        return;
    }
    printDepartmentcounter(node->left, departmentCounts);
    cout << "ID: " << node->s.id << ", Name: " << node->s.name << ", Department: " << node->s.department
              << ", GPA: " << node->s.gpa << endl;
    departmentCounts[node->s.department]++;
    printDepartmentcounter(node->right, departmentCounts);
}

void  BST :: printDepartmentcounter(BST& bst) {
     unordered_map< string, int> departmentCounts;
    printDepartmentcounter(bst.root, departmentCounts);
     cout << "Students per departments:" <<  endl;
    for (const auto& pair : departmentCounts) {
         cout << pair.first << ": " << pair.second <<  endl;
    }
}

void  BST :: Printall(Node* r){
    if (r == NULL)
        return;
    Printall(r->left);
    cout <<r->s.id << "\t";
    cout << r->s.name << "\t";
    cout << r->s.gpa << "\t";
    cout << r->s.department<< "\n";
    Printall(r->right);
}