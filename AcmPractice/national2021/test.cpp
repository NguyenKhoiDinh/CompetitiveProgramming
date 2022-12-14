#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i= a, i< (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define int long long
const int M = 1e9+7;
 
vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % M;
            }
        }
    }
    return c;
}
 
vector<vector<int>> matpow(vector<vector<int>> mat, int pw) {
    if (pw == 1) return mat;
    vector<vector<int>> ans = matpow(mat, pw/2);
    ans = matmul(ans, ans);
    if (pw % 2) ans = matmul(ans, mat);
    return ans;
}
 
vector<int> mul(vector<int> dp, vector<vector<int>> mat) {
    int n = dp.size();
    vector<int> ans(n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j] = (ans[j] + dp[i]*mat[i][j])%M;
        }
    }
    return ans;
}
 
signed main(){
  freopen("input.txt", "r", stdin); 
  freopen("test.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
 
    int r, n, k;
    cin >> r >> n >> k;
 
    map<int, vector<int>> mp;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y; x--, y--;
        mp[y].push_back(x);
    }
    mp[n];
 
    vector<int> dp(1 << r);
    dp[(1 << r) - 1] = 1;
 
    int prv = 0;
    for (auto pp: mp) {
        int u = pp.first;
        vector<int> v = pp.second;
        int bv = 0;
        for (int i: v) bv |= (1 << i);
 
        int pw = u-prv; prv = u+1;
        // initialize REGULAR matrix
        if (pw > 0) {
            vector<vector<int>> mat(1 << r, vector<int>(1 << r));
            for (int msk1 = 0; msk1 < (1 << r); msk1++) {
                for (int msk2 = 0; msk2 < (1 << r); msk2++) {
                    int ok = 1;
 
                    int new_msk = msk2;
                    for (int i = 0; i < r; i++) {
                        if ((msk1 & (1 << i)) == 0) {
                            if ((msk2 & (1 << i)) == 0) {
                                ok = 0;
                            }
                            new_msk ^= (1 << i);
                        }
                    }
 
                    if (ok == 0) continue;
 
                    // check if new_msk generates in forms of two
                    for (int i = 0; i < r; i++) {
                        if (new_msk & (1 << i)) {
                            if (new_msk & (1 << (i+1))) {
                                i++;
                            } else {
                                ok = 0; break;
                            }
                        }
                    }
 
                    //.ok, connect msk1 to msk2
                    if (ok) mat[msk1][msk2] = 1;
                }
            }
            //cout << u << ' ' << dp[(1 << r) - 1] << endl;
            dp = mul(dp, matpow(mat, pw));
            //cout << u << ' ' << dp[(1 << r) - 1] << endl;
        }
 
        if (u == n) break;
        // from REGULAR row to NON-REGULAR row
        {
            vector<vector<int>> mat(1 << r, vector<int>(1 << r));
            for (int msk1 = 0; msk1 < (1 << r); msk1++) {
                for (int msk2 = 0; msk2 < (1 << r); msk2++) {
                    int ok = 1;
 
                    // if bit activated in bv, it must be activated in msk1 and in msk2
                    int new_msk = msk2;
                    for (int i = 0; i < r; i++) {
                        if (bv & (1 << i)) {
                            if ((msk1 & (1 << i)) == 0) {
                                ok = 0;
                            }
                            if ((msk2 & (1 << i)) == 0) {
                                ok = 0;
                            }
                            new_msk ^= (1 << i);
                        } else {
                            if ((msk1 & (1 << i)) == 0) {
                                if ((msk2 & (1 << i)) == 0) {
                                    ok = 0;
                                }
                                new_msk ^= (1 << i);
                            }
                        }
                    }
 
                    if (ok == 0) continue;
 
                    // check if new_msk generates in forms of two
                    for (int i = 0; i < r; i++) {
                        if (new_msk & (1 << i)) {
                            if (new_msk & (1 << (i+1))) {
                                i++;
                            } else {
                                ok = 0; break;
                            }
                        }
                    }
 
                    //.ok, connect msk1 to msk2
                    if (ok) mat[msk1][msk2] = 1;
                }
            }
            //cout << u << ' ' << dp[(1 << r) - 1] << endl;
            dp = mul(dp, matpow(mat, 1));
            //cout << u << ' ' << dp[(1 << r) - 1] << endl;
        }
    }
    cout << dp[(1 << r) - 1] << '\n';
 
    return 0;
}