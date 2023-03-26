#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double epsilon = 0.00000001;

struct Pos
{
    double x;
    double y;
    double z;
};

Pos getMidPoint(Pos a, Pos b, double v)
{
    Pos mid;
    mid.x = a.x * v + b.x * (1 - v);
    mid.y = a.y * v + b.y * (1 - v);
    mid.z = a.z * v + b.z * (1 - v);

    return mid;
}

double getDistance(Pos a, Pos b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));
}

int main()
{
    vector<Pos> v(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> v[i].x;
        cin >> v[i].y;
        cin >> v[i].z;
    }

    int i = 10000;
    double minDist = 99999999;

    Pos mid1 = getMidPoint(v[0], v[1], 0.5);
    Pos mid2 = getMidPoint(v[2], v[3], 0.5);

    while (i--)
    {
        double l = 0, r = 1;
        double midValue = (l + r) / 2.0;
        while (midValue >= 0 && midValue <= 1)
        {
            if (l + epsilon > r) break;
            midValue = (l + r) / 2;
            mid1 = getMidPoint(v[0], v[1], midValue);

            Pos temp1, temp2;
            temp1 = getMidPoint(v[0], v[1], midValue + epsilon);
            temp2 = getMidPoint(v[0], v[1], midValue - epsilon);

            double ldist = getDistance(temp1, mid2);
            double rdist = getDistance(temp2, mid2);
            double dist = getDistance(mid1, mid2);

            double ret = min(ldist, rdist);
            if (ret > dist) break;
            ret = dist;

            if (rdist < ldist)
                r = midValue;
            else
                l = midValue;
        }

        l = 0, r = 1;
        midValue = (l + r) / 2;
        while (midValue >= 0 && midValue <= 1)
        {
            if (l + epsilon > r) break;
            midValue = (l + r) / 2;
            mid2 = getMidPoint(v[2], v[3], midValue);

            Pos temp1, temp2;
            temp1 = getMidPoint(v[2], v[3], midValue + epsilon);
            temp2 = getMidPoint(v[2], v[3], midValue - epsilon);

            double ldist = getDistance(temp1, mid1);
            double rdist = getDistance(temp2, mid1);
            double dist = getDistance(mid2, mid1);

            double ret = min(ldist, rdist);
            if (ret > dist) break;
            ret = dist;

            if (rdist < ldist)
                r = midValue;
            else
                l = midValue;
        }

        double distance = getDistance(mid1, mid2);

        if (minDist < distance) break;
        minDist = distance;
    }

    if (minDist < 0.0001) minDist = 0;
    cout << ceil(minDist) << endl;

    return 0;
}