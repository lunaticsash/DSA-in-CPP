#include <iostream>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch  - 'A'+ 'a';
        return temp;
    }
}
// char toLowerCase(char ch){
//     if(ch >= 'A' && ch <= 'Z'){
//         return ch + 32;
//     }
//     return ch;
// }

bool palindrome(char a[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(toLowerCase(a[s]) != toLowerCase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(name[s], name[e]);
        s++;
        e--;
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        // cout<<name[i];//for printing name
        count++;
    }
    return count;
}

int main()
{
    char name[20];

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Your name is ";
    cout << name << endl;

    int len = getLength(name);

    cout << "length : " << len << endl;

    reverse(name, len);
    cout << "Reversed name is " << name << endl;

    cout<<"Palindrome or not : "<<palindrome(name, len)<<endl;

    cout<<"Character is "<< toLowerCase('b')<<endl;
    cout<<"Character is "<< toLowerCase('C')<<endl;

    return 0;
}