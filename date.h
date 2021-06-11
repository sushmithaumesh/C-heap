//date.h
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include<string>
#include<iostream>

class Date{

private:
	 int _day;
	 int _month;
	 int _year;

public:
	Date();
	
	Date(const int& day, const int& month, const int& year);
	
	
	 int get_day() const;
	 int get_month() const;
	 int get_year() const;

	
	 int set_day(const int& day);
	 int set_month(const int& month);
	 int set_year(const int& year);

	


};




#endif 

