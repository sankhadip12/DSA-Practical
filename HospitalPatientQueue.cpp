#include <iostream>
using namespace std;

struct Node
{
    int patientID;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void addPatient()
{
    int id;

    cout << "Enter patient ID: ";
    cin >> id;

    Node* newNode = new Node;

    newNode->patientID = id;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient " << id << " added to the queue.\n";
}

void serveNextPatient()
{
    if (front == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "Patient " << temp->patientID << " served.\n";

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

void displayPatients()
{
    if (front == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "Waiting Patients: ";

    while (temp != NULL)
    {
        cout << temp->patientID << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== HOSPITAL PATIENT MANAGEMENT =====\n";
        cout << "1. Add Patient to Queue\n";
        cout << "2. Serve Next Patient\n";
        cout << "3. Display All Waiting Patients\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                serveNextPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}