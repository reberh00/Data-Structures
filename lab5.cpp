//razlika datuma

#include<iostream>


using namespace std;

class Datum {
private:
	int dan=0, mjesec=0, godina=0;

public:
	Datum() = default;

	Datum(int dan, int mjesec, int godina) {
		this->dan = dan;
		this->mjesec = mjesec;
		this->godina = godina;
	}

	void setDan(int dan) {
		if (dan < 1 || dan>30)
			cout << "Nepostojeci dan" << endl;
		else
			this->dan = dan;
	}

	void setMjesec(int mjesec) {
		if (mjesec < 1 || mjesec>12)
			cout << "Nepostojeci mjesec" << endl;
		else
			this->mjesec = mjesec;
	}

	void setGodina(int godina) {

		this->godina = godina;
	}

	int getDan() {
		return dan;
	}

	int getMjesec() {
		return mjesec;
	}

	int getGodina() {
		return godina;
	}

	void izracunajRazliku(Datum d2) {
		int dani1, dani2, dd, mm, gg;

		dani1 = dan + (mjesec * 30) + (godina * 360);

		dani2 = d2.getDan() + (d2.getMjesec() * 30) + (d2.getGodina() * 360);

		gg = abs(dani1 - dani2) / 360;

		mm = (abs(dani1 - dani2) - gg * 360) / 30;

		dd = (abs(dani1 - dani2) - (gg * 360) - (mm * 30));

		cout << "razlika je u " << dd << " dana, " << mm << " mjeseci " << gg << " godina " << endl;

	}

	int usporedi(Datum d2) {
		int dani1, dani2, dd, mm, gg;

		dani1 = dan + (mjesec * 30) + (godina * 360);

		dani2 = d2.getDan() + (d2.getMjesec() * 30) + (d2.getGodina() * 360);

		if ((dani1 - dani2) > 0) {
			cout << "Prvi datum je veci"<<endl;
				return -1;
		}

		else if ((dani1 - dani2) < 0) {
			cout << "Drugi datum je veci"<<endl;
				return 1;
		}
		else {
			cout << "Datumi su isti"<<endl;
			return 0;
		}
	}

};



int main() {
	int d, mj, gd;
	Datum datum[2];

	for (int i = 0; i < 2; i++) {

		cout << "Datum " << i + 1 << " : " << endl;

		cout << "Unesi dan: " << endl;
		cin >> d;
		datum[i].setDan(d);

		cout << "Unesi mjesec: " << endl;
		cin >> mj;
		datum[i].setMjesec(mj);

		cout << "Unesi godinu: " << endl;
		cin >> gd;
		datum[i].setGodina(gd);

	}
	if(datum[0].usporedi(datum[1])!=0)
	datum[0].izracunajRazliku(datum[1]);
		

	return 0;
}