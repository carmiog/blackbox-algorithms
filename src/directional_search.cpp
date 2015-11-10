#include "directional_search.hpp"
#include <armadillo>
#include "function.hpp"
coordinate_search_heuristic_t operator|(coordinate_search_heuristic_t t1, coordinate_search_heuristic_t t2) {
    return static_cast<coordinate_search_heuristic_t>(static_cast<int>(t1) | static_cast<int>(t2));
}

arma::colvec coordinate_search(const MultivariateFunctionR& f, const arma::colvec& x0, double s,  double precision, coordinate_search_heuristic_t heuristic, double mu, double beta, double alpha, int limit) {
    int iterations = 0;
    int dim = f.from_dim();
    arma::mat eye(dim, dim, arma::fill::eye);
    arma::mat directions_set = join_rows(eye, -eye);
    arma::colvec x{x0};
    double x_eval = f.evaluate(x);
    int mem = 0;
    while (s > precision && (iterations < limit || limit <= 0)) {
        if(!(heuristic & DYNAMIC))
            mem = 0;
        bool found = false;
        arma::colvec improving_point = x;
        double improving_eval = x_eval;
        int polling_count = 0;
        
        // Find improving direction
        while (polling_count < dim*2 && !(found && heuristic & FIRST)) {
            const arma::colvec& d = directions_set.col(mem);
            double direction_eval = f.evaluate(x + s*d);
            if (direction_eval < improving_eval && direction_eval < mu*x_eval) {
                improving_point = x + s*d;
                improving_eval = direction_eval;
                found = true;
            }
            mem = (mem + 1) % (dim*2);
            ++polling_count;
        }
        
        if (found) {
            s *= beta;
            x = improving_point;
            x_eval = improving_eval;
        } else {
            s *= alpha;
        }
    }
    return x;
}
