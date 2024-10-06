#include <bits/stdc++.h>
#define pb push_back
#define loop(n) for(int i=0;i<n;i++)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

vector<pil> adj[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	loop(m){
		int x, y;
		ll c;
		cin>>x>>y>>c;
		adj[x].pb(make_pair(y, c));
	}
	ll dis[n+1];
	dis[1] = 0;
	for(int i=2;i<=n;i++) dis[i]=ll(1e17);
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push(make_pair(0ll, 1));
	while(!q.empty()){
		auto [d, x] = q.top();
		q.pop();
		if(dis[x]==d) // !!!Lazy priority queue!!!
			for(auto [y, c]: adj[x]){
				if(dis[y]>c+dis[x]){
					dis[y] = c+dis[x];
					q.push(make_pair(dis[y], y));
				}
			}
	}
	loop(n) cout<<dis[i+1]<<" ";cout<<endl;
}