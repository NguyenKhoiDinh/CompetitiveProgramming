#include <bits/stdc++.h> 

using namespace std;
int numTest;
int n, m; 
string command; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x0 = 0;
    int y0 = 0;                                            
    cin >> n >> m;
    cin >> command; 
    int limLeft = 1, limRight = m, limUp = 1, limDown = n; 
    int minLeft = 0, maxRight = 0, minUp = 0, maxDown = 0; 
    for (int i = 0; i < (int) command.size(); i++) {
      if (command[i] == 'L') {
        y0--;
        if (minLeft > y0) {
          minLeft = y0; 
          if (limLeft < limRight) {
            limLeft++;
          }
          else {
            break; 
          }
        }
      }
      else if (command[i] == 'R') {
        y0++;
        if (maxRight < y0) {
          maxRight = y0;
          if (limLeft < limRight) {
            limRight--; 
          }
          else {
            break; 
          }
        }
      }
      else if (command[i] == 'U') {
        x0--;
        if (minUp > x0) {
          minUp = x0;
          if (limUp < limDown) {
            limUp++;
          }
          else {
            break; 
          }
        }
      }
      else {
        x0++;
        if (maxDown < x0) {
          maxDown = x0;
          if (limUp < limDown) {
            limDown--;
          }
          else {
            break; 
          }
        }
      }
    }
    x0 = max(limUp, 1);
    y0 = max(limLeft, 1);
    cout << x0 << ' ' << y0 << endl; 
  }
  return 0; 
}