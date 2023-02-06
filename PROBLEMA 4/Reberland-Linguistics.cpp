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
 
 
using namespace std;
 
set<string> ans;
string s;
int tb[10010][4];
 
void dp(int idx, int tam) {
 
  if(idx < 0) return;
 
  auto& res = tb[idx][tam];
 
  if(~res) return;
  res = 1;
 
  string aux = ""; 
 
  for(int i = 0; i < tam; i++) 
    aux += s[idx+1+i];
 
  if(idx-1 >= 0) {
    string a = "";
    for(int i = 0; i < 2; i++)
      a += s[idx-1+i];
    if(a != aux) {
      dp(idx-2, 2);
      ans.insert(s.substr(idx-1, 2));
    }  
  }
 
  if(idx-2 >= 0 && s.substr(idx-2, 3) != aux) {
    string a = "";
    for(int i = 0; i < 3; i++)
      a += s[idx-2+i];
    if(a != aux) {
      dp(idx-3, 3);
      ans.insert(s.substr(idx-2, 3));
    } 
  }
 
}
 
void solve() {
  memset(tb, -1, sizeof tb);
  cin >> s;
  reverse(s.begin(), s.end());
  for(int i = 0; i < 5; i++) 
    s.pop_back();
  reverse(s.begin(), s.end());
 
  int n = s.size();
  if(n < 2) {
    cout << 0 << endl;
    return;
  }
  dp(n-1, 0);
 
 
  cout << ans.size() << endl;
  for(auto it: ans) cout << it << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(false);
 
  int t=1; 
 
  while(t--) solve();
}