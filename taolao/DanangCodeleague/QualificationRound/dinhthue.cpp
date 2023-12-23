#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 10;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Per Austrin, Simon Lindholm
 * Date: 2004-02-08
 * License: CC0
 * Description: Solves $A * x = b$. If there are multiple solutions, an arbitrary one is returned.
 *  Returns rank, or -1 if no solutions. Data in $A$ and $b$ is lost.
 * Time: O(n^2 m)
 * Status: tested on kattis:equationsolver, and bruteforce-tested mod 3 and 5 for n,m <= 3
 */

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
    // for(vd v: A) {
    //     for(double e: v) printf("%.5g ", e);
    //     puts("");
    // }
    // puts("");

    // for(double e: b) printf("%.5g ", e);
    // puts("");


  int n = sz(A), m = sz(x), rank = 0, br, bc;
  if (n) assert(sz(A[0]) == m);
  vi col(m); iota(all(col), 0);

  rep(i,0,n) {
    double v, bv = 0;
    rep(r,i,n) rep(c,i,m)
      if ((v = fabs(A[r][c])) > bv)
        br = r, bc = c, bv = v;
    if (bv <= eps) {
      rep(j,i,n) if (fabs(b[j]) > eps) return -1;
      break;
    }
    swap(A[i], A[br]);
    swap(b[i], b[br]);
    swap(col[i], col[bc]);
    rep(j,0,n) swap(A[j][i], A[j][bc]);
    bv = 1/A[i][i];
    rep(j,i+1,n) {
      double fac = A[j][i] * bv;
      b[j] -= fac * b[i];
      rep(k,i+1,m) A[j][k] -= fac*A[i][k];
    }
    rank++;
  }

  x.assign(m, 0);
  for (int i = rank; i--;) {
    b[i] /= A[i][i];
    x[col[i]] = b[i];
    rep(j,0,i) b[j] -= A[j][i] * b[i];
  }

  return rank; // (multiple solutions if rank < m)
}

int n, m, a[MAXN][MAXN], g[MAXN][MAXN], f[MAXM][MAXM];

int getBoardIndex(int i, int j) {return i*n+j;}
int getFilterIndex(int i, int j) {return i*m+j;}

int main() {
    // freopen("input.txt", "r", stdin);

  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

    scanf("%d%d", &n, &m);
    assert(m <= n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            scanf("%d", &g[i][j]);
    }

    vector<vd> A;
    vd b;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            vd A_row;
            for(int x = 0; x < m; ++x) {
                for(int y = 0; y < m; ++y) {
                    int I = i + x - m/2, J = j + y - m/2;
                    int val = (I < 0 || J < 0 || I >= n || J >= n) ? 0 : a[I][J];
                    A_row.push_back(val);
                }
            }
            A.push_back(A_row);
            b.push_back(g[i][j]);
        }
    }

    vd x;
    x.assign(m*m, 0);
    solveLinear(A, b, x);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            f[i][j] = round(x[i*m + j]);
        }
    }

    // for(double e: x) printf("%.5g ", e);
    // puts("");

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j)
            printf("%d ", f[i][j]);
        puts("");
    }

    return 0;
}