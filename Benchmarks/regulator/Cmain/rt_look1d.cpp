#include "define.h"
/* Code of rt_look1d */
/* Update function of  */
real_T rt_Lookup(real_T* x, int_T xlen, real_T u, real_T* y) {
    BitmapCov::munitBitmap[3] = 1;
    /* Calculate code of  */
    int_T idx = rt_GetLookupIndex(x, xlen, u);
    real_T num = y[idx + 1] - y[idx];
    real_T den = x[idx + 1] - x[idx];
    real_T m = num / den;
    return (y[idx] + (m * (u - x[idx])));
}