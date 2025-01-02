// Sum of all numbers from 1 to n which are divisible by 3

#include<iostream>
using namespace std;

int main(){

    int sum = 0,n;
    cout<<"Enter the valus of n ";
    cin>>n;

    for(int i = 1; i<=n; i++){
        if(i%3 == 0){
            sum+=i;
            cout<< i;
        }

    }
    cout<<"\nSum = "<<sum;

    return 0;
}