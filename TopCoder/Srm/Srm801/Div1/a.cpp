#include <bits/stdc++.h>

using namespace std;

long long sqr(int x) {
  return 1LL * x * x;
}

long long distance(int x0, int y0, int x1, int y1) {
  return sqr(x1 - x0) + sqr(y1 - y0);
}

class SecondDiameters {
  public:
  long long getSecondDiameters(vector <int> X, vector <int> Y) {
    int n = (int) X.size();
    priority_queue <long long> listDistance, tmp;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        listDistance.push(distance(X[i], Y[i], X[j], Y[j]));
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      priority_queue <long long> dist;
      for (int j = 0; j < n; j++) {
        dist.push(distance(X[i], Y[i], X[j], Y[j]));
      }
      priority_queue <long long> garbage;
      while (!dist.empty() && dist.top() == listDistance.top()) {
        garbage.push(listDistance.top());
        dist.pop();
        listDistance.pop();
      }
      long long maxDiameter = listDistance.top();
      garbage.push(maxDiameter);
      listDistance.pop();
      while (true) {
        while (!dist.empty() && dist.top() == listDistance.top()) {
          garbage.push(listDistance.top());
          dist.pop();
          listDistance.pop();
        }
        long long secondDiameter = listDistance.top();
        if (secondDiameter != maxDiameter) {
          ans += secondDiameter;
          break;
        }
        else {
          garbage.push(listDistance.top());
          listDistance.pop();
        }
      }
      while (!garbage.empty()) {
        listDistance.push(garbage.top());
        garbage.pop();
      }
    }
    return ans;
  }
};

SecondDiameters S;

int main () {
  cout << S.getSecondDiameters({1, 2, 3, 4, 5},
{1, 3, 6, 10, 15});
  return 0;
}