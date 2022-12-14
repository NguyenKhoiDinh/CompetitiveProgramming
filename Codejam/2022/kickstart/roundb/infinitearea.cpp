#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
const double PI = acos(-1); 
long long R, A, B; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> R >> A >> B;
    double sum = 0.0;
    bool flag = true; 
    while (R > 0) {
      sum += R * R; 
      if (flag == true) {
        R *= A; 
      }
      else {
        R /= B; 
      }
      flag = !flag; 
    }  
    cout << fixed << setprecision(12) << sum * PI << endl; 
  }
  return 0; 
}