#include <bits/stdc++.h>
using namespace std;
/* nichijou */
template<class T,class U>
bool cmax(T & a, const U & b) {return a < b ? a = b, 1 : 0;}
template<class T,class U>
bool cmin(T & a, const U & b) {return b < a ? a = b, 1 : 0;}
/* data type */
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define F first
#define S second
/* STL container */
typedef vector<int> vi;
typedef vector<ll> vll;
#define SZ(a) ((int)(a).size())
#define ALL(a) begin(a), end(a)
#define CLR(a) (a).clear()
#define BK(a) ((a).back())
#define FT(a) ((a).front())
#define DB(a) (a).pop_back()
#define DF(a) (a).pop_front()
#define PB push_back
#define EB emplace_back
/* I gave you my heart and then you turned around. */
void _BG(const char * s) {cerr<<s<<endl;}
template<class T, class ... TT>
void _BG(const char * s,T a, TT...b)
{
    for (size_t c = 0; *s && (c || *s != ','); cerr << *s++)
        c += count(ALL("([{"),*s) - count(ALL(")]}"),*s);
    cerr << " = " << a;
    if (*s) {
        cerr << ", ";
        ++s;
    }
    _BG(s,b...);
}
#ifdef PR3PONY
#define BG(...) do { \
    cerr << __PRETTY_FUNCTION__ << ':' << __LINE__ << ": "; \
    _BG(#__VA_ARGS__,__VA_ARGS__); \
} while(0)
#else
#define BG(...)
#endif
/* Good Luck && Have Fun ! */
const int N = 60;
double dp[N + 1][N + 1][N + 1];
int pr[N + 1][N + 1][N + 1];
void solve()
{
    int W, E;
    cin >> W >> E;
    for (int p = 0; p <= N; ++p)
        for (int r = 0; p + r <= N; ++r)
            for (int s = 0; p + r + s <= N; ++s) {
                dp[p][r][s] = -87;
            }
    dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = (E + W) / 3.;
    pr[1][0][0] = 0;
    pr[0][1][0] = 1;
    pr[0][0][1] = 2;
    for (int t = 1; t < N; ++t) {
        for (int p = 0; p <= t; ++p) {
            for (int r = 0; r + p <= t; ++r) {
                int s = t - p - r;
                double v = W * (s * 1. / t) + E * (r * 1. / t); // p
                if (cmax(dp[p + 1][r][s], dp[p][r][s] + v))
                    pr[p + 1][r][s] = 0;
                v = W * (p * 1. / t) + E * (s * 1. / t); // r
                if (cmax(dp[p][r + 1][s], dp[p][r][s] + v))
                    pr[p][r + 1][s] = 1;
                v = W * (r * 1. / t) + E * (p * 1. / t); // s
                if (cmax(dp[p][r][s + 1], dp[p][r][s] + v))
                    pr[p][r][s + 1] = 2;
            }
        }
    }
    tuple<double, int, int, int> mx(-87, -1, -1, -1);
    for (int p = 0; p <= N; ++p) {
        for (int r = 0; r + p <= N; ++r) {
            int s = N - p - r;
            mx = max(mx, make_tuple(dp[p][r][s], p, r, s));
        }
    }
    double tmp;
    int a[3];
    tie(tmp, a[0], a[1], a[2]) = mx;
    cerr << "max= " << tmp << endl;
    string ans;
    while (a[0] + a[1] + a[2]) {
        int i = pr[a[0]][a[1]][a[2]];
        ans += "PRS"[i];
        a[i]--;
    }
    reverse(begin(ans), end(ans));
    cout << ans << '\n';
}
int main()
{
  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, X;
    cin >> T >> X;
    for (int kase = 1; kase <= T; ++kase) {
        cout << "Case #" << kase << ": ";
        solve();
    }
}