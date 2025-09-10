#include "mex.h"
#include "matrix.h"

#include "csum.h"

/* sort of the int main of mex */
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    // nlhs: number of left handside args
    // plhs: pointer to left handside args
    // nrhs: number of right handside args
    // prhs: pointer to right handside args

    if (nrhs==2)
    {
        printf("2 arguments provided!\n");

    }
    else
    {
        printf("Please provide 2 args!\n");
        mexErrMsgTxt("Please provide 2 args! \n");
    }
}

// [y,t] = step(Gs)
// int nlhs ==> 2
// plhs[0] ==> y
// plhs[1] ==> t

// we dont want to manipulate the righ hand side

// the .mexw64 that we just built is basically a .dll file.