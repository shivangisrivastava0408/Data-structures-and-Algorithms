#include <bits/stdc++.h>
using namespace std;

void merge(long long int arr[], int l, int r, int mid, long long int &ans){
    long long int n1,n2;
    n1=mid-l+1;
    n2=r-mid;
    long long int arr1[n1],arr2[n2];
    long long int i,j;
    for(i=0;i<n1;i++)
        arr1[i]=arr[l+i];
    for(i=0;i<n2;i++)
        arr2[i]=arr[mid+1+i];
    i=0,j=0;
    long long int k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            ans+=n1-i;
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void mergesort(long long int arr[], int l, int r, long long int &ans){
    if(l<r){
        long long int mid = l+(r-l)/2;
        mergesort(arr,l,mid,ans);
        mergesort(arr,mid+1,r,ans);
        merge(arr,l,r, mid,ans);
    }
}

int main() {
    long long int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
            cin>>arr[i];
        long long int ans=0;
        mergesort(arr,0,n-1,ans);
        cout<<ans<<endl;
    }
	return 0;
}
