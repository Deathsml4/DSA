/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int lcs(vector<int> a, int m, vector<int> b, int n) {
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = ((dp[i-1][j] > dp[i][j-1])? dp[i-1][j]:dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

int main()
{
    int m, n, k;
    cin >> m >> n;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < m; i++) {
        cin >> k;
        a.push_back(k);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        b.push_back(k);
    }
    
    cout << lcs(a, m, b, n);

    return 0;
}
