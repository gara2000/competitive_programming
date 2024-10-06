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

int parent[100001];
void init(int n){
	loop(n) parent[i+1] = i+1;
}

int find(int x){
	if(parent[x]==x) return x;
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
	init(n);
	loop(m){
		int x, y;
		cin>>x>>y;
		Union(x, y);
	}
	set<int> s;
	vector<int> a;
	loop(n) s.insert(find(i+1));
	for(auto x: s) a.pb(x);
	cout<<a.size()-1<<endl;
	loop(a.size()-1){
		cout<<a[i]<<" "<<a[i+1]<<endl;	
	}
	return 0;
}