/*
 * =====================================================================================
 *         Author:  Andrew Bills
 *   Organization:  Weber State
 *    Description:  Ask user to specify the address and price
 *    				of two house that are on sale
 *    				It prints out which of the two houses is cheaper
 *       Filename:  housePrice.cpp
 *       	Usage:  ./housePrice.cpp
 *       Compiler:  C++
 * =====================================================================================
 */
#include <iostream>
#include <iomanip> 

using namespace std;
/*  Structures/Constants */
struct house
{
	int streetNum;
	char streetName[30];
	double price;
};

// Function prototypes
struct house InputHouse(void);
void PrintHouse(int houseNum, struct house h);  
int ComparePrices(struct house h1, struct house h2);

/* Main Program */
int main(int argc, char* argv[])
{
	cout<<"Enter info for first house\n";
	struct house firstHouse = InputHouse();
	cout<<"\nEnter info for second house\n";
	struct house secondHouse = InputHouse();

	PrintHouse(1, firstHouse);  
	printf("\n\n");
	PrintHouse(2, secondHouse);
	printf("\n\n");

	int comparison = ComparePrices(firstHouse, secondHouse);
    
    //The switch statement below is used for printing out the decision.
    switch (comparison) {
        case 1: std::cout << "The first house is cheaper"; break;
        case 2: std::cout << "The two houses are equally expensive"; break;
        case 3: std::cout << "The second house is cheaper"; break;
        default: std::cout << "Invalid comparison value there must be a bug";break;
    }

	return 0;
}


/* This function prompts the user for the houses street number, street name, 
and house price, and at the end it returns the housing information. */
struct house InputHouse(void)
{
    
    struct house info; 
    cout << "Please enter the street Number: " << endl;
    cin >> info.streetNum;
    cout << "Please enter the street Name: " << endl;
    cin.ignore();
    cin.getline(info.streetName,30);
    cout << "Please enter the Price: " << endl;
    cin >> info.price;
    
    return info;
}


/* This function prints out the infromation about a house, in a understanable format. */
void PrintHouse(int houseNum, struct house h)
{
    cout << houseNum <<" house: at " << h.streetNum << " " << h.streetName << " $[" << setprecision(2) << fixed << h.price <<"]";
}


/* This function finds out which house cost more, if they are the same, or if 
their is a bug. At which point the function will return a number for the 
switch, in the main function, to decide what to output to the user. */
int ComparePrices(struct house h1, struct house h2)
{
    
    if(h1.price < h2.price)return 1;
    else if(h1.price == h2.price) return 2;
    else if(h1.price > h2.price) return 3;
    else return 4;
    
}


