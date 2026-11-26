/* unit_08838894: 0x08838894-0x08838AB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A8;
extern char *D_09B22D70;

extern void func_08890E38(char *, s8);
extern void func_08821890(char *, s32);
extern void func_09AE9780(char *, char *);
extern u8 func_08826EF4(char *, char *, u8 *);
extern void func_08821ADC(char *, char *, u8 *);
extern void func_08821A10(char *, s32, s32);
extern s8 func_088D8DF4(char *, u8);
extern u8 func_09AE99E8(char *, u8);
extern s8 func_09AE9818(char *, u8, char *, char *);
extern void func_0881B5F8(char *, char *, s32, s32, u8 *);
extern void func_08821924(char *, s32);

void func_08838894(char *arg0, char *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    u8 buf[6];
    s32 i;
    u8 *e;
    s8 a;
    s8 b;
    u8 r;
    u8 *p;

    func_08890E38(D_08A631A8, 0);
    buf[5] = 0;
    buf[4] = 0;
    buf[3] = 0;
    buf[2] = 0;
    buf[1] = 0;
    buf[0] = 0;
    if (arg2 != 0) {
        func_08821890(arg0, (s32)arg1);
        func_09AE9780(D_09B22D70 + 0xA888, arg1);
        if (arg2[1] != 5 && arg2[1] != 6) {
            if (func_08826EF4(arg0, arg1, arg2) == 0) {
                return;
            }
            func_08821ADC(arg0, arg1, arg2);
        } else {
            func_08821A10(arg0, (s32)arg1, (s32)arg2);
        }
        i = 0;
        p = buf;
        do {
            e = (u8 *)(arg1 + i + 0x634);
            if (*e == 0) {
                break;
            }
            a = func_088D8DF4(arg1, *e);
            r = func_09AE99E8(D_09B22D70 + 0xA888, *e);
            if (r == 0) {
                if (a > 0) {
                    *p = 0xE;
                } else if (a < 0) {
                    *p = 2;
                }
            } else if (r != (u8)arg1[(u8)i + 0x676]) {
                b = func_09AE9818(D_09B22D70 + 0xA888, *e, arg0 + 0x11CA, arg0 + 0x11BE);
                if (b < a) {
                    *p = 4;
                } else if (b > a) {
                    *p = 0xF;
                }
            }
            i++;
            p++;
        } while (i < 6);
    }
    func_0881B5F8(arg0, arg1, arg3, arg4, buf);
    func_08821924(arg0, (s32)arg1);
}
