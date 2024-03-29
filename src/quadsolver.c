/**
 * Part of Quadsolver program
 * Software created by Jared Teller and Joe Manto
 * Licensed under GNU General Public License. See LICENSE.txt for more information.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "getInput.h"
#include "quadsolver.h"
#include <math.h>

/**
 * Execution of the program starts here
 * @param [int argc] the number of command line arguments
 * @param [char const *argv] the array of strings entered in the command line
 */ 
int main(int argc, char const *argv[]) {

  showDetails();
  //200 should be the max number of character for 3 floats.
  while(input(solve,1024));

  return 0;
}

/**
 * This function prints the details section of the program to the user when called.
 */
void showDetails(){
  printf("%s\n","QuadSolver v1 written by Joe Manto & Jared Teller");
  printf("%s\n","[Help] 'h' for the help details");
  printf("%s\n","[Exit] 'q' to quit the program");
  printf("%s\n","[Logging] 'l' to start redirecting sdtout");
}


/**
 * This function finds the discriminant of the quadratic (what is under the square root) b*b -4ac
 * The proper checks for d > 0, d<0, d=0 will be made and the expected result will be printed
 * @param [double a] 
 * @param [double b]
 * @param [double c]
 */ 
double findDiscriminant(double a, double b, double c){
    double discriminant = b * b - 4.0 * a * c;
    if(discriminant < 0.0f){
        printf("\nDiscriminant: %lf   No real number solution with the given input.\n", discriminant);
        return -1;
    }else if(discriminant > 0.0f){
        printf("\nDiscriminant: %lf   Two distinct real number answers are expected.\n", discriminant);
        return discriminant;
    }else{
        printf("\nDiscriminant: %lf   A repeated real number solution is expected.\n", discriminant);
        return discriminant;
    }
    return 0;
}

/**
 * This function is a helper that prints the results of the quadratic formula
 */
void printResult(double a, double b, double c, double * roots){
  
  printf("\n\t%.15gx^2 + %.15gx + %.15g = 0\n\n\troot1: %.15g,\troot2: %.15g\n\n",a,b,c,roots[0],roots[1]);
    
}

/**
 * This is the core solving function that will compute the roots of the quadratic equation
 * @param [double *args] The 3 arguments a b and c 
 */
double * solve(double * args){
  double a = args[0];
  double b = args[1];
  double c = args[2];
  double d = findDiscriminant(a, b, c); //get the discriminant

  
  double * roots = malloc(sizeof(double)*2);
  roots[0] = FP_NAN; roots[1] = FP_NAN;

  if(d == -1) return roots; //negative discriminant
  if(fpclassify(d) == FP_ZERO){ //the discriminant was 0 so the solution is one repeated number -b / 2 * a
    double rootx2 = (-b) / (2 * a); //no need to +- 0
     roots[0] = rootx2;
     roots[1] = rootx2;
  }else{ //two distinct real roots
    double root1 = ((-b) + sqrt(d)) / (2 * a); 
    double root2 = ((-b) - sqrt(d)) / (2 * a);
    roots[0] = root1; roots[1] = root2;
  }
  
  printResult(a,b,c,roots);
  free(args);

  return roots;
}
