#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("input.txt", "w", stdout); 
  cout << 20 << endl; 
  for (int testCase = 1; testCase <= 20; testCase++) {
    int n = rnd.next(1, 400);
    int D = rnd.next(1, 1000);
    cout << n << ' ' << D << endl;
    for (int i = 1; i <= n; i++) {
      cout << rnd.next(0, D - 1) << ' '; 
    } 
    cout << endl;
  }
  return 0; 
}