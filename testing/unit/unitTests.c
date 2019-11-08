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
#include <float.h>

#include "../../src/getInput.h"
#include "../../src/quadsolver.h"

int checkFlagTest();
int checkForRoundOffTest();
int checkDoubleClassification();
int checkCovertTokensToDouble();
int checkFindDiscriminant();

/**
 * Main function, program starts here
 * @param [int argc] number of arguments
 * @param [char const *argv[]] array of char arrays
 */ 
int main(int argc,char *argv[]){
    int func = atoi(argv[1]); //returns 0 if cannot convert to an integer
    
    setUpErrLogging(); //sets stderr redirecting to cerr.log

   /* char * string = "joe";
    double * convert = malloc(sizeof(double));
    sscanf(string, "%lf\n", convert);

    printf("%.14g",*convert);*/
    
  
    //if argv[1] is a string
    if(func == 0){
        if(strcmp(argv[1],"all") == 0){
            //run all the tests
            checkFlagTest();
            checkForRoundOffTest();
            checkDoubleClassification();
        }
    }else{
        switch (func){
        case 1:
            checkFlagTest();
            break;
        case 2:
            checkForRoundOffTest();
            break;
        case 3:
            checkDoubleClassification();
            break;
        case 4:
            checkCovertTokensToDouble();
        case 5:
            checkFindDiscriminant();
        default:
            break;
        }
    }

    printf("%s\n","✅🤖ALL TESTS PASSED🤖✅");
    return 0;
}

/**
 * ----- function Definition 
 * int checkForFlag(char flag , char * buffer) 
*/
int checkFlagTest(){
    assert(checkForFlag('q',"q\n") == 1);
    assert(checkForFlag('q',"q\0") == 1);
    assert(checkForFlag('q',"k") == 0);
    assert(checkForFlag('q',"\0") == 0);
    assert(checkForFlag('q',"\n") == 0);
    assert(checkForFlag('q',"\t") == 0);
    assert(checkForFlag('q',"THIS IS A TEST") == 0);
    assert(checkForFlag('q',"test") == 0);
    assert(checkForFlag('h',"h\n") == 1);
    assert(checkForFlag('h',"h\0") == 1);
    assert(checkForFlag('h',"h\0") == 1);
    assert(checkForFlag('h',"k") == 0);
    assert(checkForFlag('h',"\0") == 0);
    assert(checkForFlag('l',"l\0\n") == 1);
    assert(checkForFlag('l',"l\0\0\0\0") == 1);
    assert(checkForFlag('l',"l\n\0\0\0") == 1);
    return 0;
}

/*
 * ----- function Definition 
 * int checkForRoundOff(char * input)
 * If there are more than 15 decimals after the digit this should return 1 meaning there was roundoff
*/
int checkForRoundOffTest(){
    char *test1 = malloc(sizeof(char)*20);
    strcpy(test1,"0.123456789012345");
    char *test2 = malloc(sizeof(char)*20);
    strcpy(test2,"0.1234567890123456");
    char *test3 = malloc(sizeof(char)*20);
    strcpy(test3,"1234567890123456");
    
    assert(checkForRoundOff(test1) == 0);
    assert(checkForRoundOff(test2) == 1);
    assert(checkForRoundOff(test3) == 0);
    
    return 0;
}

/*
 * ----- function Definition 
 * int classifyDouble(double input)
 * This function should classify INFS as INF and NaNs as NaNs
*/
int checkDoubleClassification(){
    double a = 1.0/0.0; //expected 0 for FP_INF
    double b = 0.0/0.0; //expected 0 for FP_NAN
    double c = 9.1231414; //expected 1 for normal 
    double d = 0.0; //expected 1 for FP_ZERO
    double e = DBL_MIN/2; //expected 1 for FP_SUBNORMAL
    assert(classifyDouble(a) == 0);
    assert(classifyDouble(b) == 0);
    assert(classifyDouble(c) == 1);
    assert(classifyDouble(d) == 1);
    assert(classifyDouble(e) == 1);
    return 0;
}

/**
 *  ----- function Definition 
 * int convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens)
 */

int checkCovertTokensToDouble(){

    int numTokens = 3;
    double * doubles = malloc(sizeof(double)*numTokens);
    char **tokens = malloc(sizeof(char *)*numTokens);
    *(tokens) = malloc(sizeof(char)*40);
    *(tokens+1) = malloc(sizeof(char)*40);
    *(tokens+2) = malloc(sizeof(char)*40);

    strcpy(tokens[0],"12.93");
    strcpy(tokens[1],"359.39929492");
    strcpy(tokens[2],"0.324");
    
    assert(convertTokensToDouble(doubles,tokens,numTokens) == 1);
    
    strcpy(tokens[0],"0.0");
    strcpy(tokens[1],"359.39929492");
    strcpy(tokens[2],"0.324");
    
    assert(convertTokensToDouble(doubles,tokens,numTokens) == 0);

    return 0;
}


/**
 *  ----- function Definition 
 * double findDiscriminant(double a, double b, double c)
 * This function takes in a, b, and c and finds the discriminant
 * Importand values are d < 0, d == 0, d > 0
 */
int checkFindDiscriminant(){
    double a = 1, b = 2, c = 1; //should return d = 0, expected 0
    
    findDiscriminant(a,b,c);
    return 0;
}
