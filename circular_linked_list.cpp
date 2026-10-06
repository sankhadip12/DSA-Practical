#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* last = NULL;
Node* current = NULL;

void addMember() {
    string name;
    cout << "Enter member name: ";
    cin >> name;
    Node* newNode = new Node;
    newNode->name = name;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
        current = newNode;
    }
    else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    cout << "Member added successfully.\n";
}

void displayMembers() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }

    Node* temp = last->next;
    cout << "\n===== DRIVING ROTATION =====\n";

    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "(Back to First Member)\n";
}

void removeMember() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }

    string name;
    cout << "Enter member name to remove: ";
    cin >> name;
    Node* currentNode = last->next;
    Node* previous = last;

    do {
        if (currentNode->name == name) {
            if (currentNode == last && currentNode == last->next) {
                last = NULL;
                current = NULL;
            }
            else if (currentNode == last) {
                previous->next = currentNode->next;
                last = previous;
                if (current == currentNode)
                    current = currentNode->next;
            }
            else if (currentNode == last->next) {
                last->next = currentNode->next;
                if (current == currentNode)
                    current = currentNode->next;
            }
            else {
                previous->next = currentNode->next;
                if (current == currentNode)
                    current = currentNode->next;
            }
            delete currentNode;
            cout << "Member removed successfully.\n";
            return;
        }
        previous = currentNode;
        currentNode = currentNode->next;
    } while (currentNode != last->next);
    cout << "Member not found.\n";
}

void searchMember() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    string name;
    cout << "Enter member name to search: ";
    cin >> name;
    Node* temp = last->next;
    int position = 1;

    do {
        if (temp->name == name) {
            cout << "Member found at position "
                 << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != last->next);
    cout << "Member not found.\n";
}

void assignNextDriver() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    cout << "Current Driver: " << current->name << endl;
    current = current->next;
    cout << "Next Driver: " << current->name << endl;
}

int main() {
    int choice;
    do {
        cout << "\n===== CIRCULAR LINKED LIST =====\n";
        cout << "1. Add Member\n";
        cout << "2. Remove Member\n";
        cout << "3. Search Member\n";
        cout << "4. Display Driving Rotation\n";
        cout << "5. Assign Next Driver\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMember(); break;
            case 2: removeMember(); break;
            case 3: searchMember(); break;
            case 4: displayMembers(); break;
            case 5: assignNextDriver(); break;
            case 6: cout << "Program Ended.\n"; break;
            default: cout << "Invalid Choice.\n";
        }
    } while (choice != 6);
    return 0;
}