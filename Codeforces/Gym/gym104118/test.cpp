#include <bits/stdc++.h>
using namespace std; 
vector <string> v; 

int main () {
  freopen("output.txt", "r", stdin);
  cin.clear();
  for (int i = 1; i <= 2000; i++) {
    string s;
    getline(cin, s); 
    v.push_back(s); 
  } 
  cout << (int) v.size();
  freopen("output2.txt", "w", stdout); 
  vector <vector <int> > listNumb; 
  for (int i = 0; i < (int) v.size(); i++) {
    vector <int> a; 
    for (int j = 0; j < (int) v[i].size(); j++) {
      if ('0' <= v[i][j] && v[i][j] <= '9') {
        int numb = 0; 
        for (int k = j; ;k++) {
          if ('0' <= v[i][k] && v[i][k] <= '9') {
            numb = numb * 10 + v[i][k] - '0'; 
          }
          else {
            a.push_back(numb); 
            j = k; 
            break; 
          }
        }
      }
    }
    listNumb.push_back(a); 
  }
  cout << "{" << endl; 
  for (int i = 0; i < (int) listNumb.size(); i++) {
    vector <int> &a = listNumb[i]; 
    int pos = -1; 
    std::vector <tuple <int, int, int> > save; 
    cout << "{ "; 
    for (int p = 1; p <= 30; p++) {
      for (int q = p; q <= 30; q++) {
        if (__gcd(p, q) == 1) {
          pos++;
          if (a[pos] == 0) {
            continue; 
          }
          save.push_back(make_tuple(p, q, a[pos]));    
        }
      }
    }
    for (int i = 0; i < (int) save.size(); i++) {
      cout << "{ " << get<0>(save[i]) << ", " << get<1>(save[i]) << ", " << get<2>(save[i]) << "} "; 
      if (i < (int) save.size() - 1) {
        cout << ", "; 
      }
    }
    cout << "}," << endl;
  }
  cout << "}";
  return 0; 
}