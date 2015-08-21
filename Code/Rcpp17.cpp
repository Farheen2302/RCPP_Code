
#include <Rcpp.h>

using namespace Rcpp;
// [[Rcpp::export]]
double sum4(NumericVector x)
{
  return std::accumulate(x.begin(), x.end(), 0.0);
}


> sourceCpp('/home/farheen/Desktop/Rcpp_16_6/Rcpp17.cpp')
> sum4(x)
[1] 18
> 