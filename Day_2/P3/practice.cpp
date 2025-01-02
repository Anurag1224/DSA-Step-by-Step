// Sum of all odd nos. from 1 to n

#include<iostream>
using namespace std;

int main() {
    
    int i, n , oddSum=0;
    cout<<"Enter the last number n ";
    cin>>n;
    for(i=1; i<=n; i++){
        if(i%2 != 0){
            oddSum+=i;
        }
    }
    cout<<"Sum = "<<oddSum;
    
    return 0;
}