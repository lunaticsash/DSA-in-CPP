//REMOVE ALL OCCURANCE OF SUBSTRING

#include <iostream>
using namespace std;

string RemoveOcc(string s, string part){
    string s;
    getline(cin, s);
    string part;

    while(s.length() != 0 && s.find(part) < s.length() )   {//find first occurance nikalta hai and ques mai bola ki left most occ se chalu kro
       s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){

    string s;
    getline(cin, s);

    string part;
    cin >> part;

    cout << RemoveOcc(s, part) << endl;

    

    return 0;

}