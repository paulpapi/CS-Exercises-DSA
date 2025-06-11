#include<iostream>
using namespace std;
void bubblesort(int arr[],int size){
    bool swapped=false;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(swapped=false)
        break;
    }
}
void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int binarysearch(int arr[],int left,int right,int key){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    cout<<"enter five numbers to sort";
    int x[5];
    for(int i=0;i<5;i++){
        cin>>x[i];
    }
    insertionsort(x,5);
    cout<<"the sorted list: ";
    for(int i=0;i<5;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    return 0;
}