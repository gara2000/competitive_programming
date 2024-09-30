 // Include statements
	#include <bits/stdc++.h>
	#include <iomanip>
	#include <cmath>

 // Definitions
	// #define endl '\n' 
	#define mod 1000000007ll
	#define pb push_back
	#define all(v) v.begin(),v.end()
	#define M_PI           3.14159265358979323846
	#define prime6 347717
	#define loop(start, end, step) for(int i=start; i<end; i+=step)
	#define fi first
	#define se second

using namespace std;
 // Type definitions
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int,int> ii;
	typedef pair<ll,ll> pll;
	typedef pair<ll,int> plli;

 // Constants
	const ll inf=ll(1e14)+5;
	const ll mo=998244353;
	//const int p=31;
 
template<typename T>
void repr(vector<T> a, int N)
{
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<typename T>
void represent(T a){
	for(auto x: a)
	cout<<x<<" ";
	cout<<endl;
}
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

class node
{
public:
	int sum;
	ii s, e;
	node *tl, *tr, *bl, *br;
	node(ii s, ii e)
	{
		this->s = s;
		this->e = e;
		this->tl= NULL;
		this->tr= NULL;
		this->bl= NULL;
		this->br= NULL;
	}
};

int n, k;
int c;
void build_tree(node* head){
	ii s = head->s;
	ii e = head->e;
	if(e==s){
		head->sum = 0;
		return;
	}

	int m1 = (s.fi+e.fi)/2;
	int m2 = (s.se+e.se)/2;

	head->tl = new node(s, make_pair(m1,m2));
	head->tr = new node(make_pair(s.fi, m2+1), make_pair(m1, e.se));
	head->bl = new node(make_pair(m1+1, s.se), make_pair(e.fi, m2));
	head->br = new node(make_pair(m1+1, m2+1), e);

	build_tree(head->tl);
	build_tree(head->tr);
	build_tree(head->bl);
	build_tree(head->br);
	
	head->sum = 0;
}

void show_rect(ii s, ii e){
	cout<< "rect:" <<endl;
	cout<<s.fi<<" "<<s.se<<endl;
	cout<<e.fi<<" "<<e.se<<endl;
}

void update(node* head, ii start, ii end){
	ii s = head->s;
	ii e = head->e;
	// show_rect(s, e);
	// show_rect(start, end);
	
	if(e.fi<start.fi||e.se<start.se||s.fi>end.fi||s.se>end.se){
		// cout<<"no"<<endl;
	    return ;
	}
	if(start.fi<=s.fi&&end.fi>=e.fi&&start.se<=s.se&&end.se>=e.se){
		// show_rect(s, e);
		// cout<<"yes"<<endl;
		head->sum ++;
		return ;
	}
	// cout<<"not entering"<<endl;

	update(head->tl, start, end);
	update(head->tr, start, end);
	update(head->bl, start, end);
	update(head->br, start, end);
}

void propagate(node* head, int tot){
	ii s = head->s;
	ii e = head->e;
	if(e==s){
		head->sum += tot;
		// show_rect(s, e);
		// cout<<head->sum<<endl;
		if(head->sum==k)
		{
			c ++;
		// show_rect(s, e);
		}
		return;
	}
	propagate(head->tl, tot+head->sum);
	propagate(head->tr, tot+head->sum);
	propagate(head->bl, tot+head->sum);
	propagate(head->br, tot+head->sum);
}

int square(int x){
	return x*x;
}

void solve()
{
	cin>>n>>k;
	c = 0;
	// cout<<n<<endl;
	int x = 1<<10;
	node* head = new node(make_pair(1, 1), make_pair(x,x));
	build_tree(head);
	// cout<<"hello"<<endl;
	for(int i=0;i<n;i++){
		ii s, e;
		cin>>s.fi>>s.se>>e.fi>>e.se;
		s.fi++;
		s.se++;
		// cout<<i<<endl;
		update(head, s, e);
	}
	propagate(head, 0);
	cout<<c<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
	// freopen("polygon.in", "r", stdi n);
 
    cout<<setprecision(20);
 
	int t=1;
	bool test = false;
	if(test)
		cin>>t;
	while(t--)
		solve();
 
	return 0;
}


