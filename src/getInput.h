/**
 * Part of Quadsolver program
 * Software created by Jared Teller and Joe Manto
 * Licensed under GNU General Public License. See LICENSE.txt for more information.
 */ 
#include <math.h>
int input(double * (*f)(double *),int size);
int checkForFlag(char flag , char * buffer);
void showHelp();
int tokenizeInput(char ** tokenizedInputBuffer,char * buffer,int numTokens);
int convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens);
int classifyDouble(double input);
int setUpLogging();
int setUpErrLogging();
int checkForRoundOff(char * input);
