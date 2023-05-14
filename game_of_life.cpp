#include "game_of_life.h"
#include <iostream>
#include <ctime>


game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	return(rand() % 4 == 0);
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 or i >= REDAKA or j < 0 or j >= STUPACA)
	{
		return false;
	}
	return _generacija[i][j];
}

void game_of_life::sljedeca_generacija()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			int susjedi = 0;
			susjedi += celija_zauzeta(i - 1, j - 1);
			susjedi += celija_zauzeta(i - 1, j);
			susjedi += celija_zauzeta(i - 1, j + 1);
			susjedi += celija_zauzeta(i, j - 1);
			susjedi += celija_zauzeta(i, j + 1);
			susjedi += celija_zauzeta(i + 1, j - 1);
			susjedi += celija_zauzeta(i + 1, j);
			susjedi += celija_zauzeta(i + 1, j + 1);

			if (_generacija[i][j])
			{
				if (susjedi == 2 or susjedi == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
			else
			{
				if (susjedi == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
		}
	}
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
				cout << "_";
		}
		cout << endl;
	}
}
