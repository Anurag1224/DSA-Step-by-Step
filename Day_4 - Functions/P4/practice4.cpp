// Functions to print sum of digits of a number N

#include<iostream>
using namespace std;

int sumOfDigit(int num){
    int digitSum=0;
    while(num>0){
        int lastDigit = num%10;
        num = num/10;
        digitSum+=lastDigit;
    }

    return digitSum;
}

int main(){
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    cout<<"Sum of digits of a number "<< n << " is "<<sumOfDigit(n);
    return 0;
}