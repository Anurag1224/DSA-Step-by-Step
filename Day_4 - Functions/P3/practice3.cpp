// Functions to print factorial N 

#include<iostream>
using namespace std;

int factN(int a){
    int fact = 1;
    for(int i = 1; i<=a; i++){
        fact*=i;
    }
    return fact;
}

int main(){
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    cout<<"factorial of "<< n << " is "<<factN(n);
    return 0;
}