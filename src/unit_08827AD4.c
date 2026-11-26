/* unit_08827AD4: 0x08827AD4-0x08827BF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_08A631A8;
extern s32 D_089CBBE8;
extern void func_0880F178(char *, char *, s32);
extern s32 func_08890F70(char *, char *);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern s32 func_08816930(s32, s32);

void func_08827AD4(s32 arg0, s32 x, s32 y, char *str, s32 scale, s32 step) {
    char buf[0x80];
    char *start;
    s32 len;
    s32 w;
    char c;

    len = 0;
    start = str;
    while (1) {
        c = *str;
        if (c == 0 || c == '\n') {
            func_0880F178(buf, start, len);
            buf[len] = 0;
            w = func_08890F70(D_08A631A8, buf);
            func_088920A8(D_08A631A8,
                          (s16)(x - w * scale / 4),
                          (s16)y, buf);
            y += step;
            if (*str == 0) {
                break;
            }
            str++;
            len = 0;
            start = str;
        } else {
            len += func_08816930(D_089CBBE8, (u8)c);
            str += func_08816930(D_089CBBE8, *(u8 *)str);
        }
    }
}
