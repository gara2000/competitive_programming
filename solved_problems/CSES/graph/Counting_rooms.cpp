#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;

typedef complex<double> pt;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;


int parent[1000001];
void init(int N){
	for(int i=0;i<=N;i++) parent[i] = i;
}

int find(int x){
	if(parent[x]==x)
		return x;
	return parent[x]=find(parent[x]);
}

void Union(int x, int y){
	x = find(x);
	y = find(y);
	parent[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int n, m;
	cin>>n>>m;
	init(n*m);
	vector<string> grid(n);
	loopi(n){
		string s;
		cin>>s;
		grid[i] = s;
	}
	loopi(n){
		loopj(m){
			if(j<m-1&&grid[i][j]==grid[i][j+1]&&grid[i][j]=='.')
				Union(j+i*m, j+1+i*m);
			if(i<n-1&&grid[i][j]==grid[i+1][j]&&grid[i][j]=='.')
				Union(j+i*m, j+(i+1)*m);
		}
	}
	set<int> s;
	loopi(n){
		loopj(m){
			if(grid[i][j]=='.')
				s.insert(find(j+i*m));
		}
	}
	cout<<s.size()<<endl;
	return 0;
}