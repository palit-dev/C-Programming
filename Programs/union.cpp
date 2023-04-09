// Program to convert decimal into Binary representation
#include <iostream>
#include <cstdlib>
using namespace std;

typedef union Data{
    int i;
    float f;

} Data;

int main(){

    Data data;
    int INT_SIZE = sizeof(int)*8;

    int *binary = (int*)calloc(INT_SIZE, sizeof(int));
    cout<<"Enter a number:\t";
    cin>>data.f;

    cout<<"The entered floating data:\t"<<data.f<<endl;
    cout<<"The entered Integer data:\t"<<data.i<<endl;

    // Binary representation
    cout<<"The binary representation:\t";
    for(int i = INT_SIZE-1; i >= 0 ; i--, data.i >>=1)
        binary[i] = data.i & 1;

    for(int i = 0; i < INT_SIZE ; i++)
        cout<<binary[i];

    cout<<endl;
    delete binary;
    return 0;
}