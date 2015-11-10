#include "point.hpp"
#include <cmath>

Point::Point(const std::vector<double>& coordinates): coordinates_(coordinates) {
    dim_ = coordinates_.size();
}

Point::Point(const Point& other) {
    *this = other;
}

Point::Point(Point& other) {
    *this = other;
}

Point::Point(): dim_(0) {}

int Point::dim() const {
    return dim_;
}

double Point::at(int index) const {
    return coordinates_[index];
}
double Point::norm2() const {
    double norm = 0;
    for(double x : coordinates_)
        norm += x*x;
    return sqrt(norm);
}

double Point::dot(const Point& other) const {
    double res = 0;
    for(int i = 0; i < dim_; ++i) {
        res += at(i)*other.at(i);
    }
    return res;
}

double Point::operator[](int index) const {
    return coordinates_[index];
}

double& Point::operator[](int index) {
    return coordinates_[index];
}

Point& Point::operator*=(double lambda) {
    for(int i = 0; i < dim_; ++i)
        coordinates_[i] *= lambda;
    return *this;
}

Point& Point::operator+=(const Point& other) {
    for(int i = 0; i < dim_; ++i)
        coordinates_[i] += other[i];
    return *this;
}

Point& Point::operator-=(const Point& other) {
    for(int i = 0; i < dim_; ++i)
        coordinates_[i] -= other[i];
    return *this;
}

Point& Point::operator/=(double lambda) {
    for(int i = 0; i < dim_; ++i)
        coordinates_[i] /= lambda;
    return *this;
}

Point& Point::operator=(const Point& other) {
    if(&other == this)
        return *this;
    coordinates_.resize(other.dim());
    dim_ = other.dim();
    for(int i = 0; i < dim_; ++i)
        coordinates_[i] = other[i];
    return *this;
}

Point operator-(const Point& p) {
    Point new_p{p};
    for(int i = 0; i < p.dim(); ++i)
        new_p[i] *= -1;
    return new_p;
}


Point operator+(const Point& p1, const Point& p2) {
    Point p{p1};
    p += p2;
    return p;
}

Point operator-(const Point& p1, const Point& p2) {
    Point p{p1};
    p += (-p2);
    return p;
}

Point operator*(double lambda, const Point& p) {
    Point new_p{p};
    new_p *= lambda;
    return new_p;
}

Point operator*(const Point& p, double lambda) {
    return lambda*p;
}

Point operator/(const Point& p, double lambda) {
    Point new_p{p};
    new_p /= lambda;
    return new_p;
}

bool operator==(const Point& p1, const Point& p2) {
    if(p1.dim() != p2.dim())
        return false;
    for(int i = 0; i < p1.dim(); ++i)
        if(p1[i] != p2[i])
            return false;
    return true;
}

