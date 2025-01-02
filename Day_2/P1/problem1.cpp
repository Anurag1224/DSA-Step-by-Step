// Sum of numbers from 1 to n using for loop

#include<iostream>
using namespace std;

int main(){

    int n, sum=0;
    cout<<"Enter the last number n ";
    cin>>n;
    for(int i=1; i<=n; i++ ){
        sum +=i; 
        if(i==5){
            break;      // it will break the loop if i becomes 5. Though the value of n will be > than 5 
        }
    }
    cout<<"Sum = "<<sum;
    return 0;
}

