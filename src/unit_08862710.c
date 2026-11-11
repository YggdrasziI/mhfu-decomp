/* unit_08862710: 0x08862710-0x08862768 (ULES01213)
 *
 * Bounds (hypothesis): 4 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

char *func_08862710(char *arg0) {
    return arg0 + *(s32 *)(arg0 + 0x34);
}

s32 func_0886271C(char *arg0) {
    return *(s32 *)(arg0 + 8) - *(s32 *)(arg0 + 0x34);
}

char *func_0886272C(char *arg0, s32 arg1) {
    return arg0 + *(s32 *)(arg0 + 0x20) + (arg1 * 0x18);
}

char *func_0886272C();

u8 func_08862748(void) {
    return *(u8 *)((char *)(func_0886272C()) + 0x10);
}
