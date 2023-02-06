#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll,ll>
using namespace std ;
 
 
const int maxn = 2e5 + 5 ; 
 
int n, vv[maxn], ans[maxn], dp[maxn] ;
vector<int> grafo[maxn] ; 
 
void dfs(int v, int p){ 
 
	dp[v] = vv[v] ; 
 
	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs(a, v) ; 
		dp[v] += max(dp[a], 0) ; 
	}
 
} 
 
void dfs2(int v, int p){ 
 
	ans[v] = dp[v] ;
 
	for(auto a : grafo[v]){
		if(a == p) continue ;
		int salvar = dp[a] ;  
		dp[v] -= max(dp[a], 0) ; 
		dp[a] += max(dp[v], 0) ; 
		dfs2(a, v) ; 
		dp[v] += max(salvar, 0) ;
	}
 
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++){
		cin >> vv[i] ; 
		if(!vv[i]) vv[i] = -1 ; 
	}
 
	for(int i = 1 ; i < n ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}
 
	dfs(1, 1) ; dfs2(1, 1) ; 
 
	for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 
 
}