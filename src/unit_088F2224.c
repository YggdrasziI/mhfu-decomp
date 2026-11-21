/* unit_088F2224: 0x088F2224-0x088F2B0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * .rodata 0x0893292C-0x0893296C: the two jump tables (the second switch's
 * table comes first).
 * A page with three entries of 0x1C bytes at +0x2C: the pad moves the cursor
 * (+0x11), a button toggles an entry, another one opens a yes/no question
 * (+0x25), then four steps (+0xD = 4..7) run one after the other.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_08A62D8C;
extern char *D_08A631A0;
extern char *D_09A0B544;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B055A6;
extern u16 D_09B055A8;

extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern s32 func_088900C4(char *, s32);
extern void func_0889D8A8(char *, char *, s32, s32 *);
extern void func_088BA2E0(s32, s32, s32, s32);
extern void func_088F61B4(char *, char *, s8);
extern void func_088FC62C(char *, char *);
extern s32 func_088FC7A8(char *);
extern s32 func_088FCF40(char *, s32);
extern void func_088FCF84(char *, s32);
extern char *func_09A7B790(s32, u16);

s32 func_088F2224(char *arg0, u16 arg1) {
    s32 ret;
    s32 local[2];
    char *temp;
    s32 i;
    char *p;
    u16 *q;
    s32 v;

    ret = 0;
    switch (*(s8 *)(arg0 + 0xD)) {
    case 0:
        func_088FC62C(arg0, arg0 + 0x2C);
        *(s32 *)(arg0 + 0x80) = 0;
        *(s8 *)(arg0 + 0x11) = 0;
        *(s8 *)(arg0 + 0xD) = 1;
    case 1:
        if (arg1 & 0x10) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) - 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        } else if (arg1 & 0x40) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) + 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) < 0 ? 2 : *(s8 *)(arg0 + 0x11) > 2 ? 0 : *(s8 *)(arg0 + 0x11);
        if (arg1 & 0x4000) {
            if (*(s32 *)(arg0 + 0x80) > 0) {
                *(u8 *)(arg0 + 0x25) = 0;
                *(s8 *)(arg0 + 0xD) = 2;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if (arg1 & 0x8000) {
            q = (u16 *)(arg0 + *(s8 *)(arg0 + 0x11) * 0x1C + 0x2C);
            if (*q != 0 && *q != 3) {
                if (*q == 1) {
                    *q = 2;
                    *(s32 *)(arg0 + 0x80) = *(s32 *)(arg0 + 0x80) + 1;
                } else {
                    *q = 1;
                    *(s32 *)(arg0 + 0x80) = *(s32 *)(arg0 + 0x80) - 1;
                }
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if (arg1 & 0x2000) {
            ret = 0x2000;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 2:
        if (arg1 & 0x80) {
            if (*(u8 *)(arg0 + 0x25) == 0) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 0x25) = 1;
        } else if (arg1 & 0x20) {
            if (*(u8 *)(arg0 + 0x25) == 1) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 0x25) = 0;
        } else if ((arg1 & 0x4000) && *(u8 *)(arg0 + 0x25) != 0) {
            *(s8 *)(arg0 + 0xD) = 3;
            *(s32 *)(arg0 + 0x28) = 0x12C;
            for (p = arg0 + 0x2C, i = 0; i < 3; i++, p += 0x1C) {
                if (*(u16 *)p == 2) {
                    local[0] = 0;
                    local[1] = (u16) func_088900C4(D_08A631A0, 1);
                    func_0889D8A8(D_09A0B544, p + 0x16, 0, local);
                }
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (((arg1 & 0x4000) && *(u8 *)(arg0 + 0x25) == 0) || (arg1 & 0x2000)) {
            *(s8 *)(arg0 + 0xD) = 1;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 3:
        *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x28) - 1;
        if (func_088FC7A8(arg0) != 0 || *(s32 *)(arg0 + 0x28) < 0) {
            *(s8 *)(arg0 + 0xD) = 4;
            func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
            temp = D_089CBBEC;
            *(s8 *)(temp + 0x534) = 0xE;
            func_08890E08(D_08A631A8, 5);
            func_08825DA8(temp);
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
            func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B055A8), 0xE, 0x10);
            return arg1 & 8;
        }
        break;
    case 4:
        if (func_088FCF40(arg0, 2) > 0) {
            if (arg1 & 0x4000) {
                *(s8 *)(arg0 + 0xD) = 5;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
                func_088FCF84(arg0, 2);
                return arg1 & 8;
            }
            break;
        }
        *(s8 *)(arg0 + 0xD) = 5;
    case 5:
        if (func_088FCF40(arg0, 1) > 0) {
            if (arg1 & 0x4000) {
                *(s8 *)(arg0 + 0xD) = 6;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
                func_088FCF84(arg0, 1);
                return arg1 & 8;
            }
            break;
        }
        *(s8 *)(arg0 + 0xD) = 6;
    case 6:
        if (func_088FCF40(arg0, 3) > 0) {
            if (arg1 & 0x4000) {
                *(s8 *)(arg0 + 0xD) = 7;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
                func_088FCF84(arg0, 3);
                return arg1 & 8;
            }
            break;
        }
        *(s8 *)(arg0 + 0xD) = 7;
    case 7:
        if (func_088FCF40(arg0, 0) > 0) {
            if (arg1 & 0x4000) {
                *(s8 *)(arg0 + 0xD) = 0;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
                func_088FCF84(arg0, 0);
                return arg1 & 8;
            }
            break;
        }
        *(s8 *)(arg0 + 0xD) = 0;
        break;
    }
    if (arg1 & 0x2000) {
        ret = 0x2000;
    }
    func_088F61B4(arg0, arg0 + 0x2C, *(s8 *)(arg0 + 0x11));
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xE;
    func_08890E08(D_08A631A8, 5);
    func_08825DA8(temp);
    switch (*(s8 *)(arg0 + 0xD)) {
    case 2:
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B055A6), 0xE, 0x10);
        func_088BA2E0(0xB8, 0xA8, *(u8 *)(arg0 + 0x25), 1);
        break;
    case 3:
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B055A8), 0xE, 0x10);
        break;
    case 4:
        func_088FCF84(arg0, 2);
        break;
    case 5:
        func_088FCF84(arg0, 1);
        break;
    case 6:
        func_088FCF84(arg0, 3);
        break;
    case 7:
        func_088FCF84(arg0, 0);
        break;
    }
    return ret | (arg1 & 8);
}
