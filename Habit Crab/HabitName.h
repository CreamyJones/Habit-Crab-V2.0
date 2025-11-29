#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <chrono> //timekeeping
#include <cstdlib> //for sys pause
#include <thread> //alternate pause method

#include "Inputs.h"
#include "HabitTime.h"
#include "HabitFrequency.h"
#include "HabitImportance.h"
#include "Reward.h"
#include "RewardLevel.h"
#include "Time.h"

using namespace std;

void HabitName()
{
	vector <string>Hourly;
	vector <string>Daily;
	vector <string>Weekly;
	vector <string>Monthly;
	vector <string>Yearly;
	int i;

	string frequency;

	string userInp;

	cout << "Choose which list you'd like to populate: \n";
	cout << " 1) Hourly\n 2) Daily\n 3) Weekly\n 4) Monthly\n 5) Yearly\n";
	cin >> i;

	/*if (i > 5 || i < 1) //this is supposed to protect against non-numeric and out-of-bounds entries for i. Gets fucky tho
	{
		cout << "Weird, that wasn't a number between 1-5. Maybe we should add 'Learn to read' to the habit list, hm? \n";

		cin.clear(); //Otherwise non-numeric input just loops until program crash


	}*/

	switch (i)
	{
	case 1:

		cout << "Go ahead and enter which habits you'd like to track every hour. Press enter after each input, and type 'done' when finished.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{
			
			getline(cin, userInp); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (userInp == "done" || userInp == "Done")
			{
				cout << "Sure! let's move on.\n";
				break;
			}

			Hourly.push_back(userInp);

		}
		
		/*for (int k = 0; k < Hourly.size(); k++)
		{

			cout << Hourly[k] << ", ";
		}*/

		break;

	case 2:

		cout << "Go ahead and enter which habits you'd like to track daily Press enter after each input, and type 'done' when finished.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, userInp); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (userInp == "done" || userInp == "Done")
			{
				cout << "Sure! let's move on.\n";
				break;
			}

			Daily.push_back(userInp);

		}

		/*for (int k = 0; k < Daily.size(); k++)
		{

			cout << Daily[k] << ", ";
		}*/


		break;

	case 3:

		cout << "Go ahead and enter which habits you'd like to track every week. Press enter after each input, and type 'done' when finished.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, userInp); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (userInp == "done" || userInp == "Done")
			{
				cout << "Sure! let's move on.\n";
				break;
			}

			Weekly.push_back(userInp);

		}

		/*for (int k = 0; k < Weekly.size(); k++)
		{

			cout << Weekly[k] << ", ";
		}*/


		break;

	case 4:

		cout << "Go ahead and enter which habits you'd like to track every month. Press enter after each input, and type 'done' when finished.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, userInp); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (userInp == "done" || userInp == "Done")
			{
				cout << "Sure! let's move on.\n";
				break;
			}

			Monthly.push_back(userInp);

		}

		/*for (int k = 0; k < Monthly.size(); k++)
		{

			cout << Monthly[k] << ", ";
		}*/

		break;

	case 5:

		cout << "Go ahead and enter which habits you'd like to track annually. Press enter after each input, and type 'done' when finished.\n";

		cin.ignore(); //consumes /n otherwise index 0 of vector is a blank space

		while (true) //use getline here in some capacity
		{

			getline(cin, userInp); //getline instead of simple cin because cin was splitting input phrases into separate words


			if (userInp == "done" || userInp == "Done")
			{
				cout << "Sure! let's move on.\n";
				break;
			}

			Yearly.push_back(userInp);

		}

		/*for (int k = 0; k < Yearly.size(); k++)
		{

			cout << Yearly[k] << ", ";
		}*/

		break;

	}


}

bool isCompleted(string userComp)
{
	bool completed = false;
	string compResp;

	if (userComp == "yes" || userComp == "Yes")
	{
		completed = true;
	}

	else if (userComp == "no" || userComp == "No")
	{
		completed = false;
	}

	else
	{
		cout << "Try typing that again for me, bud. Yes or No is all I need to hear from you right now.\n";
		cin >> compResp;

		isCompleted(compResp);
	}

	return completed;
}

int HabitPoints(string habitType)
{
	int ha_Bits = 0;
	int RewardPoints = 0;

	if (habitType == "Hourly")
	{
		RewardPoints = RewardPoints + 1;
	}

	else if (habitType == "Daily")
	{
		RewardPoints = RewardPoints + 2;
	}

	else if (habitType == "Weekly")
	{
		RewardPoints = RewardPoints + 7;
	}

	else if (habitType == "Monthly")
	{
		RewardPoints = RewardPoints + 30;
	}

	else if (habitType == "Yearly")
	{
		RewardPoints = RewardPoints + 365;
	}

	return RewardPoints;
}

void InputRecursion(string userReply)
{
	//string userAnswer;

	//cin >> userAnswer;

	if (userReply == "no" || userReply == "No")
	{
		return;
	}

	else if (userReply == "yes" || userReply == "Yes")
	{
		HabitName();

		cout << "Would you like to add any other habits? Yes or no?\n";

		cin >> userReply;

		InputRecursion(userReply);
	}

	else
	{
		cout << "Idk what that means man, I'm still just a crab here. Do you want to add any other habits? Yes or No. \n";

		cin >> userReply;

		InputRecursion(userReply);
	}
	
}