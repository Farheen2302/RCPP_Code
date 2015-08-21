#include <Rcpp.h>

using namespace Rcpp;
// [[Rcpp::export]]

IntegerVector findInterval2(NumericVector a, NumericVector y)
{
    IntegerVector out(a.size());
    NumericVector::iterator it, pos;
    IntegerVector::iterator out_it;
    
    for(it = a.begin(), out_it = out.begin(); it != a.end(); ++it,++out_it)
    {
        pos = std::upper_bound(y.begin(),y.end(),*it);
        *out_it = std::distance(y.begin(),pos);
    }
    return out;
}