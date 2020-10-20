/*  Name: Michael Henson
    Class: csc1720

    This is the header file for the vector class
*/

#ifndef vector_t_H
#define vector_t_H
#include<iostream>
using namespace std;

class vector_t
{

   private: 
      double x;
      double y;
      double z;
   
   public:

      //default constructor sets all values to 0
      vector_t();
      //parameterized constructor
      vector_t(double, double, double);


      /* len- returns the length of a vector
         precondition- none
         post- the length of the vector is returned as a double */
      double len(void) const;

      
      /* setx- sets the value of x
         pre- a double is passed in
         post- x now holds the value of the double passed in */
      void setx(double);


      /* getx- returns the value of x
         pre- none
         post- the value of x is returned */
      double getx() const;

  
      /* sety- sets the value of y
         pre- a double is passed in
         post- y now holds the value of the double passed in */
      void sety(double);

   
      /* gety-returns the value of y
         pre- none
         post- the value of y is returned */
      double gety() const;


      /* setz- sets the value of z
         pre- a double is passed in
         post- z now holds the value of the double passed in */
      void setz(double);


      /* getz-returns the value of z
         pre- none
         post- the value of z is returned */
      double getz() const;


      /* setall- updates the values of all private members
         pre- 3 doubles are passed in 
         post- the private member variables now store the doubles */
      void setall(double, double, double);

      /* operator- - overloads the - operator to be able to subtract vectors */ 
      vector_t operator-(const vector_t &other) const;
 
      /* operator+ - overloads the + operator to be able to add vectors */ 
      vector_t operator+(const vector_t &other) const;


      /* dot- returns the dot product of two vectors
         pre- none
         post- the dot product is returned no changes to the vectors   */
      double dot(const vector_t &other) const;
  

      /* unit- returns the unit vector of a vector
         pre- none
         post- the unit vector is returned no changes made to original vector */
      vector_t unit(void) const;


      /* scale- scales the vector by a passed in value and returns the new vector
         pre- the scalar is passed in
         post- the new vector is returned */
      vector_t scale(double) const;


      /* friend operator>>- overloads the >> with access to the private member variables
         pre- the >> is used with a vector_t object
         post-reads information about a vector if properly "called"*/
      friend istream& operator>>(istream &in, vector_t &vec);


      /* friend operator<<- overloads the << operator with access to the private member variables
         pre- the << is used with a vactor_t object
         post-outputs the private member variables of the vector */
      friend ostream& operator<<(ostream &out, const vector_t &vec);
};
#endif
