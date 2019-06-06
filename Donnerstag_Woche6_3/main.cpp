#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Baum
{
public:
	int alter;
	double hoehe;
};


bool istKleiner(Baum baum1, Baum baum2)
{
	return baum1.hoehe < baum2.hoehe;
}

bool istJuenger(Baum baum1, Baum baum2)
{
	if (baum1.alter == baum2.alter)
	{
		return baum1.hoehe < baum2.hoehe;
	}

	return baum1.alter < baum1.alter;
}


bool operator<(Baum b1, Baum b2)
{
	return b1.alter < b2.alter;
}



int main()
{
	cout << "Programm zu Donnerstag Woche6 3" << endl << endl;

	vector<Baum> wald;


	Baum eiche;
	eiche.alter = 10;
	eiche.hoehe = 5.5;

	Baum linde;
	linde.alter = 20;
	linde.hoehe = 12.5;

	Baum weide;
	weide.alter = 5;
	weide.hoehe = 2.1;

	Baum erle;
	erle.alter = 15;
	erle.hoehe = 30.5;


	wald.push_back(eiche);
	wald.push_back(linde);
	wald.push_back(weide);
	wald.push_back(erle);

	for (int i = 0; i < wald.size(); i++)
	{
		cout << "Alter: " << wald[i].alter << "\t Hoehe: " << wald[i].hoehe << endl;
	}

	cout << endl;

	// Wald nach Hoehe sorieren , Verwendung eines Funktionszeigers
	sort(wald.begin(), wald.end(), &istKleiner);


	for (int i = 0; i < wald.size(); i++)
	{
		cout << "Alter: " << wald[i].alter << "\t Hoehe: " << wald[i].hoehe << endl;
	}

	cout << endl;


	// Wald nach Alter sorieren , Verwendung eines Funktionszeigers
	sort(wald.begin(), wald.end(), &istJuenger);

	bool(*funktionsZeiger)(Baum, Baum);
	funktionsZeiger = &istJuenger;

	sort(wald.begin(), wald.end(), funktionsZeiger);
	
	for (int i = 0; i < wald.size(); i++)
	{
		cout << "Alter: " << wald[i].alter << "\t Hoehe: " << wald[i].hoehe << endl;
	}

	cout << endl;

	Baum groessterBaum = *(max_element(wald.begin(), wald.end(), &istKleiner));

	
	// Sorrieren auch ohne Ververgleichsfunktion, funktioniert, weil der < Operator für die Baumklasse überladen wurde
	sort(wald.begin(), wald.end());

	system("pause");
	return 0;
}