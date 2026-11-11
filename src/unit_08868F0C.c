/* unit_08868F0C: 0x08868F0C-0x08868F50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern int sceCtrlSetSamplingCycle(s32);
extern int sceCtrlSetSamplingMode(s32);

void func_08868F0C(char *arg0) {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(1);
    *(s32 *)(arg0 + 0x10) = 0;
    *(s8 *)(arg0 + 0x14) = 0;
    *(s8 *)(arg0 + 0x15) = 0;
    *(s8 *)(arg0 + 0x16) = 0;
    *(s8 *)(arg0 + 0x17) = 0;
}
