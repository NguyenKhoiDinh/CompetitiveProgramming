#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005; 
int it[4 * MAX_N]; 
int n;
int a[MAX_N]; 
int b[MAX_N]; 
vector <int> ids[MAX_N]; 
map <int, int> key;
int available;

void build(int index, int L, int R) {
  it[index] = R - L + 1;
  if (L == R) {
    return; 
  }
  int mid = (L + R) >> 1; 
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R); 
} 

void update(int index, int L, int R, int pos, int value) {
  if (L > pos || R < pos) {
    return; 
  }
  it[index] += value; 
  if (L == R) {
    return;
  }
  int mid = (L + R) >> 1; 
  update(2 * index, L, mid, pos, value);
  update(2 * index + 1, mid + 1, R, pos, value); 
}

int get(int index, int L, int R, int le, int ri) {
  if (L > ri || le > R) {
    return 0; 
  }
  if (le <= L && R <= ri) {
    return it[index]; 
  }
  int mid = (L + R) >> 1; 
  int v1 = get(2 * index, L, mid, le, ri); 
  int v2 = get(2 * index + 1, mid + 1, R, le, ri); 
  return v1 + v2; 
}

int main () {
  long long ans = 0LL; 
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]); 
    b[i] = a[i];  
  }
  sort(b + 1, b + n + 1); 
  for (int i = 1; i <= n; i++) {
    if (key.find(b[i]) == key.end()) {
      int sz = (int) key.size() + 1; 
      key[b[i]] = sz; 
    }
  }
  for (int i = 1; i <= n; i++) {
    int ID = key[a[i]]; 
    ids[ID].push_back(i);  
  }
  build(1, 1, n); 
  int position = 1;
  available = n;  
  for (int ID = n; ID >= 2; ID--) {
    vector <int> &a = ids[ID];
    if (a.empty() == true) {
      continue;
    }
    for (vector <int> :: iterator it = a.begin(); it != a.end(); it++) {
      update(1, 1, n, *it, -1);                                                       
      available--; 
    }
    vector <int> :: iterator curPosition = lower_bound(a.begin(), a.end(), position);
    if (curPosition == a.begin()) {
      curPosition = a.end(); 
      curPosition--; 
      ans += get(1, 1, n, position, *curPosition); 
      position = *curPosition; 
    }
    else {
      curPosition--;
      int value = get(1, 1, n, *curPosition, position); 
      ans += available - value; 
      position = *curPosition; 
    }
  }
  printf("%lld", ans);
  return 0; 
}