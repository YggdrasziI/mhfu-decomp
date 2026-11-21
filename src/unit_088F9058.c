/* unit_088F9058: 0x088F9058-0x088F9EF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between matched units.
 * Draws a page with a list of five entries (one of three lists chosen by the
 * byte at arg0 + 0x10), a counter, and, when the byte at arg0 + 0x22 is not
 * zero, the detail sheet of the 0x40-byte record arg1 + 0xB90 + n * 0x40
 * with the names of the bits set in its 64-bit mask.
 *
 * .data 0x089B8600-0x089B862A, 0x089B862C-0x089B8656 and
 * 0x089B8658-0x089B8666: the constants of the three initialised locals
 * (s16[7][3], s16[7][3], s16[7]), each followed by 2 bytes of padding.
 *
 * Optimized for speed: guarded loops tested at the bottom, `/ 6` is a
 * multiplication (the `%` stay divisions).
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

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern s32 D_089B81F8[];
extern u16 D_089AC89A;
extern u16 D_089AC89C;
extern u16 D_089AD104;
extern u16 D_089AD106;
extern u16 D_089AD108;
extern u16 D_089AD10A;
extern u16 D_089AD110;
extern u16 D_089AD112;
extern u16 D_089AD116;
extern u16 D_089AD11E;
extern u16 D_089AD120[];
extern u16 D_089AD168[];
extern u16 D_09B05300[];
extern u16 D_09B05480[];
extern u16 D_09B05568;
extern u16 D_09B05582;
extern u16 D_09B0558E;
extern u16 D_09B055D2;
extern u16 D_09B055E6;
extern u16 D_09B055E8;
extern u16 D_09B055EA;
extern u16 D_09B055F2;
extern u16 D_09B055F4;
extern u16 D_09B05D52;
extern u8 D_09CD0258[][6];
extern char D_089B849C[];
extern char D_089B84A4[];
extern char D_089B84A8[];
extern char D_089B84B8[];
extern char D_089B8668[];
extern char D_089B8670[];
extern char D_089B8674[];

extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_0882E6F0(char *, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern s32 func_088581C0(char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
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

void func_088F9058(char *arg0, char *arg1, s32 arg2) {
    s16 a[7][3] = { { 0, 0, 0 }, { 0x2C, 0x17, 2 }, { 0x32, 8, 1 }, { 0x2C, -5, -0x28 }, { 0x2B, 0xF, -6 }, { 8, 0xF, 1 }, { 0, 0, 0 } };
    s16 b[7][3] = { { 0xA4, 0x9C, 0xB4 }, { 0xA4, 0x9C, 0xB4 }, { 0xA4, 0x9C, 0xB4 }, { 0xA4, 0x9C, 0xB4 }, { 0xA4, 0x9C, 0xB4 }, { 0x9C, 0x9C, 0xB4 }, { 0xA4, 0x9C, 0xB4 } };
    s16 c[7] = { 0x60, 0x60, 0x60, 0x60, 0x60, 0x6C, 0x60 };
    s8 off;
    s32 lang;
    char *temp;
    s32 *frame;
    u16 i;
    char *list;
    u16 count;
    u16 row;
    s32 y;
    u16 x;
    u8 j;
    char *e;
    u8 n;
    u16 x2;
    u16 k;
    u16 yy;
    u16 m;
    s32 bit;
    s32 pages;
    char *text;

    lang = *(s32 *)(D_08A631A0 + 0xF7A574);
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B055D2), 0xE, 0x10);
    frame = &D_089B81F8[arg2];
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0xC0, 0xE0, 0xFF, *frame);
    func_0882DCB0(D_089CBBEC, 0xD8, 0x38, 0xF8, 0xC0, 0xFF, *frame);
    func_0882D6F0(D_089CBBEC, 0xE0, 0x70, 0xE7, 1, 0x80, 0x80, 0x80);
    if (lang == 5 && (u32) *(s8 *)(arg0 + 0x10) < 2) {
        func_08827918(D_089CBBEC, 0x156, 0x40, func_09A7B790(D_09B22D70, (&D_09B05568)[(u32) (*(s8 *)(arg0 + 0x10) + 0x3C)]), 0xE, 0x10);
    } else {
        func_08827918(D_089CBBEC, 0x158, 0x40, func_09A7B790(D_09B22D70, (&D_09B05568)[(u32) (*(s8 *)(arg0 + 0x10) + 0x3C)]), 0xE, 0x10);
    }
    func_08890E38(D_08A631A8, 0);
    func_0882A9DC(D_089CBBEC, 0x148, 0xE2, 0x35);
    func_08891474(D_08A631A8, 0x158, 0xE4, func_09A7B790(D_09B22D70, D_09B05582));
    func_08890E38(D_08A631A8, 5);
    func_08891474(D_08A631A8, 0x1B0, 0xE4, D_089B8668, *(s8 *)(arg0 + 0x10) + 1);
    func_08890E38(D_08A631A8, 0);
    func_08891474(D_08A631A8, 0xEE, 0x60, func_09A7B790(D_09B22D70, D_09B055E6));
    func_08891474(D_08A631A8, 0x138, 0x60, func_09A7B790(D_09B22D70, D_09B0558E));
    off = 0;
    switch (*(s8 *)(arg0 + 0x10)) {
    case 1:
        off = a[lang][1];
        count = *(u16 *)(arg1 + 0x1074);
        list = arg1 + 0xED0;
        func_08891474(D_08A631A8, b[lang][1] + 0xD8, 0x60, func_09A7B790(D_09B22D70, D_09B055F4));
        func_08891474(D_08A631A8, b[lang][2] + 0xD8, 0x60, func_09A7B790(D_09B22D70, D_09B055E8));
        break;
    case 2:
        off = a[lang][2];
        count = *(u8 *)(arg1 + 0x1076);
        list = arg1 + 0xF5C;
        func_08891474(D_08A631A8, b[lang][1] + 0xD8, 0x60, func_09A7B790(D_09B22D70, D_09B055F4));
        func_08891474(D_08A631A8, b[lang][2] + 0xD8, 0x60, func_09A7B790(D_09B22D70, D_09B055EA));
        break;
    case 0:
        off = a[lang][0];
        count = *(u8 *)(arg1 + 0x1077);
        list = arg1 + 0xFE8;
        func_08891474(D_08A631A8, b[lang][0] + 0xD8, 0x60, func_0885151C(D_089CC438, D_089AD108));
        break;
    }
    func_08890E38(D_08A631A8, 0);
    for (i = 0; i < 5; i++, list += 0x1C) {
        if (*(s32 *)(list + 4) != 0) {
            row = i;
            y = (row + 1) * 0x10 + 0x64;
            func_08891474(D_08A631A8, 0xE0, y, D_089B84B8, *(u8 *)(list + 4), *(u8 *)(list + 5), *(u16 *)(list + 6) % 100);
            func_08891474(D_08A631A8, 0x122, y, func_09A7B790(D_09B22D70, D_09B05300[*(u8 *)list]));
            if (*(s8 *)(arg0 + 0x10) == 0) {
                for (x = 0, j = 0; j < *(u8 *)(list + 1); j++, x += 0x10) {
                    func_0882A9DC(D_089CBBEC, x + 0x17C, y, 0x1D3);
                }
            } else {
                y = (row + 1U) * 0x10 + 0x64;
                func_08891474(D_08A631A8, 0x174, y, D_089B84A4, *(u8 *)(list + 1) + 1);
                func_088912BC(D_08A631A8, 0x18C, y, list + 8);
            }
        }
    }
    func_08891474(D_08A631A8, 0x158 - off, 0xC4, func_09A7B790(D_09B22D70, (&D_09B05568)[(u32) (*(s8 *)(arg0 + 0x10) + 0x42)]));
    if (lang == 3) {
        func_08891474(D_08A631A8, 0x162, 0xD4, D_089B8670, count);
        func_08891474(D_08A631A8, 0x180, 0xD4, func_09A7B790(D_09B22D70, D_09B055F2));
    } else {
        func_08891474(D_08A631A8, 0x16C, 0xD4, D_089B8670, count);
        func_08891474(D_08A631A8, 0x188, 0xD4, func_09A7B790(D_09B22D70, D_09B055F2));
    }
    pages = *(s8 *)(arg0 + 0x22);
    if (pages != 0) {
        if ((s8) pages > 1) {
            func_0882E6F0(D_089CBBEC, 0x16, 0x2E, 0x9C, 0xF0);
        }
        func_08890E38(D_08A631A8, 5);
        func_08891474(D_08A631A8, 0x24, 0x2E, func_0885151C(D_089CC438, D_089AD11E));
        func_08891474(D_08A631A8, 0x8C, 0x2E, D_089B849C, *(s8 *)(arg0 + 0x1E) + 1, *(s8 *)(arg0 + 0x22));
        func_08890DE8(D_08A631A8, 0xC, 0xC);
        func_0882BE60(D_089CBBEC, 0x18, 0x42, 0x18, 0x18, 0xFF, 0xFF, 0xFF, 0xEF);
        func_08891474(D_08A631A8, 0x18, 0x5E, func_0885151C(D_089CC438, D_089AD104));
        text = func_0885151C(D_089CC438, D_089AD116);
        func_08891474(D_08A631A8, c[lang], 0x5E, text);
        func_08891474(D_08A631A8, 0x18, 0x6C, func_0885151C(D_089CC438, D_089AD106));
        func_08891474(D_08A631A8, c[lang], 0x6C, func_0885151C(D_089CC438, D_089AD116));
        func_08891474(D_08A631A8, 0x18, 0x7A, func_0885151C(D_089CC438, D_089AC89A));
        func_08891474(D_08A631A8, c[lang], 0x7A, func_0885151C(D_089CC438, D_089AD116));
        func_08891474(D_08A631A8, 0x18, 0x88, func_0885151C(D_089CC438, D_089AC89C));
        func_08891474(D_08A631A8, c[lang], 0x88, func_0885151C(D_089CC438, D_089AD116));
        func_08891474(D_08A631A8, 0x18, 0x96, func_0885151C(D_089CC438, D_089AD108));
        func_08891474(D_08A631A8, c[lang], 0x96, func_0885151C(D_089CC438, D_089AD116));
        func_08891474(D_08A631A8, 0x18, 0xA4, func_0885151C(D_089CC438, D_089AD112));
        func_08891474(D_08A631A8, c[lang], 0xA4, func_0885151C(D_089CC438, D_089AD116));
        func_08891474(D_08A631A8, 0x18, 0xB2, func_0885151C(D_089CC438, D_089AD10A));
        func_08891474(D_08A631A8, c[lang], 0xB2, func_0885151C(D_089CC438, D_089AD116));
        func_0882D6F0(D_089CBBEC, 0x12, 0xC4, 0xBC, 1, 0, 0, 0);
        func_08891474(D_08A631A8, 0x18, 0xCA, func_0885151C(D_089CC438, D_089AD110));
        func_08890E38(D_08A631A8, 0);
        e = arg1 + 0xB90 + *(s8 *)(arg0 + 0x1E) * 0x40;
        if (*(s8 *)e & 2) {
            func_0882AF70(D_089CBBEC, 0x7E, 0x3E, 0x4C, 0x4C, 0x1D4);
        }
        func_08891474(D_08A631A8, 0x32, 0x46, func_09A7B790(D_09B22D70, D_09B05300[*(u8 *)(e + 1)]));
        func_088912BC(D_08A631A8, c[lang] + 8, 0x5E, e + 0x18);
        func_08891474(D_08A631A8, c[lang] + 8, 0x6C, D_089B8674, *(u8 *)(e + 3) + 1);
        func_08891474(D_08A631A8, c[lang] + 8, 0x7A, D_089B8674, *(u16 *)(e + 4));
        func_08891474(D_08A631A8, c[lang] + 8, 0x88, D_089B8674, *(u16 *)(e + 6));
        n = func_088581C0(D_089CC438, *(u16 *)(e + 8));
        for (x2 = 0, k = 0; k < n; k++, x2 += 0x10) {
            func_0882A9DC(D_089CBBEC, x2 + (c[lang] + 8), 0x96, 0x1D3);
        }
        func_08891474(D_08A631A8, c[lang] + 8, 0xA4, func_09A7B790(D_09B22D70, D_09B05480[*(s8 *)(e + 2)]));
        func_08891474(D_08A631A8, c[lang] + 8, 0xB2, func_0885151C(D_089CC438, D_089AD168[*(u8 *)(e + 0xA)]));
        for (yy = 0, m = 0; m < 0x40; m++) {
            bit = bit_of(m);
            if (bit >= 0) {
                if (*(u64 *)(e + 0x10) & ((u64) 1 << bit)) {
                    func_08891474(D_08A631A8, 0x24, yy + 0xD8, D_089B84A8, func_0885151C(D_089CC438, D_089AD120[bit]));
                    yy += 0xE;
                }
            }
        }
    } else {
        func_08891474(D_08A631A8, 0x36, 0x64, func_09A7B790(D_09B22D70, D_09B05D52));
        func_0882A9DC(D_089CBBEC, 0x7E, 0xB0, 0x1EB);
    }
}
