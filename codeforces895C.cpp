// codeforces895C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long prime[19] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
long long a[100050];
long long b[100050];
long long p[19];
long long l,r;
long long twopow[100050];
const long long mod = 1000000007;
long long change(long long x) {
	long long ans = 0,i,j;
	for (i = 0; i < 19; i++) {
		j = 0;
		while (x > 1 && x%prime[i] == 0) {
			j = 1 - j;
			x /= prime[i];
		}
		if (j == 1)
			ans = ans + (1LL << i);
		if (x==1)
			break;
	}
	return ans;
}
void build() {
	long long i, j;
	for(i=1;i<=l;i++)
		for (j = 18; j >= 0; j--) {
			if ((b[i] & (1LL << j))!= 0) {
				if (p[j] == 0)
				{
					p[j] = b[i];
					break;
				}
				else
					b[i] ^= p[j];
			}
		}
	r = 0;
	for (j = 18; j >= 0; j--)
		if (p[j] != 0)
			r++;
}
int main()
{
	long long i, k, n;
	ios::sync_with_stdio(false);
	twopow[0] = 1;
	for (i = 1; i < 100050; i++)
		twopow[i] = twopow[i - 1] * 2 % mod;
	while (cin >> n) {
		memset(p, 0, sizeof(p));
		for (i = 1; i <= n; i++)
			cin >> a[i];
		 l = 0;
		 for (i = 1; i <= n; i++)
			 if (a[i] == 1)
				 continue;
			 else
			 {
				 k = change(a[i]);
				 if (k != 0) {
					 l++;
					 b[l] = k;
				 }
			 }
		 build();
		 cout << (twopow[n - l] * twopow[l - r]%mod+mod-1)%mod << endl;
	}
    return 0;
}

