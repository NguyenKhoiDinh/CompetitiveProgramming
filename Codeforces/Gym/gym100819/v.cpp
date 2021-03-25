#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
struct gear {
  int x, y, radius;
};
bool visited[MAX_N];
int n;
bool flag = true;
gear a[MAX_N];
int color[MAX_N];

int sqr(int x) {
  return x * x;
}

bool isConnected(int u, int v) {
  return (sqr(a[u].x - a[v].x) + sqr(a[u].y - a[v].y) == sqr(a[u].radius) + sqr(a[v].radius) + 2 * a[u].radius * a[v].radius);
}

void DFS(int u) {
  visited[u] = 1;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false && isConnected(u, i) == true) {
      DFS(i);
    }
  }
}

void fillColor(int u, int currentColor) {
  color[u] = currentColor;
  for (int i = 1; i <= n; i++) {
    if (isConnected(u, i) == true) {
      if (color[i] == -1) {
        fillColor(i, !currentColor);
      }
      else if (color[i] == currentColor) {
        flag = false;
        return;
      }
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].radius;
    color[i] = -1;
  }
  fillColor(1, 0);
  if (flag == false) {
    cout << "The input gear cannot move.";
    return 0;
  }
  DFS(1);
  if (visited[n] == false) {
    cout << "The input gear is not connected to the output gear.";
    return 0;
  }
  if (color[1] != color[n]) {
    cout << '-';
  }
  int gcd = __gcd(a[1].radius, a[n].radius);
  a[1].radius /= gcd;
  a[n].radius /= gcd;
  cout << a[1].radius << ':' << a[n].radius;
  return 0;
}