#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

using namespace std;

//dice roll program including a "secret" gambling game

int main()
{
	srand(time(NULL));
	bool quit = false;
	int dice, roll, nRoll = 0;
	int rollHistory[100];
	int rollDiceHistory[100];

	cout << "Welcome to the dice rolling program! Type '0' to quit and '1' to show dice roll history." << endl;
	while (quit == false)
	{
		cout << "Size of dice(2-100): ";
		cin >> dice;

		//dice rolling
		if (dice > 1 && dice <= 100)
		{
			roll = rand() % dice + 1;
			cout << "You rolled: " << roll << endl;
			nRoll++;
			rollHistory[nRoll] = roll;
			rollDiceHistory[nRoll] = dice;

			//easter egg hint
			if (nRoll == 10)
			{
				cout << "Psst... type '101' to gamble against Bob..." << endl;
			}
		}

		//quit
		else if (dice == 0)
		{
			cout << "Goodbye! Thanks for rolling! :)";
			Sleep(1500);
			quit = true;
		}

		//dice roll history
		else if (dice == 1)
		{
			cout << "Dice roll history: " << endl;
			for (int i = 1; i <= nRoll; i++)
			{
				cout << "Roll " << i << ": " << rollHistory[i] << " (out of " << rollDiceHistory[i] << ")" << endl;
			}
		}

		//easter egg gamble
		else if (dice == 101)
		{
			string gamblerName;
			int bet, rounds = 1;
			bool gambling = true;
			cout << "Welcome to the gambling room! Please enter your name: ";
			cin >> gamblerName;
			cout << "Wow! That's an unlucky name... welp, good luck " << gamblerName << "!" << endl;
			Sleep(1000);
			cout << "Bob laughs at you from across the room... " << endl;
			Sleep(1000);
			cout << "The dealer hands you 100 chips" << endl;
			int chips = 100;
			int bobChips = 100;
			Sleep(1000);
			while (gambling == true)
			{
				if (chips >= 10 && bobChips >= 10)
				{
					cout << "Round " << rounds << "! Place your bets(10-" << chips << "):";
					cin >> bet;
					if (bet > 5 && bet <= chips)
					{
						int pot = bet * 2;
						chips = chips - bet;
						bobChips = bobChips - bet;
						cout << "You bet " << bet << " chips." << endl;
						Sleep(1000);
						cout << "Size of dice(2-100): ";
						cin >> dice;

						//dice rolling
						if (dice > 1 && dice <= 100)
						{
							rounds++;
							cout << "You roll the dice..." << endl;
							Sleep(1500);
							roll = rand() % dice + 1;
							cout << "You rolled: " << roll << endl;
							int yourRoll = roll;
							Sleep(1000);
							cout << "Bob rolls the dice..." << endl;
							Sleep(1500);
							roll = rand() % dice + 1;
							cout << "Bob rolled: " << roll << endl;
							int bobRoll = roll;
							Sleep(1000);
							if (yourRoll > bobRoll)
							{
								cout << "You won! You get " << pot << "chips." << endl;
								chips = chips + pot;
								Sleep(1000);
								cout << "You now have " << chips << "chips." << endl;
								cout << "Bob now has " << bobChips << "chips." << endl;
								Sleep(1000);
							}
							else
							{
								cout << "You lost! You lose " << bet << "chips." << endl;
								bobChips = bobChips + pot;
								Sleep(1000);
								cout << "You now have " << chips << "chips." << endl;
								cout << "Bob now has " << bobChips << "chips." << endl;
								Sleep(1000);
								cout << "Bob laughs at you from across the room..." << endl;
							}
						}
						else if (dice == 0)
						{
							cout << "See ya later! Thanks for gambling! :)";
							Sleep(2000);
							gambling = false;
						}
						else
						{
							cout << "Incorrect value!" << endl;
						}
					}
					else if (bet < 5 && bet > 0)
						cout << "That's way too low, do you wanna sit here all day?" << endl;
					else if (bet > chips)
						cout << "You can't afford that you dumbo!" << endl;
					else if (bet > bobChips)
						cout << "Bob can't afford that big of a bet." << endl;
					else if (bet == 0)
						gambling = false;
					else
						cout << "Incorrect value!" << endl;
				}
				else if (chips < 10)
				{
					cout << "Uh oh! You can't place any more bets. You lost to Bob!" << endl;
					Sleep(2000);
					cout << "Bob laughs at you from across the room..." << endl;
					Sleep(2000);
					cout << "Bob: nobody can win Bob the Great, ha ha ha!" << endl;
					Sleep(2000);
					cout << "You leave the gambling room..." << endl;
					Sleep(2000);
					gambling = false;
				}
				else if (bobChips < 10)
				{
					string laugh;
					cout << "Oh wow! It looks like Bob can't place any more bets. You've won the game!" << endl;
					Sleep(1000);
					cout << "Do you want to laugh at Bob from across the room(y/n)?";
					cin >> laugh;
					if (laugh == "y" || laugh == "yes")
					{
						cout << "You laugh at Bob from across the room... Bob starts crying." << endl;
						Sleep(2000);
						cout << "Revenge is sweet. Thanks for playing, " << gamblerName << "!" << endl;
						Sleep(2000);
						cout << "You leave the gambling room..." << endl;
						Sleep(2000);
						gambling = false;
					}
					else
					{
						cout << "You try to shake Bob's hand, but Bob storms off crying. Bob is a bad loser." << endl;
						Sleep(2000);
						cout << "Oh well. A win is a win. Thanks for playing, " << gamblerName << "!" << endl;
						Sleep(2000);
						cout << "You leave the gambling room..." << endl;
						Sleep(2000);
						gambling = false;
					}
				}
			}
		}

		//oof, error error!
		else
		{
			cout << "Incorrect value!" << endl;
		}
	}
	return 0;
}