#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 50005; 
int a[MAX_N]; 
int sum[MAX_N];
int n, p;
vector <pair <int, int> > save; 

int main () {
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  int sum = 0; 
  int minIndex = n + 5; 
  for (int i = 1; i <= n; i++) {
    sum += a[i]; 
    save.push_back(make_pair(sum, i));
  }
  sort(save.begin(), save.end());
  int l = 0; 
  int ans = -1;
  for (int i = 0; i < n; i++) {
    while (l < i && save[i].first - save[l].first >= p) {
      minIndex = min(minIndex, save[l].second); 
      l++; 
    }
    if (minIndex != n + 5) {
      ans = max(ans, save[i].second - minIndex); 
    }
  }
  cout << ans;
  return 0; 
}