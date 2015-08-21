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
        