/* unit_08851F20: 0x08851F20-0x08851F94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

u16 func_08851F20(char *arg0, s32 arg1) {
    char *p = arg0 + arg1 * 0x8C + 0x30;

    if (((u8 *)p)[0x31] == 5) {
        return *(u16 *)&D_08959FCC[*(u16 *)(p + 0x32)];
    }
    return *(u16 *)&D_08960B9C[*(u16 *)(p + 0x32)];
}
