#include <iostream>
#include <iomanip>

#define PI 3.14159

using namespace std;

int main(){
    double a, b, c;
    
    cin >> a >> b >> c;

    double triangulo = (a * c) / 2;
    double circulo = PI * (c * c);
    double trapezio = ((a + b) * c) / 2;
    double quadrado = b * b;
    double retangulo = a * b;

    cout << "TRIANGULO: " << fixed << setprecision(3) << triangulo << endl;
    cout << "CIRCULO: " << fixed << setprecision(3) << circulo << endl;
    cout << "TRAPEZIO: " << fixed << setprecision(3) << trapezio << endl;
    cout << "QUADRADO: " << fixed << setprecision(3) << quadrado << endl;
    cout << "RETANGULO: " << fixed << setprecision(3) << retangulo << endl;

    return 0;
}