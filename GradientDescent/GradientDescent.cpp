#include "GradientDescent.h"

GradientDescent::GradientDescent()
{
	step_size = 0.05;
	iterations = 1000;
}

void GradientDescent::set_y(std::vector<double> user_y)
{
	y = user_y;
}

void GradientDescent::add_x_row(std::vector<double> row)
{
	x.push_back(row);
}

void GradientDescent::set_theta(std::vector<double> th)
{
	theta = th;
}

std::vector<double> GradientDescent::get_theta()
{
	return theta;
}

double GradientDescent::normed(double value, int feature_number)
{
	return (value - e_x[feature_number-1]) / std[feature_number-1];
}

double GradientDescent::get_step()
{
	return step_size;
}

void GradientDescent::set_step(double s)
{
	step_size = s;
}

int GradientDescent::get_iterations()
{
	return iterations;
}

void GradientDescent::set_iterations(int i)
{
	iterations = i;
}

void GradientDescent::calculate()
{
	std::cout << "x : " << x.size() << ", " << x[0].size() << std::endl;
	std::cout << "y : " << y.size() << std::endl;
	std::cout << "theta : " << theta.size() << std::endl;  
	feature_norm_x();
	gradientDescent(step_size, iterations);
}


double GradientDescent::innerProduct(std::vector<double> a, std::vector<double> b)
{
	int i;
	double prod = 0.0;

	for (i=0; i<a.size(); i++)
	{
		prod += a[i]*b[i];
	}
	return prod;
}

void GradientDescent::gradientDescent(double alpha, int iterations)
{
	int iter;
	int feat;
	int ex;
	
	for (iter = 0; iter < iterations; iter++)
	{
		 
		for (feat = 0; feat < theta.size(); feat++)
		{
			
			double grad = 0.0;
			double inner_prod_sum = 0.0;

			//Replaces the lambda call in python
			for (ex = 0; ex < y.size(); ex++)
			{
				
				std::vector<double> xtemp;
				int dummy = 0;
				for (dummy = 0; dummy < x[0].size(); dummy++)
				{
					xtemp.push_back(x[ex][dummy]);
				}

				inner_prod_sum += (innerProduct(theta, xtemp) - y[ex])*x[ex][feat];
			}

			grad = (1.0 / (double)y.size())*inner_prod_sum;
			double temp = theta[feat] - alpha*grad;
			theta[feat] = temp;

		}
	}

}

void GradientDescent::feature_norm_x()
{
	int sample = 0;
	int feature = 0;

	for(feature=1; feature < theta.size(); feature++)
	{
		e_x.push_back(0.0);
		e_x2.push_back(0.0);
	}

	for (sample = 0; sample < y.size(); sample++)
	{
		for(feature=1; feature < theta.size(); feature++)
		{
			e_x[feature-1] += x[sample][feature];
			e_x2[feature-1] += x[sample][feature]*x[sample][feature];
		}
	}	

	for (feature = 0; feature < theta.size()-1; feature++)
	{
		e_x[feature] /= (double)y.size();
		e_x2[feature] /= (double)y.size();
		double var = e_x2[feature] - e_x[feature]*e_x[feature];
		if (var > 0.00001)
		{
			std.push_back(sqrt(var));
		}
		else
		{
			std.push_back(0);
		}

	}

	for (sample = 0; sample < y.size(); sample++)
	{
		for(feature=1; feature < theta.size(); feature++)
		{
			if(std[feature-1] != 0)
			{
				x[sample][feature] = (x[sample][feature] - e_x[feature-1]) / std[feature-1];
			}
			else
			{
				x[sample][feature] = 0;
			}
		}
	}	

	for (feature = 1; feature < theta.size(); feature++)
	{
		std::cout << e_x[feature-1] << ", " << std[feature-1] << std::endl; 
	}
}