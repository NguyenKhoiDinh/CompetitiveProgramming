#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("input.txt", "w", stdout);
  cout << 40 << endl;
  for (int test = 1; test <= 40; test++) {
    int n = rnd.next(1, 1000); 
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
      cout << rnd.next(0, 100000000) << ' '; 
    }
    cout << endl; 
  }  
  return 0; 
}