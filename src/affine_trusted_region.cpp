#include "affine_trusted_region.hpp"
#include <iostream>
#include <armadillo>
#include "function.hpp"

arma::colvec affine_trusted_region_linear_minimize(const MultivariateFunctionR& f, const arma::colvec& x0, double radius, int limit) {
    int iterations = 0;
    //int iteration = 0;
    arma::colvec x{x0};
    arma::colvec last1;
    arma::colvec last2;
    while (iterations < limit || limit <= 0) {
        last2 = last1;
        last1 = x;
        arma::colvec b = f.differentiate(x);
        x = x - (radius/arma::norm(b))*b;
        if(iterations > 2 && arma::all(x == last2)) {
            return (last1 + x)/2.0;
        }
        ++iterations;
    }
    return x;
}
