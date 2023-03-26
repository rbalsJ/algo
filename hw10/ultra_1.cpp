#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[26][26] = {};
int check[26] = {};
int maxDist = 0;

vector <char> road;
vector <int> connected;
vector <vector<char>> graph(26);
vector <string> result;

void backTrack(int start, int distance)
{
	int count = 0;

	for (int i = 0; i < connected.size(); i++)
	{
		if (check[connected[i]] == 0)
			count++;
	}

	if (road.size() != 0 && road.back() == 'a')
	{
		if (distance > maxDist)
		{
			string temp = "a";
			for (int i = 0; i < road.size(); i++)
				temp.push_back(road[i]);
			result.push_back(temp);
			maxDist = distance;
			return;
		}
		else return;
	}

	else if (road.size() != 0 && check[0] != 0 && count == 0)
		return;

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (check[graph[start][i] - 'a'] == 0)
		{
			check[graph[start][i] - 'a'] = 1;

			int weight = map[start][graph[start][i] - 'a'];
			road.push_back(graph[start][i]);
			backTrack(graph[start][i] - 'a', distance + weight);

			if (start != 0)
				check[graph[start][i] - 'a'] = 0;
			road.pop_back();
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	char u, v;
	int d;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> d;
		graph[u - 'a'].push_back(v);
		graph[v - 'a'].push_back(u);

		map[u - 'a'][v - 'a'] = d;
		map[v - 'a'][u - 'a'] = d;
	}

	for (int i = 0; i < graph[0].size(); i++)
		connected.push_back(graph[0][i] - 'a');

	backTrack(0, 0);

	if (result.size() == 0)
	{
		cout << "None" << endl;
		return 0;
	}

	int maxIndex = 0;
	int maxSize = 0;
	for (int i = 0; i < result.size(); i++)
	{

		if (result[i].size() > maxSize)
		{
			maxSize = result[i].size();
			maxIndex = i;
		}
		else if (result[i].size() == maxSize)
		{
			if (result[maxIndex].compare(result[i]) > 0)
				maxIndex = i;
		}
	}

	cout << maxDist << endl;

	return 0;
}