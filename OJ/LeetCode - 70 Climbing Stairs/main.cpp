#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	int a=1,b=1;
    	while(n--)
    	{
    		b+=a;
    		a=b-a;
    	}
    	return a;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
