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

/*
    We divide the array into two halves, leftarr and rightarr.
    we recursively find the majority element of leftarr and rightarr 
    and set lmajor=<majority element of left array>
    and set rmajor=<majority element of right array>
    and we count the occurences of lmajor and rmajor in O(n)
    if both are equal then the answer is lmajor or rmajor (not make a much difference)
    if(lmajor>n/2) then the answer is lmajor
    if(rmajor>n/2) then the answer is rmajor
    so T(n) = 2*(T(n/2)) + 2*n
    ==> T(n) = O(n*log(n))
*/

int majorityElement(int arr[], int n)
{
    if(n==0) return -1;                             /*   If number of elements are zero, we have no majority elements*/
    if(n==1) return arr[0];                         /*   If number of elements are one, then first element is the majority element*/
    int m=n/2;                                      /*   number of elements in left subarrary */
    int larr[m];                                    /*   left subarray*/
    int rarr[n-m];                                  /*   right subarray */
    for(int i=0;i<m;i++) larr[i]=arr[i];
    for(int i=m;i<n;i++) rarr[i-m]=arr[i];
    int lmajor = majorityElement(larr, m);          /*   majority element of left subarray*/
    int rmajor = majorityElement(rarr,n-m);         /*   majority element of right subarray  */
    if(lmajor==rmajor) return lmajor;               /*   if both are equal then we can print any one of them*/
    int cnta=0;                                        
    int cntb=0;
    f(i,n){ 
        if(arr[i]==lmajor) cnta++;
        if(arr[i]==rmajor) cntb++;
    }
    if(cnta>n/2) return lmajor;                     /*   if frequency of both of them are not equal then we print the element having frequency  */
    if(cntb>n/2) return rmajor;                     /*   higher then n/2. Also both of them can't have frequency>n/2 at the same time */
    return -1;                                      /*   as total number of elements is n. */
}


int32_t main()
{
    int n; cin>>n;                                  /*   take input n, the number of elements in the array */
    int arr[n]; input(arr,n);                       /*   the array itself   */ 
    int ans = majorityElement(arr, n);              /*   find majority element using the function.     */
    if(ans==-1){
        cout<<"No majority element"<<endl;return 0; /*   if it turns out to be -1, it means we don't have any majority element.     */
    }
    cout<<"Majority element = "<<ans<<endl;return 0;/*   output the majority element.   */
}