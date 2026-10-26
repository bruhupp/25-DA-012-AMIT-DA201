//Name: Amit
//Roll Number: 25/DA/012
//14. Write a program to solve the 0/1 Knapsack problem using Dynamic Programming.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<vector<int>> dp(
        n + 1, vector<int>(capacity + 1, 0)
    );

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            // Exclude the current item
            dp[i][w] = dp[i - 1][w];

            // Include the current item if it fits
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "\nMaximum value = " << dp[n][capacity] << endl;

    // Identify the selected items
    cout << "Selected items (1-based indexing): ";

    int w = capacity;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }

    cout << endl;

    return 0;
}