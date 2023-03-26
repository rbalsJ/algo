#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;

void caclArea(vector<pair<int, int>> point)
{
    for (int i = 0; i < point.size() - 2; i++)
    {
        pair<int, int> p = point[i];
        pair<int, int> q = point[i + 1];
        pair<int, int> r = point[i + 2];

        int area;
        area = (q.first * p.second + r.first * q.second + p.first * r.second)
            - (p.first * q.second + q.first * r.second + r.first * p.second);
        
        if (i == point.size() - 3)
        {
            if (area > 0)
                answer.insert(answer.begin(), 1);
        }
        else
        {
            if (area > 0)
                answer.push_back(i + 2);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> point;
    for (int i = 0; i < N; i++)
    {
        int x; int y;
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }

    point.push_back(make_pair(point[0].first, point[0].second));
    point.push_back(make_pair(point[1].first, point[1].second));

    caclArea(point);

    if (answer.empty())
        cout << "0" << endl;
    else
    {
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << endl;
    }

    return 0;
}