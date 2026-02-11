#include<iostream>
using namespace std;

void printArray(int arr[], int size){

    cout<<"printing the array"<<endl;
    for(int i = 0;i<size; i++){
    cout<<arr[i]<<" ";
    }
    cout<<"printing done"<<endl;

}

int main(){
    int third[15]= {2,7};
    //printArray(third,12);

    int thirdsize = sizeof(third)/sizeof(int); // sizeof memory ne jitny space li bite mai into its boxes deta hai
 
    // cout<<thirdsize<<endl;

    // int v = 8;
    // cout<<sizeof(int)<<endl;


    char ch[5] = {'a' , 'b' , 'c' , 'd'};

   cout<< ch[7]<< endl; //kuch nhi dega
   cout<< ch[3]<< endl;

    // printArray(third, 15);: This calls the printArray function and passes the array third along with its size (15) to it.


}
