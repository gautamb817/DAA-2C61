#include<iostream>
using namespace std;

int index(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[high]=arr[i+1];
    arr[i+1]=pivot;
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int i=index(arr,low,high);
        quicksort(arr,low,i-1);
        quicksort(arr,i+1,high);
    }
}
int main(){
    int arr[]={4,2,6,9,2};
    int len=sizeof(arr)/sizeof(arr[0])-1;
    quicksort(arr,0,len);
    for(int i=0;i<=len;i++){
        cout<<arr[i]<<" ";
    }
}