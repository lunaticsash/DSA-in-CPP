#include<iostream>
using namespace std;

int main(){

    int am;
    cout<<"Enter the ammount ";
    cin>>am;

    int Rs100;
    int Rs50;
    int Rs20;
    int Rs1;

    switch(1){ // 1 means it is true for all so you have to enter in the swtch statement anyways.
        
        case 1:
        Rs100=am/100;
        am=am%100;
        cout<<"number of 100 notes "<<Rs100<<endl;
        

        case 2:
        Rs50=am/50;
        am=am%50;
        cout<<"number of 50 notes "<<Rs50<<endl;
        

        case 3:
        Rs20=am/20;
        am=am%20;
        cout<<"number of 20 notes "<<Rs20<<endl;
      

        case 4:
        Rs1=am/1;
        am=am%1;
        cout<<"number of 1 notes "<<Rs1<<endl;
        break;
     


    }
}