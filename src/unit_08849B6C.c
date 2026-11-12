/* unit_08849B6C: 0x08849B6C-0x08849BCC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_089CC438;
extern s32 func_0884FA5C(s32, s32);

s32 func_08849B6C(char *arg0) {
    if ((func_0884FA5C(D_089CC438, 0) & 0xFF) == 1) {
        return -1;
    }
    *(s8 *)(arg0 + 0x57E) = 0;
    *(s8 *)(arg0 + 0x537) = 1;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    return 0;
}
