#include <bits/stdc++.h> 

using namespace std;

int main () {
  double X; 
  cin >> X; 
  double smaller = (int) X; 
  double bigger = smaller + 1.0; 
  if (X - smaller < bigger - X) {
    cout << (int) smaller;
  }
  else {
    cout << (int) bigger;
  }
  return 0; 
}