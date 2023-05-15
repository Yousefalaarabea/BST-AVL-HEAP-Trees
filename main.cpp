#include <bits/stdc++.h>
#include "Node.h"
#include "AVL.h"
#include "BST.h"
#include "Heap.h"
using namespace std;


int main() {
    stringstream stringstream1;
    stringstream stringstream2;
    fstream infile;
    infile.open("test.txt");
    string nums;
    bool check = false ;
    getline(infile, nums);
    int counter = stoi(nums);
    Student s;
    while (!check) {
        bool flag = true;
        int temp = counter;
        int choice;
        cout << "Choose Data Structure :\n";
        cout << "1. BST\n" << "2. AVL\n" << "3. Min Heap\n" << "4. Max Heap\n" << "5. Exit Program\n";
        cin >> choice;
        if (choice == 1) {
            BST tree;
            while (temp--) {
                string line1, line2, line3, line4;
                stringstream1.clear();
                stringstream2.clear();
                getline(infile, line1);
                stringstream1 << line1;
                int id;
                stringstream1 >> id;
                getline(infile, line2);
                getline(infile, line3);
                stringstream2 << line3;
                float gpa;
                stringstream2 >> gpa;
                getline(infile, line4);
                string name = line2;
                string dep = line4;
                s.AddStudentToStruct(id, name, dep, gpa);
                tree.Insert(s);
                if (infile.eof()) break;
            }
            infile.close();
            while (flag) {
                label1 :
                int choice2;
                cout << "Choose one of the following options :" << endl;
                cout << "1. Add student\n" << "2. Remove student\n" << "3. Search student\n"
                     << "4. Print All (sorted by id)\n" << "5. Return to main menu\n";
                cin >> choice2;
                if (choice2 == 1) {
                    cout << "Enter student id :  " << endl;
                    cin >> s.id;
                    while (s.id <= 10 || s.id > 100) {
                        cout << "Invalid id enter it again : " << endl;
                        cin >> s.id;
                    }
                    cout << "Enter student name :  " << endl;
                    cin.ignore();
                    getline(cin, s.name);
                    cout << "Enter student gpa :  " << endl;
                    cin >> s.gpa;
                    while (s.gpa <= 0 || s.gpa > 4.00) {
                        cout << "Invalid Gpa enter it again : " << endl;
                        cin >> s.gpa;
                    }
                    cout << "Enter student department :  " << endl;
                    cin >> s.department;
                    while (s.department != "CS" && s.department != "IS" && s.department != "AI" &&
                           s.department != "DS" && s.department != "IT") {
                        cout << "Invalid department enter it again : " << endl;
                        cin >> s.department;
                    }
                    ofstream file("test.txt", ios::app);
                    file << endl << s.id << endl;
                    file << s.name << endl;
                    file << s.gpa << endl;
                    file << s.department << endl;
                    file.close();
                    tree.Insert(s);
                    counter++;
                    cout << "The student is added " << endl;
                    tree.Printall(tree.root);
                } else if (choice2 == 2) {
                    cout << "Enter student id you want to remove : " << endl;
                    int id;
                    cin >> id;
                    if (tree.Remove(id)) {
                        cout << endl << "Student is deleted" << endl;
                    }
                    tree.Printall(tree.root);
                } else if (choice2 == 3) {
                    cout << "Enter student id you want to find : " << endl;
                    int id;
                    cin >> id;
                    tree.Search(id);
                } else if (choice2 == 4) {
                    tree.printDepartmentcounter(tree);
                } else if (choice2 == 5) {
                    flag = false;
                } else {
                    cout << "Invalid choice " << endl;
                    goto label1;
                }
            }
        } else if (choice == 2) {
            AVL tree;
            vector<Student> NewStudent;
            while (temp--) {
                string line1, line2, line3, line4;
                stringstream1.clear();
                stringstream2.clear();
                getline(infile, line1);
                stringstream1 << line1;
                int id;
                stringstream1 >> id;
                getline(infile, line2);
                getline(infile, line3);
                stringstream2 << line3;
                float gpa;
                stringstream2 >> gpa;
                getline(infile, line4);
                string name = line2;
                string dep = line4;
                s.AddStudentToStruct(id, name, dep, gpa);
                tree.Insert(s);
                if (infile.eof()) break;
            }
            infile.close();
            while (flag) {
                label2 :
                int choice2;
                cout << "Choose one of the following options :" << endl;
                cout << "1. Add student\n" << "2. Remove student\n" << "3. Search student\n"
                     << "4. Print All (sorted by id)\n" << "5. Return to main menu\n";
                cin >> choice2;
                if (choice2 == 1) {
                    cout << "Enter student id :  " << endl;
                    cin >> s.id;
                    while (s.id <= 10 || s.id > 100) {
                        cout << "Invalid id enter it again : " << endl;
                        cin >> s.id;
                    }
                    cout << "Enter student name :  " << endl;
                    cin.ignore();
                    getline(cin, s.name);
                    cout << "Enter student gpa :  " << endl;
                    cin >> s.gpa;
                    while (s.gpa <= 0 || s.gpa > 4.00) {
                        cout << "Invalid Gpa enter it again : " << endl;
                        cin >> s.gpa;
                    }
                    cout << "Enter student department :  " << endl;
                    cin >> s.department;
                    while (s.department != "CS" && s.department != "IS" && s.department != "AI" &&
                           s.department != "DS" && s.department != "IT") {
                        cout << "Invalid department enter it again : " << endl;
                        cin >> s.department;
                    }
                    ofstream file("test.txt", ios::app);
                    file << endl << s.id << endl;
                    file << s.name << endl;
                    file << s.gpa << endl;
                    file << s.department << endl;
                    file.close();
                    tree.Insert(s);
                    counter++;
                    cout << "The student is added " << endl;
                    tree.printAll();
                } else if (choice2 == 2) {
                    cout << "Enter student id you want to remove : " << endl;
                    int id;
                    cin >> id;
                    if (tree.Remove(id) == true) {
                        cout << endl << "Student is deleted" << endl;
                        tree.printAll();
                    }
                } else if (choice2 == 3) {
                    cout << "Enter student id you want to find : " << endl;
                    int id;
                    cin >> id;
                    tree.Search(id);
                } else if (choice2 == 4) {
                    tree.printAll();
                    tree.printDepartmentcounter();
                } else if (choice2 == 5) {
                    flag = false;
                } else {
                    cout << "Invalid choice " << endl;
                    goto label2;
                }
            }
        } else if (choice == 3) {
            Heap minHeap(false);
            while (temp--) {
                string line1, line2, line3, line4;
                stringstream1.clear();
                stringstream2.clear();
                getline(infile, line1);
                stringstream1 << line1;
                int id;
                stringstream1 >> id;
                getline(infile, line2);
                getline(infile, line3);
                stringstream2 << line3;
                float gpa;
                stringstream2 >> gpa;
                getline(infile, line4);
                string name = line2;
                string dep = line4;
                s.AddStudentToStruct(id, name, dep, gpa);
                minHeap.insert(s);
                if (infile.eof()) break;
            }
            infile.close();
            label3 :
            int choice2;
            while (flag) {
                cout << "Choose one of the following options :" << endl;
                cout << "1. Add student\n" << "2. Print All (sorted by gpa) \n" << "3. Return to main menu\n";
                cin >> choice2;
                if (choice2 == 1) {
                    cout << "Enter student id :  " << endl;
                    cin >> s.id;
                    while (s.id <= 10 || s.id > 100) {
                        cout << "Invalid id enter it again : " << endl;
                        cin >> s.id;
                    }
                    cout << "Enter student name :  " << endl;
                    cin.ignore();
                    getline(cin, s.name);
                    cout << "Enter student gpa :  " << endl;
                    cin >> s.gpa;
                    while (s.gpa <= 0 || s.gpa > 4.00) {
                        cout << "Invalid Gpa enter it again : " << endl;
                        cin >> s.gpa;
                    }
                    cout << "Enter student department :  " << endl;
                    cin >> s.department;
                    while (s.department != "CS" && s.department != "IS" && s.department != "AI" &&
                           s.department != "DS" && s.department != "IT") {
                        cout << "Invalid department enter it again : " << endl;
                        cin >> s.department;
                    }
                    ofstream file("test.txt", ios::app);
                    file << endl << s.id << endl;
                    file << s.name << endl;
                    file << s.gpa << endl;
                    file << s.department << endl;
                    file.close();
                    counter++;
                    minHeap.insert(s);
                    cout << "The student is added " << endl;
                    minHeap.printAll();
                } else if (choice2 == 2) {
                    minHeap.printAll();
                } else if (choice2 == 3) {
                    flag = false;
                } else {
                    cout << "Invalid choice" << endl;
                    goto label3;
                }
            }
        } else if (choice == 4) {
            Heap maxHeap(true);
            while (temp--) {
                string line1, line2, line3, line4;
                stringstream1.clear();
                stringstream2.clear();
                getline(infile, line1);
                stringstream1 << line1;
                int id;
                stringstream1 >> id;
                getline(infile, line2);
                getline(infile, line3);
                stringstream2 << line3;
                float gpa;
                stringstream2 >> gpa;
                getline(infile, line4);
                string name = line2;
                string dep = line4;
                s.AddStudentToStruct(id, name, dep, gpa);
                maxHeap.insert(s);
                if (infile.eof()) break;
            }
            infile.close();
            int choice2;
            while (flag) {
                label4 :
                cout << "Choose one of the following options :" << endl;
                cout << "1. Add student\n" << "2. Print All (sorted by gpa) \n" << "3. Return to main menu\n";
                cin >> choice2;
                if (choice2 == 1) {
                    cout << "Enter student id :  " << endl;
                    cin >> s.id;
                    while (s.id <= 10 || s.id > 100) {
                        cout << "Invalid id enter it again : " << endl;
                        cin >> s.id;
                    }
                    cout << "Enter student name :  " << endl;
                    cin.ignore();
                    getline(cin, s.name);
                    cout << "Enter student gpa :  " << endl;
                    cin >> s.gpa;
                    while (s.gpa <= 0 || s.gpa > 4.00) {
                        cout << "Invalid Gpa enter it again : " << endl;
                        cin >> s.gpa;
                    }
                    cout << "Enter student department :  " << endl;
                    cin >> s.department;
                    while (s.department != "CS" && s.department != "IS" && s.department != "AI" &&
                           s.department != "DS" && s.department != "IT") {
                        cout << "Invalid department enter it again : " << endl;
                        cin >> s.department;
                    }
                    ofstream file("test.txt", ios::app);
                    file << endl << s.id << endl;
                    file << s.name << endl;
                    file << s.gpa << endl;
                    file << s.department << endl;
                    file.close();
                    counter++;
                    maxHeap.insert(s);
                    cout << "The student is added " << endl;
                    maxHeap.printAll();
                } else if (choice2 == 2) {
                    maxHeap.printAll();
                } else if (choice2 == 3) {
                    flag = false;
                } else {
                    cout << "Invalid choice" << endl;
                    goto label4;
                }
            }
        } else if (choice == 5) {
            return 0;
        }
    }
}


