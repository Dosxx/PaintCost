
// Author     :      Kekeli dos Akouete
// File       :      PaintCost.cpp
// Description:      A program that estimate a cost of paint
// IDE used   :      NetBeans IDE8.1


// This application calculate the cost of paint based on 
// the square footage to be paint and offers discounts for 
// various number of cans of paint purchased

#include <iostream>
#include <iomanip>
#include <cmath>

const double PAINTCOST = 12.99;
const int ROOMHEIGHT = 8;
const int COVERAGE_PER_CAN = 250;
 
void displayTitle();
// Display the Title of the company's paint costing application 
void getData(int& length, int& width);
// Get input from the keyboard for the length and width
// which are supplied to main for calculation
// the value of length and width are set 
int calcSqFt(int,int);
// received the value of length and width and calculate
// the square footage of the room including the ceiling 
// the square footage of right and left wall of the room
// the square footage of the front and back wall of the room are all
// added for the total footage
double calcTotalCans(int sqFt);
// use the square footage input from the user to calculate 
// the number of cans needed
// the function return the number of cans needed round up 
// to the next whole number
double calcCost(double can);
// use the constant prince per can
// calculate the total cost and return it to main
// received an argument of type double and it is 
// call by value
void displayResults(int totalSqFt, double totalCans, double cost);
// get the value of three functions calcSqFt,calcTotalCan
// and calcCost and display the results on the screen
void displayMsg(double cans);
// display a message of free gift based on the quantity of 
// cans purchased

/*
 * Chesapeake Remodeling Company Paint Costing Application
 */
int main() 
{
    using namespace std;
  // main local variables
    int length, width,SquareFt;
    double cans,paintCost;
  // function calling   
    displayTitle();
    getData(length, width);
    
while( length > 0) 
{   
    SquareFt = calcSqFt(length,width);
    
    cans = calcTotalCans(SquareFt);
    
    paintCost = calcCost(cans);
 
    displayResults(SquareFt,cans,paintCost);
    
    displayMsg(cans);
  
    getData(length, width);
}
    return 0;
}

// using <iostream> 
void displayTitle()
{
    using namespace std;
    cout << "\n               Chesapeake Remodeling Company" << endl;
    cout << "                       Paint Costing          " << endl;
    cout << "               ----------------------------- " << endl
                                                            << endl;
    return;
}
// using <iostream> 
void getData(int& length ,int& width)
{
    using namespace std;
  
   cout << "     Enter length in feet <0 to stop>.................";
   cin >> length;
   if(length > 0)
   {    
       cout << "     Enter width in feet .............................";
        cin >> width; 
   }    
   else
   {
       return;
   }
   
}
// using <iostream> 
int calcSqFt(int length, int width)
{
    using namespace std;
    int totalSqFt,ceiling,frontBackSide,rightLeftSide;
    ceiling = length * width;
    frontBackSide = (ROOMHEIGHT * length)* 2;
    rightLeftSide = (ROOMHEIGHT * width) * 2;
    totalSqFt = (ceiling + frontBackSide + rightLeftSide);
    return totalSqFt;
}
// using <iostream> 
// using <cmath>
double calcTotalCans(int totalSqFt)
{
    using namespace std;
   
    double totalCans;
    totalCans =  ceil(static_cast<double> (totalSqFt)/COVERAGE_PER_CAN);
    return totalCans;
}
// using <iostream> 
double calcCost(double totalCans)
{
    using namespace std;
    
    double cost;
    cost = PAINTCOST * totalCans;
    return cost;
}
// using <iostream> 
// using <iomanip>
void displayResults(int totalSqFt, double totalCans, double cost)
{
    using namespace std;
    
    // output formatting and display  

   cout << "\n\n             Square footage =     "  << setw(11) 
                                             << totalSqFt << endl;
  
   cout << "             Cans           =     " << setw(11)
                                             << totalCans << endl;

   cout << "             Cost           =        " << setw(11)
                                             << cost << endl << endl;
   // return;
}
// using <iostream> 
void displayMsg(double totalCans)
{
    using namespace std;
   cout << "     Thank you for your purchase." << endl;
   
    if(totalCans <= 3)
        cout << "     Gift =     free paint brush." << endl << endl;
    else if(totalCans < 8)
        cout << "     Gift =     free paint tray." << endl << endl;
    else
        cout << "     Gift =     $10 gift card." << endl << endl;
    return;
}