#include <bits/stdc++.h> 

using namespace std;
int sg[1024]; 
string convert(int i) {
  string ret = ""; 
  for (int j = 0; j < 10; j++) {
    if ((i & (1 << j)) > 0) {
      ret += '1';
    }
    else {
      ret += '0'; 
    }
  }
  reverse(ret.begin(), ret.end()); 
  return ret; 
}

int main () {
  freopen("output.txt", "w", stdout);
  for (int i = 0; i < 1024; i++) {
    vector <int> check(1024); 
    for (int mask = i; mask > 0; mask = (mask - 1) & i) {
      check[sg[i - mask]] = 1;   
    }
    int mex = 0; 
    while (check[mex] > 0) {
      mex++; 
    }
    sg[i] = mex; 
  }
  for (int i = 0; i < 1024; i++) {
    cout << i << "     " << convert(i) << " :      " << sg[i] << endl; 
  }
  return 0; 
}