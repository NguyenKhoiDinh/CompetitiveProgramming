#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
int n, L; 
vector <pair <int, int> > a, b, ans; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n >> L; 
    a.clear();
    b.clear();
    ans.clear();
    for (int i = 1; i <= n; i++) {
      pair <int, int> element; 
      cin >> element.first >> element.second; 
      a.push_back(make_pair(element.first, i)); 
      if (element.second == 0) {
        b.push_back(element); 
      }
      else {
        b.push_back(make_pair(L - element.first, element.second)); 
      }
    }
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 
    int l = 0; 
    int r = n - 1; 
    for (int i = 0; i < n; i++) {
      int index = (b[i].second == 0 ? a[l++].second : a[r--].second);
      ans.push_back(make_pair(b[i].first, index));  
    }
    sort(ans.begin(), ans.end()); 
    for (int i = 0; i < n; i++) {
      cout << ans[i].second << ' '; 
    }
    cout << endl; 
  }
  return 0; 
}