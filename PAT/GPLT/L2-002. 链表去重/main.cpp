//
//  main.cpp
//  Test
//
//  Created by Misaka on 2018/3/30.
//  Copyright © 2018 Misaka. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
struct Node
{
	Node(){}
	Node(string a, int k, string n) : address(a), key(k), next(n){}
	string address;
	int key;
	string next;
	bool operator ==(const string & i)
	{
		return this->address == i;
	}
};

class isEqual
{
public:
isEqual(Node m) : m(m){}
bool operator()(Node &a)
{
	return abs(a.key) == abs(m.key);
}
private:
Node m;
};

int main()
{
	string start_address;
	int n;
	cin >> start_address >> n;
	vector<Node> input(n);
	for(int i = 0; i < n; i++)
	{
		cin >> input[i].address >> input[i].key >> input[i].next;
	}
	vector<Node> ans, del;
	string next = start_address;
	while(!input.empty())
	{
		auto it = find(input.begin(), input.end(), next);
		Node now = *it;
		next = now.next;
		if(find_if(ans.begin(), ans.end(), isEqual(now)) == ans.end())
		{
			if(!ans.empty())
			{
				auto last = ans.end() - 1;
				last->next = now.address;
			}
			ans.push_back(now);
		}
		else
		{
			if(!del.empty())
			{
				auto last = del.end() - 1;
				last->next = now.address;
			}
			del.push_back(now);
		}
		input.erase(it);
	}
	for(auto i:ans)
	{
		cout << i.address << " " << i.key << " " << i.next << endl;
	}
	for(auto i:del)
	{
		cout << i.address << " " << i.key << " " << i.next << endl;
	}
	return 0;
}

//智障做法
//练习C++ STL 的find 和find_if
//学习虚函数