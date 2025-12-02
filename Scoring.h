#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "HabitName.h"
using namespace std;

class Scoring 
{
	
public:
	int runCheck()
	{
		int roundpoint = 0;
		roundpoint += frequency("Hourly");
		roundpoint += frequency("Daily");
		roundpoint += frequency("Weekly");
		roundpoint += frequency("Monthly");
		roundpoint += frequency("Yearly");
		return roundpoint;
		
	}
private:
	int frequency(const string& freq)
	{
		vector<string>* habitList = 0; //pointer to vector
		if (freq == "Hourly") habitList = &Hourly;
		else if (freq == "Daily") habitList = &Daily;
		else if (freq == "Weekly") habitList = &Weekly;
		else if (freq == "Monthly") habitList = &Monthly;
		else if (freq == "Yearly") habitList = &Yearly;
		
		vector <string>& list = *habitList; //pointer dereference to get actual vector
		cout << "\nChecking " << freq << " habits:\n";
		int pointsPerHabit = HabitPoints(freq);
		int gained = 0;
		for (int i = 0; i < list.size(); ) 
		{
			cout << "Did you complete \"" << list[i] << "\"? (yes or No): "; 
			string answer;
			cin >> answer;
			
			if (answer == "yes" || answer == "y")
			{
				gained += pointsPerHabit;
				cout << "Great job! plus " << pointsPerHabit << " points for \"" << list[i] << "\" habit.\n";
				list.erase(list.begin() + i); //remove completed habit from list
			}
			else if (answer == "no" || answer == "n")
			{
				cout << "No points for \"" << list[i] << "\"\n";
				i++; //only increment if habit not removed
			}
			else
			{
				cout << "Invalid input. Please answer 'yes' or 'no'.\n";
			}
		}
		cout << "Total points earned for " << freq << " habits: " << gained << " points.\n";
		return gained;
		system("pause");
		system("cls");
	}

};