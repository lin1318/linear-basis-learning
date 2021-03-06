// 线性基_B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct edge {
	long long to, val;
};
bool vis[500050];
long long a[500050];
vector<edge> e[500050];
long long dis[500050];
long long p[63];
long long n, m,num;
void dfs(long long k) {
	vis[k] = true;
	for(int i=0;i<e[k].size();i++)
		if (vis[e[k][i].to] == true) {
			num++;
			a[num] = dis[k] ^ dis[e[k][i].to] ^ e[k][i].val;
		}
		else
		{
			dis[e[k][i].to] = dis[k] ^ e[k][i].val;
			dfs(e[k][i].to);
		}
}
int main()
{
	long long i, j, k,ans,l;
	edge x;
	while (cin >> n >> m) {
		num = 0;
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; i++)
			e[i].clear();
		for (i = 1; i <= m; i++) {
			cin >> j >> k>>l;
			x.to = k; x.val = l;
			e[j].push_back(x);
			x.to = j;
			e[k].push_back(x);
		}
		memset(dis, 0, sizeof(dis));
		memset(p, 0, sizeof(p));
		dfs(1);
        for(i=1;i<=num;i++)
			for (j = 62; j >= 0; j--) {
				if (((1LL << j)&a[i])!= 0) {
					if (p[j] == 0)
					{
						p[j] = a[i];
						break;
					}
					else
						a[i] ^= p[j];
				  }
			}
		ans = dis[n];
		for (i = 62; i >= 0; i--)
			if ((ans^p[i]) > ans)
				ans ^= p[i];
		cout << ans << endl;
	}
    return 0;
}

