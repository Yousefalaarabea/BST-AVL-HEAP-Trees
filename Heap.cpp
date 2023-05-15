#include "Heap.h"

Heap :: Heap(bool isMaxHeap) : isMaxHeap_(isMaxHeap) {}

bool Heap :: compare(Student s1, Student s2) {
    if (isMaxHeap_) {
        return s1.gpa > s2.gpa;
    } else {
        return s1.gpa < s2.gpa;
    }
}

void Heap :: insert(Student student) {
    students_.push_back(student);
    int index = students_.size() - 1;
    while (index > 0 && compare(students_[index], students_[(index - 1) / 2])) {
         swap(students_[index], students_[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void Heap ::  printAll() {
    vector<Student> sortedStudents = students_;
    sort(sortedStudents.begin(), sortedStudents.end(), [this](const Student& s1, const Student& s2) {
        return compare(s1, s2);
    });
     cout << "Students (sorted by GPA):" <<  endl;
    for (const auto& student : sortedStudents) {
         cout << "ID: " << student.id << ", Name: " << student.name
                  << ", GPA: " << student.gpa << ", Department: " << student.department <<  endl;
    }
     unordered_map< string, int> departmentCounts;
    for (const auto& student : students_) {
        departmentCounts[student.department]++;
    }
     cout << "Department Report:" <<  endl;
    for (const auto& pair : departmentCounts) {
         cout << pair.first << ": " << pair.second <<  endl;
    }
}
