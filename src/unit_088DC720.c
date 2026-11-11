/* unit_088DC720: 0x088DC720-0x088DC748 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089BAB08;

char *func_088DC720(char *arg0) {
    *(char **)arg0 = &D_089BAB08;
    *(s32 *)(arg0 + 0x1B4) = 0;
    *(s32 *)(arg0 + 0x234) = 0;
    *(s32 *)(arg0 + 0x14C) = 0;
    *(s32 *)(arg0 + 0x148) = 0;
    *(s32 *)(arg0 + 0x144) = 0;
    return arg0;
}
