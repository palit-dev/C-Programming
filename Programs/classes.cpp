// Program to check whether a number is Palindrome or not
#include <iostream>
#include <cstdio>
using namespace std;

class Number{
    private:
        long f;

    public:
        Number(long number){
            f = number;
        }
        

        bool isPalindrome()
        {
            char number[40];
            int length;
            // Convert the number into string
            sprintf(number, "%ld", f);
            for(length = 0; number[length]!='\0'; length++);
            for(int i = 0, j = length -1; number[i]!='\0'; i++, j--)
                if(number[i]!=number[j])
                    return false;
            return true;
        }
};

int main(){
    long f;
    cout<<"Enter number:\t";
    cin>>f;

    Number n(f);
    cout<<n.isPalindrome()<<endl;
    return 0;

}
