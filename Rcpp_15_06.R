library("Rcpp")
cppFunction('int add(int a, int b, int c){int sum = a + b +c;return sum;}')
add(4,5,6)

R code:
  
  signR <-function(x){
    if(x>1){
      1
    }else if(x==0){
      0
    }else {
      -1
    }
  }
C Code:
  int signR(int x){
    if(x>0)
      return 1;
    else if(x==0)
      return 0;
    else 
      return -1;
  }
Rcpp code:
  cppFunction('int signR(int x){
    if(x>0)
      return 1;
    else if(x==0)
      return 0;
    else 
      return -1;
  }')

#Vector input and scalar output
sumR<- function(x){
  total <-0
  for(i in seq_along(x)){
    total <-total + x[i]
  }
  total
  }
C++ code:
cppFunction('double sumC(NumericVector x){
  double total = 0;
  int i=0;
  int len = x.size();
  for(i=0;i<len;i++)
  {
    total = total + x[i];
  }
  return total;
}')
#Vector input vector output

pdistR <- function(x, ys){
  sqrt((x - ys) ^ 2)
}


NumericVector pdisC(double x, NumericVector ys)
{
  int n = ys.size();
  NumericVector out(n);
  for(int i=0li<n;i++){
    out[i]=sqrt(pow(x-ys),2.0);
  }
  return out;
}
cppFunction('NumericVector pdistC(double x, NumericVector ys)
{
  int n = ys.size();
  NumericVector out(n);
  for(int i = 0; i< n ; i++) {
    out[i]=sqrt(pow(x - ys[i],2.0));
  }
  return out;
}')


#using sourceCpp
#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
double meanC(NumericVector x)
{
  int n = x.size();
  double total = 0.0;
  for(int i = 0; i < n ; i++)
  {
    total += x[i];
  }
  return total/n;
}

#Passing function as a parameter to other function
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int func(Function pred,NumericVector x)
{
  int n = x.size();
  for(int i = 0 ; i < n ; i++)
  {
    NumericVector res = pred(x[i]);
    if(res[0])
      return i + 1;
  }
  return 0;
}
##minmax
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector mini(NumericVector x, NumericVector y)
{
  int n = std::max(x.size(),y.size());
  NumericVector x1 = rep_len(x, n);
  NumericVector y1 = rep_len(y, n);
  NumericVector out(n);
  for(int i = 0 ; i < n ; i++)
  {
    out[i] = std::min(x1[i], y1[i]);
  }
  return out;
}
##Attributes and classes
#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export]]
NumericVector attrbs()
{
  NumericVector out = NumericVector::create(1,2,3);
  out.names()=CharacterVector::create('a','b','c');
  out.attr("my-attr")="My_attributes";
  out.attr("class")="my-class";
  
  return out;
}

###
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
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]

List scal_mis()
{
  int int_s=NA_INTEGER;
  String chr_s=NA_STRING;
  bool lgl_s = NA_LOGICAL;
  double num_s = NA_REAL;
  
  return List::create(int_s,chr_s,lgl_s,num_s);
}
