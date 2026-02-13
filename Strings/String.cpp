#include <iostream>
#include <cstring>
using namespace std;


int main(){
    char name[20] = {'P', 'r', 'a', '\0', 'n', 'j', 'a', 'l', '\0'};
    cout << name << endl;
    cout << "The length of the string is: " << strlen(name) << endl;
    string str = {'P', 'r', 'a', '\0', 'n', 'j', 'a', 'l', '\0'};
    cout << "The string is: " << str << endl;
    cout << "The length of the string is: " << str.length() << endl;
}