#include <iostream>
#include <string>
//#include <vector>

using namespace std;
//const vector<string> month_names = {"January", "February", "March"}

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message:

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message:

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor.

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);

   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january.
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
  string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date :: Date(){ // First constructor with no parameters sets the date January 1st, 2000
  day = 1;
  month = 1;
  monthName ="January";
  year = 2000;
  //cout << day<<"/"<<month<<"/"<<year<<endl;
}
Date :: Date(unsigned m, unsigned d, unsigned y){
  bool date_error = false;
  unsigned days_per_month;

  if (m > 12){
    m = 12;
    date_error = true;
  }else if (m == 0){
    m =1;
    date_error = true;
  }

  days_per_month = daysPerMonth(m, y);
  if(d > days_per_month){
    d = days_per_month;
    date_error = true;
  }else if (d == 0){
    d = 1;
    date_error = true;
  }
  month = m;
  day = d;
  monthName = name(month);
  year = y;

  if(date_error){
    cout << "Invalid date values: Date corrected to "<< month << "/" << day << "/" << year << ".\n";
  }
  return;
}

Date :: Date(const string &mn, unsigned d, unsigned y){
  unsigned num_of_month;
  string name_of_month;
  unsigned days_in_month;

  num_of_month = number(mn);
  if (num_of_month == 0){
    cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
    monthName = "January";
    month = 1;
    day = 1;
    year = 2000;
    return;
  }
  month = num_of_month;
  monthName = name(num_of_month);
  year =y;
  days_in_month = daysPerMonth(num_of_month,y);

  if (d > days_in_month){
    day = days_in_month;
    cout << "Invalid date values: Date corrected to "<< month << "/" << day << "/" << year << ".\n";
  } else if(d == 0){
    day = 1;
    cout << "Invalid date values: Date corrected to "<< month << "/" << day << "/" << year << ".\n";
  }else {
    day = d;
  }
  return;
}
void Date :: printNumeric()const{
  cout << month << "/" << day << "/" <<year;
}
void Date :: printAlpha()const{
  cout << monthName<<" "<<day<<", "<<year;
}

bool Date::isLeap(unsigned y) const{
  if ( y % 4 == 0 ){
    if (y % 100 == 0){
      if (y % 400 == 0){
        return true;
      }else{
        return false;
      }
    }else{
      return true;
    }
  }else{
    return false;
  }
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
  unsigned num;
  if (m ==2){
    if(isLeap(y)){
      num =29;
    }else{
      num = 28;
    }
  } else if (m == 1|| m== 3|| m == 5|| m == 7|| m == 8|| m == 10|| m == 12){
    num = 31;
  }else if (m==4|| m == 6|| m == 9|| m == 11){
    num =30;
  }
  return num;
}
string Date::name(unsigned m) const{
  string monthName;
  if(m == 1){
    monthName ="January";
  } else if(m ==2){
    monthName ="February";
  }else if(m==3){
    monthName ="March";
  }else if (m==4){
    monthName ="April";
  }else if(m==5){
    monthName ="May";
  }else if(m==6){
    monthName ="June";
  }else if(m==7){
    monthName ="July";
  }else if(m==8){
    monthName ="August";
  }else if(m==9){
    monthName ="September";
  }else if(m==10){
    monthName ="October";
  }else if(m==11){
    monthName ="November";
  }else if(m==12){
    monthName ="December";
  }
  return monthName;
}
unsigned Date::number(const string &mn) const{
  unsigned monthNum;
  if (mn =="January"|| mn == "january"){
    monthNum=1;
  }else if (mn =="February"|| mn =="february"){
    monthNum=2;
  }else if (mn =="March" || mn == "march"){
    monthNum=3;
  }else if (mn =="April"|| mn== "april"){
    monthNum=4;
  }else if (mn =="May"|| mn=="may"){
    monthNum = 5;
  }else if (mn =="June" || mn=="june"){
    monthNum= 6;
  }else if (mn =="July"||mn=="july"){
    monthNum =7;
  }else if (mn =="August"||mn=="august"){
    monthNum =8;
  }else if (mn =="September"||mn=="september"){
    monthNum = 9;
  }else if (mn =="October"||mn=="october"){
    monthNum=10;
  }else if (mn =="November"||mn=="november"){
    monthNum = 11;
  }else if (mn =="December"||mn=="december"){
    monthNum =12;
  }else{
    monthNum = 0; //Misspelled month
  }
  return monthNum;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
