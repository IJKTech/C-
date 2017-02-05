#include "GradientDescent.h"

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	//cout << "Hello" << endl;
	vector<double> y;
	vector<double> x_row;
	vector<double> theta;
	int i;

	GradientDescent g;

	for (i=0; i < 50; i++)
	{
		y.push_back(3.0 - 7.0*(double)i + 2.0*(double)(i*i) + 0.5*(double)rand()/(double)RAND_MAX);
		x_row.push_back(1.0);	//Must always be 1.0, fitting a function such as y = ax^2 + bx + c this represents the c
		x_row.push_back((double)i); // to find b
		x_row.push_back((double)(i*i)); // to find c
		g.add_x_row(x_row);
		x_row.clear();
	}
	theta.push_back(1.0);
	theta.push_back(1.0);
	theta.push_back(1.0);
	
	g.set_theta(theta);
	g.set_y(y);

	g.set_iterations(5000);
	//Might take a while
	g.calculate();

	theta = g.get_theta();

	double check = theta[0] + theta[1]*g.normed(10.0, 1) + theta[2]*g.normed(100.0,2);

	cout << "Fitted: " << check << endl;
	cout << "Truth: " << 3.0 - 7.0*10.0 +2.0*100.0 << endl;

	return 0;
}