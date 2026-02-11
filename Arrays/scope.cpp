#include <iostream>
using namespace std;

void update(int arr[], int n)
{

    cout << "inside the functuon" << endl;

    // updating arrays first element;
    arr[0] = 120; // address liya hai cz arr address hota first ka to jab yaha change hoga to original value mai bhi update hoga.
    // printing the array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "going back to main fucntion" << endl;
}

int main()
{

    int arr[3] = {1, 2, 3};

    update(arr, 3);

    // printing the array

    cout << "Printing in main fucntion" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}