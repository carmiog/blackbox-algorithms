#ifndef SRC_DIRECTIONAL_SEARCH_H_
#define SRC_DIRECTIONAL_SEARCH_H_
#include <armadillo>
#include "function.hpp"
enum coordinate_search_heuristic_t {
    BEST = 1 << 0, FIRST = 1 << 1, DYNAMIC = 1 << 2
};

coordinate_search_heuristic_t operator|(coordinate_search_heuristic_t t1, coordinate_search_heuristic_t t2);

arma::colvec coordinate_search(const MultivariateFunctionR& f, const arma::colvec& x0, double s0, double precision=1e-4, coordinate_search_heuristic_t heuristic=FIRST | DYNAMIC, double mu=1, double beta=1, double alpha=0.5, int limit=100000);
#endif