#include <iostream>
#include <string>
using namespace std;

#define MAX 5

string cart[MAX];
int top = -1;

void push()
{
    string product;

    if (top == MAX - 1)
    {
        cout << "Stack Overflow - Cart is Full." << endl;
    }
    else
    {
        cout << "Enter product: ";
        cin >> product;

        top++;
        cart[top] = product;

        cout << product << " added to cart." << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow - Cart is Empty." << endl;
    }
    else
    {
        cout << "Removed: " << cart[top] << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Cart is Empty." << endl;
    }
    else
    {
        cout << "Last Added Product: " << cart[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Cart is Empty." << endl;
    }
    else
    {
        cout << "Cart Products (Top to Bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << cart[i] << " ";
        }

        cout << endl;
    }
}

void menu()
{
    int choice;

    do
    {
        cout << "\n===== ONLINE SHOPPING CART =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Remove Product" << endl;
        cout << "3. View Last Added Product" << endl;
        cout << "4. Display Cart" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);
}

int main()
{
    menu();
    return 0;
}