#include <iostream>
using namespace std;

int search1(int arr[], int low, int high, int x){
    if(low>high) return -1;
    if(low==high && arr[low]==x) return low;
    else if(low==high && arr[low]!=x) return -1;
    int mid=low+(high-low)/2;
    if(mid<high && arr[mid]==x && arr[mid]<arr[mid+1])
        return mid;
    if(x<arr[mid])
        return search1(arr,low,mid-1,x);
    if(x>=arr[mid])
        return search1(arr,mid+1,high,x);
}

int search2(int arr[], int low, int high, int x){
    if(low>high) return -1;
    if(low==high && arr[low]==x) return low;
    else if(low==high && arr[low]!=x) return -1;
    int mid=low+(high-low)/2;
    if(low<mid && arr[mid]==x && arr[mid-1]<arr[mid])
        return mid;
    if(x<=arr[mid])
        return search2(arr,low,mid-1,x);
    if(x>arr[mid])
        return search2(arr,mid+1,high,x);
}

int main() {
	int arr[]={1,2,3,4,5,5,5,5,5,5,6,7,7,7,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	int i=search1(arr,0,n-1,6);
	int j=search2(arr,0,n-1,6);
	cout<<j<<" "<<i;
	return 0;
}
