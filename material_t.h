#include"ray.h"
#include"vector_t.h"
#include"drgb_t.h"
#include"irgb_t.h"

#ifndef MATERIAL_T
#define MATERIAL_T

class material_t
{  
    private:
      string name;
      drgb_t ambient;
      drgb_t diffuse;
      drgb_t specular;
 public:
      material_t(void);
      material_t(istream &ins);
      drgb_t getamb(void);
      drgb_t getdif(void);
      drgb_t getspec(void);
      string getname(void);
      void dump(ostream &outs);
   private:
      void load(istream &ins);
      void item_load(istream &ins, const string &attribute);
};


#endif

