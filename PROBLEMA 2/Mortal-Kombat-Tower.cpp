#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define endl '\n'
#define int long long
 
using namespace std;
 
 
 
const int MAX = 3e5;
 
int n;
vector<int> v(MAX);
int tb[MAX][2];
 
int dp(int idx, bool amigo=true) {
    if(idx >= n) {
        return 0;
    }
 
    if(tb[idx][amigo] != -1) return tb[idx][amigo];
 
    int esc2 = 1e8, esc1 = 1e8;
    if(amigo) {
        esc1 = (v[idx]) + dp(idx+1, false);
        if(idx + 1 < n) esc2 = v[idx] + v[idx+1] + dp(idx+2, false);
    }else {
        esc1 = dp(idx+1, true);
        esc2 = dp(idx+2, true);
    }
 
    return tb[idx][amigo] = min(esc1, esc2);
}
 
int32_t main() {
 
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            tb[i][0] = tb[i][1] = -1;
        } 
 
        cout << dp(0) << '\n';
    }    
 
    return 0;
}