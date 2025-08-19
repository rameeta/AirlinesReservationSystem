/* IMPORTANT KEY TERMS AND THEIR USE

#include<fstream>
This is for file handling in C++.
ifstream = input file stream (reading from a file).
ofstream = output file stream (writing to a file).

#include<windows.h>
This is a Windows-specific header.
lets you use Windows API functions like Sleep(), system("cls"), etc.
Sleep(milliseconds) → pause program execution.
system("cls") → clear the terminal screen (Windows only).

#include<sstream>
This is for string streams.
stringstream lets you treat a string like a stream (like cin or cout).
Example: converting an int into a string.

while(getline(in , line)){
Reads one line from the file at a time and stores it in line.
Continues until end of file.

int post = line.find(flight);
Searches for flight (like "F1001") inside that line.
Returns position index if found, or string::npos if not found.

if(post != string::npos){
Checks if the substring was found.
npos = constant meaning “not found”.

stringstream sec;
Creates a string stream object.
You can insert numbers into it and later convert them into strings.

sec << current;
Puts the integer value current into the stringstream.

string strCurr = sec.str();
Converts the content of stringstream into an actual string.
Example: if current = 49, strCurr = "49".

int seatPosition = line.find_last_of(':');
Finds the last occurrence of : in that line (before seat number).

line.replace(seatPosition + 2, string::npos , strCurr);
Replaces the old seat number (after last :) with the updated one (strCurr).
seatPosition + 2 → skip the colon and space.
string::npos → means “till the end of the string”.

*/




#include<iostream>
#include<fstream> 
#include<windows.h>
#include<windows.h>
#include<sstream>
using namespace std;

class Airline{
  private:
  string Flight , Destination , Departure;
  int Seats;  

  public:
  Airline(string flight , string destination , string departure, int seats ){
    //intialize them
    Flight = flight;
    Destination = destination;
    Departure = departure;
    Seats = seats;
  }
  //getter functions
  string getFlight(){
    return Flight;
  }
  string getDestination(){
    return Destination;
  }
  string getDeparture(){
    return Departure;
  }
  int getSeat(){
    return Seats;
  }
  void update (string flight){
    ifstream in("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight.txt");
    ofstream file("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight temp.txt");
    string line;
    while(getline(in , line)){
      int post = line.find(flight);
    if(post != string :: npos){
      int current = Seats -1;
      Seats = current;
      stringstream sec;
      sec << current ;
      string strCurr = sec.str();

      int seatPosition = line.find_last_of(':');
      line.replace(seatPosition + 2, string :: npos , strCurr);
    }
    file << line << endl;
    }
    file.close();
    in.close();
    remove("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight.txt");
    rename("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight temp.txt", "C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight.txt");
    cout << "Seat Reserved Successfully! " << endl;
  }
};

void display(){
    ifstream in("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight.txt");
    if(!in){
        cout << "Error: File not found! " << endl;
    }
    else{
        string line;
        while(getline(in , line)){
            cout << line << endl;
        }

    }
}
int main(){
    Airline flight1("F1001", "Germany" , "India", 50);
    Airline flight2("F2002", "Germany" , "Bali", 30);
    Airline flight3("F3003", "Germany" , "USA", 2);
    Airline flight4("F4004", "Germany" , "Dubai" , 25);
    Airline flight5("F5005", "Germany", "Egypt", 14);

    //file handling 
    ofstream file ("C:/Users/RAMEETA/OneDrive/Desktop/c++projects/Flight.txt");
    if(!file){
       cout << "Error : File not found!" << endl;
    }
    else{
        file << flight1.getFlight() << " : " << flight1.getDestination() << " : " << flight1.getDeparture() << " : " << flight1.getSeat() << endl << endl;
        file << flight2.getFlight() << " : " << flight2.getDestination() << " : " << flight2.getDeparture() << "  : " << flight2.getSeat() << endl << endl;
        file << flight3.getFlight() << " : " << flight3.getDestination() << " : " << flight3.getDeparture() << "   :  " << flight3.getSeat() << endl << endl;
        file << flight4.getFlight() << " : " << flight4.getDestination() << " : " << flight4.getDeparture() << " : " << flight4.getSeat() << endl << endl;
        file << flight5.getFlight() << " : " << flight5.getDestination() << " : " << flight5.getDeparture() << " : " << flight5.getSeat() << endl << endl;
        
        cout << "Data saved successfully! " << endl;
        file.close();
    }
    bool quit = false;
    while(!quit){
        system("cls");
        cout << "\t WELCOME TO AIRLINE MANAGEMENT SYSTEM! " << endl;
        cout << "\t ------------------------------------- " << endl;
        cout << endl;
        cout << "\t 1. Reserve A Seat. " << endl;
        cout << "\t 2. Exit. " << endl;
        cout << "\t -> Enter Your Choice: " << endl;
        cout << endl;
        int val;
        cin >> val;

        if(val == 1){
            system("cls");
            display();
            string flight;
            cout << "Enter Flight No: " << endl;
            cin >> flight;
            if(flight == flight1.getFlight() && flight1.getSeat() > 0){
              flight1.update(flight);
            }
            else if(flight1.getSeat() <= 0){
              cout << "Sorry, all seats are already booked! " << endl;
            }
            if(flight == flight2.getFlight() && flight2.getSeat() > 0){
              flight2.update(flight);
            }
            else if(flight2.getSeat() <= 0){
              cout << "Sorry, all seats are already booked! " << endl;
            }
            if(flight == flight3.getFlight() && flight3.getSeat() > 0){
              flight3.update(flight);
            }
            else if(flight3.getSeat() <= 0){
              cout << "Sorry, all seats are already booked! " << endl;
            }
            if(flight == flight4.getFlight() && flight4.getSeat() > 0){
              flight4.update(flight);
            }
            else if(flight4.getSeat() <= 0){
              cout << "Sorry, all seats are already booked! " << endl;
            }
            if(flight == flight5.getFlight() && flight5.getSeat() > 0){
              flight5.update(flight);
            }
            else if(flight5.getSeat() <= 0){
              cout << "Sorry, all seats are already booked! " << endl;
            }

        Sleep(5000);
        }
        else if(val == 2){
          system("cls");
          quit = true;
          cout << "Airline Management is always at your service! " << endl;
          Sleep(3000);
        }

    }
}
