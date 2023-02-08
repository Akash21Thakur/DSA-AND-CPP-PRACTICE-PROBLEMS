#include <bits/stdc++.h>
using namespace std;

int func(string s)
{
	int red_count = 0;

	for (char c : s)
	{

		if (c == 'R')
			++red_count;
	}

	int left = 0, right = s.size() - 1, result = 0;

	while (left < right)
	{
		if (s[left] == 'R' && s[right] == 'R')
		{
			red_count -= 2;
			result += right - left - 1 - red_count;

			++left;

			--right;
		}

		else if (s[left] != 'R')
			++left;

		else

			--right;
	}
	return result;
}
int main()
{
	string s;
	cin >> s;
	cout << func(s) << endl;
}
