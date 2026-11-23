/* unit_08869774: 0x08869774-0x088697D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08869774: returns an offset into arg0 selected by arg1, or 0. */

typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_08869774(char *arg0, s32 arg1) {
    char *p = *(char **)(arg0 + 0x71C);
    s32 v;

    if (arg1 == 0) {
        v = *(s32 *)(p + 0x8);
    } else if (arg1 == 1) {
        v = *(s32 *)(p + 0xC);
    }
    if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
        return v;
    }
    if (v == 0) {
        return 0;
    }
    return v + *(s32 *)(arg0 + 0x50);
}
