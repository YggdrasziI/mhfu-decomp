/* unit_088ADEF0: 0x088ADEF0-0x088ADF58 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

s32 func_088ADEF0(s32 arg0, s32 arg1, char *arg2) {
    *(s32 *)arg2 = arg1;
    *(s32 *)(arg2 + 4) = arg0;
    if (arg1 == 2) {
        *(s8 *)(arg2 + 0xD) = 1;
    }
    if (arg1 == 4) {
        *(s8 *)(arg2 + 0xD) = 0;
    }
    return 0;
}

s32 func_088ACB1C(void);

void func_088ADF24(char *arg0) {
    if (*(u8 *)(arg0 + 0xC) != 0) {
        *(s32 *)(arg0 + 8) = func_088ACB1C();
    }
}
