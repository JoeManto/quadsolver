#include <math.h>
int input(void (*f)(double *),int size);
int checkForFlag(char flag , char * buffer);
void showHelp();
int tokenizeInput(char ** tokenizedInputBuffer,char * buffer,int numTokens);
int convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens);
int classifyDouble(double input);
int setUpLogging();
