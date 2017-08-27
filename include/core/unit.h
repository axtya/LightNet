//core/unit.h

/*
Header file for the base class for units.
The unit is a simple object which can be used as a weight, bias, or function,
and comes wrapped together with members representing the last input and the gradient
*/

#pragma once

typedef double(*ActivationFunction)(double);

union Parameter
{
	double weight;
	double bias;
	ActivationFunction activation;
};

class Unit
{
	protected:

		Parameter param;
		double gradient;
		double lastInput;
	
	public:

	    virtual double forwardPropagate(double) =0;
		virtual void backwardPropagate(double) =0;
		virtual double getParameter();

		friend Optimizer;
};

