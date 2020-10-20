sphere_t::sphere_t(istream &ins, material_tptr mats[], int matcnt)
{
   ins >> center;
   ins >> radius;
   ins >> mats{matcnt];
}

double sphere_t::hits(vector_t &base, vector_t &dir)
{
   normal = &base;
   point = &dir;   
}
virtual void sphere_t::dump(ostream &outs)
{
   outs << center;
   outs << radius;
   outs << mats->dumb();
}
 void sphere_t::load(istream &ins)
{   
   string attribute; 

   ins >> attribute;
   while(!ins.eof())
   {
      item_load(ins,attribute);
      ins >> attribute;
   }
}

/* item_load:
 * pre-condition:
 * post-condition:
 */
void sphere_t::item_load(istream &ins,  string &attribute)
{
   int ndx;
   
   ndx = table_lookup(attributes, NUM_ATTRIBUTES, attribute);
   switch(ndx)
   {
      case PIXELDIM_ATT: ins >> pixel_dim[0] >> pixel_dim[1];
            break;
      case WORLDDIM_ATT: ins >> world_dim[0] >> world_dim[1];
            break;
      case VIEWPOINT_ATT: ins >> view_point;
            break;
   }
}

