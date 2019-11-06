#include "spike.h"

int sscanfConversion();
int nanSpike();
int infSpike();
int subNormalSpike();
int findDiscriminant(float a, float b, float c);

int main(int argc, char*argv[]){
    double a = 2, b=12.3, c=1;
    if(argc != 2){
        printf("Please enter a valid number of arguments... eg. ./spike 2");
    }else{
        int spikeNum = atoi(argv[1]);
        switch (spikeNum){
            case 1:
                sscanfConversion();
                break;
            case 2:
                nanSpike();
                break;
            case 3:
                infSpike();
                break;
            case 4:
                subNormalSpike();
                break; 
            case 5:
                findDiscriminant(a,b,c);
                break;
            default:
                break;
        }
    }
}

//sscanf convert a string to a float SPIKE 1
int sscanfConversion(){
    char temp[] = "1.000567";
    double num = 0;
    sscanf(temp, "%lf", &num);
    printf("%f\n", num);
    return 0;
}

//NaN spike - produce a NaN in C SPIKE 2
int nanSpike(){
    double x = sqrt(-1);
    printf("%d\n", isnan(x)); //should be 1 for true
    return 0;
}

//produce an INF in C SPIKE 3
int infSpike(){
    double x = 1E307 * 100; //this should be INF because it is too large
    printf("%d\n", isinf(x)); //should be 1 for true
    return 0;
}

//Subnormal spike SPIKE 4
int subNormalSpike(){
    printf("%d\n", isnormal(1.0)); //should be 1 for true
    printf("%d\n", isnormal(DBL_MIN/2.0)); //should be 0 for false
    return 0;
}

/**finding discriminant and bad values for it
 * discriminant is defined as b*b - 4*a*c
 * A discriminant of 0 means there is a repeated real number solution
 * A positive discriminant means there are two distinct real number solutions
 * A negative discriminant means there are no real number solutions 
 * SPIKE 5
*/
int findDiscriminant(float a, float b, float c){
    double discriminant = (double)b * (double)b - 4.0 * (double)a * (double)c;
    if(discriminant < 0){
        printf("Discriminant: %lf   No real number solution with the given input.\n", discriminant);
    }else if(discriminant > 0){
        printf("Discriminant: %lf   Two distinct real number answers are expected.\n", discriminant);
    }else{
        printf("Discriminant: %lf   A repeated real number solution is expected.\n", discriminant);
    }
    return 0;
}



