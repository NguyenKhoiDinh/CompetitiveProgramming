#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
const int MAX_N = 100005;
long long MOD;
int n;
vector <int> adj[MAX_N];
long long in[MAX_N], out[MAX_N];

void dfs_out(int u, int father) {
	out[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == father) {
			continue;
		}
		dfs_out(v, u);
		(out[u] *= (1 + out[v]) % MOD) %= MOD;
	}
}

void dfs_in(int u, int father) {
	vector <int> children;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != father) {
			children.push_back(v);
		}
	}
	int sz = (int) children.size();
	vector <long long> F(sz + 5), revF(sz + 5);
	F[0] = 1LL;
	for (int i = 1; i <= sz; i++) {
		int v = children[i - 1];
		F[i] = (F[i - 1] * ((out[v] + 1) % MOD)) % MOD;
	}
	revF[sz + 1] = 1LL;
	for (int i = sz; i >= 1; i--) {
		int v = children[i - 1];
		revF[i] = (revF[i + 1] * ((out[v] + 1) % MOD)) % MOD;
	}
	for (int i = 0; i < sz; i++) {
		int v = children[i];
		long long left = F[i];
		long long right = revF[i + 2];
		long long val = in[u];
		(val *= left) %= MOD;
		(val *= right) %= MOD;
		in[v] = val;
		in[v]++;
		in[v] %= MOD;
		dfs_in(v, u);
	}
}

int main () {
	scanf("%d %lld", &n, &MOD);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_out(1, 0);
	in[1] = 1;
	dfs_in(1, 0);
	for (int i = 1; i <= n; i++) {
		long long res = in[i];
		(res *= out[i]) %= MOD;
		printf("%lld\n", res);
	}
	return 0;
}