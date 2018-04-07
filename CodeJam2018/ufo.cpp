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
	cout << "Case #" << z + 1 << ":" << endl;
	cout << 0.5 * cos(theta) << ' ' << 0.5 * sin(theta) << ' ' << 0.0 << endl;
	cout << -0.5 * sin(theta) << ' ' << 0.5 * cos(theta) << ' ' << 0.0 << endl;
	cout << 0.0 << ' ' << 0.0 << ' ' << 0.5 << endl;
    }
    return(0);
}
