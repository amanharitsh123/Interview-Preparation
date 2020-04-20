#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
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
    cin>>n;
    vector<lli> arr;
    input(arr,n);
    vector<lli> min_ind(n,0);
    lli mi=LLONG_MAX;
    lli ind=-1;
    for(lli i=0;i<n;i++) {
      if(arr[i]<mi)
        mi=arr[i],ind=i;
      min_ind[i]=ind;
    }
    lli ans=0;
    lli sub=0;
    lli j=n;
    //output(min_ind);
    for(lli i=n-1;i>=0;) {
      ind=min_ind[i];
      mi=arr[ind];
      ans+=(mi-sub)*j;
      sub+=(mi-sub);
      j=ind;
      i=ind-1;
    }
    cout<<ans<<endl;
	}
}

