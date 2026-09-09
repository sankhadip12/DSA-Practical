#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int StudentID;
    string StudentName;
    float Marks;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning() {
    Node* newNode = new Node;
    cout << "Enter Student ID: ";
    cin >> newNode->StudentID;
    cout << "Enter Student Name: ";
    cin >> newNode->StudentName;
    cout << "Enter Marks: ";
    cin >> newNode->Marks;
    newNode->next = head;
    head = newNode;
    cout << "Student inserted successfully.\n";
}

void insertAtEnd() {
    Node* newNode = new Node;
    cout << "Enter Student ID: ";
    cin >> newNode->StudentID;
    cout << "Enter Student Name: ";
    cin >> newNode->StudentName;
    cout << "Enter Marks: ";
    cin >> newNode->Marks;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    cout << "Student inserted successfully.\n";
}

void insertAtPosition() {
    int position;
    cout << "Enter position: ";
    cin >> position;
    if (position <= 1) {
        insertAtBeginning();
        return;
    }
    Node* newNode = new Node;
    cout << "Enter Student ID: ";
    cin >> newNode->StudentID;
    cout << "Enter Student Name: ";
    cin >> newNode->StudentName;
    cout << "Enter Marks: ";
    cin >> newNode->Marks;
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Student inserted successfully.\n";
}

void deleteByStudentID() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    if (head == NULL) {
        cout << "No student records found.\n";
        return;
    }
    if (head->StudentID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted successfully.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->StudentID != id) 
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Student ID not found.\n";
        return;
    }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Student deleted successfully.\n";
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->StudentID == id) {
            cout << "\nStudent Found\n";
            cout << "Student ID: " << temp->StudentID << endl;
            cout << "Student Name: " << temp->StudentName << endl;
            cout << "Marks: " << temp->Marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student ID not found.\n";
}

void displayRecords() {
    if (head == NULL) {
        cout << "No student records found.\n";
        return;
    }
    Node* temp = head;
    cout << "\n===== STUDENT RECORDS =====\n";
    while (temp != NULL) {
        cout << "Student ID: " << temp->StudentID << endl;
        cout << "Student Name: " << temp->StudentName << endl;
        cout << "Marks: " << temp->Marks << endl;
        cout << "--------------------------\n";
        temp = temp->next;
    }
}

void countStudents() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Total Students: " << count << endl;
}
int main() {
    int choice;
    do {
        cout << "\n===== STUDENT RECORD MANAGEMENT =====\n";
        cout << "1. Insert At Beginning\n";
        cout << "2. Insert At End\n";
        cout << "3. Insert At Position\n";
        cout << "4. Delete By Student ID\n";
        cout << "5. Search Student\n";
        cout << "6. Display Records\n";
        cout << "7. Count Students\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteByStudentID(); break;
            case 5: searchStudent(); break;
            case 6: displayRecords(); break;
            case 7: countStudents(); break;
            case 8: cout << "Program Ended.\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 8);
    return 0;
}