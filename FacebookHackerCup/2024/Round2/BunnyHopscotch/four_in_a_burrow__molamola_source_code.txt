#include <bits/stdc++.h>
using namespace std;

using FL = long double;
using ll = long long;
const ll mod = 1e9 + 7;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Fi first
#define Se second
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
#define pb push_back

char A[10][10];
int win;
set <pii> S;
int _bind(int x[]) {
	int r = 0;
	rep(i, 7) r |= (x[i]) << (3 * i);
	return r;
}

int xx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int yy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int step(int s, int r, int c, int dr, int dc, char ch, int v[]) {
	if(0 <= r && r <= 5 && 0 <= c && c <= 6 && r > 5 - v[c] && A[r][c] == ch) {
		return 1 + step(s - 1, r + dr, c + dc, dr, dc, ch, v);
	}
	return 0;
}

int check_win(int r, int c, int v[]) {
	char ch = A[r][c];
	int w[8] = {};
	rep(dir, 8) {
		w[dir] = step(3, r + xx[dir], c + yy[dir], xx[dir], yy[dir], ch, v);
	}
	rep(dir, 4) {
		if(1 + w[dir] + w[dir + 4] >= 4) return ch == 'F';
	}
	return -1;
}

void dfs(int t, int v[], int winner = -1) {
	if(t == 42) {
		if(winner != -1) {
			win |= 1 << winner;
		}
		return;
	}
	int rv = _bind(v);
	if(S.find({rv, winner}) != S.end()) return;
	S.insert({rv, winner});
	char turn_c = (t % 2 == 0 ? 'C' : 'F');
	for(int i=0;i<7;i++) {
		if(v[i] == 6) continue;
		char ch = A[5 - v[i]][i];
		if(turn_c != ch) continue;
		int tv = winner;
		if(winner == -1) {
			tv = check_win(5 - v[i], i, v);
		}
		v[i]++;
		dfs(t + 1, v, tv);
		v[i]--;
	}
}

void solve() {
	rep(i, 6) scanf("%s", A[i]);
	win = 0;
	S.clear();
	int v[7] = {};
	dfs(0, v);
	char ans[5] = "0CF?";
	printf("%c\n", ans[win]);
}

int main() {
	int T = 1; scanf("%d", &T);
	for(int tc=1;tc<=T;tc++) {
		fprintf(stderr, "! %d\n", tc);
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}