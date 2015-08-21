#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector pdistC(NumericVector x, double ys)
{
    return sqrt(pow((x - ys),2));
}