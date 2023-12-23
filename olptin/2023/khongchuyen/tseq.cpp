#include <iostream> 
#include <vector>
#include <algorithm> 
#include <utility>
#include <math.h> 
struct itnode {
  int cnt;
  long long totalx; 
  long long totaly; 
  itnode *left, *right; 
};
struct element {
  int cnt;
  long long totalx;
  long long totaly;
};
int n, m; 
int b[100005];
std::vector <std::pair <int, int> > list1, list2; 
std::vector <itnode *> version1, version2; 
std::vector <long long> prefixSum1, prefixSum2; 

itnode *createNode() {
  itnode *ret = new itnode();
  ret->cnt = 0;
  ret->totaly = 0;
  ret->totalx = 0;
  ret->left = NULL;
  ret->right = NULL;   
  return ret; 
}

void build(itnode *&root, int L, int R) {
  root = createNode();
  if (L == R) {
    return;
  }
  int mid = (L + R) / 2;  
  build(root->left, L, mid);
  build(root->right, mid + 1, R); 
}

void update(itnode *&root, int L, int R, int position, const int &value) {
  if (L > position || position > R) {
    return; 
  }
  itnode *tmp = createNode(); 
  *tmp = *root; 
  if (L == R) {
    tmp->cnt++; 
    tmp->totalx += value;                       
    tmp->totaly += position; 
    root = tmp; 
    return; 
  }
  int mid = (L + R) / 2; 
  if (position <= mid) {
    update(tmp->left, L, mid, position, value); 
  }
  else {
    update(tmp->right, mid + 1, R, position, value); 
  }
  tmp->cnt = tmp->left->cnt + tmp->right->cnt;
  tmp->totalx = tmp->left->totalx + tmp->right->totalx;
  tmp->totaly = tmp->left->totaly + tmp->right->totaly;
  root = tmp;                                                                                   
}

element get(itnode *root, int L, int R, int l, int r) {
  if (L > r || l > R) {
    return (element) {0, 0, 0}; 
  }  
  if (l <= L && R <= r) {
    return (element) {root->cnt, root->totalx, root->totaly}; 
  }
  int mid = (L + R) / 2; 
  element eLeft = get(root->left, L, mid, l, r); 
  element eRight = get(root->right, mid + 1, R, l, r); 
  element ret = (element) {eLeft.cnt + eRight.cnt, eLeft.totalx + eRight.totalx, eLeft.totaly + eRight.totaly}; 
  return ret; 
} 

void process(std::vector <std::pair <int, int> > &a1, std::vector <std::pair <int, int> > &a2) {
  int n1 = (int) a1.size(); 
  std::sort(a1.begin(), a1.end()); 
  prefixSum1.resize(n1 + 1); 
  prefixSum1[0] = 0LL; 
  for (int i = 1; i <= n1; i++) {
    prefixSum1[i] = prefixSum1[i - 1] + a1[i - 1].second - a1[i - 1].first; 
  }
  itnode *root;
  version1.push_back(root);
  build(version1.back(), 0, m - 1);
  for (int i = 1; i <= n1; i++) {
    itnode *node = version1.back(); 
    update(node, 0, m - 1, a1[i - 1].second, a1[i - 1].first); 
    version1.push_back(node); 
  }
  int n2 = (int) a2.size(); 
  std::sort(a2.begin(), a2.end()); 
  prefixSum2.resize(n2 + 1); 
  prefixSum2[0] = 0LL; 
  for (int i = 1; i <= n2; i++) {
    prefixSum2[i] = prefixSum2[i - 1] + a2[i - 1].second; 
  }
  version2.push_back(root);
  build(version2.back(), 0, m - 1);
  for (int i = n2; i >= 1; i--) {
    itnode *node = version2.back(); 
    update(node, 0, m - 1, a2[i - 1].second, a2[i - 1].first); 
    version2.push_back(node); 
  }                                                             
}

long long solve1(const int &X, const std::vector <std::pair <int, int> > &a) {
  long long ret = 0LL; 
  int n = (int) a.size(); 
  int lo = 1;
  int hi = n;
  int p = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid - 1].first < X) {
      p = mid; 
      lo = mid + 1; 
    }  
    else {
      hi = mid - 1; 
    }
  }
  ret += prefixSum1[n] - prefixSum1[p];
  if (p > 0) {
    element value = get(version1[p], 0, m - 1, X, m - 1);
    ret += value.totaly - (long long) value.cnt * (X - 1);
    value = get(version1[p], 0, m - 1, 0, X - 1);
    ret += value.totaly - value.totalx;   
  }  
  return ret; 
} 

long long solve2(const int &X, const std::vector <std::pair <int, int> > &a) {
  long long ret = 0LL; 
  int n = (int) a.size(); 
  int lo = 1;
  int hi = n; 
  int p = 0; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (a[mid - 1].first < X) {
      p = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  ret += (long long) p * (m - X + 1) + prefixSum2[p];
  element value = get(version2[n - p], 0, m - 1, X, m - 1);
  ret += value.totaly + (long long) value.cnt * (-X + 1);
  value = get(version2[n - p], 0, m - 1, 0, X - 1);
  ret += (long long) value.cnt * m - value.totalx + value.totaly; 
  return ret; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i]; 
  }
  for (int i = 1; i < n; i++) {
    if (b[i] < b[i + 1]) {
      list1.push_back(std::make_pair(b[i], b[i + 1])); 
    }
    else if (b[i] > b[i + 1]) {
      list2.push_back(std::make_pair(b[i], b[i + 1])); 
    }
  }
  process(list1, list2); 
  long long ans = 100000000000007LL; 
  for (int i = 1; i <= n; i++) {
    int X = b[i];
    long long ret = solve1(X, list1);
    ret += solve2(X, list2); 
    ans = std::min(ans, ret);  
  }
  std::cout << ans;
  return 0; 
}