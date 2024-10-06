## Tsting script
```bash
echo "--- Compilation ---"
g++ main.cpp -o a.out
for file in data/*.in
do
    out=${file%%in}out
    ans=${file%%in}ans

    ./a.out < $file > $ans

    echo "--- $file ---"
    ./a.out < $file
    echo
    echo "--- Comparison ---"
    diff $ans $out
done
```

## C++ template
```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(20);
    return 0;
}
```

## Variables used in this documentation
```c++
int a, b, c, d;
double x, y;
complex<double> z;
string s;
vector<T> v;
map<T1, T2> m;
```

## Useful adhoc functions
```c++
clamp(v, a, b); //closest value to v in [a, b]
gcd(a, b);
lcm(a, b);
fmod(x, y); // the floating point reminder of x divided by y
exp(a), exp2(a), log(a), log2(a), log10(a);
sqrt(a);
ceil(x), floor(y);
```

## STL containers
```c++
myCon.begin(), myCon.end();
myCon.rbegin(), myCon.rend();
myCon.size(), myCon.empty();
min_element(it_from, it_to);
max_element(it_from, it_to);
accumulate(it_from, it_to);
sort(it_from, it_to);
fill(it_from, it_to, value);
iota(it_from, it_to, start); // fills with consecutive values starting from the value start
```

### Vectors
```c++
v1+v2; // to concatenate two vectors
v.back(); // get the last element
v.front(); // get the first element (not efficient) DONT USE!!! if you need it use DEQUE
```

### Deques
Similar to a vector with efficient push_front and pop_front but less efficient push_back and pop_back (but still constant)
```c++
v.push_back(value);
v.pop_back();
v.push_front(value);
v.pop_front();
v.front();
v.back();
```

### Sets
```c++
*s.begin(); // the minimal value
*s.rbegin(); // the maximal value
s.find(a); // iterator pointing to a if exists and s.end() otherwise
s.lower_bound(a); // iterator pointing to the first element greater or equal to a
s.upper_bound(a); // iterator pointing to the first element strictly greater than a
```

### Strings
```c++
if(s1<s2); // lexicographical comparison
if("a"=="b"); // comparison of pointers
if(string("a")==string("b")); // comparison fo strings
s.substr(first_pos, len);
s.find("pattern"); // look for first occurence
s.find("pattern", pos); // look for first occurence after position 42
```



## Complex numbers & geometry

### Definition
```c++
complex<T>(real_part, imag_part);
```

### Methods
```c++
z.real();
z.imag();
norm(z); // module squared
abs(z); // module
conj(z);
arg(z);
proj(z); // return z if not infinite otherwise returns the projection of z 
//on the infinit axis (inf, 3) -> (inf, 0)
```

### Cross product
-  ⃗a × ⃗b > 0 when ⃗b is counter-clockwise to ⃗a  
-  ⃗a × ⃗b < 0 when ⃗b is clockwise to ⃗a  
-  ⃗a × ⃗b = 0 when ⃗b is co-linear to ⃗a  

### Projection
proja⃗(b⃗) = p⃗ = a⃗ × a⃗ · b⃗/ ( a⃗ · a⃗) = |b⃗| cos α  a⃗ /|a⃗| 

### Built-in functions
```c++
sin(x), cos(x), tan(x);
fmod(x);
fabs(x);
atan(x);
atan2(x, y); // atan(x, y)=tan⁻¹(y/x), 
//we coud use it with y=sin and x=cos to find the angle
```

### Algorithms for computational geometry

#### Definitions (useful functions)
Use complex numbers:
- addition, subtraction and multiplication by a scalar are defined
- scalar product a⃗ · ⃗b = real(¯a * b)
- cross product a⃗ × ⃗b = imag(¯a * b)
```c++
// Definition
#define pt complex<double>

double scalar(pt z1, pt z2){
    return (conj(z1)*z2).real();
}
double cross(pt z1, pt z2){
    return (conj(z1)*z2).imag();
}
int cross_sign(pt a, pt b){
    if(cross(a, b)<0) return -1;
    if(cross(a, b)>0) return 1;
    return 0;
}
```

#### Orthogonal Projection 
```c++
pt proj(pt z1, pt z2){
	// projection of z2 over the line defined by z1
	pt origin=pt (0,0);
	if(z1==origin||z2==origin) return origin;
	return (dot(z1, z2)/dot(z1,z1))*z1;
}
// The distance from a point to line
double orth_dis(pt a, pair<pt, pt> line){
	pt z1 = line.second-line.first;
	pt z2 = a-line.first;
	pt p = proj(z1, z2);
	return abs(z2-p);
}
```

#### Triangle area
```c++
double signed_triangle_area(pt a, pt b, pt c){
    return cross(b-a, c-a)/2;
}
double triangle_area(pt a, pt b, pt c){
    return fabs(signed_triangle_area(a, b, c));
}
```

#### Polygon area
```c++
double polygon_area(vector<pt> v){
    // set a reference point
    pt z = v[0];
    double signed_poly_area = 0;
    for(int i=0; i<v.size()-1; i++){
        poly_area += signed_triangle_area(z, v[i], v[i+1]);
    }
    return fabs(signed_poly_area);
}
```

#### Intersection between segments
```c++
double checkIntersection(pt a, pt b, pt c, pt d){
    // Check that the segment [c, d] intersects the line defined by [a, b]
    bool check1 = cross_sign(c-a, b-a)!=cross_sign(d-a, b-a);
    // Check that the segment [a, b] intersects the line defined by [c, d]
    bool check2 = cross_sign(a-c, d-c)!=cross_sign(b-c, d-c);

    return check1 && check2;
}
```

#### Test if a point is inside a polygon
Follow the boundry of the polygon:
- if it made **even** turns then the point is **outside**
- if it made **odd** number of turns then the point is **insdide**
```c++
typedef complex<double> pt;
vector<vec> polygon ;
const double PI = acos(-1);
double angle(pt a, pt b) {
    const double angle = fmod(a.arg()-b.arg(),2*PI);
    if(angle <= PI) return angle ;
    return angle-2*PI;
}
bool is_inside(pt p) {
    double totalArg = 0;
    vec last = polygon.back();
    for(auto cur : polygon) {
        totalArg += angle(cur-p, last-p);
        last=cur;
    }
    return !(fabs(fmod(totalArg/(2*PI),2))<0.1) ;
}
```

#### Convex Hall: Graham scan
- Start from the leftmost point L
- for all points P in increasing order of polar angle L->P
    - add P to convex hull
    - while the last three points turn right (cross(p2-p1, p3-p2)<0)
        - remove the most recent point of the hull

```c++
/// L is the leftmost point
/// v is the vector of points other than L (v neither contains L, 
/// nor a point with the same coordinates as L)
/// v doesn't contain the same point twice
bool turn_right(pt a, pt b, pt c){
    if(cross_sign(b-a, c-b)<=0)
        return true;
    return false;
}
double get_angle(pt a, pt b){
    return arg(b-a);
}
vector<pt> sort_by_inc_ang(pt L, vector<pt> v){
    set<pair<double, int>> s;
    vector<pt> sorted_v;
    for(int i=0;i<v.size(); i++)
    {
        double ang = get_angle(L, v[i]);
        s.insert(make_pair(ang, i));
    }
    for(auto [_, i]: s)
        sorted_v.push_back(v[i]);
    return sorted_v;
}
vector<pt> convex_hull(pt L, vector<pt> v){
    v = sort_by_inc_ang(L, v);
    // add the first point at the end to ensure a cycle
    v.push_back(L);
    vector<pt> res; res.push_back(L);
    for(auto &p: v){
        res.push_back(p);
        int len = res.size();
        while(len>=3&&turn_right(res[len-3], res[len-2], res[len-1])){
            res.erase(res.end()-2);
        }
    }
    // remove the redundant first point
    res.erase(res.end()-1);
    return res;
}
```



## Algorithms

### Graph

#### BFS (easy)
```c++
int seen[NB_NODE_MAX] ;
void bfs(int start) {
    vector<int> todo = {start} ;
    seen[start] = true ;
    for(size_t id = 0 ; id < todo.size() ; id++)
        for(auto v : nxt[todo[id]])
            if(!seen[v]) {
                seen[v] = true;
                todo.push_back(v);
            }
}
```

#### Dijkstra
```c++
#define INF int(1e18)
long long dist[NB_NODES_MAX];
typedef pair<long long,int> pill;
fill(dist,dist+NB_NODES_MAX,INF);
// priority queue in reverse order
priority_queue<pill,vector<pill>,greater<pill>> p_queue;
p_queue.push(make_pair(0,start_node));
dist[start_node] = 0;
while(!p_queue.empty()) {
    auto [node_dist, node] = p_queue.top() ;
    p_queue.pop();
    if(dist[node] == node_dist) // lazy priority queue
        for(auto v : nxt[node])
            if(node_dist + v.second < dist[v.first]) {
                dist[v.first] = node_dist + v.second;
                p_queue.push(make_pair(dist[v.first],v.first));
            }
}
```

#### Bellman-Ford
Bellman-Ford DP problem: “q(n, k) is the minimal distance of n from the source node using k intermediate edges”
```c++
int from[MAX_NB_EDGES], to[MAX_NB_EDGES],weight[MAX_NB_EDGES];
int dist[MAX_PATH_LENGTH+1][MAX_NB_NODES];
bool BellmanFord(int root) {
    fill(dist[0],dist[MAX_PATH_LENGTH],INF);
    dist[0][root] = 0;
    for(int len = 0 ; len < MAX_PATH_LENGTH ; len++)
        for (int e = 0 ; e < nb_edges ; e++)
            dist[len+1][to[e]] = min(dist[len+1][to[e]], dist[len][from[e]]+weight[e]);
    int ans = INF;
    for(len=0; len<=MAX_PATH_LENGTH; len++)
        ans = min(ans, dist[len][target])
    return ans;
}

// Simplified version (since MAX_PATH_LENGTH is at most nb_nodes long)
int dist[MAX_NB_NODES];
void BellmanFord(int root, int target) {
    fill(dist, dist+MAX_NB_NODES, INF);
    dist[root] = 0;
    for(int k = 0 ; k < nb_nodes - 1 ; k++) // N - 1 times
        for (int i = 0 ; i < nb_edges ; i++)
            dist[to[i]] = min(dist[to[i]], dist[from[i]]+weight[i]);  
}

// Detect negative cycles with Bellman-Ford
bool detect_negative_cycle_BellmanFord(int root, int target) {
    fill(dist, dist+MAX_NB_NODES, INF);
    dist[root] = 0;
    for(int k = 0 ; k < nb_nodes - 1 ; k++) // N - 1 times
        for (int i = 0 ; i < nb_edges ; i++)
            dist[to[i]] = min(dist[to[i]], dist[from[i]]+weight[i]);
    // now time to check for negative cycles:
    int dist_target = dist[target]; // copy distance
    for(int k = 0 ; k < nb_nodes - 1 ; k++) // N - 1 times
        for (int i = 0 ; i < nb_edges ; i++)
            dist[to[i]] = min(dist[to[i]], dist[from[i]]+weight[i]);
    return dist[target] < dist_target ; // negative cycle?
}
```

#### Floyd-Warshall
Floyd-Warshall answers the DP problem: “q(start,end,pivot): what is the shortest path between start and end going through intermediate nodes 1..pivot?”
```c++
int dist[MAX_NB_NODES][MAX_NB_NODES];
// We store q(start,end,pivot) in dist[start][end]
void FloydWarshall() {
    // initialize distance
    fill(dist[0],dist[MAX_NB_NODES],INF);
    for (int e = 0 ; e < nb_edges ; e++)
        dist[fr[e]][to[e]] = min(dist[fr[e]][to[e]], weight[e]);
    // now compute
    for(int pivot = 0 ; pivot < nb_nodes ; pivot++)
        for(int start = 0 ; start < nb_nodes ; start++)
            for(int end = 0 ; end < nb_nodes ; end++)
                dist[start][end] = min(dist[start][end],
                                       dist[start][pivot]+dist[pivot][end]);
}
```

#### Hierholzer's algorithm (Eulerian paths)
```c++
set < int > Adj [ MAXN ]; vector < int > Circuit ;

void Hierholzer ( int v) {
    while (! Adj [v ]. empty ()) { // follow edges until stuck
        int tmp = * Adj [ v ]. begin ();
        Adj [v ]. erase ( tmp ); // remove edge, modifying graph
        Adj [ tmp ]. erase ( v );
        Hierholzer ( tmp );
    }
    Circuit . push_back (v ); // got stuck: append node at the end of circuit
}

void Hierholzer_main () {
    int v = 0; // find node with odd degree, else start with node 0
    for ( int u =0; u < N && v == 0; u ++)
        if ( Adj [u ]. size () & 1)
            v = u ; // node with odd degree
    Hierholzer (v);
}
```

#### MST

##### Kruskal's algorithm
For all edges (a, b) by increasing weight  
- if a and b not in the same component  
    - link a and b
```c++
vector<pair<weight, pair<int,int> > > edges;
// ...
sort(edges.begin(),edges.end());
long long weight_mst = 0;
for(auto [w,p] : edges)
    if(unite(p.first,p.second))
    weight_mst += w;
```

##### Prim's algorithm
Make a modified Dijkstra:
-  maintain a set S of nodes, initialized as {x} for any node x
-  while there remains a node not in S:
    - select an edge {n, n ′} ∈ E ∩ (S, V \ S) minimizing w(n, n ′)
    - add {n, n ′} to E ′
```c++
long long dist[NB_NODES_MAX];
//...
fill(dist,dist+NB_NODES_MAX,INF);
set<pair<long long,int>> p_queue; // (weight, node)
p_queue.insert(make_pair(0,start_node));
dist[start_node] = 0;
while(!p_queue.empty()) {
    auto [node_dist, node] = *p_queue.begin() ; // c++17
    p_queue.erase(p_queue.begin());
    for(auto v : nxt[node])
        if(v.second < dist[v.first]) {
            p_queue.erase(make_pair(dist[v.first],v.first));
            dist[v.first] = v.second;
            p_queue.insert(make_pair(dist[v.first],v.first));
        }
}
```

### Max-flow
**Theorem**: finding maximum matching in bipartite graph G is equivalent to finding the max flow from s (a source we link to the left side of G) to t (a target we link to the right side of G)

#### Ford-Fulkerson with DFS (Max flow)
- Initialize f (flow) with empty flow
- While there exists a path p from s (source) to t (target) in the residual
    - increase f with the path p using maximal capacity
```c++
int capa[Tm][Tm], flow[Tm][Tm]; // adjacency matrix
bool visited[Tm];
int dfs(int x, int max_flow) {
    if(visited[x]) return 0; // already search/ed for a flow
    if(x==target) return max_flow;// found our flow
    visited[x] = true; // stop visiting x
    for(int n: nxt[x]) // mixes adjacency lists with matrix
        if(flow[x][n] < capa[x][n]) { // residual
            const int sub_flow = dfs(n, min(max_flow,capa[x][n]-flow[x][n]));
            if(sub_flow > 0) {
                flow[x][n]+= sub_flow;
                flow[n][x]-= sub_flow;
                return sub_flow;
            }
        }
    return 0; // haven't found a flow
}
int totalFlow = 0, curFlow = 1 ;
while(curFlow > 0) {
    fill(visited,visited+Tm,false) ;
    curFlor = dfs(source,INF) ;
    totalFlow += curFlow ;
}
// in the worst case the flow increases by one each time
// hence in O(E) × F where F is the final flow
// if using integers
```

## Node class for segment tree
```c++
class node 
{
public:
	node* left;
	node* right;
	ll m;
	int i, s, e;
	node(int i, int s, int e)
	{
		this->s = s;
		this->e = e;
		this->i = i;
		left = NULL;
		right = NULL;
		m = 0;
	}
};

void build_tree(node* head)
{
	int i = head->i;
	int s = head->s;
	int e = head->e;

	// If leaf node
	if(e==s)
	{
		head->m = a[e];
		return;
	}

	int mid = (e+s)/2;

	// Create children
	head->left = new node(2*i, s, mid);
	head->right = new node(2*i+1, mid+1, e);

	// Recurse throught the tree
	build_tree(head->left);
	build_tree(head->right);

	node* left = head->left;
	node* right = head->right;

	// Set head parameters
	head->m = min(left->m, right->m);
}

void update(node* head, int idx, int val)
{
	int i = head->i;
	int s = head->s;
	int e = head->e;

	if(idx<s||idx>e)
		return;

	if(e==s)
	{
		a[e] = val;
		head->m = val;
		return;
	}

	int mid = (e+s)/2;

	// Recurse throught the tree
	update(head->left, idx, val);
	update(head->right, idx, val);

	node* left = head->left;
	node* right = head->right;

	// Set head parameters
	head->m = min(left->m, right->m);
}

ll query(node* head, int l, int r)
{
	int i = head->i;
	int s = head->s;
	int e = head->e;

	if(r<s||l>e)
		return inf;

	if(l<=s&&e<=r)
		return head->m;

	node* left = head->left;
	node* right = head->right;

	return min(get_min(left, l, r), get_min(right, l, r));
}

```

## Number theory
### Binary exponentiation
```c++
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```
### GCD and LCM
```c++
int gcd (int a, int b) {
    if (b == 0)
        return a;
    return gcd (b, a % b);
}

int lcm (int a, int b) {
    return a*b / gcd(a, b) ;
}
```
### Inverse Modulo
```c++
//O(log(n))
ll power(ll a,ll n,ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

//O(1)
ll mod_inv (ll a,ll mod)
{
    return power(a,mod-2,mod);
}

//O(1)
ll mod_division(ll a,ll b,ll mod)//calculates (a/b)%m
{
    return (a%mod * mod_inv(b,mod)%mod)%mod;
}
```
### Prime Numbers
#### Prime factorization
```c++
vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
```
#### Sieve of Eratosthenes - Generating Primes
```c++
// Getting prime factorization for all numbers between 2 and n
vector<bool> is_prime(n, 1);
vector<int> fact(n+1);
for(int i=2; i*i<=n; i++)
{
    if(is_prime[i])
    {
        for(int j=1; j*i<=n ; j++)
        {
            is_prime[i*j] = 0;
            fact[i*j] = i; 
        }
    }
}

for(int i=2;i<=n;i++)
	if(is_prime[i])
		fact[i] = i;

// we want to determine the prime factors of target
int target;
cin>>target;
while(target>1)
{
    prime_factor = fact[target];
    // Do something
    target /= fact[target];
}
```
## Combinatorics
### Binomial Coefficients - DP
```c++
// A Dynamic Programming based solution that uses
// table C[][] to calculate the Binomial Coefficient
#include <bits/stdc++.h>
using namespace std;
  
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
  
    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
  
            // Calculate value using previously
            // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
  
    return C[n][k];
}
```

## Custom Operators
### Arithmetic Operators
```c++
class MyClass {
public:
    int value;
};

// Declaration of arithmetic operators as non-member functions
MyClass operator+(const MyClass& lhs, const MyClass& rhs);
MyClass operator-(const MyClass& lhs, const MyClass& rhs);
MyClass operator*(const MyClass& lhs, const MyClass& rhs);
MyClass operator/(const MyClass& lhs, const MyClass& rhs);
MyClass operator%(const MyClass& lhs, const MyClass& rhs);

// Definition of the addition operator (+) as a non-member function
MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
    MyClass result;
    result.value = lhs.value + rhs.value;
    return result;
}

// Definition of the subtraction operator (-) as a non-member function
MyClass operator-(const MyClass& lhs, const MyClass& rhs) {
    MyClass result;
    result.value = lhs.value - rhs.value;
    return result;
}

// Definition of the multiplication operator (*) as a non-member function
MyClass operator*(const MyClass& lhs, const MyClass& rhs) {
    MyClass result;
    result.value = lhs.value * rhs.value;
    return result;
}

// Definition of the division operator (/) as a non-member function
MyClass operator/(const MyClass& lhs, const MyClass& rhs) {
    MyClass result;
    result.value = lhs.value / rhs.value;
    return result;
}

// Definition of the modulus operator (%) as a non-member function
MyClass operator%(const MyClass& lhs, const MyClass& rhs) {
    MyClass result;
    result.value = lhs.value % rhs.value;
    return result;
}
```
### Comparison Operators
```c++
class MyClass {
public:
    int value;
};

// Declaration of comparison operators as non-member functions
bool operator==(const MyClass& lhs, const MyClass& rhs);
bool operator!=(const MyClass& lhs, const MyClass& rhs);
bool operator<(const MyClass& lhs, const MyClass& rhs);
bool operator<=(const MyClass& lhs, const MyClass& rhs);
bool operator>(const MyClass& lhs, const MyClass& rhs);
bool operator>=(const MyClass& lhs, const MyClass& rhs);

// Definition of the equality operator (==) as a non-member function
bool operator==(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value == rhs.value;
}

// Definition of the inequality operator (!=) as a non-member function
bool operator!=(const MyClass& lhs, const MyClass& rhs) {
    return !(lhs == rhs);
}

// Definition of the less than operator (<) as a non-member function
bool operator<(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value < rhs.value;
}

// Definition of the less than or equal to operator (<=) as a non-member function
bool operator<=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value <= rhs.value;
}

// Definition of the greater than operator (>) as a non-member function
bool operator>(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value > rhs.value;
}

// Definition of the greater than or equal to operator (>=) as a non-member function
bool operator>=(const MyClass& lhs, const MyClass& rhs) {
    return lhs.value >= rhs.value;
}
```

## Strings
### Trie Structure
```c++
#include<bits/stdc++.h>
using namespace std;
 
const int SIZE = 26;
 
struct node{
	bool endOfWord;
	node* ar[SIZE];
};
 
node* getNode()
{
	node* n = new node;
	n->endOfWord = false;
 
	for(int i=0;i<SIZE;i++)
	n->ar[i] = NULL;
 
	return n;
}
 
void insert(node *root , string st)
{
	node *tempRoot = root;
 
	for(int i=0;i<st.size();i++)
	{
		int index = st[i] - 'a';
 
		if(tempRoot->ar[index] == NULL)
		tempRoot->ar[index] = getNode();
 
		tempRoot = tempRoot->ar[index];
	}
 
	tempRoot->endOfWord = true;
}
 
bool search(node *root , string st)
{
	node *tempRoot = root;
 
	for(int i=0;i<st.size();i++)
	{
		int index = st[i] - 'a';
 
		if(tempRoot->ar[index] == NULL)
		return false;
 
		tempRoot = tempRoot->ar[index];
	}
 
	return tempRoot->endOfWord;
}
 
int main()
{
	node *root = getNode();
 
	int n , code;
	string st;
 
	while(1)
	{
		cin>>code;
 
		if(code == 1)
		{
			cout<<"Enter string to insert\n";
			cin>>st;
			insert(root , st);
		}
		else
		if(code == 2)
		{
			cout<<"Enter string to search\n";
			cin>>st;
			cout<<search(root , st)<<endl;
		}
		else
		break;
	}
}
```
### Substring hashing
```c++
//the idea is to calculate the polynomial rolling hash of the input string str
//then given a query (2 integers l and r) calculate the hash of the substring 
//str[l:r]. To do so we use a prefix array dp[n] to memorize the contribution 
//of the substring str[0:i] in the hash value of str.

lli dp[1000001];
lli inv[1000001];

//Calculate a to the power of n under modulo mod
lli power(lli a , lli n)
{
	lli result = 1;
 
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
 
		n >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}
 
//initialize the prefix array and the inverse modulo array
void init(string input_string)
{
	lli p = 31;
	lli p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);
 
 
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
 
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
 
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}

//The actual substring haching function
lli substringHash(int L , int R)
{
	int result = dp[R];
 
	if(L > 0) result -= dp[L-1];
    if(ans<0) ans+=mod;
	result = (result * inv[L]) % mod;
 
	return result;
}
 
int main()
{
	string input_string;
	int tc , L , R;
 
	cin>>input_string;
	init(input_string);
 
	cin>>tc;
 
	REP(i , tc)
	{
		cin>>L>>R;
		cout<<substringHash(L , R)<<endl;
	}
}
```