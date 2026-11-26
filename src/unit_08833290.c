/* unit_08833290: 0x08833290-0x08834304 (ULES01213)
 *
 * Draws the detail sheet of one record (arg3): a frame, an icon, then label /
 * value rows; when arg4 is not 1, a second frame with the names of the bits
 * set in the 64-bit mask at +0x34 and of the three entries at +0x44.
 *
 * .data 0x089387A4-0x089387BC, 0x089387BC-0x089387DC, 0x089387DC-0x089387EA
 * (+2 bytes of padding) and 0x089387EC-0x0893884E (+2 bytes of padding): the
 * constants of the four initialised locals (s16[6][2], s16[16], s16[7],
 * s16[7][7]).
 *
 * Optimized for speed (`/ 6` is a multiplication, loops tested at the bottom).
 * The row at +0x40 keeps its x in an s32 local (`xs`), which is what gives
 * its registers; the y of the two last loops is `yb + row * 0x10`, reduced by
 * the compiler to a stepped value.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_089AC89A;
extern u16 D_089AC89C;
extern u16 D_089AD104;
extern u16 D_089AD106;
extern u16 D_089AD108;
extern u16 D_089AD10A;
extern u16 D_089AD10C;
extern u16 D_089AD10E;
extern u16 D_089AD110;
extern u16 D_089AD112;
extern u16 D_089AD114;
extern u16 D_089AD116;
extern u16 D_089AD11A;
extern u16 D_089AD11C;
extern u16 D_089AD120[];
extern u16 D_089AD168[];
extern u16 D_089AD188[];
extern u16 D_09B05300[];
extern u16 D_09B05480[];
extern u8 D_09CD0258[][6];
extern char D_08938478[];
extern char D_08938548[];
extern char D_08938850[];

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882DCB0(char *, u16, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern s32 func_08857E6C(char *, char *);
extern s32 func_08858008(char *, char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

static inline s32 bit_of(u32 m) {
    if (m >= 0x24) {
        return -1;
    }
    return D_09CD0258[(u8) (m / 6)][(u8) (m % 6)];
}

void func_08833290(char *arg0, u16 arg1, s32 arg2, char *e, s32 arg4) {
    s16 a[6][2] = { { 0xE0, 0xBE }, { 8, 8 }, { 0x20, 0xD }, { 8, 0x28 }, { 0xE0, 0x4D }, { 8, 0xC8 } };
    s16 b[16] = { 2, 0, 1, 3, 4, 3, 3, 1, 1, 1, 3, 1, 3, 0, 4, 5 };
    s16 c[7] = { 6, 6, 6, 6, 6, 7, 6 };
    s32 lang;
    s8 col;
    s32 h;
    s32 y0;
    s32 x0;
    u16 x;
    u16 y;
    char *text;
    s32 cw;
    s32 step;
    s32 xb;
    s32 yb;
    s32 xb2;
    s32 v;
    u32 k;
    u16 xx;
    s32 xs;
    s32 n;
    u32 m;
    s32 bit;
    s32 row;

    lang = *(s32 *)(D_08A631A0 + 0xF7A574);
    if (*(s8 *)e == 0) {
        col = 9;
    } else {
        col = 5;
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    h = (u16) a[0][1];
    func_0882DCB0(arg0, arg1, arg2, (u16) a[0][0], h, 0xFF, 0x1D5);
    x0 = arg1;
    y0 = (u16) arg2;
    x = x0 + (u16) a[1][0];
    y = y0 + (u16) a[1][1];
    if (*(s8 *)e != 0) {
        func_0882BE60(arg0, x, y, 0x18, 0x18, 0xFF, 0xFF, 0xFF, 0xEF);
        if (*(s8 *)e & 2) {
            func_0882AF70(arg0, 0x9A, 0x10, 0x4C, 0x4C, 0x1D4);
        }
    } else {
        func_0882BE60(arg0, x, y, 0x18, 0x18, 0x7F, 0x7F, 0x7F, 0xEF);
    }
    x = x0 + (u16) a[2][0];
    y = y0 + (u16) a[2][1];
    text = func_0885151C(D_089CC438, D_089AD116);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    if (*(s8 *)e != 0) {
        if ((s32) ((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
            text = func_09A7B790(D_09B22D70, D_09B05300[*(u8 *)(e + 1)]);
        } else {
            text = D_089CC438 + 0x6A210;
        }
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938478, text);
    }
    xb = x0 + (u16) a[3][0];
    yb = y0 + (u16) a[3][1];
    x = xb;
    y = yb;
    text = func_0885151C(D_089CC438, D_089AD104);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    cw = c[lang];
    step = cw * 0xE;
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0 && arg4 != 1) {
        func_08890E38(D_08A631A8, 0);
        func_088912BC(D_08A631A8, (u16) (x + 0xE), y, e + 0x4E);
    }

    y = yb + 0x10;
    x = xb;
    text = func_0885151C(D_089CC438, D_089AD106);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938548, *(u8 *)(e + 0x16) + 1);
    }

    y = yb + 0x20;
    x = xb;
    text = func_0885151C(D_089CC438, D_089AC89A);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        if (arg4 != 1) {
            v = func_08857E6C(D_089CC438, e);
        } else {
            v = (s16) *(float *)(e + 0x18);
        }
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938548, v);
    }

    y = yb + 0x30;
    x = xb;
    text = func_0885151C(D_089CC438, D_089AC89C);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        if (arg4 != 1) {
            v = func_08858008(D_089CC438, e);
        } else {
            v = (s16) *(float *)(e + 0x1C);
        }
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938548, v);
    }

    y = yb + 0x40;
    xs = (u16) xb;
    text = func_0885151C(D_089CC438, D_089AD108);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, xs, y, D_08938478, text);
    xs = (u16) (xs + (u16) step);
    func_08891474(D_08A631A8, xs, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        xx = xs + 0xE;
        v = *(s16 *)(e + 0x2A);
        if (v < 1000) {
            n = 0;
        } else if (v < 2500) {
            n = 1;
        } else if (v < 4500) {
            n = 2;
        } else if (v < 6000) {
            n = 3;
        } else if (v < 7000) {
            n = 4;
        } else {
            n = 5;
        }
        for (k = 0; k < n; k++, xx += 0x10) {
            func_0882A9DC(arg0, xx, y, 0x1D3);
        }
    }

    text = func_0885151C(D_089CC438, D_089AD112);
    y = yb + 0x50;
    x = xb;
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        if ((s32) ((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
            text = func_09A7B790(D_09B22D70, D_09B05480[*(s8 *)(e + 2)]);
        } else {
            text = D_089CC438 + 0x6A224;
        }
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938478, text);
    }

    y = yb + 0x60;
    x = xb;
    text = func_0885151C(D_089CC438, D_089AD10A);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938478, func_0885151C(D_089CC438, D_089AD168[*(u8 *)(e + 0x4B)]));
    }

    y = yb + 0x70;
    x = xb;
    text = func_0885151C(D_089CC438, D_089AD10C);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        if (*(u8 *)(e + 0x2C) == 1) {
            text = func_0885151C(D_089CC438, D_089AD11A);
        } else {
            text = func_0885151C(D_089CC438, D_089AD11C);
        }
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938478, text);
    }

    x = xb;
    y = yb + 0x80;
    text = func_0885151C(D_089CC438, D_089AD10E);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_08938478, text);
    x += (u16) step;
    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938478, func_0885151C(D_089CC438, D_089AD188[(u16) b[*(u8 *)(e + 0x4B)]]));
    }

    if (arg4 != 1) {
        func_0882DCB0(arg0, arg1, (u16) (y0 + (u16) h), (u16) a[4][0], (u16) a[4][1], 0xFF, 0x1D5);
        xb2 = x0 + (u16) a[5][0];
        yb = y0 + (u16) a[5][1];
        x = xb2;
        y = yb;
        text = func_0885151C(D_089CC438, D_089AD110);
        func_08890E38(D_08A631A8, col);
        func_08891474(D_08A631A8, x, y, D_08938478, text);
        {
            s16 d[7][7] = { { 0 }, { 0 }, { 3, -2 }, { 0 }, { 1 }, { 1 }, { 0 } };

            x += (u16) (d[lang][1] + (cw + d[lang][0]) * 0xE);
        }
        func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD116));
        if (*(s8 *)e != 0) {
            func_08890E38(D_08A631A8, 0);
            func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_08938850, *(s32 *)(e + 0x30), func_0885151C(D_089CC438, D_089AD114));
        }
        if (*(s8 *)e != 0) {
            row = 1;
            func_08890E38(D_08A631A8, 0);
            for (m = 0; m < 0x40; m++) {
                bit = bit_of(m);
                if (bit >= 0) {
                    if ((*(u32 *)(e + 0x34) + ((u64) *(u32 *)(e + 0x38) << 32)) & ((u64) 1 << bit)) {
                        x = xb2;
                        y = yb + row * 0x10;
                        func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD120[bit]));
                        row++;
                    }
                }
            }
            func_08890E38(D_08A631A8, 9);
            for (m = 0; m < 3; m++) {
                v = *(s8 *)(e + m + 0x44);
                if (v >= 0) {
                    x = xb2;
                    y = yb + row * 0x10;
                    func_08891474(D_08A631A8, x, y, D_08938478, func_0885151C(D_089CC438, D_089AD120[v]));
                    row++;
                }
            }
        }
    }
}
