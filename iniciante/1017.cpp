#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int t, v;
    float d, consumo;

    cin >> t;
    cin >> v;

    d = v * t;
    consumo = d / 12;

    cout << fixed << setprecision(3) << consumo << endl;

    return 0;
}