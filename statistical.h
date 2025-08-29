#pragma once
#ifndef STATISTICAL_H
#define STATISTICAL_H

#include "DynamicArray.h"

class Statistical {
  
public:
    DynamicArray<double> dataset;
    
    
    Statistical(const DynamicArray<double>& dataset);


   static  double  standarddeviation(const DynamicArray<double>& dataset);

    static double varianceIn(const DynamicArray<double>& dataset);

    static double midrangeIn(const DynamicArray<double>& dataset);

    static double quartilesIn(const DynamicArray<double>& dataset);

    static double  outliers(const DynamicArray<double>& dataset);

    static  double mean(const DynamicArray<double>& data);

    static double thesumofsquares(const DynamicArray<double>& dataset);

    static double meanabsolutedeviation(const DynamicArray<double>& dataset); 

   static double rootmeansquare(const DynamicArray<double>& dataset);

private:

    static double median(double arr[], int start, int end);
};
  

#endif
