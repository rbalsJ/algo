#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<string, int>> original;

int goalIndex = 0;

int checkDigit(char ch)
{
	if (ch == 'a')
		return 0;
	else if (ch == 'c')
		return 1;
	else if (ch == 'g')
		return 2;
	else if (ch == 'n')
		return 3;
	else
		return 4;
}

void countSort(int start, int end, int index, vector<pair<string, int>>& dna, int dataCount[], int tempCount[])
{
	for (int i = start; i < end; i++)
	{
		dataCount[checkDigit(original[i].first[index]) + 1]++;
		tempCount[checkDigit(original[i].first[index]) + 1]++;
	}

	for (int i = 0; i < 5; i++)
	{
		dataCount[i + 1] += dataCount[i];
		tempCount[i + 1] += dataCount[i];
	}

	for (int i = start; i < end; i++) {
		dna[start + tempCount[checkDigit(original[i].first[index])]++] = original[i];
	}
	for (int i = start; i < end; i++) {
		original[i] = dna[i];
	}
}

void radixSort(int start, int end, int index, vector<pair<string, int>>& dna)
{
	if (end <= start + 1)
		return;

	int dataCount[6] = {};
	int tempCount[6] = {};

	countSort(start, end, index, dna, dataCount, tempCount);

	for (int i = 0; i < 5; i++)
		radixSort(start + dataCount[i], start + dataCount[i + 1], index + 1, dna);
}

int main()
{
	int N;

	cin >> N;

	size_t maxSize = 0;
	int count = 0;

	string input;
	getline(cin, input);

	while (1)
	{
		getline(cin, input);
		if (input == "")
			break;
		if (input.size() > maxSize)
			maxSize = input.size();
		original.push_back(make_pair(input, count + 1));
		count++;
	}

	vector<pair<string, int>> dna(original.size());
	radixSort(0, original.size(), 0, dna);

	cout << original[N - 2].second << endl;
	cout << original[N - 1].second << endl;
	cout << original[N].second << endl;
}