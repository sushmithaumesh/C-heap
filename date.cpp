//date.cpp:

#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iostream>

#include"date.h"
// default constructor
// default value of member variables is 0
Date::Date()
{
_month=0;
_day=0;
 _year=0;
}
// overloaded constructor

Date::Date(const int& day, const int& month, const int& year)
	{
	}

//getters return the variable at that instance
	int Date::get_day()const
	{
	
 	return _day;

	}

	int Date::get_month()const
	{
   	return _month;
	}

	int Date::get_year() const
	{
	return _year;
	}


//setters set the value for member variable to the function parameter 
	int Date:: set_day(const int& day)
	{
	 _day=day;
	}

	int Date:: set_month(const int& month)
	{
	_month= month;
	}
	int Date:: set_year(const int& year)
	{
	_year= year;
	}
	









































 
