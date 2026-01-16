#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int n=mid-low+1;
    int m=high-mid;
    int *arr1=new int[n];
    int *arr2=new int[m];
    for(int i=0;i<n;i++){
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<m;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr[k++]=arr1[i++];
    }
    while(j<m){
        arr[k++]=arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[6]={12,11,13,5,6,7};
    mergesort(arr,0,5);
    for(int i=0;i<6;i++){
        cout << arr[i]<< " ";
    }
    cout<<endl;
    int arr2[]={38,27,43,3,9,82,10};
    int index=sizeof(arr2)/sizeof(arr[0])-1;
    mergesort(arr2,0,index);
    for(int i=0;i<index;i++){
        cout << arr2[i]<<" ";
    }
}
