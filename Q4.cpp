#include<iostream>
using namespace std;
int maxsum(int arr[],int sum,int len){
    int curr=0;
    for(int i=0;i<len;i++){
        if(curr<0){
            curr=0;
        }
        curr+=arr[i];
        sum=sum>curr?sum:curr;
    }
    return sum;

}
int main(){
    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int len=sizeof(arr)/sizeof(arr[0]);
    int sum=arr[0];
    int ms=maxsum(arr,sum,len);
    cout <<ms;
}