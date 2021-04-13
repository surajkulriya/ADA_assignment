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



// find the correct position of pivot element(here pivot is last element)
// in sorted array and place it there.
// place all smaller elements at lower indexes
// and greater elements at higher indexes
int partition(int arr[], int l, int r)
{
    int s=l;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<arr[r]){                      /*  If the current element is smaller then pivot element    */
            swap(arr[i],arr[s]);                /*  swap it with the previous element that is greater then pivot element    */
            s++;
        }
    }
    swap(arr[s],arr[r]);                        /*  Swap piovt element with the left most element that is greater then pivot    */
    return s;
}

int32_t main()
{
    int n; cin>>n; int arr[n]; input(arr,n);
    int ans=0;int l=0; int r=n-1;
    // keep pivoting random elements until 
    // we get element at index n/2
    while(true)                                 /*  Find element at index n/2   */
    {
        int a = partition(arr, l, r);
        if(a==n/2){
            ans+=arr[a]; break;
        }
        if(a>n/2) r=a-1;
        if(a<n/2) l=a+1;
    }
    if(!(n&1))                                  /*  If length of array is even, find element at index n/2-1 */
    {
        l=0;r=n-1;
        // keep pivoting random elements until 
        // we get element at index n/2-1
        while(true)
        {
            int a = partition(arr, l, r);
            if(a==n/2-1){
                ans+=arr[a]; break;
            }
            if(a>n/2-1) r=a-1;
            if(a<n/2-1) l=a+1;
        }   

        ans*=5;                                 /*  If length of array is even, add two middle elements and take their average*/
        cout<<ans/10;
        if(ans&1) cout<<".5";
        cout<<endl;
        return 0;
    }
    cout<<ans<<endl;return 0;
}