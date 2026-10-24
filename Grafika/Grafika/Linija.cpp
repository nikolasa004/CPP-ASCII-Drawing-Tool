#include "Linija.h"
using namespace std;
#include<cmath>
#include<iostream>

vector<Tacka> Linija::vratiTacke() const
{
	vector<Tacka>tacke;

	if (x1 == x2)
	{
		int duzina=abs(y2-y1);

		for (int i = 0; i <= duzina; i++)
		{
			if (i == 0 || i == duzina)
			{
				if (y1 < y2)
				{
					if(!gumica)
						tacke.push_back(Tacka(x1, y1 + i, "+"));
					else
						tacke.push_back(Tacka(x1, y1 + i, " "));
				}
				else
				{
					if (!gumica)
						tacke.push_back(Tacka(x1, y1 - i, "+"));
					else
						tacke.push_back(Tacka(x1, y1 - i, " "));
				}
			}
			else if (y1 < y2)
			{
				if (!gumica)
					tacke.push_back(Tacka(x1, y1 + i, "|"));
				else
					tacke.push_back(Tacka(x1, y1 + i, " "));
			}
			else
			{
				if (!gumica)
					tacke.push_back(Tacka(x1, y1 - i, "|"));
				else
					tacke.push_back(Tacka(x1, y1 - i, " "));
			}
		}
	}
	else if (y1 == y2)
	{
		int duzina = abs(x2 - x1);

		for (int i = 0; i <= duzina; i++)
		{
			if (i == 0 || i == duzina)
			{
				if (x1 < x2)
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 + i, y1, "+"));
					else
						tacke.push_back(Tacka(x1 + i, y1, " "));
				}
				else
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 - i, y1, "+"));
					else
						tacke.push_back(Tacka(x1 - i, y1, " "));
				}
			}
			else if (x1 < x2)
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 + i, y1, "-"));
				else
					tacke.push_back(Tacka(x1 + i, y1, " "));
			}
			else
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 - i, y1, "-"));
				else
					tacke.push_back(Tacka(x1 - i, y1, " "));
			}
		}
	}
	else
	{
		int duzina = abs(y2 - y1);

		for (int i = 0; i <= duzina; i++)
		{
			if (i == 0 || i == duzina)
			{
				if (x1 < x2 && y1<y2)
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 + i, y1+i, "+"));
					else
						tacke.push_back(Tacka(x1 + i, y1+i, " "));
				}
				else if (x1<x2 && y1>y2)
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 + i, y1 - i, "+"));
					else
						tacke.push_back(Tacka(x1 + i, y1 - i, " "));
				}
				else if (x1 > x2 && y1 < y2)
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 - i, y1 + i, "+"));
					else
						tacke.push_back(Tacka(x1 - i, y1 + i, " "));
				}
				else
				{
					if (!gumica)
						tacke.push_back(Tacka(x1 - i, y1 - i, "+"));
					else
						tacke.push_back(Tacka(x1 - i, y1 - i, " "));
				}
			}
			else if (x1 < x2 && y1 < y2)
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 + i, y1 + i, "\\"));
				else
					tacke.push_back(Tacka(x1 + i, y1 + i, " "));
			}
			else if (x1 < x2 && y1 > y2)
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 + i, y1 - i, "/" ));
				else
					tacke.push_back(Tacka(x1 + i, y1 - i, " "));
			}
			else if (x1 > x2 && y1 < y2)
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 - i, y1 + i, "/" ));
				else
					tacke.push_back(Tacka(x1 - i, y1 + i, " "));
			}
			else
			{
				if (!gumica)
					tacke.push_back(Tacka(x1 - i, y1 - i, "\\"));
				else
					tacke.push_back(Tacka(x1 - i, y1 - i, " "));
			}
		}
	}

	return tacke;
}

void Linija::unosOblika()
{
	cout << "Krenite da unosite podatke, obavezni atributi imaju zvezdicu (*)" << endl;
	cout << "Ukoliko ne zelite da unosite vrednost za neki atribut, unesite /" << endl;
	cout<<"Ako unosite kosu liniju zbog odnosa velicina polja moguc je samo nagib gde y koordinata raste za 1 a x za 0.5"<<endl;
	cout<<"To znaci da ako unosite kosu liniju kod krajnje tacke y treba da je porastao duplo u odnosu na x"<<endl;
	cout<<"Primer: za pocetnu tacku (0,0) krajnja tacka moze biti (1,2) ili (2,4) itd., za pocetnu tacku (2,6) krajnja tacke moze biti (4,2) "<<endl;

	string nivo;
	int nivoInt = 0;
	cout << "Unesite nivo linije" << endl;
	cin >> nivo;

	if (nivo != "/")
	{
		try
		{
			nivoInt = stoi(nivo);

			if (nivoInt < 0)
			{
				cout << "Nivo mora biti veci od 0" << endl;
				return;
			}
		}
		catch (...)
		{
			cout << "Unos nije validan" << endl;
			return;
		}
	}

	int x1;
	cout << "Unesite x koordinatu pocetne tacke*" << endl;
	try
	{
		cin >> x1;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (x1 < 0 || x1 > 39)
	{
		cout << "X koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	int y1;
	cout << "Unesite y koordinatu pocetne tacke*" << endl;
	try
	{
		cin >> y1;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (y1 < 0 || y1 > 39)
	{
		cout << "Y koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	int x2;
	cout << "Unesite x koordinatu krajnje tacke*" << endl;
	try
	{
		cin >> x2;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (x2 < 0 || x2 > 39)
	{
		cout << "X koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	int y2;
	cout << "Unesite y koordinatu krajnje tacke*" << endl;
	try
	{
		cin >> y2;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (y2 < 0 || y2 > 39)
	{
		cout << "Y koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	if (x1!=x2 && y1!=y2 && 2 * abs(x2 - x1) != abs(y2 - y1))
	{
		cout << "Podaci nisu uneti pravilno, uneta je kosa linija gde y ne menja se duplo u odnosu na x" << endl;
		return;
	}

	//namestanje pravog x zbog koordinatnog sistema
	x1 *= 2;
	x1 += 1;
	x2 *= 2;
	x2 += 1;

	//namestanje pravog y zbog koordinatnog sistema
	y1 += 1;
	y2 += 1;

	this->nivo = nivoInt;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}