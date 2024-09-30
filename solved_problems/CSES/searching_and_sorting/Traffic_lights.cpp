#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
using namespace std;

typedef complex<double> pt;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	int x;
	cin>>x;
	int n;
	cin>>n;
	set<ii> s;
	map<int,int> m;
	m[x]++;
	s.insert({0, x});
	loop(n){
		int p;
		cin>>p;
		auto it = s.upper_bound({p,int(1e9)});
		it--;
		s.erase(it);
		auto [l, r] = *it;
		int length = r-l;
		m[length]--;
		if(!m[length]) m.erase(length);
		s.insert({l, p});
		s.insert({p, r});
		m[p-l]++;
		m[r-p]++;
		auto max = m.rbegin();
		cout<<(*max).first<<" ";
	}
	cout<<endl;
	return 0;
}