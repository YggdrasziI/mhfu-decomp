/* unit_0885CB98: 0x0885CB98-0x0885CCD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two matched units.
 * Its jump table (0x089314E0-0x089314FC) is linked from this unit.
 */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

s32 func_0885CB98(s32 arg0, u8 arg1, u16 arg2) {
    switch (arg1) {
    case 0:
        return D_08973834[arg2].unk8;
    case 1:
        return D_08963254[arg2].unk8;
    case 2:
        return D_08967674[arg2].unk8;
    case 3:
        return D_0896B814[arg2].unk8;
    case 4:
        return D_0896F84C[arg2].unk8;
    case 5:
        return D_08959FCC[arg2].unk4;
    case 6:
        return D_08960B9C[arg2].unk4;
    default:
        return 9999999;
    }
}
