#include <iostream>
using namespace std;

int arr[100], n;

void inputArray();
void displayArray();
void insertElement();
void deleteElement();
void searchElement();

int main()
{
    int choice;

    inputArray();

    do
    {
        cout << "\n===== STUDENT REGISTRATION OPERATIONS =====\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Searching\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayArray();
                break;

            case 2:
                insertElement();
                displayArray();
                break;

            case 3:
                deleteElement();
                displayArray();
                break;

            case 4:
                searchElement();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}

void inputArray()
{
    cout << "Enter the number of students: ";
    cin >> n;

    cout << "Enter " << n << " registration numbers:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void displayArray()
{
    cout << "Student Registration Numbers: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void insertElement()
{
    int pos, value;

    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid Position!\n";
        return;
    }

    cout << "Enter registration number: ";
    cin >> value;

    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    cout << "Registration number inserted successfully.\n";
}

void deleteElement()
{
    int pos;

    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n)
    {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Registration number deleted successfully.\n";
}

void searchElement()
{
    int key, found = -1;

    cout << "Enter registration number to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
        cout << "Registration number not found.\n";
    else
        cout << "Registration number found at index " << found << ".\n";
}