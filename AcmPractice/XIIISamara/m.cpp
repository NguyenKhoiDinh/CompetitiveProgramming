#include <bits/stdc++.h>

using namespace std;
queue <pair <long long, long long> > myqueue;
int n;
long long lastTime = 0LL;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long t, d;
    cin >> t >> d;
    myqueue.push(make_pair(t, d));
  }
  while (!myqueue.empty()) {
    pair <long long, long long> element = myqueue.front();
    myqueue.pop();
    long long t = element.first;
    long long d = element.second;
    if (lastTime <= t) {
      lastTime = t + d;
    }
    else {
      lastTime += d;
    }
  }
  cout << lastTime;
  return 0;
}