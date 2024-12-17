#include<bits/stdc++.h>
using namespace std;

const int mod = 100003;
struct modint{
private:
   int x;

   public:
      modint(long long x = 0) : x(x % mod) {}
         int val() const {assert(x >= 0 && x < mod); return x;}

            modint operator + (const modint &that) const {int t = x + that.x; return modint(t < mod ? t : t - mod);}
               modint operator += (const modint &that) {return *this = *this + that;}
                  modint operator - (const modint &that) const {int t = x - that.x; return modint(t >= 0 ? t : t + mod);}
                     modint operator -= (const modint &that) {return *this = *this - that;}
                        modint operator * (const modint &that) const {int t = (long long)x * that.x % mod; return modint(t);}
                           modint operator *= (const modint &that) {return *this = *this * that;}
                              modint qpow(int k) const {modint ans(1), a = *this; for(; k; k >>= 1, a *= a) if(k & 1) ans *= a; return ans;}
                                 modint inv() const {return qpow(mod - 2);}
                                    modint operator / (const modint &that) const {return *this * that.inv();}
                                       modint operator /= (const modint &that) {return *this = *this / that;}
                                       } ;

                                       void solve(){
                                          int n, k; cin >> n >> k;
                                             vector<int> a(n + 1); for(int i = 1; i <= n; i ++) cin >> a[i];

                                                vector<vector<int>> factor(n + 1);
                                                   for(int i = 1; i <= n; i ++) for(int j = i; j <= n; j += i) factor[j].emplace_back(i);

                                                      int best = 0;
                                                         for(int i = n; i >= 1; i --) if(a[i]){
                                                               best ++;
                                                                     for(int j : factor[i]) a[j] ^= 1;
                                                                        }

                                                                           vector<modint> dp(n + 2); dp[n + 1] = modint(0);
                                                                              for(int i = n; i >= 1; i --) dp[i] = (modint(n) + modint(n - i) * dp[i + 1]) / modint(i);
                                                                              for (int i = 1; i <= n; i++) {
                                                                                cout << dp[i].val() << "     "; 
                                                                              }
                                                                              cout << endl; 
                                                                                 for(int i = 1; i <= k; i ++) dp[i] = modint(1);

                                                                                    modint fact(1); for(int i = 1; i <= n; i ++) fact *= modint(i);
                                                                                       cout << (fact * accumulate(dp.begin(), dp.begin() + best + 1, modint(0))).val() << '\n';
                                                                                       }

                                                                                       int main(){
                                                                                          ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
                                                                                             int T = 1; while(T --) solve();
                                                                                                return 0;
                                                                                                }