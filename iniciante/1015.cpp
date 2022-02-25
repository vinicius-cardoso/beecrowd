#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

typedef struct Ponto{
    float x;
    float y;
};

int main(){
    Ponto p1, p2;
    float d;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;

    d = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));

    cout << fixed << setprecision(4) << d << endl;

    return 0;
}