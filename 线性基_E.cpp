#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long a[10050];
long long p[63];
long long d[63];
bool flag;
long long cnt;
void rebuild() {
	for (int i = 62; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if ((p[i] & (1LL << j)) != 0)
				p[i] ^= p[j];
	for (int i = 0; i <= 62; i++)
		if (p[i] != 0) {
			d[cnt++] = p[i];
		}
}
long long kthquery(long long k) {
	long long ret = 0;
	if (flag)
		k--;
	if (k >= (1LL << cnt))
		return -1;
	for (int i = 60; i >= 0; i--)
		if ((k&(1LL << i)) != 0)
			ret ^= d[i];
	return ret;
}
int main() {
	long long i, j, k, n, ans, t, q, ti;
	ios::sync_with_stdio(false);
	cin >> t;
	ti = 0;
	while (t--) {
		cin >> n;
		ti++;
		for (i = 1; i <= n; i++)
			cin >> a[i];
		memset(p, 0, sizeof(p));
		memset(d, 0, sizeof(d));
		cnt = 0;
		flag = false;
		for (i = 1; i <= n; i++) {
			for (j = 62; j >= 0; j--) {
				if (((1LL << j)&a[i]) != 0) {
					if (p[j] == 0)
					{
						p[j] = a[i];
						break;
					}
					else
					{
						a[i] ^= p[j];
					}
				}
			}
			if (a[i] == 0)
				flag = true;
		}
		cin >> q;
		cout << "Case #" << ti << ":" << endl;
		rebuild();
		while (q--)
		{
			cin >> k;
			cout << kthquery(k) << endl;
		}
	}
}