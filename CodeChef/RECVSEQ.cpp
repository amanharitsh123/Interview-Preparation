#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
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
  T temp;
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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    vector<lli> arr;
    cin>>n;
    input(arr,n);
    set<lli> d;
    for(lli i=1;i<n;i++) {
      d.insert(arr[i]-arr[i-1]);
    }

    lli changes=n, ans=-1, dd=-1;
    for(auto x:d) {
      lli temp=0;
      lli a=arr[0];
      for(lli i=0;i<n;i++) {
        if(arr[i]!=a)
          ++temp;
        a+=x;
      }

      if(temp<changes) {
        changes=temp;
        ans=arr[0];
        dd=x;
      }
      temp=0;
      a=arr[n-1];
      for(lli i=n-1;i>=0;i--) {
        if(arr[i]!=a)
          ++temp;
        a-=x;
      }

      if(temp<changes) {
        changes=temp;
        ans=a+x;
        dd=x;
      }
    }

    for(lli i=0;i<n;i++)
      cout<<ans<<" ",ans+=dd;
    
    cout<<endl;
	}
}
