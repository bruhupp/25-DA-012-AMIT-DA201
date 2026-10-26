//Name: Amit
//Roll Number: 25/DA/012
//15. Write a program to solve the N-Queens problem using the Backtacking technique.
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> position;
int solutionCount = 0;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Check the same column
        if (position[i] == col)
            return false;

        // Check diagonals
        if (abs(position[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

void solveNQueens(int row)
{
    // All queens have been placed
    if (row == n)
    {
        solutionCount++;

        cout << "\nSolution " << solutionCount << ":\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (position[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }

        return;
    }

    // Try placing a queen in each column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            position[row] = col;
            solveNQueens(row + 1);
        }
    }
}

int main()
{
    cout << "Enter value of N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "N must be positive.\n";
        return 0;
    }

    position.resize(n);

    solveNQueens(0);

    if (solutionCount == 0)
        cout << "\nNo solution exists for N = " << n << endl;
    else
        cout << "\nTotal solutions = " << solutionCount << endl;

    return 0;
}