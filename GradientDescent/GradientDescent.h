#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H
#include <vector>
#include <cmath>
#include <iostream>

class GradientDescent
{
public:                    
    
    GradientDescent();
    void set_y(std::vector<double> user_y);
    void add_x_row(std::vector<double> row);
    void set_theta(std::vector<double> th);
    std::vector<double> get_theta();
    double normed(double value, int feature_number);
    double get_step();
    void set_step(double s);
    int get_iterations();
    void set_iterations(int i);
    void calculate();
    
private:                   
    
    std::vector< std::vector<double> > x; // holds features
    std::vector<double> y; //holds data to fit to
    std::vector<double> theta;
    std::vector<double> e_x;
    std::vector<double> e_x2;
    std::vector<double> std;
    double step_size;
    int iterations;
    void feature_norm_x();
    double innerProduct(std::vector<double> a, std::vector<double> b);
    void gradientDescent( double alpha, int iterations);
    
};



#endif