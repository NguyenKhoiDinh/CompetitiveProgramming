#include <bits/stdc++.h> 

using namespace std; 
const long long mod = 998244353LL; 
map <string, int> f[3000005];
set <pair <int, string> > myset[3000005];
map <string, int> f2;
set <pair <int, string> > myset2;  
int n; 
vector <int> adj[3000005]; 
int a[3000005], d[3000005]; 
string name[3000005]; 
map <string, int> id;
stack <pair <int, string> > mystack;  
void dfs1(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs1(v, u);
    if (f[u].size() < f[v].size()) {
      f[u].swap(f[v]);
      myset[u].swap(myset[v]);  
    }
    for (map <string, int>::iterator it = f[v].begin(); it != f[v].end(); it++) {
      string fname = it->first; 
      int cnt = it->second;
      if (myset[u].find(make_pair(cnt, fname)) != myset[u].end()) {
        myset[u].erase(myset[u].find(make_pair(cnt, fname))); 
      }
      f[u][fname] += cnt;
      int value = f[u][fname]; 
      myset[u].insert(make_pair(value, fname));   
    }
    f[v].clear();
    myset[v].clear();   
  }
  if (myset[u].empty() == false) {
    set <pair <int, string> >::iterator it = myset[u].begin(); 
    pair <int, string> current = *it; 
    string sname = current.second;
    d[u] = id[sname];  
  }
  string sname = name[u]; 
  if (f[u].find(sname) != f[u].end()) {
    int cnt = f[u][sname];
    myset[u].erase(myset[u].find(make_pair(cnt, sname)));    
  }
  f[u][sname]++;
  int cnt = f[u][sname];
  myset[u].insert(make_pair(cnt, sname));  
}
void dfs2(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    string sname = name[u];
    if (f2.find(sname) != f2.end()) {
      int cnt = f2[sname]; 
      myset2.erase(myset2.find(make_pair(cnt, sname))); 
    }
    mystack.push(make_pair(f2[sname], sname)); 
    f2[sname]++;
    int cnt = f2[sname];                 
    myset2.insert(make_pair(cnt, sname));
    set <pair <int, string> >::iterator it = myset2.begin(); 
    a[v] = id[it->second]; 
    dfs2(v, u);                                                            
    myset2.erase(myset2.find(make_pair(cnt, sname))); 
    pair <int, string> pass = mystack.top();
    mystack.pop();
    string fname = pass.second;
    f2[fname] = pass.first;
    if (pass.first == 0) {
      f2.erase(f2.find(fname)); 
    }
    else {
      myset2.insert(make_pair(pass.first, pass.second)); 
    }      
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      f[i].clear();
      myset[i].clear();
      a[i] = 0;
      d[i] = 0;   
    }
    while (mystack.empty() == false) {
      mystack.pop(); 
    }
    f2.clear();
    myset2.clear(); 
    id.clear(); 
    vector <string> listNames; 
    for (int i = 1; i <= n; i++) {
      int parent;
      cin >> parent;
      if (parent != -1) {
        adj[parent].push_back(i);
        adj[i].push_back(parent); 
      }           
      cin >> name[i];
      listNames.push_back(name[i]);  
    }
    sort(listNames.begin(), listNames.end());
    vector <string> tmp;
    tmp.push_back(listNames[0]);
    for (int i = 1; i < (int) listNames.size(); i++) {
      if (listNames[i] != listNames[i - 1]) {
        tmp.push_back(listNames[i]); 
      }
    }
    listNames = tmp;
    for (int i = 0; i < (int) listNames.size(); i++) {
      id[listNames[i]] = i + 1; 
    }
    dfs1(1, -1);
    dfs2(1, -1); 
    int sz = (int) listNames.size();
    long long hash = 0LL;
    for (int i = 1; i <= n; i++) {
      hash = (hash * (sz + 1)) % mod + a[i]; 
      hash %= mod;
      hash = (hash * (sz + 1)) % mod + d[i];
      hash %= mod;  
    }  
    cout << hash << endl;  
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}