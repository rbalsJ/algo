#include <iostream>
#include <algorithm>
using namespace std;

int input[10001] = { 0 };
int temp[10001] = { 0 };
int k = 0;

void flip(int array[], int start, int end)
{
	reverse(array + start, array + end + 1);
	for (int i = start; i <= end; i++)
		array[i] = -(array[i]);
}

void countFlip()
{
	int start = 0;
	int end = 0;
	int count = 0;

	for (int i = 1; i <= k; i++)
	{
		if (i != input[i] && start == 0)
		{
			start = i;
			i--;
			continue;
		}

		else if (input[i] == start || -(input[i]) == start)
		{
			end = i;
			flip(input, start, end);
			count++;

			start = 0;
			end = 0;
			i = 0;
		}
	}

	if (count > 2)
	{
		count = 0;

		for (int i = k; i > 0; i--)
		{
			if (temp[i] != i && end == 0)
			{
				end = i;
				i++;
				continue;
			}

			else if (temp[i] == end || -(temp[i]) == end)
			{
				start = i;
				flip(temp, start, end);
				count++;

				end = 0;
				i = k + 1;
			}
		}
	}

	if (count == 1)
		cout << "one" << "\n";

	else if (count == 2)
		cout << "two" << "\n";

	else if (count > 2)
		cout << "over" << "\n";
}

int main()
{
	cin >> k;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			cin >> input[j];
			temp[j] = input[j];
		}
		countFlip();
	}

	return 0;
}