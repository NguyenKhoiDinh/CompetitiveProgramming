#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;
const double EPS = 1e-9;
struct point {
  double x, y;
};
struct line {
  double a, b, c;
};
vector <point> listPoints;
vector <line> listLine;
int n;
int ans;

point intersectPoint(line &AB, line &CD) {
  point res;
  double det = AB.a * CD.b - AB.b * CD.a;
  res.x = (CD.b * AB.c - AB.b * CD.c) / det;
  res.y = (AB.a * CD.c - CD.a * AB.c) / det;
  return res;
}

double calcDistance(const point &A, const point &B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

void process(const point &I) {
  vector <double> dist;
  for (int i = 0; i < n; i++) {
    dist.push_back(calcDistance(I, listPoints[i]));
  }
  set <double> S;
  for (int i = 0; i < n; i++) {
    S.insert(dist[i]);
  }
  ans = min(ans, (int) S.size());
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    point A;
    cin >> A.x >> A.y;
    listPoints.push_back(A);
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  ans = 105;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      point midPoint, vecto;
      midPoint.x = (listPoints[i].x + listPoints[j].x) / 2;
      midPoint.y = (listPoints[i].y + listPoints[j].y) / 2;
      process(midPoint);
      vecto.x = listPoints[j].x - listPoints[i].x;
      vecto.y = listPoints[j].y - listPoints[i].y;
      line newLine;
      newLine.a = vecto.x;
      newLine.b = vecto.y;
      newLine.c = newLine.a * midPoint.x + newLine.b * midPoint.y;
      listLine.push_back(newLine);
    }
  }
  for (int i = 0; i < (int) listLine.size(); i++) {
    for (int j = i + 1; j < (int) listLine.size(); j++) {
      double det = listLine[i].a * listLine[j].b - listLine[i].b * listLine[j].a;
      if (det == 0.0) {
        continue;
      }
      point I = intersectPoint(listLine[i], listLine[j]);
      process(I);
    }
  }
  cout << ans;
  return 0;
}