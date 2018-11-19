//Project 2: Blood Donor Calculator
//Benjamin He
//Professor Stahl
//UCLA, 2018-2019 Winter Quarter, CS31 

#include <iostream>
#include <string>
using namespace std;

/*        Under 16 Years Old  	    Under 110 Pounds  	      Between 16-22 Years Old  	          Otherwise  
Male	         NO	                      NO	                 Under 5' Tall, NO
                                                                 5' Tall Or More, YES	             YES
 	 	 	 	 
Female 	         NO	                      NO	                 Under 4'10" Tall, NO
                                                      4'10" Tall, Must Weigh 146 Or More Then YES
                                                      4'11" Tall, Must Weigh 142 Or More Then YES
                                                                 5' Tall Or More, YES	             YES
 	 	 	 	 
Trans Male
Trans Female
Queer
Different  	     NO	                      NO	                         NO	                         YES
*/

int main()
{
	//Define all variables being used.
	string name;
	string gender;
	int age = 0;
	int weight = 0;
	int height = 0;
	bool canDonate = true;

	//Take in and check each input (to save user's time).
	cout << "Name:" << endl;
	getline(cin, name);
	//Check if name is valid.
	if (name.empty())
	{
		cout << "--- You must enter a valid name." << endl;
		return (0);
	}

	cout << "Gender:" << endl;
	getline(cin, gender);
	//Check if gender is valid.
	if (gender != "Male" && gender != "Female" && gender != "Trans Male" && gender != "Trans Female" && gender != "Queer" && gender != "Different")
	{
		cout << "--- You must enter a valid gender." << endl;
		return (0);
	}

	cout << "Age:" << endl;
	cin >> age;
	//Check if age is valid.
	if (age <= 0)
	{
		cout << "--- You must enter a valid age." << endl;
		return (0);
	}

	cout << "Weight:" << endl;
	cin >> weight;
	//Check if weight is valid.
	if (weight <= 0)
	{
		cout << "--- You must enter a valid weight." << endl;
		return (0);
	}

	cout << "Height:" << endl;
	cin >> height;
	//Check if height is valid.
	if (height <= 0)
	{
		cout << "--- You must enter a valid height." << endl;
		return (0);
	}

	//If inputs are all valid, determine whether user can donate.
	
	//General age and weight conditions
	if (age < 16 || weight < 110)
	{
		canDonate = false;
	}
	//Conditions for Male
	if (gender == "Male")
	{
		if (age >= 16 && age <= 22)
		{
			if (height < 60)
			{
				canDonate = false;
			}
		}
	}

	//Conditions for Female
	if (gender == "Female")
	{
		if (age >= 16 && age <= 22)
		{
			if (height < 58)
			{
				canDonate = false;
			}
			else if (height == 58)
			{
				if (weight < 146)
				{
					canDonate = false;
				}
			}
			else if (height == 59)
			{
				if (weight < 142)
				{
					canDonate = false;
				}
			}
		}
	}

	//Conditions for Trans Male, Trans Female, Queer, Different
	if (gender == "Trans Male" || gender == "Trans Female" || gender == "Queer" || gender == "Different")
	{
		if (age <= 22)
		{
			canDonate = false;
		}
	}

	//If canDonate is still true, then that means all conditions for donating blood are satisfied. Otherwise, you cannot donate blood.
	if (canDonate)
	{
		cout << "--- Yes, " << name << " you can donate blood." << endl;
	}
	else
	{
		cout << "--- No, " << name << " you cannot donate blood." << endl;
	}
}
