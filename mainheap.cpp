#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include <stdlib.h>

#include"date.h"
#include"student.h"
#include"address.h"

int main()
{

	// open the student text file 
    std::ifstream inFile;
    inFile.open("student.dat");
    std::string line;
    std::string strFieldData[11];
    bool first_line = true;

//opens files in ouput stream for writing and any file open before it is discarded
    std::ofstream ofs;
    ofs.open("fullreport.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("shortreport.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofs.open("alphareport.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();


// make a counter variable to keep track of the number of elements in the student array while in the loop
	int counter = 0;

	//put array of 50 students into the heap
	Student* student_rec = new Student[50];
    while(getline(inFile,line))
    {
        if(!first_line)
	{
        std::stringstream ssFieldData(line);
        for(int i =0 ; i < 11 ; i++)
        {
           getline(ssFieldData, strFieldData[i], ',');
        }

// Student * student_rec[counter] = new Student();
	
	    std::string FieldData;
	    std::string Address;
	    std::string Dob;
	  //the array element is set to the firstname and lastname from setters in student class by using the string variable which is a array of 11 elements 

	    student_rec[counter].setFirstname(strFieldData[0]);

	    student_rec[counter].setLastname(strFieldData[1]);

 Address = Address + strFieldData[2] + ",";

 Address = Address + strFieldData[3] + ",";

 Address = Address + strFieldData[4] + ",";

  Address = Address + strFieldData[5] + ",";

 Address = Address + strFieldData[6] + ",";

//sets the student array current element to point at the address,DOB and graddate at that instance.
 student_rec[counter].setAddress(Address);
	    student_rec[counter].setDOB(strFieldData[7]);
	    student_rec[counter].setGradDate(strFieldData[8]);

std::string::size_type sz;     // alias of size_t
	    double GPA = atof (strFieldData[9].c_str());
	    student_rec[counter].setGPA(GPA);

//converts string to integer and stores it in the student array
int credithours = atoi (strFieldData[10].c_str());
	    student_rec[counter].setcredithours(credithours);

            student_rec[counter].fullreport();
	    student_rec[counter].shortreport();
	    student_rec[counter].alphareport();

            counter++;
//delete student_rec[counter];
	}
	first_line = false;
    }//end while 


	//delete the student array from the heap
	delete [] student_rec;
}
