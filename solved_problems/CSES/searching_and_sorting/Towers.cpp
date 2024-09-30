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
	int n;
	cin>>n;
	map<int,int> m;
	int ans = 0;
	loop(n){
		int x;
		cin>>x;
		auto it = m.upper_bound(x);
		if(it==m.end()){
			m[x]++;
			ans++;
		} else {
			m[(*it).first]--;
			if(!m[(*it).first]) m.erase((*it).first);
			m[x]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}