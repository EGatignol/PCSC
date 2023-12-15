# PCSC project : Implementation of numerical methods for the solution of nonlinear equations.

## General description
The aim of the project is to solve nonlinear equations. The methods considered are :
- Bissection
- Fixed Point
- Newton
- Classic Chord
  
For fixed-point methods (general fixed point and its special cases, such as the classic chord and Newton), you can use an "Aitken" convergence accelerator. 

Conditions of use for each method :

The bissection and classic chord methods only consider scalar nonlinear problem.\
Newton can be applied to all kinds of non-linear equations regardless of input and output dimensions.\
Fixed-Point can be applied when the input and output dimensions of the function are equal.

## Compile the project

g++ -Wall -c main.cc result_method.cc function.cc polynomial_1_to_n.cc find_root.cc fixed_point.cc newton.cc classic_chord.cc bissection.cc CSVReaderPolynome.cpp PlotConvergence.cpp

## Flow and usage

In our case, we've decided to focus on systems of polynomial equations.
Here are the stages of the program:

- main()
- the coefficients of the polynome are read from the file Coeff_F1.csv that must be filled by the user. The system of equation is created in this way.
- the user must enter the method to be used on the terminal (follow the request on the terminal).
- the user must enter the needed parameter to initialize the method (follow the request on the terminal).
- if the method is correctly initialized, the position and its evaluation is printed. A graph illustrates the possible convergence of method.

Concerning the format of the Coeff_F1.csv, each line correspond to the output dimension (if one line the output is in $R^1$, two lines output in $R^2$,...). The column corresponds to the coefficient of the polynome.

Example of usage in the Coeff_F1.csv:

<pre>
1  2  3
0  5  0
</pre>

correspond to the system of equation :

$$
\begin{align*}
1 &+ 2x + 3x^2 \\
0 &+ 5x + 0x^2 \\
\end{align*}
$$
## Test
Several tests were carried out using google test. To reproduce these and/or add new ones, you first need to clone the github google test in the project location using the command :
<p align="center">
  git clone git@github.com:google/googletest.git
</p>
The tests carried out concern the correct initialization of the methods (respect of dimensions) and the verification of the convergence of the methods for simple cases.

## Perspectives

### Organization
parler de eigen, google test 
### improvements in application options


## Authors
Enora Gatignol, Thibault Schiesser

