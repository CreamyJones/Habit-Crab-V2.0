//Reward.h
#pragma once
#include <iostream>
#include <limits>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <chrono> //timekeeping
#include <cstdlib> //for sys pause
#include <thread> //alternate pause method
#include "Data.h"
#include "Inputs.h"
#include "HabitName.h"
#include "Time.h"

using namespace std;
void RewardList()
{
	string Reward;
	int i;

	chrono::seconds dura(3);

	cout << "Low-tier rewards should be something like 'go out to eat with the family'.\n ";

	cout << "Which rewards would you like to input?\n";
	cout << " 1) Lower-tier\n 2) Mid-tier\n 3) High-tier\n";
	cin >> i;

	switch (i)
	{

	case 1:

		cout << "Please enter some low-tier rewards. These should be something like 'go out to eat with the family'.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, Reward); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (Reward == "done" || Reward == "Done")
			{
				cout << "Okie doke, moving on then.\n";
				break;
			}

			Low.push_back(Reward);

		}

		/* for (int k = 0; k < Low.size(); k++) //verification of vector population
		{
			cout << Low[k] << ", ";
		} */

		break;

	case 2:

		cout << "Now for some mid-tier rewards. These should be something like 'buy a guitar'.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, Reward); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (Reward == "done" || Reward == "Done")
			{
				cout << "Okie doke, moving on then.\n";
				break;
			}

			Mid.push_back(Reward);

		}

		/*for (int k = 0; k < Mid.size(); k++) //verification of vector population
		{
			cout << Mid[k] << ", ";
		}*/

		break;

	case 3:

		cout << "Now for the high-tier. These should be something like 'a vacation to Italy'.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, Reward); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (Reward == "done" || Reward == "Done")
			{
				cout << "Okie doke, moving on then.\n";
				break;
			}

			High.push_back(Reward);

		}
	default:
		break;
	}

		/*for (int k = 0; k < High.size(); k++) //verification of vector population
		{
			cout << High[k] << ", ";
		}*/
}

void RewardRecursion(string userReward)
{
	//string userAnswer;

	//cin >> userAnswer;

	if (userReward == "no" || userReward == "No")
	{
		cout << "You're right, you've rewarded yourself enough \n";
		
		system("pause");
		system("cls");
	}

	else if (userReward == "yes" || userReward == "Yes")
	{
		RewardList();

		cout << "Would you like to add any other rewards? Yes or no?\n";

		cin >> userReward;

		RewardRecursion(userReward);
		return;
	}

	else
	{
		cout << "Idk what that means man, I'm still just a crab here. Do you want to add any other rewards or what? Yes or No. \n";

		cin >> userReward;

		RewardRecursion(userReward);
	}
	system("pause");
	system("cls");
}
