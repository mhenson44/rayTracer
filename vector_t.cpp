#include "vector_t.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void vector_t::setall(double a, double b, double c)
{
   x=a;
   y=b;
   z=c;
}
double vector_t::len() const
{
   double hold;
   hold=sqrt((x*x)+(y*y)+(z*z));
   return hold;
};


void vector_t::setx(double in)
{
   x=in;
};


double vector_t::getx() const
{
   return x;
};


void vector_t::sety(double in)
{
   y=in;
};


double vector_t::gety() const
{
   return y;
}


void vector_t::setz(double in)
{
   z=in;
};


double vector_t::getz() const
{
   return z;
};


double vector_t::dot(const vector_t &other) const
{
   double dot;
   dot = (x * other.getx()) + (y * other.gety()) + (z * other.getz());

   return dot;
};


vector_t vector_t::operator-(const vector_t &other) const
{
   vector_t subtract;

   subtract.x = x - other.getx();
   subtract.y = y - other.gety();
   subtract.z = z - other.getz();

   return subtract;
};


vector_t vector_t::operator+(const vector_t &other) const
{ 
   vector_t sum;

   sum.x = x + other.getx();
   sum.y = y + other.gety();
   sum.z = z + other.getz();

   return sum;
};


vector_t vector_t::scale(double factor) const
{
   vector_t scaled;
   scaled.setx(x*factor);
   scaled.sety(y*factor);
   scaled.setz(z*factor);
 
   return scaled;
};


istream& operator>>(istream &in, vector_t &vec)
{
   char ch;

   in>>ch;
   if(ch!='<')
   {
      cerr << "Bad Vector " << endl;
      exit(1);
   } 
   in >> vec.x;
   in>>ch;
   if(ch!=',')
   {
      cerr << "Bad Vector " << endl;
      exit(2);
   } 
   in >> vec.y;
   in>>ch;
   if(ch!=',')
   {
      cerr << "Bad Vector " << endl;
      exit(3);
   } 
   in >> vec.z;
   in >> ch;
   if(ch!='>')
   {
      cerr << "Bad Vector " << endl;
      exit(4);
   } 
 
return in; 
};


ostream& operator<<(ostream &out, const vector_t &vec)
{
   double a=vec.getx();
   double b=vec.gety();
   double c=vec.getz();
   out<<"<"<<setprecision(2)<<a<<","<<b<<","<<c<<">";
   return out;
};


vector_t vector_t::unit(void) const
{
   vector_t unit;
  
   unit.setx(x/sqrt((x*x)+(y*y)+(z*z))); 
   unit.sety(y/sqrt((x*x)+(y*y)+(z*z)));
   unit.setz(z/sqrt((x*x)+(y*y)+(z*z)));

   return unit;
};


vector_t::vector_t(double a, double b, double c)
{
   setall(a,b,c);

};


vector_t::vector_t()
{
   x=0;
   y=0;
   z=0;
};
