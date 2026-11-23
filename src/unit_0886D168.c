/* unit_0886D168: 0x0886D168-0x0886D248 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886D168 */
#pragma optimize_for_size off
typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_09C121B0;
extern char D_08A62C9C;
extern char *D_09A4F060;
extern void func_09AD7C88(char *, s8);
extern void func_0886CE10(char *, s8);

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_0886D168(char *arg0) {
    s32 i;
    s32 j;
    char *e;

    for (i = 0; i < 20; i++) {
        e = get_entry(D_09C121B0, i);
        if (e != 0 && *(s8 *)(e + 0x630) != -1) {
            func_09AD7C88(e, *(s8 *)(e + 0x630));
        }
    }
    for (j = *(s8 *)(arg0 + 0x21) - 1; j >= 0; j--) {
        s8 k = *(&D_08A62C9C + j);
        if ((*(u8 *)(D_09A4F060 + k * 32 + 0x1E) & 1) == 0) {
            func_0886CE10(arg0, k);
        }
    }
}
