#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[26][26] = {};
int check[26] = {};
int visit[26] = {};
int maxDist = 0;

vector <char> road;
vector <int> connected;
vector <vector<char>> graph(26);
vector <string> result;

int BFS(int cur)
{
	queue<int> Q;

	visit[cur] = 1;

	Q.push(cur + 'a');
	bool exitLoop = false;

	while (!Q.empty())
	{
		cur = Q.front() - 'a';
		Q.pop();
		for (int i = graph[cur].size() - 1; i >= 0; i--)
		{
			int next = graph[cur][i] - 'a';
			if (visit[next] == 0 && check[next] == 0)
			{
				Q.push(graph[cur][i]);
				if (graph[cur][i] == 'a')
				{
					exitLoop = true;
					break;
				}
				visit[next] = true;
			}
		}
		if (exitLoop == true)
			break;
	}

	if (Q.size() == 0)
		return 0;
	else return 1;
}

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
			maxDist = distance;
			return;
		}
	}

	memset(visit, 0, sizeof(visit));

	if (start != 0 && BFS(start) == 0)
		return;

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

	cout << maxDist << endl;

	return 0;
}