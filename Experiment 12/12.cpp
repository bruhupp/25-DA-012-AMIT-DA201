//Name: Amit
//Roll Number: 25/DA/012
//12. Write a program to solve the Matrix Chain Multiplicationo problem using Dynamic Programming. 
#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int main()
{
    int n;
    int p[MAX];
    int dp[MAX][MAX];

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter " << n + 1 << " dimensions:\n";

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Length is the number of matrices in the chain
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications = "
         << dp[1][n] << endl;

    return 0;
}