/* 
Program to find the second larget number in an array 
*/

#include <iostream>
#include<climits>
using namespace std;

int secondLargest(int *a, int n)
{
    int largest = INT_MIN;
    int second = INT_MIN;
    for(int i = 0; i< n; i++)
    {
        if(a[i]>largest)
        {
            second = largest;
            largest = a[i];
        }
        else if(a[i]>second)
            second = a[i];

    }
        
    return second;
}

int main(){
    int a[] = {5,2,3,4,0,1};
    int n = 6;

    cout<<secondLargest(a, n)<<endl;

}