#include "material.h" //Adds the header file for this class
#include <iostream>
#include <string>

using namespace std;

/** @file
*This cpp file contains the c++ code for all of the methods within the materials class including the constructor and destructor
*the arguments passed to the constructor are the ID number(int), density(int), colour(as a hex rgb value of int) and the name of the material(string)
*The only methods within this class are the getters,setters,constructor and destructor
*The getter and setter methods are needed as the attributes of the material are all private and can only be accessed from within the class
*/

/**
*The deconstructor method
*/
material::~material()
{

}

/** Brief description
* Constructor
* This constructor takes the colour as a hexidecimal value ie 0xffffff
*/
material::material(int IDGive, int densityGive, int colourGive, string nameGive)
{
	//This is the class constructor which is called to create an object
	this->ID = IDGive;
	this->density = densityGive;
	this->colour = colourGive;
	this->name = nameGive;
	
}

/** Brief description
* Default constructor for when no arguments are passed
*/
// Default constructor used when no arguments provided - added by SAM -------------------------------------------------------------------------
material::material() { ID = 0; name = "not chosen"; colour = 0; density = 0; }

//Below are the getter functions which are used to return information about the material
/** Brief description
* Getter function
*/
int material::getID()
{
	return this->ID;
}
/** Brief description
* Getter function
*/
string material::getName()
{
	return this->name;
}
/** Brief description
* Getter function
*/
int material::getColour()
{
	return this->colour;
}
/** Brief description
* Getter function
*/
int material::getDensity()
{
	return this->density;
}

//Below are the setter functions which are used to set the values of the attributes of the object


/** Brief description
* Setter function
*/
void material::setID(int const &IDGive)
{
	this->ID = IDGive;
}
/** Brief description
* Setter function
*/
void material::setName(string const &nameGive)
{
	this->name = nameGive;
}
/** Brief description
* Setter function
*/
void material::setColour(int const &colourGive)
{
	this->colour = colourGive;
}
/** Brief description
* Setter function
*/
void material::setDensity(int const &densityGive)
{
	this->density = densityGive;
}