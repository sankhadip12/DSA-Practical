#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top = NULL;

void visitPage()
{
    string page;

    cout << "Enter webpage: ";
    cin >> page;

    Node* newNode = new Node;

    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Visited: " << page << endl;
}

void goBack()
{
    if (top == NULL)
    {
        cout << "History is empty!" << endl;
        return;
    }

    Node* temp = top;

    cout << "Going back from: " << temp->page << endl;

    top = top->next;
    delete temp;

    if (top != NULL)
        cout << "Current webpage: " << top->page << endl;
    else
        cout << "No previous webpage." << endl;
}

void viewCurrentPage()
{
    if (top == NULL)
    {
        cout << "History is empty!" << endl;
        return;
    }

    cout << "Current webpage: " << top->page << endl;
}

void displayHistory()
{
    if (top == NULL)
    {
        cout << "History is empty!" << endl;
        return;
    }

    Node* temp = top;

    cout << "Visited Pages (Top to Bottom): ";

    while (temp != NULL)
    {
        cout << temp->page << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== BROWSER BACK HISTORY =====" << endl;
        cout << "1. Visit a new webpage" << endl;
        cout << "2. Go back" << endl;
        cout << "3. View current webpage" << endl;
        cout << "4. Display all visited webpages" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                visitPage();
                break;

            case 2:
                goBack();
                break;

            case 3:
                viewCurrentPage();
                break;

            case 4:
                displayHistory();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}