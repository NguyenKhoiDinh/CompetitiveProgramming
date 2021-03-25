import java.io.*;
import java.util.*;

public class BinarySearch {
    static int MOD = (int)(1e9) + 7;

    int n;
    int[] left_child, right_child, depth, go_left, go_right;
    boolean[][] is_anc;

    int build_binsearch_tree(int from, int to, int cur_depth, int left_cnt, int right_cnt, boolean[] mark) {
        if (from > to) return -1;
        if (from == to) {
            left_child[from] = right_child[from] = -1;
            depth[from] = cur_depth; go_left[from] = left_cnt; go_right[from] = right_cnt;
            for(int i = 0; i < n; ++i)
                if (mark[i] == true) is_anc[from][i] = true;
            return from;
        }

        int mid = (from + to) / 2;
        for(int i = 0; i < n; ++i)
            if (mark[i] == true) is_anc[from][i] = true;
        mark[mid] = true; depth[mid] = cur_depth; go_left[mid] = left_cnt; go_right[mid] = right_cnt;

        left_child[mid] = build_binsearch_tree(from, mid - 1, cur_depth + 1, left_cnt + 1, right_cnt, mark);
        right_child[mid] = build_binsearch_tree(mid + 1, to, cur_depth + 1, left_cnt, right_cnt + 1, mark);
        mark[mid] = false;
        return mid;
    }

    void add(int[][][][][] dp, int i, int j, int k, int t, int u, int val) {
        dp[i][j][k][t][u] = (dp[i][j][k][t][u] + val) % MOD;
    }

    int mul(int a, int b) { return (int)( ((long)(a) * b) % MOD); }

    public int count(String s) {
        n = s.length();

        left_child = new int[n]; right_child = new int[n];
        depth = new int[n]; go_left = new int[n]; go_right = new int[n];
        is_anc = new boolean[n][n];
        build_binsearch_tree(0, n - 1, 0, 0, 0, new boolean[n]);

        int[] fact = new int[n + 1];
        fact[0] = 1; for(int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);

        int[][] binom = new int[n + 1][n + 1];
        for(int i = 0; i <= n; ++i) { binom[i][0] = binom[i][i] = 1; binom[i][1] = i; }
        for(int i = 3; i <= n; ++i)
            for(int j = 2; j < i; ++j) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;

        int[][][][][] dp = new int[2][n][2][n + 1][n + 1];
        int cur = 0, nxt = 1;
        int left_most = 0; for(int i = n - 1; i >= 0; --i) if (left_child[i] == -1) left_most = i;
        int right_most = 0; for(int i = 0; i < n; ++i) if (right_child[i] == -1) right_most = i;
        dp[cur][ left_most ][0][0][0] = 1;

        for(int v = 0; v < n; ++v) {
            // init for dp[nxt]
            for(int leaf = 0; leaf < n; ++leaf)
                for(int leaf_occupied = 0; leaf_occupied < 2; ++leaf_occupied)
                    for(int owed0 = 0; owed0 <= n; ++owed0)
                        for(int unused0 = 0; unused0 <= n; ++unused0) dp[nxt][leaf][leaf_occupied][owed0][unused0] = 0;

            // bottom-up to update dp[nxt]
            for(int leaf = 0; leaf < n; ++leaf)
                for(int leaf_occupied = 0; leaf_occupied < 2; ++leaf_occupied)
                    for(int owed0 = 0; owed0 <= n; ++owed0)
                        for(int unused0 = 0; unused0 <= n; ++unused0) {
                            int cur_state = dp[cur][leaf][leaf_occupied][owed0][unused0];
                            if (cur_state == 0) continue;

                            if (s.charAt(v) == '0') {
                                // case 1: use this 0 to pay
                                if (owed0 >= 1)
                                    add(dp, nxt, leaf, leaf_occupied, owed0 - 1, unused0, mul(cur_state, owed0) );
                                // case 2: this 0 will be use later
                                if (unused0 + 1 <= n)
                                    add(dp, nxt, leaf, leaf_occupied, owed0, unused0 + 1, cur_state);
                                continue;
                            }

                            // s[v] = '1'
                            // case 1: leaf is unoccupied, put v at leaf
                            if (leaf_occupied == 0) {
                                if (right_child[leaf] == -1) add(dp, nxt, leaf, 1, owed0, unused0, cur_state);
                                else {
                                    add(dp, nxt, right_child[leaf], 0, owed0, unused0, cur_state);
                                    if (unused0 >= 1) add(dp, nxt, right_child[leaf], 1, owed0, unused0 - 1, mul(unused0, cur_state));
                                }
                            }

                            // case 2: put v at u which is an ancestor of leaf
                            for(int u = leaf + 1; u < n; ++u)
                                if (is_anc[leaf][u] == true) {
                                    int borrow0 = go_left[leaf] - go_left[u] - 1 + (1 - leaf_occupied);
                                    if (owed0 + borrow0 > n) continue;

                                    for(int nxt_leaf = u + 1; nxt_leaf < n; ++nxt_leaf)
                                        if (is_anc[nxt_leaf][u] == true &amp;&amp; left_child[nxt_leaf] == -1) {
                                            int use0 = go_right[nxt_leaf] - go_right[u] - 1;

                                            // case 2a: nxt_leaf is unoccupied
                                            if (use0 <= unused0) {
                                                int add = mul( mul( binom[unused0][use0], fact[use0] ), cur_state);
                                                add(dp, nxt, nxt_leaf, 0, owed0 + borrow0, unused0 - use0, add);
                                            }

                                            // case 2b: nxt_leaf is occupied
                                            if (use0 + 1 <= unused0 &amp;&amp; right_child[nxt_leaf] == -1) {
                                                int add = mul( mul( binom[unused0][use0 + 1], fact[use0 + 1] ), cur_state);
                                                add(dp, nxt, nxt_leaf, 1, owed0 + borrow0, unused0 - use0 - 1, add);
                                            }
                                        }
                                }

                        }

            int tmp = cur; cur = nxt; nxt = tmp;
        }

        int res = 0;
        for(int unused0 = 0; unused0 <= n; ++unused0)
            res = (res + mul(dp[cur][right_most][1][0][unused0], fact[unused0]) ) % MOD;
        return res;
    }
}