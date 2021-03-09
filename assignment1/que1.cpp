#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define debug(x) cout<<#x<<'='<<(x)<<endl<<flush
#define N (int)1e7
#define pb push_back
// #define mod 998244353
#define mod 1000000007
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define input(arr,n) f(_,n) cin>>arr[_]
#define out(arr,n) f(_,n) cout<<arr[_]<<" ";cout<<endl;
bool sortcol( vector<int>& v1, vector<int>& v2 ) { return v1[0] < v2[0]; } 
#define debug(x) cout<<#x<<'='<<(x)<<endl<<flush
//  n-1 steps
int min_ele(int arr[], int n)
{
    if(n==1) return arr[0];
    int ans=arr[0];
    f(i,n-1) ans=min(ans,arr[i+1]);
    return ans;
}

// n-1 steps
int max_ele(int arr[], int n)
{
    if(n==1) return arr[0];
    int ans=arr[0];
    f(i,n-1) ans=max(ans,arr[i+1]);
    return ans;
}

int32_t main()
{
    int n; cin>>n;                                          /* Take input n, the number of elements in the array */ 
    int arr[n]; input(arr,n);                               /* Take input array n*/
    int min_arr[(n+1)/2]; int max_arr[(n+1)/2];int i;
    //  n/2 steps for computing min_arr and max_arr
    for(i=0;i<n-1;i+=2)                                     /* In n/2 steps only, we can compute min_arr and maxarr. in one single comparison we are comaparing two adjacent elements*/
    {                                                       /* If one of them is minimum, then other one is automatically maximum*/
        min_arr[i/2]=min(arr[i],arr[i+1]);
        max_arr[i/2]=arr[i]+arr[i+1]-min_arr[i/2];
    }
    if(i==n-1) min_arr[i/2]=arr[i],max_arr[i/2]=arr[i];     /* If number of elements are odd, then put last element in both the arrays, i.e. min_arr and max_arr */
    //  n/2-1 steps for computing min_element + n/2-1 steps for computing max_element
    cout<<"min element = "<<min_ele(min_arr,(n+1)/2)<<" max element = "<<max_ele(max_arr,(n+1)/2)<<endl;
    // total steps 3n/2-2

}