#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 2)
		{
			cout << 1;
			continue;
		}
		vector<int> num;
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			cin >> temp;
			num.push_back(temp);
		}
		int result = 0;
		bool up = true;
		bool mark = false;
		int num_now = num[0];
		for (int i = 0; i < n; i++)
		{
			if (mark == false)
			{
				result++;
				num_now = num[i];
				while (num[i] == num_now)
				{
					i++;
					if (i >= n)
						break;
				}
				if (num[i] > num_now)
					up = true;
				else
					up = false;
				mark = true;
			}
			else
			{
				if ((up == true && num[i] < num_now) || (up == false && num[i] > num_now))
				{
					i--;
					mark = false;
				}
			}
			num_now = num[i];
		}
		cout << result;
	}

	return 0;
}