#include <iostream>
using namespace std;

int main(){

    // switch (expression)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }

    int num = 2 ; //mtlb case 2 pe land krega cz numb ki value vaha land kr rhi and then it will break as it is mentioned below

    cout<<endl;
    switch( num ) { //if else if ke jagah use hota hai for better understanding

        case 1: cout<<" first "<<endl;
                break;

        case 2 /*'1' for charachter*/: cout<< "second" <<endl;
        break;

        default: cout<< "it is default case"<<endl;

    }
}

// int main()
// {

//     int num = 1;
//     int ch = '1';

//     cout << endl;
//     switch (ch)
//     {

//     case 1:
//         cout << "first" << endl;
//         break;

//     case '1':
//         switch (num) //nested switch
//         {
//         case 1:
//             cout << "value of num is " << num<< endl;
//             break;
//         }
//         break;
//     default:
//         cout << "it is default case" << endl;
//     }
// }