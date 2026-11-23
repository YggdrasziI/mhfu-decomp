/* unit_0886F7FC: 0x0886F7FC-0x0886F894 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 * Owns its table initializer, 0x089A8288-0x089A82CE (s16[35]), as .data.
 *
 * Set the bit of the 64-bit mask at +0x5B8 whose index is
 * the position of the 16-bit key in a 35-entry table.
 *
 * Optimized for speed: the search loop steps a pointer, tested at the bottom.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned long long u64;

void func_0886F7FC(char *arg0, u16 arg1) {
    /* Initialised local: D_089A8288 (70 bytes) in the original. */
    s16 tbl[35] = {
        0x4B1, 0x4CC, 0x48C, 0x463, 0x45C, 0x4B9, 0x4DD, 0x48D, 0x464, 0x45D,
        0x4A3, 0x4CE, 0x48E, 0x465, 0x45E, 0x4AC, 0x4DF, 0x48F, 0x466, 0x45F,
        0x4BC, 0x4D0, 0x490, 0x467, 0x460, 0x4B6, 0x4E1, 0x491, 0x468, 0x461,
        0x4BE, 0x4E2, 0x492, 0x469, 0x462
    };
    s32 i;

    for (i = 0; i < 35; i++) {
        if (arg1 == (u16) tbl[i]) {
            *(u64 *)(arg0 + 0x5B8) |= (u64) 1 << i;
            return;
        }
    }
}
