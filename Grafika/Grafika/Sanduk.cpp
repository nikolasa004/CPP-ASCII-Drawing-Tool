#include "Sanduk.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<Tacka> Sanduk::vratiTacke() const
{
    std::vector<Tacka> tacke;

    std::string sandukSablon[] = {
        "    ********    ",
        "  *****  *****  ",
        " ******  ****** ",
        "***          ***",
        "*******  *******",
        " ******  ****** ",
        "  *****  *****  ",
        "   ****  ****   ",
        "    ********    ",
        "      ****      ",
        "       **       "
    };

    int visina = 11;
    int sirina = 16;

    for (int i = 0; i < visina; ++i) {
        for (int j = 0; j < sirina; ++j) {
            if (sandukSablon[i][j] == '*') {
                tacke.push_back(Tacka(x + j, y + i, "*"));
            }
        }
    }

    return tacke;
}

void Sanduk::unosOblika()
{
    cout << "Unesite nivo sanduka" << endl;
    string nivo;
    int nivoInt = 0;
    cin >> nivo;

    if (nivo != "/")
    {
        try
        {
            nivoInt = stoi(nivo);
            if (nivoInt < 0)
            {
                cout << "Nivo mora biti veci ili jednak 0" << endl;
                return;
            }
        }
        catch (...)
        {
            cout << "Unos nije validan" << endl;
            return;
        }
    }

    cout << "Unesite x koordinatu*" << endl;
    int x;
    try
    {
        cin >> x;
        if (x < 0 || x > 39)
        {
            cout << "X koordinata mora biti izmedju 0 i 39" << endl;
			return;
        }
    }
    catch (...)
    {
        cout << "Unos nije validan" << endl;
        return;
    }

    cout << "Unesite y koordinatu*" << endl;
    int y;
    try
    {
        cin >> y;
        if (y < 0 || y > 39)
        {
			cout << "Y koordinata mora biti izmedju 0 i 39" << endl;
			return;
		}
    }
    catch (...)
    {
        cout << "Unos nije validan" << endl;
        return;
    }

    this->x = x * 2 + 1;
    this->y = y + 1;
    this->nivo = nivoInt;
}
