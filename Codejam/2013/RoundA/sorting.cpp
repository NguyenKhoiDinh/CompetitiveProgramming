#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1005; 
int numTest;
int a[MAX_N];
int n;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    vector <int> odd, even; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (abs(a[i]) % 2 == 1) {
        odd.push_back(a[i]);
      }
      else {
        even.push_back(a[i]);
      }
    }
    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 1; i <= n; i++) {
      if (abs(a[i]) % 2 == 1) {
        cout << odd.back() << ' '; 
        odd.pop_back();
      }
      else {
        cout << even.back() << ' ';
        even.pop_back();
      }
    }
    cout << endl;
  }
  return 0; 
}