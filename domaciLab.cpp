/*Napisati klasu koja predstavlja kompleksni broj.
Klasa ima privatne podatke i gettere i settere.
Napisati funkcije za zbrajanje, oduzimanje,
množenje i dijeljenje kompleksnih brojeva.
Funkcije kao rezultat vraćaju kompleksni broj.
Zatražiti od korisnika unos dva kompleksna broja.
Izračunati zbroj, razliku, produkt i kvocijent.
*/

#include <iostream>

using namespace std;

class ComplexNum {

private:
    double real_part;
    double imaginary_part;

public:
    ComplexNum(double real_part, double imaginary_part) {
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    void setReal(double real_part) {
        this->real_part = real_part;
    }

    double getReal() {
        return real_part;
    }

    void setImaginary(double imaginary_part) {
        this->imaginary_part = imaginary_part;
    }

    double getImaginary() {
        return imaginary_part;
    }

    ComplexNum add(ComplexNum complexNum2) {
        double real_part = this->real_part + complexNum2.real_part;
        double imaginary_part = this->imaginary_part + complexNum2.imaginary_part;
        return ComplexNum(real_part, imaginary_part);
    }

    ComplexNum subtract(ComplexNum complexNum2) {
        double real_part = this->real_part - complexNum2.real_part;
        double imaginary_part = this->imaginary_part - complexNum2.imaginary_part;
        return ComplexNum(real_part, imaginary_part);
    }

    ComplexNum multiply(ComplexNum complexNum2) {
        double real_part = (this->real_part * complexNum2.real_part) - (this->imaginary_part * complexNum2.imaginary_part);
        double imaginary_part = (this->real_part * complexNum2.imaginary_part) + (this->imaginary_part * complexNum2.real_part);
        return ComplexNum(real_part, imaginary_part);
    }

    ComplexNum divide(ComplexNum complexNum2) {
        double denominator = (complexNum2.real_part * complexNum2.real_part) + (complexNum2.imaginary_part * complexNum2.imaginary_part);
        double real_part = ((this->real_part * complexNum2.real_part) + (this->imaginary_part * complexNum2.imaginary_part)) / denominator;
        double imaginary_part = ((this->imaginary_part * complexNum2.real_part) - (this->real_part * complexNum2.imaginary_part)) / denominator;
        return ComplexNum(real_part, imaginary_part);
    }

};

int main()
{
    double real_part1, imaginary_part1, real_part2, imaginary_part2;



    cout << "Unesi realni dio prvog kompleksnog broja" << endl;
    cin >> real_part1;
    cout << "Unesi imaginarni dio prvog kompleksnog broja" << endl;
    cin >> imaginary_part1;
    cout << "Unesi realni dio drugog kompleksnog broja" << endl;
    cin >> real_part2;
    cout << "Unesi imaginarni dio drugog kompleksnog broja" << endl;
    cin >> imaginary_part2;

    ComplexNum complexNum1(real_part1, imaginary_part1);
    ComplexNum complexNum2(real_part2, imaginary_part2);

    ComplexNum addition = complexNum1.add(complexNum2);
    cout << "Zbroj dva kompleksna broja je: " << addition.getReal() << " + " << addition.getImaginary() << "i" << endl;

    ComplexNum subtraction = complexNum1.subtract(complexNum2);
    cout << "Razlika dva kompleksna broja je: " << subtraction.getReal() << " + " << subtraction.getImaginary() << "i" << endl;

    ComplexNum multiplication = complexNum1.multiply(complexNum2);
    cout << "Umnozak dva kompleksna broja je: " << multiplication.getReal() << " + " << multiplication.getImaginary() << "i" << endl;

    ComplexNum division = complexNum1.divide(complexNum2);
    cout << "Rezultat dijeljenja dva kompleksna broja je: " << division.getReal() << " + " << division.getImaginary() << "i" << endl;

    return 0;
}
