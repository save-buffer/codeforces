#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dist;

int simulate(int T)
{
    int k = 0;
    vector<int> d = dist;
    bool left = false;
    bool right = false;
    for(int i = 0; true; i++)
    {
	for(int j = 0; j < i; j++)
	{
	    if(T + j <= n)
	    {
		d[T + j] = max(d[T + j] - 1, 0);
		if(d[T + j] == 0)
		{
//		cout << i << ' ' << T + j << ' ' << k << endl;
		    if(T + j > k)
			right = true;
		    else
			left = true;
		}
	    }
	    if(j != 0)
	    {
		if(T - j > 0)
		    d[T - j] = max(d[T - j] - 1, 0);

		if(T - j > 0 && d[T - j] == 0)
		{
//		    cout << i << ' ' << T - j << ' ' << k << endl;
		    if(T - j > k)
			right = true;
		    else
			left = true;
		}
	    }
	}
	
	if(!right)
	    k++;
	
	if(right && left)
	    return(i);
	if(k >= n)
	    return(-1);
    }
    return(-1);
}

int main(void)
{
    cin >> n;
    
    dist.resize(n + 1);
    for(int i = 1; i <= n; i++)
	cin >> dist[i];

    int min_time = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
	int t = simulate(i);
//	cout << i << ' ' << t << endl;
	if(t > -1)
	    min_time = min(t, min_time);
	if(min_time <= 2)
	    break;
    }

//    min_time = simulate(3);
    if(min_time == INT_MAX)
	min_time = -1;
    cout << min_time << endl;
    return(0);
}
