#include <iostream>

using namespace std;

int main(){
    int seg, min, hor;

    cin >> seg;

    min = seg / 60;
    seg = seg % 60;

    hor = min / 60; 
    min = min % 60;

    cout << hor << ":" << min << ":" << seg << endl;

    return 0;
}