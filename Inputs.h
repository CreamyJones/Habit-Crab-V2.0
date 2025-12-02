//Input.h
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <chrono> //timekeeping
#include <cstdlib> //for sys pause
#include <thread> //alternate pause method

#include "HabitName.h"
#include "Time.h"

using namespace std;


void userStart()
{
	string yesNo;

	cin >> yesNo;

	if (yesNo == "Yes" || yesNo == "yes" || yesNo == "Y" || yesNo == "y")
	{
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "Great! I can't wait to get to know you better!\n";

		//chrono::seconds dura(3);
		//this_thread::sleep_for(dura);

		cout << "let's start by inputting some habits you'd like to reinforce\n";

		//this_thread::sleep_for(dura);

		cout << "You can choose to input habits on an hourly, daily, weekly, monthly, or even yearly basis!\n";
		cout << "--------------------------------------------------------------------------------------------\n";
		//HabitName();
	}

	else if (yesNo == "No" || yesNo == "no" || yesNo == "N" || yesNo == "n")
	{
		cout << "Um, you woke *me* up. Come back when you're serious.\n\n";
		return;
	}

	else
	{
		cout << "You know I'm a crab, right? Like, it's a wonder I can read English at all.\n";
		//chrono::seconds dura(3);
		//this_thread::sleep_for(dura);
		cout << "Please enter Yes or No in a format I can read.\n";
	}
}

void initialize()
{
	string userName;
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "Welcome to Habit Crab, your premier productivity tracker! \n\n\n";
	//chrono::seconds dura(3);
	//this_thread::sleep_for(dura);
	cout << "First, let's get to know each other. What's your name?\n\n\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cin >> userName;

	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "Nice to meet you, " << userName << "!\n\n";
	cout << "My name is Gabby The Crab! Yes, you have to call me the whole thing.\n";
	//this_thread::sleep_for(dura);
	cout << "I'm here to help you keep track of your schedule and reinforce your productive side!\n";
	//this_thread::sleep_for(dura);
	cout << "Keep chipping away at the habits you'd like to reinforce and watch me thrive!\n";
	//this_thread::sleep_for(dura);
	cout << "You'll also earn Ha-Bits per completed task that you can spend on rewards of your choosing!\n";
	//this_thread::sleep_for(dura);
	cout << "However, if you don't complete the habits that you set for yourself, you'll lose points\n";
	//this_thread::sleep_for(dura);
	cout << "Fail to complete enough tasks in a row, and I'll just straight up die!\n";
	//this_thread::sleep_for(dura);
	cout << "That's right, that's the kind of pact we're entering here.\n";
	//this_thread::sleep_for(dura);
	cout << "If you can't face the habits you set for yourself, then you'll have to face the emotional blackmail of killing me,\n";
	//this_thread::sleep_for(dura);
	cout << "Gabby The Crab!\n";
	//this_thread::sleep_for(dura);
	cout << "There's no other mascot after me either! Once I die, that's it! \n";
	//this_thread::sleep_for(dura);
	cout << "You pretty much lose access to this app. \n";
	//this_thread::sleep_for(dura);
	cout << "So, don't be a schmuck! My life and your general sense of self-worth are on the line here.\n";
	//this_thread::sleep_for(dura);
	cout << "Would you like to get started?\n\n";
	cout << "-------------------------------------------------------------------------------------------\n";

	userStart();
	system("pause");
	system("cls");
}