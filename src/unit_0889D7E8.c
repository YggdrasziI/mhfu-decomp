/* unit_0889D7E8: 0x0889D7E8-0x0889D8A8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_0880BFF0(void *, void *, int);
extern void *func_0889C518(void);

char *func_0889D7E8(s32 arg0, char *arg1) {
    if ((arg1 != 0) && (func_0880BFF0(arg1 + 0xAD, func_0889C518(), 6) == 0) && (*(u16 *)(arg1 + 0xB4) != 0)) {
        return arg1 + 0xB4;
    }
    return 0;
}

char *func_0889D848(s32 arg0, char *arg1) {
    if ((arg1 != 0) && (func_0880BFF0(arg1 + 0xAD, func_0889C518(), 6) == 0) && (*(u16 *)(arg1 + 0xB4) == 0)) {
        return arg1 + 0x9C;
    }
    return 0;
}
