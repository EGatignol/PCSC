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

The command to compile :
<p align="center">
  g++ -Wall -c main.cc result_method.cc function.cc polynomial_1_to_n.cc find_root.cc fixed_point.cc newton.cc classic_chord.cc bissection.cc CSVReaderPolynome.cpp PlotConvergence.cpp
</p>

## Flow and usage

In our case, we've decided to focus on systems of polynomial equations.
Here are the stages of the program:

- main()
- the coefficients of the polynome are read from the file Coeff_F1.csv that must be filled by the user. The system of equation is created in this way.
- the user must enter the method to be used on the terminal (follow the request on the terminal).
- the user must enter the needed parameter to initialize the method (follow the request on the terminal).
- if the method is correctly initialized, the position and its evaluation is printed. A graph illustrates the possible convergence of method.

Concerning the format of the Coeff_F1.csv, each line correspond to the output dimension (if one line the output is in $R^1$, two lines output in $R^2$,...). The column corresponds to the coefficient of the polynome.

Example of usage in the Coeff_F1.csv (pay attention to add 0 until the largest degree of the complete system):

<pre>
1  2  3
0  5  0
</pre>

which correspond to the system of equation :

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

Then you can compile the test by using :

<p align="center">
  g++ -Wall -c result_method.cc function.cc polynomial_1_to_n.cc find_root.cc fixed_point.cc newton.cc classic_chord.cc bissection.cc test.cpp
</p>

The tests carried out concern the correct initialization of the methods (respect of dimensions) and the verification of the convergence of the methods for simple cases.

## Documentation

It is possible to generate a documentation of the project using doxygen, with the following command in the terminal :

<p align="center">
  doxygen Doxygen
</p>

## Perspectives

### Improvements in organization

We use three different libraries that we need to add into the project: Eigen, googletest and gnuplot.
  - The library Eigen is directly in the github. The disadvantage is that the file is very heavy.
  - Googletest need to be clone outside of github by the user (as explain in test). So that is not optimal.
  - The library Gnuplot is a submodle in github. So we can directly obtain it from github without the file being too large in github.

So to improve the organization, Eigen and Googletest would also have to be submodules.

A .gitIgnore could also have been added to the project, so as to avoid any status errors on the github due to generated files (which don't have to be pushed). 

### Improvements in application options
For the moment, the code focuses on solving systems of polynomial functions. This considerably limits the possible applications of our code. To extend the code, it is possible to add a daughter class to the existing "Function" class. If this new class follows the same structure as our polynomial class (output type, evaluation of the function and its derivative/jacobian, a possible function for fixed-point), the use of our iterative methods will not be affected. To this aim, the use of parsers could be of interest.

It should also be noted that most of our code has been created dynamically, to give us a degree of flexibility without having to extend a lot of templates. This could be an interesting area for reflection.

## Sources

- gnuplot documentation
- eigen documentation
- course support : Programming concepts in scientific computing

## Authors
Enora Gatignol, Thibault Schiesser

