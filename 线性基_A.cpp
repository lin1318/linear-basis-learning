// 线性基_A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	long long id, magic;
};
bool cmp(node a,node b) {
	return a.magic > b.magic;
}
node a[1050],p[1050];
int main()
{
	long long i, j, k, n, m,ans;
	while (cin >> n) {
		for (i = 1; i <= n; i++)
			cin >> a[i].id >> a[i].magic;
		for (i = 62; i >= 0; i--)
		{
			p[i].id = 0;
			p[i].magic = 0;
		}
		sort(a + 1, a + 1 + n, cmp);
		for(i=1;i<=n;i++)
			for(j=62;j>=0;j--)
				if (((1LL << j) & (a[i].id))!= 0) {
					if (p[j].id == 0) {
						p[j] = a[i];
						break;
					}
					else
						a[i].id = a[i].id^p[j].id;
				}
		ans = 0;
		for (j = 62; j >= 0; j--)
			if (p[j].magic > 0)
				ans += p[j].magic;
		cout << ans << endl;
	}
    return 0;
}

