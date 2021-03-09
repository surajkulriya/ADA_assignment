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
    Find the element that has the highest probability of being a majority element.
    If there is a majority element i.e. a element occurs more then n/2 times,
    there must be at least one instance where two ajacent elements will have same value(that's equal to majority element)
    If there are multiple elements that have the possibily of being a majority element,
    we form an array of them and find the `candidate element`(element having highest possibility of being a majority element)
    recursively.
    T(n) = T(n/2) + n/2
    ==>T(n) = O(n)
*/
int findCandidate(vector<int>arr, int n)
{
    if(n==1) return arr[0];                                 /*  if number of elements in the array is one, this is a majority element*/
    vector<int> next;                                       /*  the array of elements that could be the majority elements   */
    for(int i=0;i<n-1;i+=2){
        if(arr[i]==arr[i+1]) next.push_back(arr[i]);        /*  if two adjacent elements are equal, they could be majority element*/
    }
    if(n&1) next.push_back(arr[n-1]);                       /*  if number of elements in array are odd, insert last element in the next array*/
    return findCandidate(next,next.size());                 /*  among the array of possible majority elements, return the element having 
                                                                highest possibility of being a majority element */
}

int32_t main()
{

    int n; cin>>n;                                          /*  number of elements in the array */ 
    vector<int> arr(n); input(arr,n);                       /*  the array itself */
    int possibelAns=findCandidate(arr,n);                   /*  find the element that could be the majority element */
    int cnt=0;
    f(i,n) cnt+=(arr[i]==possibelAns);                      /*  check whethe the candidate element is actually a majority element or not*/
    if(cnt>n/2)
    {
        cout<<"Majority element = "<<possibelAns<<endl;     /*  output majority element */
        return 0;
    }
    cout<<"No majority element"<<endl;                      /*  majority element not found  */
}