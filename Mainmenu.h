#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <limits>
#include <ctime>
#include "Scoring.h"
#include "HabitName.h"
#include "Reward.h"
#include "Data.h"

using namespace std;

class Mainmenu
{
public:
	Mainmenu(Scoring& s, int startingPoints) : Score(s)
	{
		totalPoints = startingPoints;
	}
	void run()
	{
		while (true)
		{
			cout << "==== Main Menu ====\n";
			cout << "Total points: " << totalPoints << endl << endl;
			cout << "1) Show habits\n";
			cout << "2) Show reward\n";
			cout << "3) Add more habits\n";
			cout << "4) Add more reward\n";
			cout << "5) Redeem reward\n";
			cout << "6) Check completion\n";
			cout << "7) Exit program\n";
			cout << "Select your option: ";
			int m;
			cin >> m;
			system("pause");
			system("cls");
			if (m == 1) showHabits();
			else if (m == 2) showRewards();
			else if (m == 3) addHabits();
			else if (m == 4) addRewards();
			else if (m == 5) redeem();
			else if (m == 6) checkcomplete();
			else if (m == 7)
			{
				cout << "Exiting program. Goodbye!\n";
				return;
			}
			else
			{
				cout << "Please enter number from 1 - 7.\n";
				break;
			}
			
		}
	}
private:
	Scoring& Score;
	int totalPoints;
	int tierCost(int tier) // returns cost based on tier
	{
		if (tier == 1) return 100;
		if (tier == 2) return 200;
		if (tier == 3) return 300;
	}
	void showHabits()
	{
		cout << "==== Your Habits ====\n\n";
		cout << "Hourly Habits:\n";
		for (int i = 0; i < Hourly.size(); i++)
		{
			cout << "   " << i << ") " << Hourly[i] << " (1pt)\n";
		}
		cout << "Daily Habits:\n";
		for (int i = 0; i < Daily.size(); i++)
		{
			cout << "   " << i << ") " << Daily[i] << " (2pt)\n";
		}
		cout << "Weekly Habits:\n";
		for (int i = 0; i < Weekly.size(); i++)
		{
			cout << "   " << i << ") " << Weekly[i] << " (7pt)\n";
		}
		cout << "Monthly Habits:\n";
		for (int i = 0; i < Monthly.size(); i++)
		{
			cout << "   " << i << ") " << Monthly[i] << " (30pt)\n";
		}
		cout << "Yearly Habits:\n";
		for (int i = 0; i < Yearly.size(); i++)
		{
			cout << "   " << i << ") " << Yearly[i] << " (365pt)\n";
		}
		cout << endl;
	}
	void showRewards()
	{
		cout << "==== Your Rewards ====\n\n";
		cout << "Low-tier Rewards:\n";
		for (int i = 0; i < Low.size(); i++)
		{
			cout << "   " << i << ") " << Low[i] << " (100pt)\n";
		}
		cout << "Mid-tier Rewards:\n";
		for (int i = 0; i < Mid.size(); i++)
		{
			cout << "   " << i << ") " << Mid[i] << " (200pt)\n";
		}
		cout << "High-tier Rewards:\n";
		for (int i = 0; i < High.size(); i++)
		{
			cout << "   " << i << ") " << High[i] << " (300pt)\n";
		}
		cout << endl;
	}
	void addHabits()
	{
		cout << "==== Add More Habits ====\n\n";
		HabitName();
		cout << "Habits added successfully.\n";
		system("pause");
		system("cls");
	}
	void addRewards()
	{
		cout << "==== Add More Rewards ====\n\n";
		RewardList();
		cout << "Rewards added successfully.\n";
		system("pause");
		system("cls");
	}
	void redeem()
	{
		cout << "==== Redeem Rewards ====\n";
		cout << "Your currently have " << totalPoints << " points.\n\n";
		showRewards();

		cout << "Select tier to redeem:\n";
		cout << "1) Low-tier (100pt)\n";
		cout << "2) Mid-tier (200pt)\n";
		cout << "3) High-tier (300pt)\n";
		cout << "4) Cancel\n";
		cout << "Enter tier number: ";
		
		vector<string>* rewardList; //pointer to vector
		int tier;
		cin >> tier;
		if (tier == 1) rewardList = &Low;
		else if (tier == 2) rewardList = &Mid;
		else if (tier == 3) rewardList = &High;
		else if (tier == 4)
		{
			cout << "Redemption cancelled.\n";
			return;
		}
		else
		{
			cout << "Invalid tier selection.\n";
			return;
		}
		vector <string>& list = *rewardList; //pointer dereference to get actual vector
		int cost = tierCost(tier);
		cout << "\nRewards in selected tier (cost " << cost << " points each):\n";
		for (int i = 0; i < list.size(); i++)
		{
			cout << "   " << i << ") " << list[i] << "\n";
		}
		int index;
		cout << "Enter reward index to redeem: ";
		cin >> index;
		if (index < 0 || index >= list.size())
		{
			cout << "Invalid reward index.\n";
			return;
		}
		if (totalPoints < cost)
		{
			cout << "You don't have enough points. You need " << cost << " but only have " << totalPoints << endl;
			return;
		}
		string reward = list[index]; // store reward before removing
		list.erase(list.begin() + index); // remove reward from list
		totalPoints -= cost; // deduct points
		cout << "You have redeemed: " << list[index] << "\n";
		cout << "Remaining points: " << totalPoints << "\n";
		system("pause");
		system("cls");
	}
	void checkcomplete()
	{
		cout << "==== Check Completion ====\n\n";
		showHabits();
		int gainedPoints = Score.runCheck();
		totalPoints += gainedPoints;
		cout << "\nTotal points: " << totalPoints << " points.\n\n";
		system("pause");
		system("cls");
	}
};
