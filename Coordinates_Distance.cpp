
#include <iostream>
#include<math.h>

using namespace std;

class Tocka {

private:
    double x;
    double y;

public:
    Tocka() {
        setX(0);
        setY(0);
    }
    Tocka(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void setX(double x) {
        this->x = x;
    }

    double getX() {
        return x;
    }

    void setY(double y) {
        this->y = y;
    }

    double getY() {
        return y;
    }

    double udaljenost() {
        double distance = sqrt(x * x + y * y);

        return distance;
    }
    void ispis(double udaljenost) {
        cout << "Udaljenost tocke (" << x << "," << y << ") od ishodista je " << udaljenost << endl;
    }

};

int main()
{
    double  x2, y2;
    double result = 0;
   
    cout << "Unesi x druge tocke" << endl;
    cin >> x2;
    cout << "Unesi y druge tocke" << endl;
    cin >> y2;

    Tocka tocka1;
    tocka1.setX(3);
    tocka1.setY(4);

    Tocka tocka2(x2, y2);

    result = tocka1.udaljenost();
    tocka1.ispis(result);
    
    result = tocka2.udaljenost();
    tocka2.ispis(result);

    return 0;
}
