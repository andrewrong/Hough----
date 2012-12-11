#include "PImage.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

int main()
{
    double sigma = 1.4;
    double **mask = NULL;
    int maskWidth = 5;
    cout<<"Please input sigma and mask's width: ";
    cin>>sigma>>maskWidth;
    
    assert(sigma >= 0 && maskWidth >= 0);

    GenereteGaussMask(mask,sigma,maskWidth);

    for(int i = 0; i < maskWidth; i++)
    {
	for(int j = 0; j < maskWidth; j++)
	{
	    cout<<mask[i][j]<<" ";
	}
	cout<<endl;
    }
    
    for(int i = 0; i < maskWidth; i++)
    {
	free(mask[i]);
    }
    free(mask);

    return 0;
}
