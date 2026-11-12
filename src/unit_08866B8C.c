/* unit_08866B8C: 0x08866B8C-0x08866BD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089A6060;

s32 func_08866B8C(char *arg0, s32 arg1, s32 arg2) {
    return *(s32 *)(arg0 + 0x8023C) + (arg1 * 0x1A800) + ((s32 *)&D_089A6060)[arg2];
}
