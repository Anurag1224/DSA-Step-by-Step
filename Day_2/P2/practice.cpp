//Sum of numbers from 1 to n using while loop

#include<iostream>
using namespace std;

int main(){

    int i=1,n, sum = 0;
    cout<<"Enter the last number ";
    cin>>n;
    while(i<=n){
        sum+=i;
        i++;
    }
    cout<<"Sum = "<<sum;
    return 0;
}