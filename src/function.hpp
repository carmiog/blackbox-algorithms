#ifndef SRC_FUNCTION_H_
#define SRC_FUNCTION_H_

#include <armadillo>
#include <iostream>
class MultivariateFunction {
public:
    virtual ~MultivariateFunction() {}
    virtual arma::colvec evaluate(const arma::colvec& p) const =0;
    virtual arma::mat differentiate(const arma::colvec& p) const {
        std::cerr << "Gradient not implemented" << std::endl;
        return arma::colvec{p};
    }
    virtual int from_dim() const =0;
    virtual int to_dim() const =0;
};

class MultivariateFunctionR {
public:
    virtual ~MultivariateFunctionR() {}
    virtual double evaluate(const arma::colvec& p) const =0;
    virtual arma::colvec differentiate(const arma::colvec& p) const {
        std::cerr << "Gradient not implemented" << std::endl;
        return arma::colvec{p};
    }
    virtual int from_dim() const =0;
};

#endif  // SRC_FUNCTION_H_