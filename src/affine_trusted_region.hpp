#ifndef SRC_AFFINE_TRUSTED_REGION_H_
#define SRC_AFFINE_TRUSTED_REGION_H_
#include <armadillo>
#include "function.hpp"

arma::colvec affine_trusted_region_linear_minimize(const MultivariateFunctionR& f, const arma::colvec& x0, double radius, int limit=1000000);
#endif