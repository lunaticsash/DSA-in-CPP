#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        cout << min({
            abs(a-b),abs(b-c),
            abs(a-c)
        }) <<'\n';
    }
    
    return 0;
}