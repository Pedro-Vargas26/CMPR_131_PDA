#pragma once
#ifndef STATISTICAL_H
#define STATISTICAL_H

#include "DynamicArray.h"

class Statistical {
private:
    DynamicArray<double> dataset; 
 
public:
    
    Statistical(const DynamicArray<double>& dataset);
    double mean() const;
    double varianceIn();
    double standarddeviation();
    double midrangeIn();
    double quartilesIn();
    double outliers();
    double thesumofsquares();
    double median(double arr[], int start, int end);
    double meanabsolutedeviation();
    double rootmeansquare();


};
  

#endif
