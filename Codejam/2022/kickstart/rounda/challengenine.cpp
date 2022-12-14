#include <bits/stdc++.h> 

using namespace std; 
int numTest; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    string N; 
    cin >> N;
    int sum = 0; 
    for (int i = 0; i < (int) N.size(); i++) {
      (sum += (N[i] - '0')) %= 9; 
    }
    sum = (9 - sum) % 9;
    bool canWrite = (sum != 0);
    bool found = false; 
    for (int i = 0; i < (int) N.size(); i++) {
      if (sum + '0' < N[i] && canWrite == true && found == false) {
        cout << sum; 
        found = true;
      } 
      canWrite = true; 
      cout << N[i]; 
    } 
    if (found == false) {
      cout << sum;
    }
    cout << endl; 
  }
  return 0; 
}