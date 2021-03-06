// Cpp_02_The_Wall_2_pointer_to_v.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <numeric>
using namespace std;


int main()
{
	string input;
	getline(cin, input);
	istringstream iss(input);
	vector<int>data;
	int number, cnt = 0;
	while (iss >> number)
	{
		data.push_back(number);
		cnt++;
	}
	int totalCubicMeters = cnt * 30;
	int currentCubicMeters = 0;
	for (auto i : data)
	{
		currentCubicMeters += i;
	}
	int countOfWorkingTeams = 0;
	vector<int> dataNumberOfWorkingTeamsAllDays;
	while (currentCubicMeters < totalCubicMeters)
	{
		for (int j = 0; j < data.size(); j++)
		{
			if (data[j] < 30)
			{
				countOfWorkingTeams++;
				data[j]++;
			}
		}
		dataNumberOfWorkingTeamsAllDays.push_back(countOfWorkingTeams);
		currentCubicMeters = 0;
		for (auto i : data)
		{
			currentCubicMeters += i;
		}
		countOfWorkingTeams = 0;
	}

	//poinper to vector
	vector<int> * pointerOfVectorData = &dataNumberOfWorkingTeamsAllDays;   
	for (int d = 0; d < dataNumberOfWorkingTeamsAllDays.size(); d++)
	{
		pointerOfVectorData->at(d) *= 195;
		//CHECK:
		//cout << pointerOfVectorData->at(d);		  
	}	
	
	for (int k = 0; k < dataNumberOfWorkingTeamsAllDays.size(); k++)
	{
		cout << dataNumberOfWorkingTeamsAllDays[k];
		if (k < dataNumberOfWorkingTeamsAllDays.size() - 1)
		{
			cout << ", ";
		}
		
	}
	cout << endl;	

	int sum = accumulate(dataNumberOfWorkingTeamsAllDays.begin(), dataNumberOfWorkingTeamsAllDays.end(), 0);
	cout << sum * 1900;
	cout << " coins" << endl;
	return 0;
}


