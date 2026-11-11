/* unit_088A1798: 0x088A1798-0x088A1848 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern int sceAtracReleaseAtracID(s32);
extern int sceAtracSetLoopNum(s32, s32);

void func_088A1798(char *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)(arg0 + 8);
    if (temp_a0 != -1) {
        sceAtracReleaseAtracID(temp_a0);
        *(s32 *)(arg0 + 8) = -1;
    }
}

void func_088A17D8(char *arg0) {
    sceAtracSetLoopNum(*(s32 *)(arg0 + 8), 0x7FFFFFFF);
    *(s32 *)(arg0 + 0x48) = 1;
    *(s32 *)(arg0 + 0x4C) = 0;
}

void func_088A1814(char *arg0) {
    sceAtracSetLoopNum(*(s32 *)(arg0 + 8), 0);
    *(s32 *)(arg0 + 0x48) = 0;
    *(s32 *)(arg0 + 0x4C) = 0;
}
