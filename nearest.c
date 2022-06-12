#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kd.h"
#include <math.h>
#define PI 3.141592

float mod(float num);
float diff_lat_or_long(float a, float b);
float deg_to_rad(float degrees);
float min(float a , float b);


void insertion_of_data(Hash* h, KDTree* k )
{
 // insert_kd(KDTree *t,  int cp , char ccode[], float latitude, float longitude)
  int i=0;
  printf("chk 1 \n");
  while(i< HASH_SIZE)
  {      printf("chk 2 \n");
       if(h->records[i] != NULL)
       {
            char kcc[3]; strcpy(kcc, h->records[i]->ccode);

             float klati= h->records[i]->latitude;
            float klongi = h->records[i]->longitude; 

            printf("nearest .c i = %d\n ",i);
            printf(" kdkdkd %s %f %f === \n", kcc,klati,klongi);
            insert_kd( k,1, kcc,klati,klongi);
       }


    i++;
  }
//    printf("KDTREE TRAVERSAL IS  :::");
//    traverse_kd( *k);

}



float mod(float num)
{
    if(num >= 0)
      return num;

    else 
      return ((-1.0)*num);

}


float diff_lat_or_long(float a, float b)
{ 
    // difference in latitudes NN NS SN SS or longitudes
     float difference = 0.0;
    if(a>0 && b>0 )
      difference = mod(a-b);  //same hemisphere

    else if(a<0 && b<0)      // same hemisphere
      difference = mod(mod(a) - mod(b));

    else if( a>0 && b<0)      // different hemispheres a=N ,b=S then add
      difference= mod(a) + mod(b);
    
    else                  //  diff hemisp a= S ,b=N
      difference=  mod(a)+mod(b);
      
}

float haversine_dist( float lat1, float lat2, float long1,float long2)
{
  
  lat1 = deg_to_rad(lat1); 
  lat2 = deg_to_rad(lat2);
  long1 = deg_to_rad(long1);
  long2 = deg_to_rad(long2);

  float theta= diff_lat_or_long(long1,long2);
  float m = (sin(lat1)*sin(lat2)) + ( cos(lat1)*cos(lat2)*cos(theta) );
  float dist =  3961* acos(m);
  printf("distance in nautical miles = %f", dist);
 /**
   float dlon = diff_lat_or_long(long1,long2);
   float dlat = diff_lat_or_long(lat1,lat2);
   float a = (sin(dlat/2) *sin(dlat/2)) + cos(lat1) * cos(lat2) * (sin(dlon/2)*sin(dlon/2));
    float c = 2 * asin(min(1,sqrt(a)));
    float R=3961;//6371.0  ;//km
   float d = R * c;
   printf("distance in nautical miles2 = %f", d);
   **/
 return dist;


}



    float deg_to_rad( float degrees)
    {
    float radians = degrees * PI / 180;
    return radians;
    }


    float min(float a , float b)
    {

     if(a>b)
       return b;
     else
       return a;
     }

 int main()
 {

    float lat1 = 12.862807;//56.130366;
    float lat2 =  60.128161; // 23.424076 ;
    float long1 = 30.217636; //106.346771 ;
    float long2 = 18.643501; //53.847818;
    float dist =  haversine_dist( lat1,lat2, long1,long2);


 }

kdnode* nearer(kdnode *p, kdnode* a, kdnode* b) 
{
    // which node out of a and b is nearest to node p geographically
   
   float lat_p = p->lati;
   float long_p= p->longi;
   float lat_a = a->lati;
   float long_a = a->longi;
   float lat_b = b->lati;
   float long_b = b->longi;

    // prototype :  float haversine_dist( float lat1, float lat2, float long1,float long2)

   float d1 = haversine_dist( lat_p, lat_a, long_p,long_a);
   float d2 = haversine_dist( lat_p, lat_b, long_p,long_b);
    if (d1 < d2) 
    {
        return a;
    } 
    else 
    {
        return b;
    }

}

