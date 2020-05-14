#include<bits/stdc++.h>
#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define MOD 1000000007
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

void solve() {
  lli n;
  cin >> n;
  vector<lli> arr;
  input(arr, n);
  map<lli, lli> mp;
  // preprocessing array
  for(lli i=0; i<n; i++) {
    lli left = 1, right = 0;
    for(lli j=i-1; j>=0 and arr[j]>arr[i]; --j)
      ++left;

    for(lli j=i; j<n and arr[j]>=arr[i]; ++j)
      ++right;
    
    left = max(left, 1LL);
    
    mp[arr[i]] += left*right;
  }

  lli q = 0;
  cin >> q;
  while(q--) {
    lli k;
    cin >> k;
    mp[k] += 0;
    cout << mp[k] << endl;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases = 1;
  while(testcases--) {
    solve();
  }
}

