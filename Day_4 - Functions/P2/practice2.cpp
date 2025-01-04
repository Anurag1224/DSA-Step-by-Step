// Function to print the sum of nos. from 1 to N 

#include<iostream>
using namespace std;

int sum(int a){
    int s = 0;
    for(int i = 1; i<=a; i++){
        s+=i;
    }
    return s;
}

int main(){
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    cout<<"Sum of numbers from "<<1<<" to "<< n << " is "<<sum(n);
    return 0;
}