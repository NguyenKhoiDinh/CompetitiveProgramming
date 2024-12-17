#include <bits/stdc++.h> 

using namespace std;
set <vector <int> > S[9];
int x, m; 
int numTest;
void backTracking(vector <int> a, int len) {
  S[(int) a.size()].insert(a);
  if ((int) a.size() == len) {
    return; 
  }   
  int numbInver = 0; 
  for (int i = 0; i < (int) a.size() - 1; i++) {
    for (int j = i + 1; j < (int) a.size(); j++) {
      if (a[i] > a[j]) {
        numbInver++; 
      }
    }
  }                         
  for (int pos = 0; pos <= (int) a.size(); pos++) {
    vector <int> new_a = a; 
    new_a.insert(new_a.begin() + pos, numbInver);
    backTracking(new_a, len);
  } 
}

int main () {
  //freopen("input.txt", "r", stdin);
  freopen("output2.txt", "w", stdout); 
  vector <int> a = {0, 1};
  backTracking(a, 8);
  for (int i = 2; i <= 8; i++) {
    cout << (int) S[i].size() << endl;
  }  
  return 0; 
}