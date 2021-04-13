#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int N =1000000;

pair<int,int> tree[N];
int compare[N];
// tree[i].second = min_element at id
// compare[i] = the element with which tree[i].first was compared to


// build the binary tree recursively
void build(int arr[],int id, int l, int r)
{
    if(l>r) return;
    if(l==r){                                                   /*  If we reach the index of the array, assign it's value to corresponding node */
        compare[id]=INT_MAX;
        tree[id].first=arr[l];
        tree[id].second=-1;
        return;
    }
    int m=(l+r)/2;  // middle index
    build(arr,id*2+1,l,m);                                      /*  Build left subtree recursively  */
    build(arr,id*2+2,m+1,r);                                    /*  Build right subtree recursively */
    if(tree[id*2+1].first>tree[id*2+2].first){                  /*  Assign min(left,right) to the node  */
        tree[id].first=tree[id*2+2].first;
        compare[id]=tree[id*2+1].first;
        tree[id].second=2;
        return;
    }
    tree[id].first=tree[id*2+1].first;
    tree[id].second=1;
    compare[id]=tree[id*2+2].first;
    return;
}

// traverse along the path of min element
// and compute second min element
int secondmin(int id, int l, int r, int ans)                    /*  Since max height of tree is log(n), we need log(n) steps for computing */
{                                                               /*  second minimum element*/
    if(l==r){
        return ans;
    }
    int m=(l+r)/2;
    if(tree[id].second==1){
        if(compare[id]<ans) ans=compare[id];
        return secondmin(id*2+1,l,m,ans);
    }
    return secondmin(id*2+2,m+1,r,ans);
}

int main()
{
    int n; cin>>n; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    build(arr,0,0,n-1);                                         /*  Build the tree in n stpes*/
    cout<<"min element = "<<tree[0].first<<" second min = "<<secondmin(0,0,n-1,100000)<<endl;
}

/*  
    Total stpes needed = n + log(n) 
    n steps for computing min element and building the tree
    and log n steps for traversing the tree with log(n) height.
*/