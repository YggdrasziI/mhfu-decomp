/* unit_08851EC8: 0x08851EC8-0x08851F20 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08851EC8: first halfword of record arg2, from the 24-byte table for
 * kind 5, else the 28-byte table. */

#include "unk_tables.h"

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

u16 func_08851EC8(s32 arg0, u8 arg1, u16 arg2) {
    if (arg1 == 5) {
        return *(u16 *)D_08959FCC[arg2].unk0;
    }
    return *(u16 *)D_08960B9C[arg2].unk0;
}
