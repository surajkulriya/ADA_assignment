#include <bits/stdc++.h>
using namespace std;

/*
    We divide the array into two equal halves, sort both of them recursively, and merge them in linear time to get sorted array.
    Therefore, T(n) = 2*T(n/2) + O(n)
    ==> T(n) = n*log(n)
*/
// mergeSort array from index l to index r(inclusive)
void mergeSort(int arr[], int l, int r)
{
    if(l>=r) return;                                                    /*  If left index is greater then right index, we got something wrong   */
    int m=(l+r)/2;                                                      /*  The middle index    */
    // make two new arrays of size n/2
    int* brr=(int*)malloc((r-m)*(sizeof(int)));                         /*  Left subarray   */
    int* crr=(int*)malloc((m-l+1)*(sizeof(int)));                       /*  Right subarray  */
    for(int i=0;i<=m;i++) crr[i]=arr[l+i];
    for(int i=m+1;i<=r;i++) brr[i-m-1]=arr[i];
    // sort both of them
    mergeSort(brr,0,r-m-1);                                             /*  Sort left subarray recursively  */
    mergeSort(crr,0,m-l);                                               /*  Sort right subarray recursively */
    int i=0; int j=0;
    int cnt=0;
    // merge two sorted arrays into original array
    while(i<r-m && j<m-l+1){                                            /*  Merge two sorted arrays to form a new sorted array  */
        if(brr[i]<=crr[j]){
            arr[cnt++]=brr[i++];
            continue;
        }
        arr[cnt++]=crr[j++];
    }
    while(i<r-m) arr[cnt++]=brr[i++];                                   /*  Put remaning elements back in the array */
    while(j<m-l+1) arr[cnt++]=crr[j++];

}

int main()
{
    int n; cin>>n;                                                      /*  Take input n, the number of elements in the array   */
    int arr[n];for(int i=0;i<n;i++) cin>>arr[i];                        /*  Take input the array    */
    mergeSort(arr,0,n-1);                                               /*  Sort it recursively */
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";                             /*  Output  */
    cout<<endl;
}