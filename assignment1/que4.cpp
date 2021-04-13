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
    for(int i=l;i<r;i++){
        if(arr[i]<arr[r]) swap(arr[i],arr[s++]);        /*  If the current element is smaller then pivot element    */
    }                                                   /*  swap it with the previous element that is greater then pivot element    */
    swap(arr[r],arr[s]);
    return s;
}

// sort array starting from index l to r(inclusive) 
void quickSort(int arr[], int l, int r)
{
    if(l>=r) return;                                    /*  If we got left index > right index, we are there*/
    int a=partition(arr, l, r);
    quickSort(arr,l,a-1);                               /*  recursively sort array at left of pivot element */
    quickSort(arr, a+1, r);                             /*  recursively sort array at right of pivot element    */
}

int32_t main()
{
    int n; cin>>n; int arr[n]; input(arr,n);
    quickSort(arr, 0, n-1);
    out(arr,n); 
}