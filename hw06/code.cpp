#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

string FindLps(string str)
{
    int n = str.size();
    int** dp = new int* [n]();
    string** lpsStr = new string* [n]();


    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n]();
        lpsStr[i] = new string[n]();
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        lpsStr[i][i] = str[i];
    }


    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (str[i] == str[j] && k == 2)
            {
                dp[i][j] = 2;
                lpsStr[i][j] = lpsStr[i + 1][j] + lpsStr[i][j - 1];
            }

            else if (str[i] == str[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
                lpsStr[i][j] = str[i] + lpsStr[i + 1][j - 1] + str[j];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);

                if (lpsStr[i][j - 1].size() > lpsStr[i + 1][j].size())
                    lpsStr[i][j] = lpsStr[i][j - 1];

                else if (lpsStr[i][j - 1].size() < lpsStr[i + 1][j].size())
                    lpsStr[i][j] = lpsStr[i + 1][j];

                else
                    lpsStr[i][j] = min(lpsStr[i][j - 1], lpsStr[i + 1][j]);
            }

        }
    }

    return lpsStr[0][n - 1];
}

int main()
{
    string inputStr;
    cin >> inputStr;
    cout << FindLps(inputStr);

    return 0;
}
