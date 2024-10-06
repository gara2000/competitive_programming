#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;

typedef pair<int,int> ii;

// Up, Down, Left, Rigth
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<string > grid(n);
	queue<ii> qm, qa;
	int inf = int(1e7);
	int dm[n][m];
	int da[n][m];
	int vm[n][m];
	int va[n][m];
	ii parent[n][m];
	ii A;
	loop(n){
		cin>>grid[i];
		loopj(m){
			vm[i][j] = 0;
			va[i][j] = 0;
			dm[i][j] = inf;
			da[i][j] = inf;
			if(grid[i][j]=='M'){
				qm.push(make_pair(i, j));
				dm[i][j] = 0;
				vm[i][j] = 1;
			}
			if(grid[i][j]=='A'){
				qa.push(make_pair(i, j));
				da[i][j] = 0;
				va[i][j] = 1;
				A = make_pair(i, j);
			}
		}
	}
	while(!qm.empty()){
		ii x = qm.front();
		qm.pop();
		loop(4){
			int r = x.fi+di[i];
			int c = x.se+dj[i];
			if(r<0||r>=n||c<0||c>=m||grid[r][c]=='#'||vm[r][c]) continue;
			vm[r][c] = 1;
			dm[r][c] = dm[x.fi][x.se]+1;
			qm.push(make_pair(r, c));
		}
	}
	while(!qa.empty()){
		ii x = qa.front();
		qa.pop();
		loop(4){
			int r = x.fi+di[i];
			int c = x.se+dj[i];
			if(r<0||r>=n||c<0||c>=m||grid[r][c]=='#'||va[r][c]) continue;
			va[r][c] = 1;
			da[r][c] = da[x.fi][x.se]+1;
			qa.push(make_pair(r, c));
			parent[r][c] = x;
		}
	}
	ii target = make_pair(-1, -1);
	loop(n){
		if(grid[i][0]!='#'&&da[i][0]<dm[i][0]){
			target = make_pair(i, 0);
			break;
		}
		if(grid[i][m-1]!='#'&&da[i][m-1]<dm[i][m-1]){
			target = make_pair(i, m-1);
			break;
		}
	}
	loop(m){
		if(grid[0][i]!='#'&&da[0][i]<dm[0][i]){
			target = make_pair(0, i);
			break;
		}
		if(grid[n-1][i]!='#'&&da[n-1][i]<dm[n-1][i]){
			target = make_pair(n-1, i);
			break;
		}
	}
	if(target==make_pair(-1, -1)){
		cout<<"NO"<<endl;
	} else {
		string ans = "";
		while(target!=A){
			if(target.fi<parent[target.fi][target.se].fi) ans+='U';
			if(target.fi>parent[target.fi][target.se].fi) ans+='D';
			if(target.se<parent[target.fi][target.se].se) ans+='L';
			if(target.se>parent[target.fi][target.se].se) ans+='R';
			target = parent[target.fi][target.se];
		}
		reverse(all(ans));
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		cout<<ans<<endl;
	}

	return 0;
}