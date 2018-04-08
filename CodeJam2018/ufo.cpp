#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int T;
    cout.precision(17);
    cin >> T;
    for(int z = 0; z < T; z++)
    {
	double A;
	cin >> A;
	double theta = acos(A / sqrt(2.0)) + (M_PI * 0.25);
	tuple<double, double, double> e1, e2, e3;
	e1 = make_tuple(0.5 * cos(theta), 0.5 * sin(theta), 0.0);
	e2 = make_tuple(-0.5 * sin(theta), 0.5 * cos(theta), 0.0);
	e3 = make_tuple(0.0, 0.0, 0.5);
    	if(A <= 1.414213 + 1e-6)
	{
	    //find closed form for larger case
	}
	cout << "Case #" << z + 1 << ":" << endl;
	cout << get<0>(e1) << ' ' << get<1>(e1) << ' ' << get<2>(e1) << endl;
	cout << get<0>(e2) << ' ' << get<1>(e2) << ' ' << get<2>(e2) << endl;
	cout << get<0>(e3) << ' ' << get<1>(e3) << ' ' << get<2>(e3) << endl;

    }
    return(0);
}
