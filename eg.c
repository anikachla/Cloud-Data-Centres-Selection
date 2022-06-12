#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265

int main () {
   float val;
   char str[20];
   
   strcpy(str, "98993489");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   double lat = 0.5;
    double va = 180.0 / PI;
    double ret = acos(lat) * va;  // by default radians as o/p , convert to degrees
   printf(" acosx = %lf ",ret); // working;

   return(0);
}