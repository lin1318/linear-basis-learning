// 线性基_F.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[100500];
long long p[63];
long long d[63];
long long mul[100500];
const long long mod = 10086;
bool cmp(long long a, long long b) {
	return a > b;
}
int main()
{
	long long i, j, k, n, m,q,nums,cnt,ans,now;
	mul[0] = 1;
	for (i = 1; i < 100050; i++)
		mul[i] = (mul[i - 1] * 2) % mod;
	while (cin >> n) {
		for (i = 1; i <= n; i++)
			cin >> a[i];
		memset(p, 0, sizeof(p));
		memset(d, 0, sizeof(d));
		nums = 0;
		for (i = 1; i <= n; i++) {
			for (j = 62; j >= 0; j--)
				if (((1LL << j)&a[i]) != 0) {
					if (p[j] == 0)
					{
						p[j] = a[i];
						break;
					}
					else
						a[i] ^= p[j];
				}
			if (a[i] == 0)
				nums++;
		}
		for (i = 62; i >= 0; i--)
			for (j = i - 1; j >= 0; j--)
				if (((1LL << j)&p[i]) != 0)
					p[i] ^= p[j];
		cnt = 0;
		for(i=0;i<=62;i++)
			if(p[i]!=0)
			{ 
				cnt++;
				d[cnt] = p[i];
			}
		sort(d + 1, d + 1 + cnt, cmp);
		now = 0; ans = 1;
		cin >> q;
		for (i = 1; i <= cnt; i++) {
			if ((now^d[i]) < q) {
				now ^= d[i];
				ans = (ans + mul[cnt-i]) % mod;
			}
		}
		ans = ans*mul[nums] % mod;
		if (q == 0)
			cout << 1 << endl;
		else
			cout << (ans + 1) % mod << endl;
	}
    return 0;
}

