/* unit_0885CA50: 0x0885CA50-0x0885CB68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two matched units.
 * Its jump table (0x089314C4-0x089314E0) is linked from this unit.
 */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

void *func_0885CA50(s32 arg0, u8 *arg1) {
    switch (arg1[1]) {
    case 0:
        return &D_08973834[*(u16 *)(arg1 + 2)];
    case 1:
        return &D_08963254[*(u16 *)(arg1 + 2)];
    case 2:
        return &D_08967674[*(u16 *)(arg1 + 2)];
    case 3:
        return &D_0896B814[*(u16 *)(arg1 + 2)];
    case 4:
        return &D_0896F84C[*(u16 *)(arg1 + 2)];
    case 5:
        return &D_08959FCC[*(u16 *)(arg1 + 2)];
    case 6:
        return &D_08960B9C[*(u16 *)(arg1 + 2)];
    default:
        return 0;
    }
}
