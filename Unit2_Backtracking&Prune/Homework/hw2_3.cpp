#include <bits/stdc++.h>

using namespace std;

int n, total, len;
int MASK;
bool out = false;
vector<int> v;

void dfs(int remain, int cur, int ori, int legal) {
    if (remain == 0) {
        cout << "yes\n";
        out = true;
        return;
    }
    if (!cur) {
        dfs(remain-1, len, ori, ori);
        return;
    }
    for (int num = 0; legal; legal ^= num) {
        num = ((~legal+1) & legal);
        if (cur >= v[__lg(num)]) {
            dfs(remain, cur-v[__lg(num)], ori ^ num, legal ^ num);
            if (out == true)
                return;
        }
    }
    return;
}

void solve() {
    total = 0;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        total += v[i];
    }
    if (total % 4) {
        cout << "no\n";
        return;
    }
    out = false;
    len = (total >> 2);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < 4; ++i) {
        if (v[i] > len) {
            cout << "no\n";
            return;
        }
    }
    MASK = (1 << n) - 1;
    dfs(3, len, MASK, MASK);
    if (out == false)   cout << "no\n";
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}