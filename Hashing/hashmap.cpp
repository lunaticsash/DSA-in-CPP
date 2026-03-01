#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //Creation
    map <string,int> m;

    //insertion
    pair<string, int> p = make_pair("Pranjal", 3);
    m.insert(p);

    pair<string, int> ok("Kumar", 2);
    m.insert(ok);

    m["mera"] = 4;
    m["mera"] = 5;

    cout<<m.at("Pranjal")<<endl;
    cout<<m["Kumar"]<<endl;
    cout<<m["mera"]<<endl;//5 since updated
    
    // cout<<m.at("unknown")<<endl;// rokega yaha se fir neeche ka code execute hone se
    cout<<m["unknown"]<<endl;// ye direct 0 se kr dega map
    cout<<m.at("unknown")<<endl;// ye direct 0 se kr dega map
    cout<<m["unknownok"]<<endl;// ye direct 0 se kr dega map
    //size
    cout<<m.size()<<endl; 
    //to check
    cout<<m.count("bro")<<endl; //0
    cout<<m.count("Pranjal")<<endl; //1

    //erase or deletion
    m.erase("Pranjal");
    cout<<m.size()<<endl;//4

    // //to access el and key
    // for(auto i: m){
    //     cout <<i.first<<" "<<i.second<<endl;
    // }

    //Iterator se traversing
    // unordered_map<string, int> :: iterator it = m.begin();

    // while(it != m.end()){
    //     cout<<it->first <<" "<<it->second<<endl;
    //     it++; 
    // }

    map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first <<" "<<it->second<<endl;
        it++; 
    }

 

    return 0;
}