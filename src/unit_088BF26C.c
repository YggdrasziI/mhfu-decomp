/* unit_088BF26C: 0x088BF26C-0x088BF858 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * A yes/no page driven by the state word at +0xC (0..3) and the cursor
 * byte at +0x4.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern char *D_089CBBEC;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088BA5BC(s32, s32, s32, s32);
extern void func_088BA494(s32, s32, s32);
extern void func_088BA2E0(s32, s32, s32, s32);
extern void func_08831F3C(char *, s32, s32, s32, s32, s32, s32, s32);

static inline s32 func_088BF26C_sel(char *arg0) {
    s32 pad;

    pad = D_08A62C6C;
    if (pad & 0x80) {
        if (*(u8 *)(arg0 + 4) == 0) {
            *(u8 *)(arg0 + 4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (pad & 0x20) {
        if (*(u8 *)(arg0 + 4) != 0) {
            *(u8 *)(arg0 + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((pad & 0x4000) && *(u8 *)(arg0 + 4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((pad & 0x2000) || ((pad & 0x4000) && *(u8 *)(arg0 + 4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

s32 func_088BF26C(char *arg0) {
    s32 ret;
    s32 pad;
    s32 sel;

    ret = 0;
    switch (*(s32 *)(arg0 + 0xC)) {
    case 0:
        *(u8 *)(arg0 + 4) = 1;
        *(s32 *)(arg0 + 0xC) = 1;
    case 1:
        sel = func_088BF26C_sel(arg0);
        if (sel == 2) {
            ret = 1;
        } else if (sel == 1) {
            *(s32 *)(arg0 + 0xC) = 2;
        }
        if (!(*(s32 *)(arg0 + 0x990) & 1)) {
            func_088BA5BC(0x10, 0xC0, 0x1C0, 0x48);
            func_088BA494(0xF0, 0xCC, 6);
            func_088BA2E0(0xB8, 0xEC, *(u8 *)(arg0 + 4), 1);
        } else {
            func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
            func_088BA494(0xF0, 0x70, 4);
            func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        }
        break;
    case 2:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x21);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        pad = D_08A62C6C;
        if (pad & 0x80) {
            if (*(u8 *)(arg0 + 4) == 0) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 4) = 1;
        } else if (pad & 0x20) {
            if (*(u8 *)(arg0 + 4) == 1) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 4) = 0;
        } else if ((pad & 0x4000) && *(u8 *)(arg0 + 4) != 0) {
            *(s32 *)(arg0 + 0xC) = 3;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (((pad & 0x4000) && *(u8 *)(arg0 + 4) == 0) || (pad & 0x2000)) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 2;
        }
        break;
    case 3:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x22);
        func_088BA494(0xF0, 0xA0, 0x25);
        if (*(u8 *)(arg0 + 4) == 0) {
            func_08831F3C(D_089CBBEC, 0xD4, 0x9E, 0xA8, 0x10, 0, 0x80, 0);
        } else {
            func_08831F3C(D_089CBBEC, 0x72, 0x9E, 0x62, 0x10, 0, 0x80, 0);
        }
        pad = D_08A62C6C;
        if (pad & 0x80) {
            if (*(u8 *)(arg0 + 4) == 0) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 4) = 1;
        } else if (pad & 0x20) {
            if (*(u8 *)(arg0 + 4) == 1) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 4) = 0;
        } else if ((pad & 0x4000) && *(u8 *)(arg0 + 4) != 0) {
            ret = 1;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if ((pad & 0x4000) && *(u8 *)(arg0 + 4) == 0) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 3;
        } else if (pad & 0x2000) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 2;
        }
        break;
    }
    return ret;
}
