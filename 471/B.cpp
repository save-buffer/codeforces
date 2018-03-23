#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    if(s.size() < 4)
    {
	cout << "No" << endl;
	return(0);
    }

    int count[26];
    for(int i = 0; i < 26; i++)
	count[i] = 0;
    for(char c : s)
	count[c - 'a']++;

    int types_of_chars = 0;
    int min_count = INT_MAX;
    for(int i = 0; i < 26; i++)
    {

	if(count[i] != 0)
	{
	    min_count = min(min_count, count[i]);
	    types_of_chars++;
	}
    }

    if(types_of_chars <= 1 || types_of_chars > 4)
    {
	cout << "No" << endl;
	return(0);
    }

    if(types_of_chars >= 3 || min_count >= 2)
    {
	cout << "Yes" << endl;
	return(0);
    }
    cout << "No" << endl;
    return(0);
}
