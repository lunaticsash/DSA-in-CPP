#include <iostream>

using namespace std;

int po(int a, int b)
{

    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    
    return ans; // ans integer hi hona chaiye kyunki  a aur b integer hi honge

}

int main()
{
    int x,y;
    cin >> x >> y;
    
    int answer= po(x, y);
    cout<<"answer is "<< answer<<endl;

    return 0;
}