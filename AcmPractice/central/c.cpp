#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005; 
int n; 
double a[MAX_N]; 
stack <pair <double, int> > st; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    double sum = a[i]; 
    int num = 1; 
    while (!st.empty()) {
      pair <double, int> stTop = st.top(); 
      if (stTop.first / stTop.second <= sum / num) {
        break; 
      }
      sum += stTop.first;
      num += stTop.second; 
      st.pop(); 
    }
    st.push(make_pair(sum, num)); 
  }
  double ans = 0.0; 
  int i = n; 
  while (i >= 1) {
    pair <double, int> stTop = st.top();
    st.pop(); 
    int num = stTop.second;
    double value = stTop.first / num;
    while (num--) {
      ans += 1.0 * (a[i] - value) * (a[i] - value);
      i--;   
    }
  }
  cout << fixed << setprecision(15) << sqrt(ans); 
  return 0; 
}