//student.h

#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS


#include<string>
#include<iostream>
#include"date.h"
#include"address.h"

class Student
{

private:
	std::string _Firstname;
	std::string _Lastname;
	Address* _address;
	Date* _DOB;
	Date* _graddate;
	double _GPA;
	unsigned int _credithours;
	std::ofstream inFilefull;
	std::ofstream inFilesh;
	std::ofstream inFilealpha;

public:
	Student();
	std::string getFirstname() const;
	std::string getLastname() const;
	std::string getAddress() const;
	double getGPA() const;
	std::string getDOB() const;
	std::string getGradDate() const;
	unsigned int getcredithours() const;


	void  setFirstname( const std::string& Firstname);
	void  setLastname( const std::string& Lastname);
	void  setAddress( const std::string& student_address);
	void  setGPA( const double& GPA);
	void  setDOB( const std::string& DOB);
	void  setGradDate( const std::string& GradDate);
	void  setcredithours(const int& credithours);

        
	// functions to create reports 
	void fullreport();
	void shortreport();
	void alphareport();

	//deconstructor
	~Student();

};
#endif
