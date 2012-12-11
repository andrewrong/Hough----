#include <assert.h>
#include "PImage.h"
#include <cmath>
#include <cstdlib>

void GenereteGaussMask(double** &gaussMask,double sigma,int maskWidth)
{
    assert(sigma != 0);
    assert(maskWidth >= 0);

    gaussMask = (double**)malloc(sizeof(double*) * maskWidth); 
    assert(gaussMask != NULL);
    
    for(int i = 0; i < maskWidth; i++)
    {
	gaussMask[i] = (double*)malloc(sizeof(double) * maskWidth);
	assert(gaussMask[i] != NULL);
    }
    
    double minValue = 10000;
    for(int i = -(maskWidth) / 2; i <= maskWidth / 2; i++)
    {
	for(int j = -(maskWidth) / 2; j <= maskWidth / 2; j++)
	{
	    double value = (1 / (2*PI*(sigma*sigma))) * (exp(-((i*i + j*j)/(2*sigma*sigma))));
	    if(value < minValue)
	    {
		minValue = value;
	    }
	    gaussMask[i+(maskWidth/2)][j+(maskWidth/2)] = value;
	}
    }

    for(int i = -(maskWidth) / 2; i <= maskWidth / 2; i++)
    {
	for(int j = -(maskWidth) / 2; j <= maskWidth / 2; j++)
	{
	    gaussMask[i+(maskWidth/2)][j+(maskWidth/2)] = floor(gaussMask[i+(maskWidth/2)][j+(maskWidth/2)] / minValue);
	}
    }
}
