#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

bool compDay(pair<int, int> i, pair<int, int> j)
{
    if (i.first == j.first)
        return i.second > j.second;
    else
        return i.first > j.first;
}

bool compPay(pair<int, int> i, pair<int, int> j)
{
    if (i.second == j.second)
        return i.first > j.first;
    else
        return i.second > j.second;
}

int main()
{
    vector<pair<int, int>> v;
    vector<pair<int, int>> not_used;
    vector<pair<int, int>> used;
    int maxPay = 0;

    int n = 0; int t = 0; int k = 0;
    cin >> n >> t >> k;

    for (int i = 0; i < n; i++)
    {
        int pay, day;
        cin >> pay >> day;
        v.push_back(make_pair(day, pay));
    }

    sort(v.begin(), v.end(), compDay);

    not_used = v;

    int count;
    for (int i = t; i > 0; i--)
    {
        count = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first >= i)
            {
                pq.push(v[j]);
                not_used.erase(not_used.begin());
                count++;
            }
        }
        while (count > k)
        {
            not_used.push_back(pq.top());
            pq.pop();
            count--;
        }
        while (pq.size() > 0)
        {
            used.push_back(pq.top());
            pq.pop();
        }

        sort(not_used.begin(), not_used.end(), compDay);
        v = not_used;
    }

    for (int i = 0; i < used.size(); i++)
        maxPay += used[i].second;

    int minGap = 1000000;
    int gap = 1000000;

    int sum = 0;
    sort(used.begin(), used.end(), compPay);
    for (int i = 0; i < used.size() - 1; i++)
        sum += used[i].second;
    minGap = maxPay - sum;

    sort(used.begin(), used.end());

    for (int i = 0; i < k; i++)
    {
        for (int j = used.size() - 1; j >= 0; j--)
        {
            for (int l = 0; l < not_used.size(); l++)
            {
                if (not_used[l].first >= j / k + 1)
                    gap = used[j].second - not_used[l].second;

                if (gap < minGap && gap != 0)
                    minGap = gap;
            }
        }
    }

    cout << maxPay << " " << maxPay - minGap << endl;

    return 0;
}