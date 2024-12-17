#include <bits/stdc++.h> 
using namespace std;
int numTest; 
int a[200005]; 
int n, m; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    vector <pair <int, bitset <10005> > > mydeque;
    mydeque.push_back(make_pair(1, bitset <10005>()));
    mydeque.back().second[0] = 1;
    for (int i = 1; i <= n; i++) {
      bitset <10005> res; 
      for (int j = 0; j < (int) mydeque.size(); j++) {
        int value = mydeque[j].first; 
        bitset <10005> bs = mydeque[j].second; 
        int prod = min(m + 1, value * a[i]);
        mydeque[j].first = prod;
        res |= (bs << prod);  
      }
      mydeque.push_back(make_pair(1, res));
      int ptr = 0;
      for (int j = 1; j < (int) mydeque.size(); j++) {
        if (mydeque[ptr].first == mydeque[j].first) {
          mydeque[ptr].second |= mydeque[j].second;
        }
        else {
          mydeque[++ptr] = mydeque[j]; 
        }
      }
      mydeque.resize(ptr + 1);  
    } 
    cout << (mydeque.back().second[m] == 1 ? "YES" : "NO") << endl; 
  }
  return 0; 
}