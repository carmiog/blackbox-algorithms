#include <gtest/gtest.h>
#include <armadillo>
#include <iostream>
#include "function.hpp"
#include "directional_search.hpp"

class Circle : public MultivariateFunctionR {
public: 
    double evaluate(const arma::colvec& p) const {
        return p[0]*p[0] + p[1]*p[1];
    }
    
    int from_dim() const {
        return 2;
    }
};

class Carre : public MultivariateFunctionR {
public:
    double evaluate(const arma::colvec& p) const {
        return fabs(p[0] + p[1]) + fabs(p[0] - p[1]);
    }

    int from_dim() const {
        return 2;
    }
};

TEST(coordinate_search, circle) {
    Circle f;
    arma::colvec x0{2, 2};
    arma::colvec minimizer = coordinate_search(f, x0, 0.5, 1e-4);
    ASSERT_FLOAT_EQ(0, arma::norm(minimizer));
}

TEST(coordinate_search, carre) {
    Carre f;
    arma::colvec x0{0, 5};
    arma::colvec minimizer = coordinate_search(f, x0, 0.5, 1e-1);
    ASSERT_FLOAT_EQ(0, arma::norm(minimizer));
}
