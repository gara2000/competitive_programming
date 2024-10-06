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
	vector<int> sign(n+1);
	bool test = true;
	loop(n){
		if(!sign[i+1]){
			queue<ii> q;
			q.push(make_pair(i+1, 1));
			sign[i+1] = 1;
			while(!q.empty()){
				auto [x, s]= q.front();
				q.pop();
				for(auto y: adj[x]){
					if(!sign[y]){
						if(s==1) sign[y] = 2;
						else sign[y] = 1;
						q.push(make_pair(y, sign[y]));
					}
					else if(sign[y]==s){
						test = false;
						break;
					}
				}
				if(!test) break;
			}
		}
		if(!test) break;
	}
	if(!test) cout<<"IMPOSSIBLE"<<endl;
	else {
		loop(n) cout<<sign[i+1]<<" ";cout<<endl;
	}
	return 0;
}