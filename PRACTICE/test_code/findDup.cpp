#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cout << "Enter the String : ";
    cin >> s;
    map<char, int> count;
    int len = s.length();

    for (int i = 0; i < 26; i++)
        count['a' + i] = 0;

    for (int i = 0; i < len; i++)
        count[s[i]]++;

    cout << "Characters with count greater than 1 : " << endl;
    for (int i = 0; i < 26; i++)
    {
        if (count['a' + i] > 1)
        {
            char ch = 'a' + i;
            cout << ch << " -> " << count['a' + i] << endl;
        }
    }
}