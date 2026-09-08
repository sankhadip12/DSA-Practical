#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, source, auxiliary, destination);

    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    cout << "===== TOWER OF HANOI =====" << endl;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number of disks." << endl;
        return 0;
    }

    cout << "\nSequence of disk movements:\n";

    towerOfHanoi(n, 'A', 'C', 'B');

    long long moves = (1LL << n) - 1;

    cout << "\nTotal number of moves: " << moves << endl;

    return 0;
}