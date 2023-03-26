#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void FindLcs(string str1, string str2)
{
    int** dp = new int* [110]();

    for (int i = 0; i < 110; i++)
        dp[i] = new int[110]();

    string** lcsStr = new string * [200]();
    
    for (int i = 0; i < 200; i++)
        lcsStr[i] = new string[200]();

    int maxLength = 0;

    string Lcs;

    for (int i = 5; i <= str1.size() + 4; i++)
    {
        for (int j = 5; j <= str2.size() + 4; j++)
        {
            if (str1[i - 5] == str2[j - 5])
            {
                if (dp[i - 2][j - 2] == max({ dp[i - 2][j - 2],dp[i - 1][j - 2],dp[i - 2][j - 1],dp[i - 1][j - 1] }))
                {
                    dp[i][j] = dp[i - 2][j - 2] + 1;
                    lcsStr[i][j] = lcsStr[i - 2][j - 2] + str1[i - 5];
                }

                else if (dp[i - 1][j - 2] == max({ dp[i - 2][j - 2],dp[i - 1][j - 2],dp[i - 2][j - 1],dp[i - 1][j - 1] }))
                {
                    dp[i][j] = dp[i - 1][j - 2] + 1;
                    lcsStr[i][j] = lcsStr[i - 1][j - 2] + str1[i - 5];
                } 

                else if (dp[i - 2][j - 1] == max({ dp[i - 2][j - 2],dp[i - 1][j - 2],dp[i - 2][j - 1],dp[i - 1][j - 1] }))
                {
                    dp[i][j] = dp[i - 2][j - 1] + 1;
                    lcsStr[i][j] = lcsStr[i - 2][j - 1] + str1[i - 5];
                }  

                else if (dp[i - 1][j - 1] == max({ dp[i - 2][j - 2],dp[i - 1][j - 2],dp[i - 2][j - 1],dp[i - 1][j - 1] }))
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    lcsStr[i][j] = lcsStr[i - 1][j - 1] + str1[i - 5];
                }   

                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    Lcs = lcsStr[i][j];
                }

                else if (dp[i][j] == maxLength)
                    Lcs = min(Lcs, lcsStr[i][j]);
            }
        }
    }

    cout << Lcs << endl;
}


int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    FindLcs(str1, str2);

    return 0;
}