//function to find the sum and min of two numbers 

#include<iostream>
using namespace std;

int sum(int a, int b){
    return a+b ;
}

int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }

}

int main(){
    int a, b;
    cout<<"Enter two numbers "<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"Sum of two numbers is "<<sum(a,b)<<endl;
    cout<<"Minimum of two numbers is " <<min(a,b);
    return 0;
}