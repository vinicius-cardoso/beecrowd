#include <iostream>
#include <iomanip>

#define PI 3.14159

using namespace std;

int main(){
    double r, area;

    cin >> r;

    area = PI * (r * r);

    cout << fixed << setprecision(4) << "A=" << area << endl;

    return 0;
}