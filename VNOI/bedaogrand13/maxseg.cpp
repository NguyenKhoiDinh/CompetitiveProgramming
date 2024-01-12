#include <iostream> 
#include <math.h>
const long long inf = -500000000000007LL;           
int n;
long long a[500005];    
int p[500005];  
struct node {
  long long sum; 
  long long maxLeft, maxRight, maxSum; 
};
long long ans[500005]; 
node f[500005]; 
int root[500005];
bool ok[500005];  

node mergeNode(const node &left, const node &right) {
  node ret;         
  ret.sum = left.sum + right.sum; 
  ret.maxLeft = std::max(left.maxLeft, left.sum + right.maxLeft);
  ret.maxRight = std::max(right.maxRight, right.sum + left.maxRight);
  ret.maxSum = std::max(left.maxRight + right.maxLeft, std::max(left.maxSum, right.maxSum)); 
  return ret; 
}

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
                                     
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
  }
  long long maxSubarray = inf;
  for (int i = n; i >= 1; i--) {
    int root1 = findRoot(p[i]);
    long long value = a[root1];
    f[root1] = (node) {value, value, value, value}; 
    if (p[i] > 1 && ok[p[i] - 1] == true) {
      int root2 = findRoot(p[i] - 1);
      f[root1] = mergeNode(f[root2], f[root1]);
      root[root2] = root1;  
    } 
    if (p[i] < n && ok[p[i] + 1] == true) {
      int root2 = findRoot(p[i] + 1);                      
      f[root1] = mergeNode(f[root1], f[root2]);
      root[root2] = root1; 
    }
    maxSubarray = std::max(maxSubarray, f[root1].maxSum);
    ok[root1] = true;      
    ans[i] = maxSubarray; 
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;                       
}