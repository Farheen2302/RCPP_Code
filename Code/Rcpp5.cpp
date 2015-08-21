#include <Rcpp.h>

using namespace Rcpp;
// [[Rcpp::export]]
double mpe(List mod)
{
    if(!mod.inherits("lm"))
        stop("Only linear model accepted");
        
    NumericVector resid = as<NumericVector>(mod["residuals"]);
    NumericVector fitted =as<NumericVector>(mod["fitted.values"]);
    int n = resid.size();
    double err = 0;
    for(int i = 0 ; i < n ; i++)
    {
        err += resid[i]/(resid[i]+fitted[i]);
    }
    return err/n;
}


##Functions

func <-function(x) {
  i <- 0
  y <- 5
  for(i in seq(y)) {
    print (x[i])
  }
}

NumericVector CallRfunc(NumericVector,Function f)
{
  NumericVector res = f(x);
  return res;
}

##missing Values

