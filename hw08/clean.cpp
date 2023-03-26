#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Clean
{
    int start;
    int end;
    int cost;
    int day;
};

bool compare(Clean a, Clean b)
{
    if (a.start == b.start)
        return a.end < b.end;
    else
        return a.start < b.start;
}

bool desc(int a, int b) {
    return a > b;
}

int main()
{
    vector<Clean> v;

    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Clean temp;
        cin >> temp.start >> temp.end >> temp.cost;
        temp.day = temp.end - temp.start + 1;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    vector<vector<Clean>> table;

    for (int i = 1; i <= v[N - 1].end; i++)
    {
        vector<Clean> temp;
        for (int j = 0; j < N; j++)
        {
            if (v[j].start == i)
                temp.push_back(v[j]);
        }
        table.push_back(temp);
    }
    
    int dp[1100] = {};
    int day[1100] = {};
    int temp[1100] = {};
    int temp2[1100] = {};

    int dpMax = 0;
    int dayMin = 10000;

    for (int i = table.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            temp[j] = max(dp[i + 1], dp[i + table[i][j].day] + table[i][j].cost - 10);
            temp2[j] = max(day[i + 1], day[i + table[i][j].day] + table[i][j].day);
        }

        sort(temp, temp + table[i].size(), desc);
        sort(temp2, temp2 + table[i].size(), desc);
        for (int k = 0; k < table[i].size(); k++)
        {
            if (temp[0] == temp[k + 1] && temp2[0] > temp2[k + 1])
                temp2[0] = temp2[k + 1];

        }
        if (temp[0] > dpMax)
        {
            dpMax = temp[0];
            dayMin = temp2[0];
        }
        else if (temp[0] == dpMax)
            dayMin = min(dayMin, temp[0]);

        dp[i] = temp[0];
        day[i] = dayMin;
    }

    cout << dp[0] + 10 << " " << day[0] << endl;
}