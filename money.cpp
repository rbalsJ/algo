#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;
string input;

long long Calc(long long a, long long b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
}

long long getMax(int number[], string op[], int count)
{
    long long maxdp[31][31] = {};
    long long mindp[31][31] = {};
    long long maxCalc = LLONG_MIN;
    long long minCalc = LLONG_MAX;

    for (int i = 0; i < count; i++)
    {
        maxdp[i][i] = number[i];
        mindp[i][i] = number[i];
    }


    for (int k = 0; k < count - 1; k++)
    {
        for (int i = 0; i < count - k - 1; i++)
        {
            int j = i + k + 1;

            maxCalc = LLONG_MIN;
            minCalc = LLONG_MAX;

            for (int l = i; l < j; l++)
            {
                long long num1, num2, num3, num4;

                num1 = Calc(maxdp[i][l], maxdp[l + 1][j], input[2 * l + 1]);
                num2 = Calc(maxdp[i][l], mindp[l + 1][j], input[2 * l + 1]);
                num3 = Calc(mindp[i][l], maxdp[l + 1][j], input[2 * l + 1]);
                num4 = Calc(mindp[i][l], mindp[l + 1][j], input[2 * l + 1]);

                maxCalc = max({ maxCalc, num1, num2, num3, num4 });
                minCalc = min({ minCalc, num1, num2, num3, num4 });
            }

            maxdp[i][j] = maxCalc;
            mindp[i][j] = minCalc;
        }
    }
    return maxdp[0][count - 1];
}


int main()
{
    int number[31] = {};
    string op[30] = {};

    int numCount = 0;
    int opCount = 0;
    int N = 0;

    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    for (int i = 0; i < input.length(); i++)
    {
        if (N % 2 == 0)
        {
            char temp = input[i];
            if (temp == '-')
            {
                temp = input[i + 1];
                input.replace(i, 1, " ");
                number[numCount] = -(temp - '0');
                numCount++;
                i++;
            }
            else
            {
                number[numCount] = temp - '0';
                numCount++;
            }
        }
        N++;
    }
    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    cout << getMax(number, op, numCount) << endl;

    return 0;
}