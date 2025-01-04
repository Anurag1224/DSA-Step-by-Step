// WAF to check if a number is prime or not.

#include<iostream>
using namespace std;

bool isPrime(int N){
    for(int i=2; i*i<N; i++){
        if(N%i == 0){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    int n;
    cout<<"Enter a number ";
    cin>>n;
    cout<<isPrime(n);
    return 0;
}