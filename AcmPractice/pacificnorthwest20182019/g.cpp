#include <bits/stdc++.h> 

using namespace std;
double x, y, X1, Y1, X2, Y2; 

int main () {
  cin >> x >> y >> X1 >> Y1 >> X2 >> Y2;
  cout << fixed << setprecision(3) << hypot(max(max(X1 - x, x - X2), 0.00), max(max(Y1 - y, y - Y2), 0.00));
  return 0; 
}