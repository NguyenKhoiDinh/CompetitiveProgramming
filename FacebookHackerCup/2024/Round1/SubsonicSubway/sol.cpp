#include <bits/stdc++.h> 

using namespace std; 
const double eps = 1e-12; 
int n; 
double L[1000005], R[1000005]; 

int main () {
  ios_base::sync_with_stdio(false); 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    vector <double> save; 
    map <double, int> id; 
    for (int i = 1; i <= n; i++) {
      cin >> L[i] >> R[i];
      L[i] += eps; 
      R[i] += eps; 
      save.push_back(1.0 * i / L[i]);
      save.push_back(1.0 * i / R[i]);   
    }
    sort(save.begin(), save.end());
    for (int i = 0; i < (int) save.size(); i++) {
      if (id.find(save[i]) == id.end()) {
        id[save[i]] = (int) id.size() + 1; 
      }
    }
    int sz = (int) save.size();
    vector <int> cnt(sz + 10, 0);
    for (int i = 1; i <= n; i++) {
      int l = id[1.0 * i / R[i]]; 
      int r = id[1.0 * i / L[i]];
      cnt[l]++;
      cnt[r + 1]--;  
    }  
    for (int i = 1; i <= sz; i++) {
      cnt[i] += cnt[i - 1]; 
    }
    double ans = 1000000007.000000; 
    for (int i = 1; i <= n; i++) {
      int l = id[1.0 * i / R[i]]; 
      int r = id[1.0 * i / L[i]]; 
      if (cnt[l] == n) {
        ans = min(ans, 1.0 * i / R[i]); 
      }
      if (cnt[r] == n) {
        ans = min(ans, 1.0 * i / L[i]); 
      }
    }
    if (ans > 100000000.000) {
      cout << -1; 
    } 
    else {
      cout << fixed << setprecision(12) << ans; 
    }
    cout << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}