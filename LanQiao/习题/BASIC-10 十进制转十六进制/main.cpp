#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a;
	string result;
	stringstream ss;
	cin >> dec >> a;
	ss << hex << a;
	result = ss.str();
	transform(result.begin(), result.end(), result.begin(), ::toupper);
	cout << result << endl;
	return 0;
}