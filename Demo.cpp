//
//  Demo.cpp
//  
//
//  Created by Byron Price on 2016/12/09.
//
//

#include <matrix.h>
#include <mex.h>
#include <math.h>
#include <algorithm>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    //declare variables
    mxArray *a_in, *b_in, *c_out, *d_out, *e_out, *f_out;
    const mwSize *dims;
    double *a, *b, *c, *d, *e, *f;
    int numRows, numCols, numDims;
    int ii,jj,kk;
    
    //associate inputs
    a_in = mxDuplicateArray(prhs[0]);
    b_in = mxDuplicateArray(prhs[1]);
    
    //figure out dimensions
    dims = mxGetDimensions(prhs[0]);
    numDims = mxGetNumberOfDimensions(prhs[0]);

    numRows = (int)dims[0];numCols = (int)dims[1];
    int myArray [numRows][numCols];
    
    //associate outputs
    c_out = plhs[0] = mxCreateDoubleMatrix(numRows,numCols,mxREAL);
    d_out = plhs[1] = mxCreateDoubleMatrix(numRows,numCols,mxREAL);
    e_out = plhs[2] = mxCreateDoubleMatrix(numRows,numRows,mxREAL);
    f_out = plhs[3] = mxCreateNumericArray(numDims,dims,mxDOUBLE_CLASS,mxREAL);

    // class ids = mxDOUBLE_CLASS  ... mxUINT64_CLASS
    //associate pointers
    a = mxGetPr(a_in);
    b = mxGetPr(b_in);
    c = mxGetPr(c_out);
    d = mxGetPr(d_out);
    e = mxGetPr(e_out);
    f = mxGetPr(f_out);

    //do something
    for(ii=0;ii<numRows;ii++)
    {
        for(jj=0;jj<numCols;jj++)
        {
           // mexPrintf("element[%d][%d] = %f\n",i,j,a[i*numCols+j]);
           //mexPrintf("ii= %d jj= %d Index = %d Value = %f\n",ii,jj,jj*numRows+ii,a[jj*numRows+ii]);
            // matrix addition
            c[jj*numRows+ii] = a[jj*numRows+ii]+b[jj*numRows+ii];
            // element-wise matrix multiplication
            d[jj*numRows+ii] = a[jj*numRows+ii]*b[jj*numRows+ii];   //std::max(a[jj*numRows+ii],b[jj*numRows+ii]);
            // example usage with numeric arrays
            myArray[ii][jj] = a[jj*numRows+ii]+b[jj*numRows+ii];
            //f[ii][jj] = a[jj*numRows+ii]*b[jj*numRows+ii];
        }
    }

    for(ii=0;ii<numRows;ii++)
    {
        for(jj=0;jj<numRows;jj++)
        {
        // matrix multiplication
        int tot = 0;
            for(kk=0;kk<numCols;kk++)
            {
                //mexPrintf("eRow = %d eCol = %d\n",ii,jj);
                //mexPrintf("aRow = %d aCol = %d bRow = %d bCol = %d\n",ii,kk,kk,jj);
                tot = tot+a[kk*numRows+ii]*b[jj*numCols+kk];
            }
            e[jj*numRows+ii] = tot;
        }
    }
    
    return;
}