/* unit_088CE1AC: 0x088CE1AC-0x088CE298 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char D_089BAB28;
extern char D_089BADAC;
extern char func_0886159C;
extern int func_088644E8(char *, s32);
extern int func_0886454C(char *);
extern int func_0890BE54(char *, char *, s32, s32);

char *func_088CE1AC(char *arg0) {
    *(char **)arg0 = &D_089BAB28;
    *(s32 *)(arg0 + 0x110) = 0;
    *(s32 *)(arg0 + 0x114) = 0;
    *(s32 *)(arg0 + 0x118) = 0;
    *(s32 *)(arg0 + 0x11C) = 0;
    *(s8 *)(arg0 + 0x128) = 0;
    *(s16 *)(arg0 + 0x130) = 0;
    *(s16 *)(arg0 + 0x138) = 0;
    *(s8 *)(arg0 + 0x129) = 0;
    *(s16 *)(arg0 + 0x132) = 0;
    *(s16 *)(arg0 + 0x13A) = 0;
    *(s8 *)(arg0 + 0x12A) = 0;
    *(s16 *)(arg0 + 0x134) = 0;
    *(s16 *)(arg0 + 0x13C) = 0;
    *(s8 *)(arg0 + 0x12B) = 0;
    *(s16 *)(arg0 + 0x136) = 0;
    *(s16 *)(arg0 + 0x13E) = 0;
    *(s16 *)(arg0 + 0x120) = 0;
    *(s16 *)(arg0 + 0x122) = 0;
    return arg0;
}

char *func_088CE208(char *arg0, s16 arg1) {
    if (arg0 != 0) {
        *(char **)arg0 = &D_089BADAC;
        if ((arg0 + 0xF80) != 0) {
            *(char **)(arg0 + 0xF80) = &D_089BAB28;
        }
        func_0890BE54(arg0 + 0x8D0, &func_0886159C, 0x140, 5);
        func_088644E8(arg0, 0);
        if (arg1 > 0) {
            func_0886454C(arg0);
        }
    }
    return arg0;
}
