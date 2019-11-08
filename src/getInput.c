/**
 * Part of Quadsolver program
 * Software created by Jared Teller and Joe Manto
 * Licensed under GNU General Public License. See LICENSE.txt for more information.
 */ 
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "getInput.h"

/**
 * This function vaildates and converts gathered input from fgets
 * @param [void (*f)(double *)] call back function
 * @param [int] buffer size for fgets
 */
int input(double * (*f)(double *),int size){
  char buffer[size];
  char * bufferPointer = fgets(buffer, size, stdin);

  if(bufferPointer != NULL){
    //check if the input was empty then prompt again
    if(*(bufferPointer+1) == '\0'){
      input((*f),size);
    //check for quit flag
    }else if(checkForFlag('q',bufferPointer)){
      printf("%s\n","quiting...");
      return 0;
    //check for help flag
    }else if(checkForFlag('h',bufferPointer)){
      showHelp();
      return 1;
    }else if(checkForFlag('l',bufferPointer)){
      setUpLogging();
      return 1;
    }else{
      //input is normal 

      //define token buffer pointer
      char ** stringTokenizedBuffer = malloc(sizeof(char*)*3);

      //tokenize bufferPointer on " " -> stringTokenizedBuffer
      if(!tokenizeInput(stringTokenizedBuffer,bufferPointer,3)) return 1;

      //define array of doubles
      double * doubleTokens = malloc(sizeof(double)*3);

      //convert all the tokens to the double array
      if(!convertTokensToDouble(doubleTokens,stringTokenizedBuffer,3)) return 1;

      //call input call back with the arguments
      (*f)(doubleTokens);
      printf("%s\n","Enter another input | [q] : quit | [l] : start logging");

      free(stringTokenizedBuffer);
      return 1;
    }
  }else{
    perror("Input Error: Input was Null");
    exit(errno);
  }
  return 0;
}

/**
 * this function will split the input by space or tab, and store the results
 * into a buffer that will later be checked for proper input
 * @param [char **] buffer storage for created tokens
 * @param [char *]  the input buffer from fgets
 * @param [int] expected number of splits 
 */
int tokenizeInput(char ** tokenizedInputBuffer,char * buffer,int numTokens){
  char bufferCopy[strlen(buffer)];
  strcpy(bufferCopy,buffer);
	char delim[] = " \t\n";
	char *ptr = strtok(bufferCopy, delim);
  int i = 0;
	for(; ptr != NULL; i++){
    tokenizedInputBuffer[i] = malloc(sizeof(char)*strlen(ptr));
    strcpy(tokenizedInputBuffer[i],ptr);
		ptr = strtok(NULL, delim);
	}
  if(i > numTokens){
    printf("\n%s\n","Invaild Input: number of arguments greater than 3");
  }
  if(i < numTokens){
    printf("\n%s\n","Invaild Input: number of arguments less than 3");
  }
  return (i == 3);
}

//
/**
 * if this function returns 0, it will exit the input function and prompt for new input
 * @param [double *] buffer storage for created doubles
 * @param [char **]  tokens from the input buffer
 * @param [int] number of tokens in tokenizeInputBuffer 
 */
int convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens){
  int roundOffFlag = 0;
  for(int i = 0; i<numTokens; i++){
    if((sscanf(tokenizeInputBuffer[i], "%lf", &doubleTokens[i])) == 0){
      printf("%s", "ascii input is not valid\n\nPlease enter another input\n");
      return 0;
    }

    int result = checkForRoundOff(tokenizeInputBuffer[i]);
    if(result == 1 && roundOffFlag == 0){
      printf("%s\n", "Warning: The input entered had more than 15 digits after the decimal. There may be roundoff in the calculation.");
      roundOffFlag = 1;
    }
    
    //run fpclassify to check for an inf, nan, a == 0
    if(i == 0 && fpclassify(doubleTokens[0]) == FP_ZERO){ //make sure a is not 0
      printf("%s\n","Input Error: first argument can't be zero");
      return 0;
    }
    if(classifyDouble(doubleTokens[i]) == 0){
      printf("%s\n","Enter another input | [q] : quit | [l] : start logging");
      return 0;
    }
  }
  return 1;
}

/**
 * This function will take in a double and classify it as a an inf, nan, zero, normal, or subnormal
 * @param [double input] - the double to be classified
 * 0 will be returned for bad classifications and 1 will be returned on normal and subnormal (with a warning for subnormal)
 */
int classifyDouble(double input){
  switch(fpclassify(input)) {
        case FP_INFINITE:  printf("%.14lf %s\n",input,"classified as inf"); return 0;
        case FP_NAN:       printf("%.14lf %s\n",input,"classified as NAN"); return 0;
        case FP_NORMAL:    return 1;
        case FP_SUBNORMAL: printf("%.14lf %s\n",input,"warning: classified as subnormal and number was rounded up"); return 1;
        case FP_ZERO:      return 1;
        default:           printf("%.14lf %s\n",input,"classified as unknown"); return 1;
    }
}

//this function checks for roundoff in each double
int checkForRoundOff(char * input){
  char delim[] = ".";
  int inputLength = strlen(input);
 
  char *ptr = strtok(input, delim);
  if(strlen(ptr)-inputLength == 0){
    return 0;
  }
  ptr = strtok(NULL, delim);
  if(strlen(ptr) > 15){
    return 1;
  }
  return 0;
}

/**
 * Shows the help details
 * @return -
 */ 
void showHelp(){
  printf("%s\n",
  "QuadSolver v1 [HELP] \n Input -\nInput is a collection of floating point numbers (a,b,c) of the polynomial separated by spaces all floating pointing numbers should be with in the max min ranges\n\n\t<float> _space <float> _space <float>\n\nEnter your input:"
  );
}

/**
 * this function will check for a flag of h or q that will then give the user help or quit the program
 * @param [char] character at flag to check for
 * @param [char*] input buffer from fgets
 * @return int flag is found
 */
int checkForFlag(char flag , char * buffer){
  return (*buffer == flag && (*(buffer+1) == '\n' || *(buffer+1) == '\0'));
}

/**
 * This function redirects stdout to the file cout.log
 * @return int
 */ 
int setUpLogging(){
  printf("%s\n","logging started...stdout stream is now redirected to cout.log");
  int out = open("cout.log",O_RDWR | O_CREAT | O_TRUNC, 0600);
  if(-1 == out){perror("can't open clog.out");return 255;}
  if(-1 == dup2(out,fileno(stdout))){perror("can't redirect to stdout");return 255;}
  return 1;
}

/**
 * This function redirects stderr to the file cerr.log
 * @return int
 */ 
int setUpErrLogging(){
  printf("%s\n","logging started...stderr stream is now redirected to cerr.log");
  int err = open("cerr.log",O_RDWR | O_CREAT | O_TRUNC, 0600);
  if(-1 == err){perror("can't open cerr.out");return 255;}
  if(-1 == dup2(err,fileno(stderr))){perror("can't redirect to stderr");return 255;}
  return 1;
}
