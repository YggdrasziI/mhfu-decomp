/* unit_08851F94: 0x08851F94-0x08851FEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08851F94: first halfword of the record named by a kind and a 16-bit
 * index, from the 24-byte table for kind 5, else the 28-byte table. */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

u16 func_08851F94(s32 arg0, u8 *arg1) {
    if (arg1[1] == 5) {
        return *(u16 *)D_08959FCC[*(u16 *)(arg1 + 2)].unk0;
    }
    return *(u16 *)D_08960B9C[*(u16 *)(arg1 + 2)].unk0;
}
