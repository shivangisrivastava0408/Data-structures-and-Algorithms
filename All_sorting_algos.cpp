#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void  selectionsort(int arr[], int n){
    int min_ind;
    for(int i=0;i<n-1;i++){
        min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i])
                min_ind=j;
        }
        swap(arr[i],arr[min_ind]);
    }
}

void insertionsort(int arr[], int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[], int l, int r, int mid){
    int n1,n2;
    n1=mid-l+1;
    n2=r-mid;
    int arr1[n1],arr2[n2];
    int i,j;
    for(i=0;i<n1;i++)
        arr1[i]=arr[l+i];
    for(i=0;i<n2;i++)
        arr2[i]=arr[mid+1+i];
    i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
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

void mergesort(int arr[], int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r, mid);
    }
}

int partition(int arr[], int low, int high){
    //ELEMENT AT THE LAST INDEX IS CHOSEN AS PIVOT
    /*int pivot=arr[high];
    int j=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            j+=1;
            swap(arr[i],arr[j]);
        }
    }
    j+=1;
    swap(arr[j],arr[high]);
    return j;*/
    
    //ELEMENT AT THE FIRST INDEX IS CHOSEN AS PIVOT
    int pivot=arr[low];
    int j=low+1;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[j]);
            j+=1;
        }
    }
    j-=1;
    swap(arr[j],arr[low]);
    return j;
}

void quicksort(int arr[], int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

void heapify(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[largest]<arr[l]){
        largest=l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

void printarr(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
	int arr0[] = {55,44,3,2,12,65,77,48,37,56};
	int n = sizeof(arr0)/sizeof(arr0[0]);
	bubblesort(arr0,n);
	printarr(arr0,n);
	int arr1[] = {88,77,66,55,44,33,22,11,1};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	selectionsort(arr1, m);
	printarr(arr1,m);
	int arr2[] = {30,27,24,21,18,15,12,9,6,3,1};
	int p = sizeof(arr2)/sizeof(arr2[0]);
	insertionsort(arr2,p);
	printarr(arr2,p);
	int arr3[] = {40,36,32,28,24,20,16,12,8,4,1};
	int q = sizeof(arr3)/sizeof(arr3[0]);
	mergesort(arr3,0,q-1);
	printarr(arr3,q);
	int arr4[] = {50,45,30,35,30,25,20,15,10,5,1};
	int r = sizeof(arr4)/sizeof(arr4[0]);
	quicksort(arr4,0,r-1);
	printarr(arr4,r);
	int arr5[] = {12,11,13,5,6,7};
	int s = sizeof(arr5)/sizeof(arr5[0]);
	heapsort(arr5,s);
	printarr(arr5,s);
	return 0;
}
