#include "material_t.h"

//constructor
//precon- 
//postcon-
material_t::material_t()
{
   name = notset;
   ambient(0,0,0);
   diffuse(0,0,0);
   specular(0,0,0); 
}
material_t::material_t(istream &ins)
{
   in >> name;
   in >> ambient;
   in >> diffuse;
   in >> specular;
}
drgb_t material_t::getamb()
{
   return ambient;
}
drgb_t material_t::getdif()
{
   return diffuse;
}
drgb_t material_t::getspec()
{
   return specular;
}
void material_t::dump(ostream &outs)
{
   drgb->dump(outs);
}
void material_t::load(istream &ins)
{
   string attribute;
   
   ins >> attribute;
   while(!ins.eof())
   {
      item_load(ins attribute);
      ins >> attribute;
   }
}
void material_t::item_load(istream &ins,const string &attribute)
{
   int ndx;

   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx)
   {
      case PIXELDIM_ATT: ins >> pixel_dim[0] >> pixel_dim [1];
            break;
      case WORLDDIM_ATT: ins >> world_dim[0] >> world_dim[1];
            break;
      case VIEWPOINT_ATT: ins >> view_point;
            break;
   }

}
