/* unit_0888553C: 0x0888553C-0x088855C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

extern char *D_08A631A0;
extern u16 func_088900C4(char *, s32);

s32 func_0888553C(s32 arg0, s32 arg1, u16 arg2, s32 arg3, u16 arg4) {
    s32 r = func_088900C4(D_08A631A0, 1) & 7;

    if (r < arg2) {
        return arg1;
    }
    if (r < arg2 + arg4) {
        return arg3;
    }
    return -1;
}
