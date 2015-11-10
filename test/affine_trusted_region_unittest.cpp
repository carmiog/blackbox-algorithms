#include <gtest/gtest.h>
#include <armadillo>
#include "function.hpp"
#include "affine_trusted_region.hpp"

class Circle : public MultivariateFunctionR {
public:    
    double evaluate(const arma::colvec& p) const {
        return p[0]*p[0] + p[1]*p[1];
    }
    
    arma::colvec differentiate(const arma::colvec& p) const {
        return arma::colvec{2*p[0], 2*p[1]};
    }
    
    int from_dim() const {
        return 2;
    }
};

TEST(linear, circle) {
    Circle f;
    arma::colvec x0{2, 2};
    arma::colvec minimizer = affine_trusted_region_linear_minimize(f, x0, 1e-4);
    ASSERT_TRUE(arma::norm(minimizer) < 1e-4);
}

TEST(linear, circle_infinite) {
    Circle f;
    arma::colvec x0{2, 2};
    arma::colvec minimizer = affine_trusted_region_linear_minimize(f, x0, 1e-4, 0);
    ASSERT_TRUE(arma::norm(minimizer) < 1e-4);
}
