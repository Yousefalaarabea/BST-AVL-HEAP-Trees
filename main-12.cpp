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
class Node
{
public:
    Student s;
    int height = 1 ;

    Node* left, * right;
    Node()
    {

        left = right = NULL;
    }
};




class BST
{
private:
    Node* Insert(Node* r, int item, string n,float  g,string dep)
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

    Node* Search(Node* r, int key)
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

    Node* removeNode(Node* root, int id) {
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

public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    void Insert(Student sn)
    {

        root = Insert(root,sn.id,sn.name,sn.gpa,sn.department);
    }

    void Search(int key) {
        Node *result = Search(root, key);

        if (result == NULL) {
            cout << "Sorry , Student is not found \n";
        } else {
            cout << "Student is found. \n";
            cout << "[" << result->s.id << "," << result->s.name << "," << result->s.gpa << "," << result->s.department
                 << "]";
        }
    }

    void Remove (int key) {
        Node *result = removeNode(root, key);
    }

    void printDepartmentReport(Node* node, std::unordered_map<std::string, int>& departmentCounts) {
        if (node == nullptr) {
            return;
        }
        printDepartmentReport(node->left, departmentCounts);
        std::cout << "ID: " << node->s.id << ", Name: " << node->s.name << ", Department: " << node->s.department
                  << ", GPA: " << node->s.gpa << std::endl;
        // Update department count
        departmentCounts[node->s.department]++;
        printDepartmentReport(node->right, departmentCounts);
    }

    void printDepartmentReport(BST& bst) {
        std::unordered_map<std::string, int> departmentCounts;
        printDepartmentReport(bst.root, departmentCounts);
        std::cout << "Department Report:" << std::endl;
        for (const auto& pair : departmentCounts) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    Student* root_ = nullptr;

    void Inorder(Node* r){
        if (r == NULL)
            return;
        Inorder(r->left);
        cout <<r->s.id << "\t";
        cout << r->s.name << "\t";
        cout << r->s.gpa << "\t";
        cout << r->s.department<< "\n";
        Inorder(r->right);
    }
};

/*
class Heap {

};

class MaxHeap {
public:

    MaxHeap (){
    }

    void heapify(int arr[],int size,int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < size && arr[left] > arr[largest])
            largest = left;
        if(right < size && arr[right] > arr[largest])
            largest = right;
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,size,largest);
        }
    }

    void buildHeap(int arr[],int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    void heapSort(int arr[], int n)
    {

        buildHeap(arr, n);
        for (int i = n-1; i >=0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }


};

class MinHeap {

    void heapify(int arr[],int size,int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < size && arr[left] < arr[largest])
            largest = left;
        if(right < size && arr[right] < arr[largest])
            largest = right;
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,size,largest);
        }
    }

    void buildHeap(int arr[],int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    void heapSort(int arr[], int n)
    {

        buildHeap(arr, n);
        for (int i = n-1; i >=0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
*/

class Heap {
private:
    std::vector<Student> students_;
    bool isMaxHeap_;
    bool compare(Student s1, Student s2) {
        if (isMaxHeap_) {
            return s1.gpa > s2.gpa;
        } else {
            return s1.gpa < s2.gpa;
        }
    }

public:
    // Constructor
    Heap(bool isMaxHeap) : isMaxHeap_(isMaxHeap) {}

    // Function to insert a student into the heap
    void insert(Student student) {
        // Add the student to the end of the vector
        students_.push_back(student);
        // Bubble up the student to maintain the heap property
        int index = students_.size() - 1;
        while (index > 0 && compare(students_[index], students_[(index - 1) / 2])) {
            std::swap(students_[index], students_[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void printAll() {
        // Make a copy of the vector and sort it by GPA

        vector<Student> sortedStudents = students_;
        sort(sortedStudents.begin(), sortedStudents.end(), [this](const Student& s1, const Student& s2) {
            return compare(s1, s2);
        });
        // Print the sorted students
        std::cout << "Students (sorted by GPA):" << std::endl;
        for (const auto& student : sortedStudents) {
            std::cout << "ID: " << student.id << ", Name: " << student.name
                      << ", GPA: " << student.gpa << ", Department: " << student.department << std::endl;
        }
        // Print the department report
        std::unordered_map<std::string, int> departmentCounts;
        for (const auto& student : students_) {
            departmentCounts[student.department]++;
        }
        std::cout << "Department Report:" << std::endl;
        for (const auto& pair : departmentCounts) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main()
{
    //AVL tree;
    Student s1;
    BST t1;
    Heap minHeap(false);
    Heap maxHeap(true);
    ifstream infile ;
    infile.open("test.txt");
    string nums;
    getline(infile, nums );
    int numofs = stoi(nums);
    vector<Student> NS ;

    while (true)
    {
        string line1,line2,line3,line4 ;
        getline(infile, line1 );
        getline(infile, line2 );
        getline(infile, line3 );
        getline(infile, line4 );
        Student s;
        int id= stoi(line1);
        float gpa = stod(line3);
        //s.AddStudentToStruct(id, line2, gpa, line4);
        t1.Insert(s);
        //tree.Insert(s);
        NS.push_back(s);
        minHeap.insert({id, line2, line4, gpa});
        maxHeap.insert({id, line2, line4 , gpa});
        if (infile.eof()) break;
    }

    infile.close();
    //s1.AddStudentToStruct(11 , "hazem" , 4.00 , "CS" );

    /*cout << "All students sorted by ID:" << endl;
    tree.printAll();
    cout << endl;
    cout << "Department report:" << endl;
    tree.printDepartmentReport();
    cout << endl;
    cout << "Removing student with ID 5:" << endl;
    tree.Remove(5);
    tree.printAll();
    cout << "Add student" << endl;
    tree.Insert(s1);
    tree.printAll();
    tree.inorderTraversal(tree.root , NS );
    cout << endl ;
    int id ;
    cout << "enter the id :";
    cin >> id;
    tree.Search(id);*/

    /*t1.Inorder(t1.root);
    t1.Insert(s1);
    t1.Inorder(t1.root);
    t1.Search(10);
    t1.Search(15);
    t1.Remove(10);
    t1.Inorder(t1.root);
    t1.printDepartmentReport(t1);*/
    Student s2;
    s2.AddStudentToStruct(11 , "hazem medhat" , "cs" , 4.00 );
    minHeap.insert(s2);
    minHeap.printAll();
    maxHeap.printAll();

    return 0;
}
class AVL
{

private:

    Node* Insert(Node* node, const Student& student) {
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

    Node* Remove(Node* node, int id)
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

    int getHeight(Node* node)
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

    int getBalance(Node* node)
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

    Node* rotateRight(Node* node) {
        Node* leftChild = node->left;
        Node* rightGrandchild = leftChild->right;
        leftChild->right = node;
        node->left = rightGrandchild;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        leftChild->height = 1 + max(getHeight(leftChild->left), getHeight(leftChild->right));
        return leftChild;
    }

    Node* rotateLeft(Node* node) {
        Node* rightChild = node->right;
        Node* leftGrandchild = rightChild->left;
        rightChild->left = node;
        node->right = leftGrandchild;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        rightChild->height = 1 + max(getHeight(rightChild->left), getHeight(rightChild->right));
        return rightChild;
    }


    Node* SearchStudent(Node* node, int id) {
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

    // Helper function to perform an inorder traversal of the AVL tree

    // Helper function to count the number of students in each department
    void countDepartments(Node* node, unordered_map<string, int>& departmentCounts) {
        if (node) {
            countDepartments(node->left, departmentCounts);
            departmentCounts[node->s.department]++;
            countDepartments(node->right, departmentCounts);
        }
    }


    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }


public:
    Node* root;
    AVL()
    {
        root = NULL;
    }

    void Insert(Student NewStudent)
    {

        root = Insert(root,NewStudent);
    }

    void Remove(int id)
    {
        root = Remove(root, id);
    }


    void Search(int id) {
        Node *node = SearchStudent(root, id);

        if (node == NULL) {
            cout << "Sorry , Student is not found \n";
        } else {
            cout << "Student is found. \n";
            cout << "[" << node->s.id << "," << node->s.name << "," << node->s.gpa << "," << node->s.department << "]";
        }
    }

    void inorderTraversal(Node* node, vector<Student>& students) {
        if (node) {
            inorderTraversal(node->left, students);
            students.push_back(node->s);
            inorderTraversal(node->right, students);
        }
    }

    void printAll() {
        vector<Student> students;
        inorderTraversal(root, students);
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", GPA: " << student.gpa << ", Department: " << student.department << endl;
        }
    }

    // Print a department report
    void printDepartmentReport() {
        unordered_map<string, int> departmentCounts;
        countDepartments(root, departmentCounts);
        for (const auto& entry : departmentCounts) {
            cout << "Department: " << entry.first << ", Count: " << entry.second << endl;
        }
    }
};