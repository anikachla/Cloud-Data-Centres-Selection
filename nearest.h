
#ifndef NEAREST_H
#define NEAREST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kd.h"
#include "hash.h"

void insertion_of_data(Hash* h, KDTree* k );
float haversine_dist( float lat1, float lat2, float long1,float long2);

#endif