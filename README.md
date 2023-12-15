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
Fixed-Point can be applied when the input and output dimensions of the function are equal.\

## Compile the project

## Flow and usage

In our case, we've decided to focus on systems of polynomial equations.
Here are the stages of the program:

- main()
- the coefficients of the polynome are read from the file XXX.CSV that must be filled by the user. The system of equation is created in this way.
- the user must enter the method to be used on the terminal (follow the request on the terminal).
- the user must enter the needed parameter to initialize the method (follow the request on the terminal).
- if the method is correctly initialized, the position and its evaluation is printed. A graph illustrates the possible convergence of method.

Concerning the format of the XXX.CSV, each line correspond to the output dimension (if one line the output is in R^1, two lines output in R^2,...). The column corresponds to the coefficient of the polynome.

Example of usage :

$$1 2 3$$\
$$0 5 0$$

correspond to the system of equation :

$$1 + 2x^2 + 3x^3$$\
$$0 + 5x^2 + 0x^3$$

## Perspectives
### Organization
parler de eigen, google test 
### improvements in application options


## Authors
Enora Gatignol, Thibault Schiesser

