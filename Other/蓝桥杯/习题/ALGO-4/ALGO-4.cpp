#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
const int MAXN = 100001;
int M;     //��ʾ�ߵ������ţ���ʼΪ0
int head[MAXN];      //��ʾĳ����������ӵı�
int dp[MAXN][2];     //dp[x][0]��ʾ��x����㲻ѡ��ʱ���Ȩֵ��dp[x][1]��ʾ��x�����ѡ��ʱ���Ȩֵ
struct Edge {
	int toNode;      //��ʾ�����ߵ���Ľ��
	int nextEdge;   //��ʾ�����ߵĳ���������ӵ���һ����
}edge[2 * MAXN];        //һ����n����㣬��n-1���ߣ����ǲ�ͬ�ĳ������������ͬ�ıߣ�������2n-2����

						//���±߼���߼�,������
void add(int from, int to) {
	edge[M].toNode = to;
	edge[M].nextEdge = head[from];
	head[from] = M++;                            //head[x]��ֵ���ܻᱻ���θ�ֵ
}

//����dfs����
void dfs(int node, int preNode) {
	for (int i = head[node]; i != -1; i = edge[i].nextEdge) {
		if (edge[i].toNode == preNode)             //˵���������Ѿ�������
			continue;
		int toNode = edge[i].toNode;           //��ʾ��i����Ľ��
		dfs(toNode, node);
		dp[node][0] += max(dp[toNode][0], dp[toNode][1]);             //�ý�㲻�㣬��ñ��ϵ���һ����ѡҲ�ɲ�ѡ
		dp[node][1] += dp[toNode][0];                                  //�Ľ��ѡ�ˣ��ñ�����һ���Ͳ���ѡ��
	}
}
int main() {
	int n;
	memset(head, -1, sizeof(head));           //���б���Ϊ-1����ʾ�����ڸñ�
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][1];                      //ÿһ������Ȩֵ
	}
	for (int j = 1; j <= n - 1; j++) {
		int from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}
	dfs(1, 0);                      //��1�Ž�㿪ʼ���̬�滮
	int result = max(dp[1][0], dp[1][1]);          //��Ϊ��ȷ������㣬���ԴӼ��ſ�ʼ��̬�滮���Ҽ��ŵ�״̬
												   //ͬ������Ҳ����д��      dfs(2, 0);   int result = max(dp[2][0], dp[2][1]);������ֻ��һ������ʱ��Ͳ�����
	cout << result << endl;
	return 0;
}