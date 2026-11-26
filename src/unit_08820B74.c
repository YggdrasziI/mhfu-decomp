/* unit_08820B74: 0x08820B74-0x08820DBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_08A62C54;

extern char *func_0885CA50(char *, char *);
extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, char *);
extern u8 func_088D6AC8(s32, s32);
extern u8 func_088D6A1C(s32, s32);
extern void func_08821924(char *, s32);

u16 func_08820B74(char *arg0, char *arg1, u8 *arg2, u8 *arg3) {
    s32 s1 = *(s32 *)(arg0 + 0x530);
    u16 r = 0;
    char *e = func_0885CA50(D_08A62C54, arg1);
    u8 v;

    func_08821890(arg0, s1);
    func_08821A10(arg0, s1, arg1);
    *arg2 = *(u8 *)(e + 0x13) + 3;
    v = func_088D6AC8(s1, 0x14);
    if (v != 0) {
        switch (v) {
        case 0x2F: *arg2 += 1; break;
        case 0x30: *arg2 += 2; break;
        case 0x31: *arg2 += 3; break;
        case 0x32: *arg2 -= 1; break;
        case 0x33: *arg2 -= 2; break;
        case 0x34: *arg2 -= 3; break;
        }
        if (*arg2 > 9) {
            *arg2 = 9;
        }
        r |= 1;
    }
    if (func_088D6A1C(s1, 0xD9) == 1) {
        *arg3 = 1;
        r |= 4;
    } else {
        *arg3 = *(u8 *)(e + 0xB);
        if (*(u16 *)(arg1 + 4) & 0x10) {
            *arg3 += 1;
        }
        if (func_088D6A1C(s1, 0x36) == 1) {
            *arg3 += 4;
            if (*arg3 > 6) {
                *arg3 = 6;
            }
            r |= 2;
        } else if (func_088D6A1C(s1, 0x35) == 1) {
            *arg3 += 2;
            if (*arg3 > 6) {
                *arg3 = 6;
            }
            r |= 2;
        }
    }
    func_08821924(arg0, s1);
    return r;
}
