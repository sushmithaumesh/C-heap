#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include"date.h"
#include"address.h"
#include"student.h"
#include"stdlib.h"


// default constructor 
// sets default value of string variable to "" , allocates GPA a default value 0 and allocates memory in the heap  
Student::Student()
{
  _Firstname="";
  _Lastname="";
  _GPA=0;
  _credithours=0;
  _address= new Address();
  _DOB= new Date();
  _graddate= new Date();

//opens a new file fullreport, shortreport and alphareport and std::ios_base::app appends the file

  inFilefull.open("fullreport.txt", std::ios_base::app);

  inFilesh.open("shortreport.txt", std::ios_base::app);

  inFilealpha.open("alphareport.txt", std::ios_base::app);

}


//getters 
std::string Student::getFirstname()const
{
    return _Firstname;
}

std::string Student::getLastname()const
{
    return _Lastname;
}

std::string Student::getDOB()const
{
	
	std::string dob_str;
    std::stringstream strDOB;
    
//if condition of variable assigned into the heap of date class
    if(_DOB)
    {
	// a variable month that equates to DOB that points to the value the getter is returning at that instance
    int month = _DOB->get_month();
// the month variable is put into the string stream with the '/' to separate parts of the DOB
    strDOB<<month<<'/';
    dob_str = strDOB.str();

// similar to assigning the variable to month asign variable day to Dob which points to value that the getter returns.
    int day = _DOB->get_day();
    strDOB<<day<<'/';
    dob_str = strDOB.str();

    int year = _DOB->get_year();
    strDOB<<year;
    dob_str = strDOB.str() + "\t";
    }
//returns the string with the Date of birth
    return dob_str;
}

std::string Student::getGradDate()const
{
	std::string graddate_str;
    std::stringstream strGD;
    //similar to the getDOB
    if(_graddate)
    {
    int month = _graddate->get_month();
    strGD<<month<<'/';
    graddate_str = strGD.str();

    int day = _graddate->get_day();
    strGD<<day<<'/';
    graddate_str = strGD.str();

    int year = _graddate->get_year();
    strGD<<year;
    graddate_str = strGD.str() + "\t";
    }

    return graddate_str;
}

double Student::getGPA()const
{
    return _GPA;
}


std::string Student::getAddress()const
{

	//declare a string and assign that string to the address variable that points to the getters in the address class and is put on the heap.
    std::string address_str;
    address_str = address_str + _address->getAddress1();
    address_str = address_str + "\t" + _address->getAddress2();
    address_str = address_str + "\t" + _address->getcity();
    address_str = address_str + "\t" + _address->getstate();
    address_str = address_str + "\t" + _address->getzipcode();
    return address_str;
}

unsigned int Student::getcredithours()const
{
    return _credithours;
}


//setter
void Student::setFirstname(const std::string& Firstname)
{
    _Firstname = Firstname;
}

void Student::setLastname(const std::string& Lastname)
{
    _Lastname = Lastname;
}

void Student::setDOB(const std::string& DOB)
{

   //declare a stringstream with its content as variable DOB
 std::stringstream ssFieldData(DOB);
// declare an array of 3 elements
    int FieldData[3];

    std::string strFieldData;
    char delimiter = '/';
    int i = 0;

//when getline gets a line from the the stringstream with the delimiter set to / and separates each part of the DOB
    while(std::getline(ssFieldData, strFieldData, delimiter))
    {
	// the string obtained after using getline and separating it with delimiter /. convert it into a integer and store it and than increment the element in the array.
        FieldData[i] = atoi(strFieldData.c_str());
        i++;
    }
 
    if(_DOB)
    {
	//uses setter from date class to set the array elements to the month day and year at that instance
     _DOB->set_month(FieldData[0]);
    _DOB->set_day(FieldData[1]);
    _DOB->set_year(FieldData[2]);
    }
}


void Student::setAddress(const std::string& student_address)
{
	//similar to setDOB 
    std::stringstream ssFieldData(student_address);
    std::string strFieldData[11];
    char delimiter = ',';
    int i = 0;
    while(std::getline(ssFieldData, strFieldData[i], delimiter))
    {
        i++;
    }
    if(_address)
    {
 _address->setAddress1(strFieldData[0]);
    _address->setAddress2(strFieldData[1]);
    _address->setcity(strFieldData[2]);
    _address->setzipcode(strFieldData[3]);
    }
}

void Student::setGradDate(const std::string& gradDate)
{

	//similar to setDOB set a delimiter and array
std::stringstream ssFieldData(gradDate);
    int FieldData[3];
    std::string strFieldData;
    char delimiter = '/';
    int i = 0;
    while(std::getline(ssFieldData, strFieldData, delimiter))
    {
        FieldData[i] = atoi(strFieldData.c_str());
        i++;
    }
 
    if(_graddate)
    {
_graddate->set_month(FieldData[0]);
    _graddate->set_day(FieldData[1]);
    _graddate->set_year(FieldData[2]);
    }
}

void Student::setGPA(const double& GPA)
{
    _GPA = GPA;
}

void Student::setcredithours(const int& credithours)
{
    _credithours = credithours;
}

// prints a report with information of all the students
void Student::fullreport()
{
   
    inFilefull<<this->getFirstname();
    inFilefull<<"\n"<<this->getLastname() << "\n" <<  std::endl;
    inFilefull<<"\n"<<this->getAddress();
    inFilefull<<"\n"<<this->getDOB();
    inFilefull<<"\n"<<this->getGradDate();
    inFilefull<<"\n"<<this->getGPA();
    inFilefull<<"\n"<<this->getcredithours();
    inFilefull<<"\n \n " <<std::endl;

}

//prints a report with only students last and first name.
void Student::shortreport()
{
    inFilesh<<"\t"<<this->getFirstname();
    inFilesh<<"\t"<<this->getLastname();
    inFilesh<<std::endl;
}

//prints a report in alphabetically order
void Student::alphareport()
{
   /* inFilefull<<"\t"<<this->getFirstname();
    inFilefull<<"\t"<<this->getLastname();
    inFilefull<<"\t"<<this->getAddress();
    inFilefull<<"\t"<<this->getDOB();
    inFilefull<<"\t"<<this->getGradDate();
    inFilefull<<"\t"<<this->getGPA();
    inFilefull<<"\t"<<this->getcredithours();
    inFilefull<<std::endl;
*/
 }

//deconstructor deletes things on the heap such as _address,_DOB,_graddate and also closes the files of full, short and alpha report.
Student::~Student()
{
    delete (_address);
    delete (_DOB);
    delete (_graddate);

    inFilefull.close();
    inFilesh.close();
    inFilealpha.close();
    

}	


