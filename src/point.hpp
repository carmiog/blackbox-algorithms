#ifndef SRC_POINT_H_
#define SRC_POINT_H_

#include <vector>

class Point {
public:
    explicit Point(const std::vector<double>& coordinates);
    Point();
    Point(const Point& other);
    explicit Point(Point& other);
    int dim() const;
    double at(int index) const;
    double norm2() const;
    double dot(const Point& other) const;
    
    double& operator[](int index);
    double operator[](int index) const;
    Point& operator*=(double lambda);
    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
    Point& operator/=(double lambda);
    Point& operator=(const Point& other);
private:
    std::vector<double> coordinates_;
    int dim_;
};

Point operator-(const Point& p);
Point operator+(const Point& p1, const Point& p2);
Point operator-(const Point& p1, const Point& p2);
Point operator*(double lambda, const Point& p);
Point operator*(const Point& p, double lambda);
Point operator/(const Point&, double lambda);
bool operator==(const Point& p1, const Point& p2);

#endif