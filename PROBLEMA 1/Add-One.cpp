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
 
 
 
const int MOD = 1e9 + 7;
const int MAXOP = 2e5 + 8;
int DP[10][MAXOP];
 
#define here DP[digit][op]
inline int expand(int digit, int op) {
	int needed = 10-digit;
	if (op < needed)
		return 1;
	if (here != -1)
		return here;
 
	return here = (expand(1, op-needed)
				+ expand(0, op-needed)) % MOD;
}
 
signed main() {
	memset(DP, -1, sizeof(DP));
 
	ios::sync_with_stdio(false); cin.tie(NULL);
 
	int t; cin >> t; while (t--) {
		string s; cin >> s;
		int op; cin >> op;
 
		int sum = 0;
		for (char c : s) {
			sum += expand(c-'0', op);
			sum %= MOD;
		}
		cout << sum << endl;
	}
}