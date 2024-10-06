#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef complex<double> pt;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<ii, vector<int>> ret_type;

vector<int> adj[100001];
vector<int> vis(100001);
ret_type bfs(int x, int parent){
	vis[x]  = 1;
	for(auto y: adj[x]){
		if(y!=parent&&vis[y]){
			ret_type a;
			a.fi.fi = y;
			a.fi.se = 1;
			a.se.push_back(y);
			a.se.pb(x);
			return a;
		}
		if(vis[y]) continue;
		ret_type res = bfs(y, x);
		if(res.fi.fi&&res.fi.se){
			res.se.pb(x);
			if(res.fi.fi==x) res.fi.se = 0;
			return res;
		} else if(res.fi.fi)
			return res;
	}	
	vector<int> a;
	ret_type res = make_pair(make_pair(0, 0), a);
	return  res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int n, m;
	cin>>n>>m;
	loop(m){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<int> ans;
	loop(n){
		int x = i+1;
		if(!vis[x]){
			ret_type res = bfs(x, 0);
			if(res.fi.fi){
				ans = res.se;
				break;
			}
		}
	}
	if(!ans.size()) cout<<"IMPOSSIBLE"<<endl;
	else{
		cout<<ans.size()<<endl;
		for(auto x: ans) cout<<x<<" ";cout<<endl;
	}
	return 0;
}