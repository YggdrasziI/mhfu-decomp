/* unit_08856BC8: 0x08856BC8-0x08856C94 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef int s32;

extern "C" {

extern int func_0884FAC4(s32, s32);
extern s32 func_0884FB38(s32, s32);

void func_08856BC8(char *arg0) {
    if (((bool) (*(s32 *)(arg0 + 0x6ADF8) & 0x1000) == 1) && !(func_0884FB38((s32) arg0, 0x22) & 0xFF)) {
        func_0884FAC4((s32) arg0, 0x22);
        *(s8 *)(arg0 + 0x44BD) = 0;
        return;
    }
    *(s8 *)(arg0 + 0x44BD) = 1;
}

void func_08856C34(char *arg0) {
    if (((bool) (*(s32 *)(arg0 + 0x6ADF8) & 0x1000) == 1) && !(func_0884FB38((s32) arg0, 0x22) & 0xFF)) {
        func_0884FAC4((s32) arg0, 0x22);
        *(s8 *)(arg0 + 0x44BD) = 0;
    }
}

}
