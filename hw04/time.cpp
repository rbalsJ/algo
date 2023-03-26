#include <queue>
#include <vector>
#include "timebomb.h"
using namespace std;

struct Round
{
    int comp1;
    int comp2;
    int result;
};

int main()
{
    int N;
    int check[10000];
    vector<Round> v(10000);

    box_ready();
    N = box_size();

    queue<int> q;
    int count = 0;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while (!q.empty())
    {
        auto round = q.size();
        int winner;
        int loser;

        if (round == 1)
            break;

        for (int i = 0; i < round / 2; i++)
        {
            winner = q.front();
            v[count].comp1 = winner;
            q.pop();

            loser = q.front();
            v[count].comp2 = loser;

            q.pop();

            v[count].result = winner;

            if (box_comp(winner, loser) == -1)
            {
                winner = loser;
                v[count].result = winner;
            }

            q.push(winner);
            count++;
        }
    }

    int maxIndex = count - 1;
    int max = v[maxIndex].result;

    int amount = 0;
    for (int i = 0; i < count; i++)
    {
        if (v[i].result == max)
        {
            if (max == v[i].comp1)
                check[amount] = v[i].comp2;
            else
                check[amount] = v[i].comp1;
            amount++;
        }
    }

    queue<int> p;

    for (int i = 0; i < amount; i++)
        p.push(check[i]);

    while (!p.empty())
    {
        auto round = p.size();
        int winner;
        int loser;

        if (round == 1)
            break;

        for (int i = 0; i < round / 2; i++)
        {
            winner = p.front();
            p.pop();

            loser = p.front();
            p.pop();

            if (box_comp(winner, loser) == -1)
                winner = loser;

            p.push(winner);
        }
    }

    box_report(p.front());

    return 0;
}