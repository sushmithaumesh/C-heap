// address.cpp

#include"address.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

// default constructor 
Address::Address()
{
	_Address1="";
	_Address2="";
	_city="";
	_state="";
	_zipcode="";

}

// overloaded constructor
Address::Address(std::string& Address1,std::string&  Address2, std::string& city,std::string& state,std::string&  zipcode)
		{
		}

// getters return the string variable at that instance
	std::string Address::getAddress1()const
	{
	   
          return _Address1;
	}
	std::string Address::getAddress2()const
	{
	
	return _Address2;
	}
	std::string Address::getcity()const
	{
	return _city;
	}
	std::string Address::getstate()const
	{
	return _state;
	}
	std::string Address::getzipcode()const
	{

	return _zipcode;
	}

	// setters set the value of string member variables to function parameter.
		void Address::setAddress1(const std::string& Address1)
		{ 
			_Address1=Address1;
		}
		void Address::setAddress2(const std::string& Address2)
		{
			_Address2=Address2;
		}
		void Address::setcity(const std::string& city)
		{
			_city=city;
		}
		void Address::setstate(const std::string& state)
		{
			_state=state;
		}
		void Address::setzipcode(const std::string& zipcode)
		{
			_zipcode=zipcode;
		}

















