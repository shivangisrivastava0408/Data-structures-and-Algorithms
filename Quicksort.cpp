#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void qs(int arr[], int low, int high){
    if (low<high){
        int p=partition(arr, low, high);
        qs(arr, low, p-1);
        qs(arr, p+1, high);
    }
}

int main() {
	// your code goes here
	int arr[]={44,77, 44, 2, 112, 444};
	qs(arr, 0, 5);
	for(int i=0;i<6;i++) cout<<arr[i]<<" ";
	return 0;
}
