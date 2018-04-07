#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int64_t T;
    cin >> T;
    for(int z = 0; z < T; z++)
    {
	int64_t N;
	cin >> N;
	vector<int64_t> l(N);
	for(int i = 0; i < N; i++)
	    cin >> l[i];
	bool done = false;
	while(!done)
	{
	    done = true;
	    for(int i = 0; i < l.size() - 2; i++)
		if(l[i] > l[i + 2])
		{
		    done = false;
		    int64_t t = l[i];
		    l[i] = l[i + 2];
		    l[i + 2] = t;
		}
	}
	int idx = 0;
	for(; idx < l.size() - 1; idx++)
	{
	    if(l[idx] > l[idx + 1])
		break;
	}
	cout << "Case #" << z + 1 << ": ";
	if(idx == l.size() - 1)
	    cout << "OK" << endl;
	else
	    cout << idx << endl;
    }
    return(0);
}
