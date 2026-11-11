/* unit_088C7814: 0x088C7814-0x088C7914 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char D_089BAB28;
extern char D_089BACDC;
extern void func_088614DC(char *);
extern int func_08861604(char *, s32);
extern int func_088CAF4C(char *);

char *func_088C7814(char *arg0) {
    func_088614DC(arg0);
    *(char **)arg0 = &D_089BACDC;
    *(char **)(arg0 + 0x1F0) = &D_089BAB28;
    *(s32 *)(arg0 + 0x300) = 0;
    *(s32 *)(arg0 + 0x304) = 0;
    *(s32 *)(arg0 + 0x308) = 0;
    *(s32 *)(arg0 + 0x30C) = 0;
    *(s8 *)(arg0 + 0x318) = 0;
    *(s16 *)(arg0 + 0x320) = 0;
    *(s16 *)(arg0 + 0x328) = 0;
    *(s8 *)(arg0 + 0x319) = 0;
    *(s16 *)(arg0 + 0x322) = 0;
    *(s16 *)(arg0 + 0x32A) = 0;
    *(s8 *)(arg0 + 0x31A) = 0;
    *(s16 *)(arg0 + 0x324) = 0;
    *(s16 *)(arg0 + 0x32C) = 0;
    *(s8 *)(arg0 + 0x31B) = 0;
    *(s16 *)(arg0 + 0x326) = 0;
    *(s16 *)(arg0 + 0x32E) = 0;
    *(s16 *)(arg0 + 0x310) = 0;
    *(s16 *)(arg0 + 0x312) = 0;
    return arg0;
}

char *func_088C789C(char *arg0, s16 arg1) {
    if (arg0 != 0) {
        *(char **)arg0 = &D_089BACDC;
        if ((arg0 + 0x1F0) != 0) {
            *(char **)(arg0 + 0x1F0) = &D_089BAB28;
        }
        func_08861604(arg0, 0);
        if (arg1 > 0) {
            func_088CAF4C(arg0);
        }
    }
    return arg0;
}
