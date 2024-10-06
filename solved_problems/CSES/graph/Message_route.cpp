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

vector<int> adj[100001];
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
	vector<int> parent(n+1);
	vector<int> vis(n+1);
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto y: adj[x]){
			if(!vis[y]){
				parent[y] = x;
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	if(!parent[1]) cout<<"IMPOSSIBLE"<<endl;
	else {
		vector<int> ans;
		int curr = 1;
		while(curr!=n){
			ans.pb(curr);
			curr = parent[curr];
		}
		ans.pb(n);
		cout<<ans.size()<<endl;
		for(auto x: ans) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}