/**
 * Part of Quadsolver program
 * Software created by Jared Teller and Joe Manto
 * Licensed under GNU General Public License. See LICENSE.txt for more information.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "../../src/getInput.h"
#include "../../src/quadsolver.h"

/**
 * Validates roots, expected vs output
 */ 
int vaildateRoots(double * expectedRoots,double * output){
    for(int i = 0;i<2;i++){
        if(expectedRoots[i] != output[i]){
            return 0;
        }
    }
    return 1;
}

/**
 * This will show us how accurate our answer is compared to what we expect
 */ 
double relativeError(double * derived, double * correct){
    double error = 0.0;

    for(int i = 0; i<2; i++){
        error+=fabs(derived[i]-correct[i])/correct[i];
    }
    return error/2.0f;
}

//MAIN FUNCTION
int main(int argc,char *argv[]){
    
    setUpErrLogging(); //sets stderr redirecting to cerr.log

    double * input = malloc(sizeof(double)*3);
    //this is a = 1, b = 2, c = 1, expected output is -1,-1 for roots
    input[0] = 1;
    input[1] = 2;
    input[2] = 1;

    double * expectedRoots = malloc(sizeof(double)*2);
    expectedRoots[0] = -1;
    expectedRoots[1] = -1;

    assert(vaildateRoots(expectedRoots,solve(input)) == 1);


    //this is a case where the discriminant is guaranted to be less than 0, expected no real numbers
    double * input1 = malloc(sizeof(double)*3);
    input1[0] = 7.213213;
    input1[1] = 2.15;
    input1[2] = 4.12312123;
    
    double * expectedRoots1 = malloc(sizeof(double)*2);
    expectedRoots1[0] = FP_NAN;
    expectedRoots1[1] = FP_NAN;


    assert(vaildateRoots(expectedRoots1,solve(input1)) == 1);

    double * input2 = malloc(sizeof(double)*3);
    input2[0] = 3.4934924;
    input2[1] = 18.3492934;
    input2[2] = 1.342424234;
    
    double * expectedRoots2 = malloc(sizeof(double)*2);
    expectedRoots2[0] = -0.0742078838284386;
    expectedRoots2[1] = -5.17821327500964;

    printf("Relative Error : %.15lf\n",relativeError(expectedRoots2,solve(input2)));

    printf("%s\n","✅🤖ALL TESTS PASSED🤖✅");
    return 0;
}


