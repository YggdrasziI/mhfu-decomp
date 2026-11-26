/* unit_08827918: 0x08827918-0x08827AD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_08A631A8;
extern s32 D_089CBBE8;
extern char *func_0880EBF0(char *, s32);
extern void func_0880F178(char *, char *, s32);
extern s32 func_08890F70(char *, char *);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern s32 func_08816930(s32, s32);

void func_08827918(char *arg0, s32 x, s32 y, char *str, s32 scale, s32 step) {
    char buf[0x80];
    char *nl;
    s32 max;
    char *start;
    s32 len;
    s32 w;
    char *p;
    s32 c;

    p = str;
    start = str;
    max = 0;
    if (*p != 0) {
        do {
            nl = func_0880EBF0(p, 0xA);
            if (nl != 0) {
                len = nl - start;
                func_0880F178(buf, start, len);
                buf[len] = 0;
                w = func_08890F70(D_08A631A8, buf);
                if (max < w) {
                    max = w;
                }
                p = nl + 1;
                start = p;
            } else {
                w = func_08890F70(D_08A631A8, start);
                if (max < w) {
                    max = w;
                }
                break;
            }
        } while (*p != 0);
    }
    x -= max * scale / 4;
    len = 0;
    start = str;
    while (1) {
        c = *str;
        if (c == 0 || c == 0xA) {
            func_0880F178(buf, start, len);
            buf[len] = 0;
            func_088920A8(D_08A631A8, (s16)x, (s16)y, buf);
            y += step;
            if (*str == 0) {
                break;
            }
            str++;
            len = 0;
            start = str;
        } else {
            len += func_08816930(D_089CBBE8, c & 0xFF);
            str += func_08816930(D_089CBBE8, *(u8 *)str);
        }
    }
}
