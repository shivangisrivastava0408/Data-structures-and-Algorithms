#include <iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if (l<r){
        int m=l+(r-l)/2;
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        Merge(arr, l, m, r);
    }
}

int main() {
	// your code goes here
	int arr[]={99,33,55,66,88,22,99,34,26};
	MergeSort(arr,0,8);
	for(int i=0;i<9;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
