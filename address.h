//address.h

#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

#include<string>
#include<iostream>

class Address{

private:
	std::string _Address1;
	std::string _Address2;
	std::string _city;
	std::string _state;
	std::string _zipcode;

public:
	Address();
	Address(std::string& Address1, std::string& Address2, std::string& city, std::string& state, std::string& zipcode);
	std::string getAddress1() const;
	std::string getAddress2() const;
	std::string getcity() const;
	std::string getstate() const;
	std::string getzipcode() const;

	void setAddress1(const std::string& Address1);
	void setAddress2(const std::string& Address2);
	void setcity(const std::string& city );
	void setstate(const std::string& state);
	void setzipcode(const std::string& zipcode);

};

#endif


