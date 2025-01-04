// WAF to print all prime numbers from 1 to n.

#include<iostream>
using namespace std;

string isPrime(int N){
    for(int i=2; i*i<=N; i++){
        if(N%i == 0){
            return "Non prime";
        }
    }
    return "Prime";
   
}

int main(){
    int n;
    cout<<"Enter a number ";
    cin>>n;
    cout<<isPrime(n);
    return 0;
}