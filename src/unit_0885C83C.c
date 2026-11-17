/* unit_0885C83C: 0x0885C83C-0x0885C968 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two matched units.
 * Its jump table (0x0893148C-0x089314A8) is linked from this unit.
 */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

s32 func_0885C83C(s32 arg0, u8 arg1, u16 arg2) {
    if (arg2 > 0x5DC) {
        return 0;
    }
    switch (arg1) {
    case 0:
        return D_08973834[arg2].unk5;
    case 1:
        return D_08963254[arg2].unk5;
    case 2:
        return D_08967674[arg2].unk5;
    case 3:
        return D_0896B814[arg2].unk5;
    case 4:
        return D_0896F84C[arg2].unk5;
    case 5:
        return D_08959FCC[arg2].unk2;
    case 6:
        return D_08960B9C[arg2].unk2;
    default:
        return 0;
    }
}
