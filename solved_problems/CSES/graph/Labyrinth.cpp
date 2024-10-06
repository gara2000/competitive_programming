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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int n, m;
	cin>>n>>m;
	vector<string> grid(n);
	int vis[n][m];
	ii parent[n][m];
	ii A, B;
	loop(n){
		cin>>grid[i];
		loopj(m){
			vis[i][j] = 0;
			parent[i][j] = make_pair(-1, -1);
			if(grid[i][j]=='A') A = make_pair(i, j);
			if(grid[i][j]=='B') {
				B = make_pair(i, j);
				vis[i][j] = 1;
			}
		}
	}
	queue<ii> q;
	q.push(B);
	while(!q.empty()){
		auto [y, x] = q.front();
		q.pop();
		loop(4){
			int a = x+dx[i];
			int b = y+dy[i];
			if(a<0||a>=m||b<0||b>=n||vis[b][a]||grid[b][a]=='#') continue;
			parent[b][a] = make_pair(y, x);
			vis[b][a] = 1;
			// cout<<b<<" "<<a<<endl;
			q.push(make_pair(b, a));
		}
	}
	if(parent[A.fi][A.se]==make_pair(-1, -1))
		cout<<"NO"<<endl;
	else {
		ii curr = A;
		string ans = "";
		while(curr!=B){
			ii next = parent[curr.fi][curr.se];	
			if(next.fi>curr.fi) ans+='D';
			if(next.fi<curr.fi) ans+='U';
			if(next.se>curr.se) ans+='R';
			if(next.se<curr.se) ans+='L';
			curr = next;
		}
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		cout<<ans<<endl;
	}
	return 0;
}