//1. Write a program to implement Bubble Sort.
//2. Write a program to implement Insertion Sort.
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int j=1;j<n;j++){
        int didSwap=0;
        for(int i=0;i<n-j;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
                didSwap=1;
            }
        }
        if(didSwap==0){
            break;
        }
        cout<<"Runs"<<endl;
    }
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
            while(j>=0&&arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                j--;
                cout<<"Runs"<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //bubbleSort(arr,n);
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}