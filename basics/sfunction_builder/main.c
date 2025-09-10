#include <stdio.h>
#include "csum.h"


int main(int argc,  char** argv)
{
    float a=1;
    float b=2.2f;

    printf("%f + %f = %f \n", a, b, sum(a,b));

    return 0;
}