#include "define.h"
/* Code of rt_look */
/* Update function of  */
int_T rt_GetLookupIndex(real_T* x, int_T xlen, real_T u) {
    BitmapCov::munitBitmap[2] = 1;
    /* Calculate code of  */
    int_T idx = 0;
    int_T bottom = 0;
    int_T top = xlen - 1;
    int_T retValue = 0;
    boolean_T returnStatus = 0U;
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u <= x[bottom], 12, 1, 6), -13, 0, 6)) {
        BitmapCov::branchBitmap[12] = 1;
        retValue = bottom;
        returnStatus = 1U;
    }
    else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u >= x[top], 14, 1, 7), -15, 0, 7)) {
        BitmapCov::branchBitmap[13] = 1;
        retValue = top - 1;
        returnStatus = 1U;
    }
    else
    {
        BitmapCov::branchBitmap[14] = 1;
    }
    if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(returnStatus == 0U, 16, 1, 8), -17, 0, 8)) {
        BitmapCov::branchBitmap[15] = 1;
        if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u < 0, 18, 1, 9), -19, 0, 9)) {
            BitmapCov::branchBitmap[16] = 1;
            for(;;)
            {
                BitmapCov::branchBitmap[17] = 1;
                idx = (bottom + top) / 2;
                if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u < x[idx], 20, 1, 10), -21, 0, 10)) {
                    BitmapCov::branchBitmap[18] = 1;
                    top = idx - 1;
                }
                else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u >= x[idx + 1], 22, 1, 11), -23, 0, 11)) {
                    BitmapCov::branchBitmap[19] = 1;
                    bottom = idx + 1;
                }
                else
                {
                    BitmapCov::branchBitmap[20] = 1;
                    retValue = idx;
                    break;
                }
            }
            BitmapCov::branchBitmap[21] = 1;
        }
        else
        {
            BitmapCov::branchBitmap[22] = 1;
            for(;;)
            {
                BitmapCov::branchBitmap[23] = 1;
                idx = (bottom + top) / 2;
                if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u <= x[idx], 24, 1, 12), -25, 0, 12)) {
                    BitmapCov::branchBitmap[24] = 1;
                    top = idx - 1;
                }
                else if (BitmapCov::CondAndMCDCRecord(BitmapCov::CondAndMCDCRecord(u > x[idx + 1], 26, 1, 13), -27, 0, 13)) {
                    BitmapCov::branchBitmap[25] = 1;
                    bottom = idx + 1;
                }
                else
                {
                    BitmapCov::branchBitmap[26] = 1;
                    retValue = idx;
                    break;
                }
            }
            BitmapCov::branchBitmap[27] = 1;
        }
    }
    BitmapCov::branchBitmap[28] = 1;
    return retValue;
}