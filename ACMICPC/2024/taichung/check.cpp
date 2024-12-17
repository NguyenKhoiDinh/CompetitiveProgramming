#include <bits/stdc++.h> 

using namespace std;
const int NUM = 40; 
vector <long long>  a, b;

int main () {
  freopen("output.txt", "r", stdin);
  for (int i = 1; i <= 40; i++) {
    long long x;
    cin >> x;
    a.push_back(x);  
  } 
  cin.clear(); 
  freopen("output2.txt", "r", stdin); 
  for (int i = 1; i <= 40; i++) {
      long long x;
          cin >> x;
              b.push_back(x);  
                }
  for (int i = 0; i < 40; i++) {
    if (a[i] == b[i]) {
      std::cout << "TEST CASE #" << i + 1 << ":  SUCCESS" << endl; 
    }
    else {
      std::cout << "TEST CASE #" << i + 1 << ":  ERROR" << endl;

    }
  }        
  return 0; 
}