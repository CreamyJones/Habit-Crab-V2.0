#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <chrono> //timekeeping
#include <cstdlib> //for sys pause
#include <thread> //alternate pause method
#include <fstream>
#include <sstream> 
#include "Data.h"
#include "Mainmenu.h"
#include "HabitName.h"
#include "Reward.h"
#include "Time.h"
#include "Scoring.h"
#include "Inputs.h"

using namespace std;
vector<string> Hourly;
vector<string> Daily;
vector<string> Weekly;
vector<string> Monthly;
vector<string> Yearly;
vector<string> Low;
vector<string> Mid;
vector<string> High;


int main()
{
	initialize();

	cout << "Would you like to add any other habits? Yes or no?\n"; //There's a way to use a recursive loop here. Do that
	string userAnswer;
	cin >> userAnswer; // enters the recursion loop

	InputRecursion(userAnswer);

	//chrono::seconds dura(3);
	//this_thread::sleep_for(dura);

	cout << "Now that you've identified your work load, let's talk rewards\n";


	//this_thread::sleep_for(dura);

	RewardList();

	cout << "Would you like to add any other rewards? Yes or no?\n";

	cin >> userAnswer;

	RewardRecursion(userAnswer);

	Scoring Score;
	int startingPoints = 0;
	Mainmenu menu(Score, startingPoints);
	menu.run();
	return 0;

}