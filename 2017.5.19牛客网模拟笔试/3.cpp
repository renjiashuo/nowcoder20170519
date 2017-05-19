#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int result = 0;
		vector<int> num;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			num.push_back(temp);
		}
		vector<pair<int, int> > numUpPair;
		int nowNum = num[0];
		int min = 0;
		for (int i = 1; i < n; i++)
		{
			if (num[i] < num[i - 1])
			{
				numUpPair.push_back(make_pair(min, i));
				min = i;
				nowNum = num[i];
			}
		}
		numUpPair.push_back(make_pair(min, n));
		for (int i = 0; i < numUpPair.size() - 1; i++)
		{
			int one = numUpPair[i].second - numUpPair[i].first;
			int two = numUpPair[i + 1].second - numUpPair[i + 1].first;
			if (one == 1 || two == 1)
			{
				if (one + two > result)
					result = one + two;
				continue;
			}
			int smallLast = numUpPair[i].second - 1;
			int bigFirst = numUpPair[i + 1].first;
			if (num[smallLast - 1] < num[bigFirst] || num[smallLast] < num[bigFirst + 1])
			{
				if (one + two > result)
					result = one + two;
			}
		}
		cout << result;
	}

	return 0;
}