#include<iostream>
using namespace std;

int main () {
    
    float a=0,b=0;
    char operation=' ';
    cout<<"This is a calculator"<<endl;
    cout<<"Enter two numbers "<< "a = ";
    cin>>a;
    cout<<"b = ";
    cin>> b;
    cout<<"Enter the operation you want to perform [ + , - , * , / ]";
    cin>>operation;

    switch(operation){
        case '+' :
            cout<<"Addition of " <<a<<" and "<< b <<" is "<< a+b;
            break;
        case '-' :
            cout<<"Subtraction of " <<a<<" and "<< b <<" is "<< a-b;
            break;
        case '*' :
            cout<<"Multiplication of " <<a<<" and "<< b <<" is "<< a*b;
            break;
        case '/' :
            cout<<"Division of " <<a<<" and "<< b <<" is "<< a/b;
            break;
        default:
            cout<<"Invalid Input";
    }
return 0 ;
}