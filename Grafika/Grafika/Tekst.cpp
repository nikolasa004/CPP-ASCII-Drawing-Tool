#include "Tekst.h"
using namespace std;
#include<cmath>
#include<iostream>

vector<Tacka> Tekst::vratiTacke() const
{
	vector<Tacka>tacke;

	int duzina = tekst.length();
	if (pravac=="gd" || pravac=="dg")
	{
		for (int i = 0; i <= duzina; i++)
		{
			if (pravac=="gd")
			{
				tacke.push_back(Tacka(x, y + i,string(1,tekst[i])));
			}
			else
			{
				tacke.push_back(Tacka(x, y - i, string(1,tekst[i])));
			}
		}
	}
	else if (pravac=="ld" || pravac=="dl")
	{
		for (int i = 0; i <= duzina; i++)
		{
			if (pravac=="ld")
			{
				tacke.push_back(Tacka(x + i, y,string(1,tekst[i])));
			}
			else
			{
				tacke.push_back(Tacka(x - i, y, string(1,tekst[i])));
			}
		}
	}
	else
	{
		for (int i = 0; i <= duzina; i++)
		{
			if (pravac=="ldgd")
			{
				tacke.push_back(Tacka(x + i, y + i, string(1,tekst[i])));
			}
			else if (pravac=="lddg")
			{
				tacke.push_back(Tacka(x + i, y - i,string(1,tekst[i])));
			}
			else if (pravac=="dlgd")
			{
				tacke.push_back(Tacka(x - i, y + i, string(1,tekst[i])));
			}
			else
			{
				tacke.push_back(Tacka(x - i, y - i, string(1,tekst[i])));
			}
		}
	}

	return tacke;
}

void Tekst::unosOblika()
{
	cout << "Krenite da unosite podatke, obavezni atributi imaju zvezdicu (*)" << endl;
	cout << "Ukoliko ne zelite da unosite vrednost za neki atribut, unesite /" << endl;

	string tekst;
	cout << "Unesite tekst*" << endl;
	cin.ignore();
	getline(cin, tekst);

	string pravac="lr";
	cout << "Unesite pravac teksta" << endl;
	cout<< "Moguci pravci su: ld(levo->desno), dl(desno->levo), gd(gore->dole), dg(dole->gore), ldgd(levo->desno;gore->dole), dlgd(desno->levo;gore->dole), lddg(levo->desno;dole->gore), dldg(desno->levo;dole->gore)" << endl;
	cin >> pravac;

	if (pravac != "ld" && pravac != "dl" && pravac != "gd" && pravac != "dg" && pravac != "ldgd" && pravac != "dlgd" && pravac != "lddg" && pravac != "dldg")
	{
		cout << "Pravac nije validan" << endl;
		return;
	}

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

	int x;
	cout << "Unesite x koordinatu*" << endl;
	try
	{
		cin >> x;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (x < 0 || x > 39)
	{
		cout << "X koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	int y;
	cout << "Unesite y koordinatu*" << endl;
	try
	{
		cin >> y;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (y < 0 || y > 39)
	{
		cout << "Y koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	//namestanje pravog x zbog koordinatnog sistema
	x *= 2;
	x += 1;

	//namestanje pravog y zbog koordinatnog sistema
	y += 1;

	this->nivo = nivoInt;
	this->x = x;
	this->y = y;
	this->tekst = tekst;
	this->pravac = pravac;
}