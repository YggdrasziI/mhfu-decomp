/* unit_088F1664: 0x088F1664-0x088F2224 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * A page with four entries (cursor at +0x10). State (+0xD): 0 initialises,
 * 1 moves the cursor and opens an entry, 10 and 15 pick a cell in a grid of
 * seven columns (column +0x11, row +0x14, row count +0x1C, cell count +0x18),
 * 20 waits for the byte at D_08A62C60 + 0x74 to clear, 30 is the list of nine
 * entries of func_088F383C (+0xE). The second half draws the state.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define SND(n) func_08883988(D_08A62D8C, 0, (n), 0, 0, 0, 0, 0, 0)
#define DIRTY(a) (*(u8 *)((a) + 0xA72D))

extern s32 D_08A62D8C;
extern char *D_08A62C60;
extern char *D_089CC438;
extern char D_09A5E71C[];

extern void func_088530C4(char *, char *, s32);
extern void func_08868C04(char *, s32, s32, char *, char *, s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088F383C(char *, u16, char *);
extern void func_088F56B8(char *, char *, s32);
extern void func_088F5C88(char *, u32 *);
extern void func_088F6450(char *, char *, s8);
extern void func_088FD170(char *);
extern u32 func_0890383C(char *);
extern void memcpy(void *, void *, s32);

s32 func_088F1664(char *arg0, u16 arg1, char *arg2) {
    s32 ret;
    s32 old;
    u16 id;
    u32 idx;
    s32 pad;

    ret = 0;
    switch (*(s8 *)(arg0 + 0xD)) {
    case 0:
        func_088FD170(arg0);
        *(s8 *)(arg0 + 0xD) = 1;
    case 1:
        if (*(s8 *)(arg0 + 0x10) < 3) {
            if (arg1 & 0x50) {
                *(s8 *)(arg0 + 0x10) = 3;
                SND(0x17);
            } else if (arg1 & 0x80) {
                if (--*(s8 *)(arg0 + 0x10) < 0) {
                    *(s8 *)(arg0 + 0x10) = 2;
                }
                SND(0x17);
            } else if (arg1 & 0x20) {
                if (++*(s8 *)(arg0 + 0x10) > 2) {
                    *(s8 *)(arg0 + 0x10) = 0;
                }
                SND(0x17);
            }
        } else if (arg1 & 0x50) {
            *(s8 *)(arg0 + 0x10) = 0;
            SND(0x17);
        }
        *(s8 *)(arg0 + 0x10) = *(s8 *)(arg0 + 0x10) < 0 ? 3 : *(s8 *)(arg0 + 0x10) > 3 ? 0 : *(s8 *)(arg0 + 0x10);
        if (arg1 & 0x4000) {
            switch (*(s8 *)(arg0 + 0x10)) {
            case 0:
            case 2:
                *(s8 *)(arg0 + 0xD) = 0xA;
                *(s8 *)(arg0 + 0x11) = 0;
                *(s8 *)(arg0 + 0x14) = 0;
                *(u32 *)(arg0 + 0x18) = *(u16 *)(arg0 + 0xC2B0);
                *(s8 *)(arg0 + 0x1C) = (*(u32 *)(arg0 + 0x18) - 1) / 7 + 1;
                SND(0x13);
                DIRTY(arg0) = 1;
                break;
            case 1:
                *(s8 *)(arg0 + 0xD) = 0xF;
                *(s8 *)(arg0 + 0x11) = 0;
                *(s8 *)(arg0 + 0x14) = 0;
                *(u32 *)(arg0 + 0x18) = func_0890383C(arg0);
                *(s8 *)(arg0 + 0x1C) = (*(u32 *)(arg0 + 0x18) - 1) / 7 + 1;
                SND(0x13);
                DIRTY(arg0) = 1;
                break;
            case 3:
                *(s8 *)(arg0 + 0xD) = 0x14;
                memcpy(D_09A5E71C, arg2 + 0x34, 0x62);
                func_08868C04(D_08A62C60, 2, 0, arg2 + 0x34, D_09A5E71C, 0x31, 1);
                SND(0x13);
                break;
            }
        } else if (arg1 & 0x2000) {
            ret = 0x2000;
            if (DIRTY(arg0)) {
                memcpy(D_089CC438 + 0x6A504, D_089CC438 + 0x479C, 0x38);
            }
            SND(0x14);
        } else if (arg1 & 0x8000) {
            *(s8 *)(arg0 + 0xD) = 0x1E;
            *(s8 *)(arg0 + 0xE) = 0;
            *(s8 *)(arg0 + 0xA72C) = 0;
            *(s8 *)(arg0 + 0x10) = 0;
            SND(0x13);
        }
        break;
    case 10:
        old = *(s8 *)(arg0 + 0x14);
        if (arg1 & 0x10) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) - 1;
            SND(0x17);
        } else if (arg1 & 0x40) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) + 1;
            SND(0x17);
        } else if (arg1 & 0x80) {
            *(s8 *)(arg0 + 0x14) = old - 1;
        } else if (arg1 & 0x20) {
            *(s8 *)(arg0 + 0x14) = old + 1;
        }
        *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) < 0 ? 6 : *(s8 *)(arg0 + 0x11) > 6 ? 0 : *(s8 *)(arg0 + 0x11);
        *(s8 *)(arg0 + 0x14) = *(s8 *)(arg0 + 0x14) < 0 ? *(s8 *)(arg0 + 0x1C) - 1 : *(s8 *)(arg0 + 0x14) > *(s8 *)(arg0 + 0x1C) - 1 ? 0 : *(s8 *)(arg0 + 0x14);
        if (*(s8 *)(arg0 + 0x14) != (s8) old) {
            SND(0x11);
        }
        if (arg1 & 0x4000) {
            id = ((u16 (*)[2])(arg0 + 0xBC28))[*(s8 *)(arg0 + 0x11) + *(s8 *)(arg0 + 0x14) * 7][0];
            if (id != 0x1A2) {
                ((u16 *)(arg2 + 0x9A))[*(s8 *)(arg0 + 0x10)] = id;
                *(s8 *)(arg0 + 0xD) = 1;
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x2000) {
            *(s8 *)(arg0 + 0xD) = 1;
            SND(0x14);
        }
        break;
    case 15:
        old = *(s8 *)(arg0 + 0x14);
        if (arg1 & 0x10) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) - 1;
            SND(0x17);
        } else if (arg1 & 0x40) {
            *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) + 1;
            SND(0x17);
        } else if (arg1 & 0x80) {
            *(s8 *)(arg0 + 0x14) = old - 1;
        } else if (arg1 & 0x20) {
            *(s8 *)(arg0 + 0x14) = old + 1;
        }
        *(s8 *)(arg0 + 0x11) = *(s8 *)(arg0 + 0x11) < 0 ? 6 : *(s8 *)(arg0 + 0x11) > 6 ? 0 : *(s8 *)(arg0 + 0x11);
        *(s8 *)(arg0 + 0x14) = *(s8 *)(arg0 + 0x14) < 0 ? *(s8 *)(arg0 + 0x1C) - 1 : *(s8 *)(arg0 + 0x14) > *(s8 *)(arg0 + 0x1C) - 1 ? 0 : *(s8 *)(arg0 + 0x14);
        if (*(s8 *)(arg0 + 0x14) != (s8) old) {
            SND(0x11);
        }
        if (arg1 & 0x4000) {
            idx = *(s8 *)(arg0 + 0x11) + *(s8 *)(arg0 + 0x14) * 7;
            if (idx < *(u32 *)(arg0 + 0x18)) {
                *(u16 *)(arg2 + 0x9C) = idx;
                *(s8 *)(arg0 + 0xD) = 1;
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x2000) {
            *(s8 *)(arg0 + 0xD) = 1;
            SND(0x14);
        }
        break;
    case 20:
        if (*(u8 *)(D_08A62C60 + 0x74) == 0) {
            memcpy(arg2 + 0x34, D_09A5E71C, 0x62);
            func_088530C4(D_089CC438, arg2 + 0x34, 1);
            *(s8 *)(arg0 + 0xD) = 1;
        }
        break;
    case 30:
        if (arg1 & 0x100) {
            if (--*(s8 *)(arg0 + 0xE) < 0) {
                *(s8 *)(arg0 + 0xE) = 8;
            }
            SND(0x11);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x200) {
            if (++*(s8 *)(arg0 + 0xE) > 8) {
                *(s8 *)(arg0 + 0xE) = 0;
            }
            SND(0x11);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x2000) {
            *(s8 *)(arg0 + 0xD) = 1;
            SND(0x14);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else {
            func_088F383C(arg0, arg1, arg2);
        }
        break;
    }
    pad = arg1 & 8;
    if (pad) {
        if (DIRTY(arg0)) {
            memcpy(D_089CC438 + 0x6A504, D_089CC438 + 0x479C, 0x38);
        }
    }
    switch (*(s8 *)(arg0 + 0xD)) {
    case 0:
    case 1:
        func_088F56B8(arg0, arg2, *(s8 *)(arg0 + 0x10));
        break;
    case 10:
    case 15:
        func_088F5C88(arg0, (u32 *)(D_089CC438 + 0x6A504));
        func_088F56B8(arg0, arg2, *(s8 *)(arg0 + 0x10));
        break;
    case 20:
        func_088F56B8(arg0, arg2, *(s8 *)(arg0 + 0x10));
        break;
    default:
    case 30:
        func_088F6450(arg0, arg2, *(s8 *)(arg0 + 0xE));
        break;
    }
    if (*(u8 *)(D_08A62C60 + 0x74) != 0) {
        return ret;
    }
    return ret | pad;
}
