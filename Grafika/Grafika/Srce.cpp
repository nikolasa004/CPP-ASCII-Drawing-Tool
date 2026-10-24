#include "Srce.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<Tacka> Srce::vratiTacke() const
{
    std::vector<Tacka> tacke;

    std::string srceSablon[] = {
        "  **   **  ",
        " **** **** ",
        " ********* ",
        "  *******  ",
        "   *****   ",
        "    ***    ",
        "     *     "
    };

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (srceSablon[i][j] == '*') {
                tacke.push_back(Tacka(x + j, y + i, "*"));
            }
        }
    }

    return tacke;
}

void Srce::unosOblika()
{
    cout << "Unesite nivo srca" << endl;
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

    cout << "Unesite x koordinatu*" << endl;
    int x;
    try
    {
        cin >> x;
        if (x < 0 || x > 39)
        {
            cout<< "X koordinata mora biti izmedju 0 i 39" << endl;
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

    // namestanje koordinata
    this->x = x * 2 + 1;
    this->y = y + 1;
    this->nivo = nivoInt;
}
