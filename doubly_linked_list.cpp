#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    Node* prev;
    Node* next;
};

Node* HEAD = NULL;
Node* CURRENT = NULL;

void addMember() {
    string name;
    cout << "Enter member name: ";
    cin >> name;
    Node* NEWNODE = new Node;
    NEWNODE->name = name;
    NEWNODE->prev = NULL;
    NEWNODE->next = NULL;
    if (HEAD == NULL) {
        HEAD = NEWNODE;
        CURRENT = NEWNODE;
        cout << "Member added successfully." << endl;
        return;
    }

    Node* temp = HEAD;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = NEWNODE;
    NEWNODE->prev = temp;
    cout << "Member added successfully." << endl;
}

void removeMember() {
    if (HEAD == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    string name;
    cout << "Enter member name to remove: ";
    cin >> name;
    Node* temp = HEAD;

    while (temp != NULL && temp->name != name) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Member not found." << endl;
        return;
    }

    if (temp == HEAD) {
        HEAD = temp->next;
        if (HEAD != NULL) {
            HEAD->prev = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    if (CURRENT == temp) {
        if (HEAD != NULL)
            CURRENT = HEAD;
        else
            CURRENT = NULL;
    }
    delete temp;
    cout << "Member removed successfully." << endl;
}

void searchMember() {
    if (HEAD == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    string name;
    cout << "Enter member name to search: ";
    cin >> name;
    Node* temp = HEAD;
    int position = 1;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Member found at position "
                 << position << "." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Member not found." << endl;
}

void displayDrivingRotation() {
    if (HEAD == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    Node* temp = HEAD;
    cout << "\nDriving Rotation (Forward): ";
    while (temp != NULL) {
        cout << temp->name;
        if (temp->next != NULL) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void assignNextDriver() {
    if (HEAD == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }

    cout << "Current Driver: "
         << CURRENT->name << endl;

    if (CURRENT->next != NULL) {
        CURRENT = CURRENT->next;
    }
    else{
        CURRENT = HEAD;
    }
    cout << "Next Driver: "
         << CURRENT->name << endl;
}

int main() {
    int choice;
    do {
        cout << "\n===== DOUBLY LINKED LIST =====" << endl;
        cout << "1. Add Member to Driving Rotation" << endl;
        cout << "2. Remove Member from Driving Rotation" << endl;
        cout << "3. Search Member" << endl;
        cout << "4. Display Driving Rotation" << endl;
        cout << "5. Assign Next Driver" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMember(); break;
            case 2: removeMember(); break;
            case 3: searchMember();break;
            case 4: displayDrivingRotation(); break;
            case 5: assignNextDriver(); break;
            case 6: cout << "Program terminated." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 6);
    return 0;
}