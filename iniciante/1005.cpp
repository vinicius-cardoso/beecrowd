#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a, b, media;

    cin >> a;
    cin >> b;

    media = ((a * 3.5) + (b * 7.5)) / 11;

    cout << fixed << setprecision(5) << "MEDIA = " << media << endl;

    return 0;
}