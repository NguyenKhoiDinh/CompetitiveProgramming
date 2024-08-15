#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <unordered_map>
 
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
typedef pair<ii, ii> iv;
 
const int N = 1e5 + 11;
int a[N];
vector<int> adj[N];
 
int top = 0;
int st[N], ed[N];
 
void dfs(int u, int p = -1)
{
    st[u] = ++top;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }
    ed[u] = top;
}
 
struct Node
{
    int sum, lazy;
    Node() {}
} Seg[4 * N];
 
void diffuse(int node, int l, int r)
{
    if (Seg[node].lazy)
    {
        Seg[node].sum = (r - l + 1) * Seg[node].lazy;
        if (l != r)
        {
            Seg[node * 2].lazy = Seg[node].lazy;
            Seg[node * 2 + 1].lazy = Seg[node].lazy;
        }
        Seg[node].lazy = 0;
    }
}
 
void update(int node, int l, int r, int L, int R, int v)
{
    diffuse(node, l, r);
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        Seg[node].lazy = v;
        diffuse(node, l, r);
        return;
    }
    int mi = (l + r) / 2;
    update(node * 2, l, mi, L, R, v);
    update(node * 2 + 1, mi + 1, r, L, R, v);
    Seg[node].sum = Seg[node * 2].sum + Seg[node * 2 + 1].sum;
}
 
int get(int node, int l, int r, int L, int R)
{
    diffuse(node, l, r);
    if (r < L || R < l)
        return 0;
    if (L <= l && r <= R)
        return Seg[node].sum;
    int mi = (l + r) / 2;
    return get(node * 2, l, mi, L, R) + get(node * 2 + 1, mi + 1, r, L, R);
}
 
int32_t main()
{
    int n;
    scanf("%lld", &n); 
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]); 
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%lld %lld", &u, &v); 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1);
 
    for (int i = 1; i <= n; i++)
        update(1, 1, n, st[i], st[i], a[i]);
 
    int q;
    scanf("%lld", &q); 
    while (q--)
    {
        int t;
        scanf("%lld", &t); 
        if (t == 1)
        {
            int u, v;
            scanf("%lld %lld", &u, &v); 
            update(1, 1, n, st[u], ed[u], v);
        }
        else if (t == 2)
        {
            int u;
            scanf("%lld", &u); 
            int sum = get(1, 1, n, st[u], ed[u]);
            if (sum <= 3)
                printf("NO\n"); 
            else if (sum % 2 == 0)
                printf("YES\n"); 
            else
            {
                bool is_prime = true;
                for (int i = 2; i * i <= sum - 2; i++)
                    if ((sum - 2) % i == 0)
                    {
                        is_prime = false;
                        break;
                    }
                if (is_prime)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
}