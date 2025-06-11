#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int>leftArr(n1),rightArr(n2);
    for(int i=0;i<n1;i++){
        leftArr[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        rightArr[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(leftArr[i]<rightArr[j]){
            arr[k]=leftArr[i];
            i++;
        }
        else{
            arr[k]=rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=leftArr[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=rightArr[j];
        j++;k++;
    }
}
void mergeSort(vector<int>&arr,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int maxCrossingSum(int arr[],int left,int mid,int right){
    int leftSum=INT_MIN,rightSum=INT_MIN,sum=0;
    for(int i=mid;i>=left;i--){
        sum+=arr[i];
        if(sum>leftSum){
            leftSum=sum;
        }
    }
    sum=0;
    for(int i=mid+1;i<=right;i++){
        sum+=arr[i];
        if(sum>rightSum){
            rightSum=sum;
        }
    }
    return leftSum+rightSum;
}
int maxSubarraySum(int arr[],int left,int right){
    if(left==right)
    return left;
    int mid=(left+right)/2;
    int leftMax=maxSubarraySum(arr,left,mid);
    int rightMax=maxSubarraySum(arr,mid+1,right);
    int crossMax=maxCrossingSum(arr,left,mid,right);
    return max(leftMax,max(rightMax,crossMax));
}
int main(){
    int arrr[] = {2, -4, 3, -1, 2, 7, -5, 6};
    int n = sizeof(arrr) / sizeof(arrr[0]);
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arrr, 0, n - 1) << endl;
    vector<int> arr={32,12,1,2,43,7};
    mergeSort(arr,0,5);
    cout<<"sorted list: ";printArray(arr);
    return 0;
}