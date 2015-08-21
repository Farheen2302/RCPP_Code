#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int func(Function pred,NumericVector x)
{
    int n = x.size();
    for(int i = 0 ; i < n ; i++)
    {
        NumericVector res = pred(x[i);
        if(res[0])
            return i + 1;
        }
    return 0;
    }
    