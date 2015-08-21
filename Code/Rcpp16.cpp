#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
double sum4(NumericVector x)
{
    double total = 0.0;
    NumericVector::iterator it;
    for(it = x.begin() ;it != x.end();++it)
    {
        if(NumericVector::is_na(*it) == FALSE)
          {
            total += *it;
          }
    }
    
    return total;
}

#Accumulate function
#include <Rcpp.h>

using namespace Rcpp;
// [[Rcpp::export]]
double sum4(NumericVector x)
{
  return std::accumulate(x.begin(), x.end(), 0.0);
}

