#include "AVL.h"
#include "Node.h"

Node* AVL ::  Insert(Node* node, const Student& student) {
    if (!node) {
        Node* node = new Node();
        node->s = student;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }
    else if (student.id < node->s.id) {
        node->left = Insert(node->left, student);
    }
    else {
        node->right = Insert(node->right, student);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && student.id < node->left->s.id) {
        return rotateRight(node);
    }
    else if (balance < -1 && student.id > node->right->s.id) {
        return rotateLeft(node);
    }
    else if (balance > 1 && student.id > node->left->s.id) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    else if (balance < -1 && student.id < node->right->s.id) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node* AVL :: Remove(Node* node, int id)
{
    if (!node)
    {
        return node;
    }
    if (id < node->s.id)
    {
        node->left = Remove(node->left, id);
    }
    else if (id > node->s.id)
    {
        node->right = Remove(node->right, id);
    }
    else
    {
        if (!node->left || !node->right)
        {
            Node* temp;
            if (node->left)
            {
                temp = node->left;
            }
            else
            {
                temp = node->right;
            }

            if (!temp)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            delete temp;
        }
        else
        {
            Node* temp = findMin(node->right);
            node->s = temp->s;
            node->right = Remove(node->right, temp->s.id);
        }
    }
    if (!node)
    {
        return node;
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0)
    {
        return rotateRight(node);
    }
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
    {
        return rotateLeft(node);
    }
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

int AVL :: getHeight (Node* node)
{
    if (node)
    {
        return node->height;
    }
    else
    {
        return 0;
    }
}

int AVL ::  getBalance(Node* node)
{
    if (node)
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return leftHeight - rightHeight;
    }
    else
    {
        return 0;
    }
}

Node* AVL ::  rotateRight(Node* node) {
    Node* leftChild = node->left;
    Node* rightGrandchild = leftChild->right;
    leftChild->right = node;
    node->left = rightGrandchild;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));
    return leftChild;
}

Node* AVL :: rotateLeft(Node* node) {
    Node* rightChild = node->right;
    Node* leftGrandchild = rightChild->left;
    rightChild->left = node;
    node->right = leftGrandchild;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));
    return rightChild;
}

Node* AVL :: findMin(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

Node* AVL :: SearchStudent(Node* node, int id) {
    if (!node) {
        return node;
    }
    else if (id < node->s.id) {
        return SearchStudent(node->left, id);
    }
    else if (id > node->s.id) {
        return SearchStudent(node->right, id);
    }
    else {
        return node;
    }
}

void AVL :: countDepartments(Node* node, unordered_map<string, int>& departmentCounts) {
    if (node) {
        countDepartments(node->left, departmentCounts);
        departmentCounts[node->s.department]++;
        countDepartments(node->right, departmentCounts);
    }
}

void AVL ::printDepartmentcounter() {
    unordered_map<string, int> departmentCounts;
    countDepartments(root, departmentCounts);
    cout << "Students per departments: " << endl;
    for (const auto& entry : departmentCounts) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void AVL :: inorderTraversal(Node* node, vector<Student>& students) {
    if (node) {
        inorderTraversal(node->left, students);
        students.push_back(node->s);
        inorderTraversal(node->right, students);
    }
}

AVL :: AVL()
{
    root = NULL;
}

void AVL :: Insert(Student NewStudent)
{

    root = Insert(root,NewStudent);
}

bool AVL :: Remove(int id)
{
    if(Search(id)== true) {
        root = Remove(root, id);
        return true;
    } else
        return false;
}

bool AVL :: Search(int id) {
    Node *node = SearchStudent(root, id);

    if (node == NULL) {
        cout << "Student is not found \n";
        return false;
    } else {
        cout << "Student is found. \n";
        cout << "[" << node->s.id << "," << node->s.name << "," << node->s.gpa << "," << node->s.department << "]";
        cout << endl ;
        return true;
    }
}

void AVL :: printAll() {
    vector<Student> students;
    inorderTraversal(root, students);
    for (const auto& student : students) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", GPA: " << student.gpa << ", Department: " << student.department << endl;
    }
}

