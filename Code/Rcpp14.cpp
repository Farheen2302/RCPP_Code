#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
bool any_naC(NumericVector x) {
  return is_true(any(is_na(x)));
}

> sourceCpp('/home/farheen/Desktop/Rcpp_16_6/Rcpp14.cpp')
> any_naC(x)
[1] FALSE
> x
[1] 3
> x <- c(1,2,3,4,5,6,NA,34)
> any_naC(x)
[1] TRUE
> 