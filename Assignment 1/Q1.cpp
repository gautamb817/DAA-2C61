#include<iostream>
using namespace std;

int binarysearch(int arr[],int length,int target){
    int low=0;
    int high=length;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int target=237;
    int length=sizeof(arr)/sizeof(arr[0]);
    int found=binarysearch(arr,length,target);
    if(found<0){
        cout<< "not found!!"<< endl;
    }
    else{
        cout << "found at "<<found<<"th index"<<endl;
    }
}
