#include <bits/stdc++.h>

using namespace std;
priority_queue <int> pq; 

int main () {
  string s; 
  while (cin >> s) {
    if (s[0] == '+') {
      int value = 0; 
      for (int i = 1; i < (int) s.size(); i++) {
        value = value * 10 + s[i] - '0';
      }
      if ((int) pq.size() < 15000) {
        pq.push(value);
      }
    }
    else {
      if (pq.empty() == false) {
        int maxValue = pq.top(); 
        while (!pq.empty() && pq.top() == maxValue) {
          pq.pop();
        }
      }
    }
  }
  set <int> S; 
  while (!pq.empty()) {
    S.insert(pq.top()); 
    pq.pop();
  }
  for (set <int> :: iterator it = S.begin(); it != S.end(); it++) {
    pq.push(*it);
  }
  cout << (int) pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top() << endl; 
    pq.pop();
  }
  return 0; 
}