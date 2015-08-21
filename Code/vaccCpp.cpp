#include <Rcpp.h>
using  namespace Rcpp;

double vaccCpp(double age,bool female, bool ily)
{
	double p = .25 + .3 * 1/(1 - exp(0.04 * age)) + 0.1 * ily;
	p = p * (female ? 1.25 : 0.75);
	p = std::max(p,0.0);
	p = std::min(p,1.0);
	return p;
}


// [[Rcpp::export]]
 NumericVector vaccRcpp(NumericVector age,LogicalVector female,LogicalVector ily) {
	 int n = age.size();
	 NumericVector out(n);
	for(int i = 0; i < n; i++)
	{
		out[i] = vaccCpp(age[i],female[i],ily[i]);
	}
	return out;
	
}
