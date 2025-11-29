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



#include "Inputs.h"
#include "HabitName.h"
#include "HabitTime.h"
#include "HabitFrequency.h"
#include "HabitImportance.h"
#include "Reward.h"
#include "RewardLevel.h"
#include "Time.h"

using namespace std;

vector <string>HabitInput;
vector <int>PointTracker;
string userAnswer, Reward;




int main()
{

	initialize();

	cout << "Would you like to add any other habits? Yes or no?\n"; //There's a way to use a recursive loop here. Do that

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


}