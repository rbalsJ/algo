#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Food
{
    int p, f, s, v, c;
};

struct Nutrient
{
    int minP, minF, minS, minV;
};

bool myCompare(Food a, Food b)
{
    return (a.p + a.f + a.s + a.v) / a.c > (b.p + b.f + b.s + b.v) / b.c;
}

vector<int> visit(50);
vector<vector<int>> selected;
Nutrient nutri;
Food minFood = { 0, };
int minCost = 1000000;
int k = 0;

void backTrack(int i, int cost, Food curr, Food food[])
{
    if (curr.p >= nutri.minP && curr.f >= nutri.minF && curr.s >= nutri.minS
        && curr.v >= nutri.minV)
    {
        if (minCost > cost)
        {
            minCost = cost;
            minFood = curr;

            if(!selected.empty()) selected.pop_back();
            selected.push_back(visit);
        }

        else if (minCost == cost)
        {
            if (minFood.p + minFood.f + minFood.s + minFood.v
                < curr.p + curr.f + curr.s + curr.v)
            {
                minFood = curr;
                if (!selected.empty()) selected.pop_back();
                selected.push_back(visit);
            }
            //else if (minFood.p + minFood.f + minFood.s + minFood.v == curr.p + curr.f + curr.s + curr.v)
            //{
            //    selected.push_back(visit);
            //}
        }
        return;
    }
    else if (cost > minCost)
        return;


    if (i >= k) return;

    visit[i + 1] = 1;
    curr.p += food[i + 1].p;    curr.f += food[i + 1].f;
    curr.s += food[i + 1].s;    curr.v += food[i + 1].v;
    backTrack(i + 1, cost + food[i + 1].c, curr, food);

    visit[i + 1] = 0;
    curr.p -= food[i + 1].p;    curr.f -= food[i + 1].f;
    curr.s -= food[i + 1].s;    curr.v -= food[i + 1].v;
    backTrack(i + 1, cost, curr, food);
}

int main()
{
    cin >> k;

    cin >> nutri.minP >> nutri.minF >> nutri.minS >> nutri.minV;

    Food* food = new Food[k + 1];

    Food currFood;
    currFood.p = 0; currFood.f = 0;
    currFood.s = 0; currFood.v = 0;
    currFood.c = 0;

    for (int i = 1; i <= k; i++)
    {
        cin >> food[i].p;   cin >> food[i].f;
        cin >> food[i].s;   cin >> food[i].v;
        cin >> food[i].c;
    }

    int p = 0; int f = 0; int s = 0; 
    int v = 0;
    for (int i = 1; i <= k; i++)
    {
        p += food[i].p; f += food[i].f;
        s += food[i].s; v += food[i].v;
    }

    //for (int i = 0; i <= k; i++)
    //    cout << food[i].p << " " << food[i].f << " "
    //    << food[i].s << " " << food[i].v << endl;

    if (p < nutri.minP || f < nutri.minF || s < nutri.minS || v < nutri.minV)
    {
        cout << "0" << endl;
        return 0;
    }

    backTrack(0, 0, currFood, food);

    for (int i = 0; i < selected[0].size(); i++)
    {
        if (selected[0][i] == 1)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}