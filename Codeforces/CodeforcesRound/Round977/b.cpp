#include <bits/stdc++.h>

using namespace std;
map <int, vector <int> > listElements; 
map <int, int> cnt; 
int n, x;
int a[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];   
    }
    listElements.clear(); 
    cnt.clear(); 
    for (int i = 1; i <= n; i++) {
      listElements[a[i] % x].push_back(a[i]); 
    }
    for (map <int, vector <int> >::iterator it = listElements.begin(); it != listElements.end(); it++) {
      vector <int> &v = it->second; 
      sort(v.begin(), v.end()); 
      reverse(v.begin(), v.end()); 
    }
    int mex = 0; 
    while (true) {
      if (listElements[mex % x].empty() == false && listElements[mex % x].back() <= mex) {
        listElements[mex % x].pop_back(); 
        mex++; 
      }
      else {
        break; 
      }
    }
    cout << mex << endl;
  }
  return 0; 
}