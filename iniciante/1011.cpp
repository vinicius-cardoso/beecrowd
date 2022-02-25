#include <iostream>
#include <iomanip>

#define PI 3.14159

using namespace std;

int main(){
    double raio, volume;

    cin >> raio;

    volume = (4.0/3) * PI * (raio * raio * raio);

    cout << "VOLUME = " << fixed << setprecision(3) << volume << endl;

    return 0;
}