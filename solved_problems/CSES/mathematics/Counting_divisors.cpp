#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int ans = 1;
		for(int i=2;i*i<=x;i++){
			int curr = 0;
			while(x%i==0){
				curr++;
				x/=i;
			}
			ans*=(curr+1);
		}
		if(x!=1) ans*=2;
		cout<<ans<<endl;
	}
	return 0;
}