class sphere_t;
typedef sphere_t * sphere_tptr;
class sphere_t:public object_t
{
 public:
 sphere_t(){};
 sphere_t(istream &ins, material_tptr mats[], int matcnt);
 ~sphere_t(){};
 virtual double hits(vector_t &base, vector_t &dir);
 virtual void dump(ostream &outs);
 private:
 //double ndotp; //dot product of normal and point
 void load(istream &ins);
 void item_load(istream &ins,string attribute);
 double center;
 double radius;
};
