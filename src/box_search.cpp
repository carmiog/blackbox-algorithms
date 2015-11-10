#include "box_search.hpp"
#include <vector>
#include <armadillo>
std::vector<int> get_boxes_with_greatest_dimension(const std::vector<arma::mat>& boxes) {
    std::vector<int> res;
    vector<arma::rowvec> widths;
    for (auto box : boxes)
        widths.push_back(box.row(1) - box.row(0));
    double max_width = 0;
    for (auto width : widths)
        if(arma::max(width) > max_width)
            max_width = arma::max(width);
     
}

direct_minimize(const MultivariateFunctionR& f, const arma::mat initial_box, int limit) {
    int iterations = 0;
    std::vector<arma::mat> boxes = {initial_box};
    while(iterations < limit) {
        
    }
}