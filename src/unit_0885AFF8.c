/* unit_0885AFF8: 0x0885AFF8-0x0885B048 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_0885AFF8(s32 arg0, s16 arg1) {
    char *base = D_089CC438 + 0x4A0;
    u16 *p;

    if (arg1 >= 24) {
        return 2;
    }
    p = (u16 *)((char *)(arg1 * 4) + (s32)base + 0x3F28);
    p[1] = 0;
    if (*p == 0) {
        return 0;
    }
    *p = 0;
    return 1;
}
