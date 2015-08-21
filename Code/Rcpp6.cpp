#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]

NumericVector CallRfunc(NumericVector x,Function f)
{
  NumericVector res = f(x);
  return res;
}