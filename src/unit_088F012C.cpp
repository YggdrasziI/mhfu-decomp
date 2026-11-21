/* unit_088F012C: 0x088F012C-0x088F1664 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * .rodata 0x0893290C-0x0893292C: the jump table.
 * A page over a grid of 8 x 12 records (pointers at +0xA730, 0x1078 bytes
 * each, with a 0x28-byte header each at +0xA8B0) and five tabs (+0x16).
 * State (+0xD): 0 resets the cursor, 1 moves it (+0x11 column, +0x14 row) and
 * opens an action, 2 shows a copy of the record (+0xABB0), 3 is a yes/no
 * question (+0x25) before erasing, 4 its confirmation, 5 edits the byte
 * +0x26 of the header, 6 waits for the text entry of its name, 7 picks a
 * second cell to move the record to.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" {

typedef struct { s16 a, b, c; } S3;
typedef long long s64;
typedef struct { f32 a, b, c, d; } F4;
typedef struct { f32 a, b, c; } F3;
typedef struct { F4 a; F3 b; } F7;

typedef struct {
    /* 0x0000 */ s8 unk0[18];
    /* 0x0012 */ u16 unk12;
    /* 0x0014 */ u16 unk14;
    /* 0x0016 */ s16 unk16[5];
    /* 0x0020 */ s16 unk20[7];
    /* 0x0030 */ s32 unk30;
    /* 0x0034 */ s8 unk34[98];
    /* 0x0096 */ u8 unk96;
    /* 0x0097 */ u8 unk97;
    /* 0x0098 */ u8 unk98;
    /* 0x009A */ S3 unk9A;
    /* 0x00A0 */ s64 unkA0;
    /* 0x00A8 */ F7 unkA8;
    /* 0x00C4 */ s8 unkC4[126];
    /* 0x0148 */ s64 unk148;
    /* 0x0150 */ s16 unk150[124];
    /* 0x0248 */ s8 unk248[8];
    /* 0x0250 */ s32 unk250[23];
    /* 0x02AC */ s32 unk2AC[100];
    /* 0x043C */ s32 unk43C[23];
    /* 0x0498 */ s32 unk498[100];
    /* 0x0628 */ s16 unk628[11];
    /* 0x0640 */ s32 unk640[340];
    /* 0x0B90 */ s32 unkB90[208];
    /* 0x0ED0 */ s32 unkED0[35];
    /* 0x0F5C */ s32 unkF5C[35];
    /* 0x0FE8 */ s32 unkFE8[35];
    /* 0x1074 */ u16 unk1074;
    /* 0x1076 */ u8 unk1076;
    /* 0x1077 */ u8 unk1077;
} Record; /* 0x1078 */

typedef struct {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ char name[0x22];
    /* 0x26 */ s8 unk26;
} Header; /* 0x28 */

typedef struct {
    /* 0x0000 */ char pad0[0xD];
    /* 0x000D */ s8 state;
    /* 0x000E */ s8 unkE;
    /* 0x000F */ s8 unkF;
    /* 0x0010 */ s8 unk10;
    /* 0x0011 */ s8 col;
    /* 0x0012 */ s8 col0;
    /* 0x0013 */ s8 row0;
    /* 0x0014 */ s8 row;
    /* 0x0015 */ u8 unk15;
    /* 0x0016 */ s8 tab;
    /* 0x0017 */ char pad17[7];
    /* 0x001E */ s8 unk1E;
    /* 0x001F */ char pad1F[6];
    /* 0x0025 */ u8 yes;
    /* 0x0026 */ char pad26[0xA706];
    /* 0xA72C */ s8 unkA72C;
    /* 0xA730 */ Record *rec[96];
    /* 0xA8B0 */ Header *hdr[96];
    /* 0xAA30 */ char padAA30[0x180];
    /* 0xABB0 */ Record cur;
} Page;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_089CC438;
extern char *D_08A62C60;
extern s32 D_08A62D8C;
extern s32 *D_09B22D70;
extern u16 D_09B0559E;
extern u16 D_09B055A0;
extern char D_09A5E6F8;

extern void func_08825DA8(char *);
extern int func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_088530C4(char *, char *, s32);
extern void func_08868C04(char *, s32, s32, char *, char *, s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern int func_08890E08(char *, s32);
extern void func_088BA2E0(s32, s32, u8, s32);
extern void func_088BA664(s32, s32);
extern void func_088F383C(Page *, u16, Record *);
extern void func_088F4A7C(Page *);
extern void func_088F6450(Page *, Record *, s8);
extern void func_08901A60(Page *);
extern void func_08901FDC(Page *, s32, s32);
extern void func_089030D8(Page *);
extern char *func_09A7B790(s32 *, u16);
extern void memcpy(void *, void *, s32);
extern void memset(void *, s32, s32);

#define SND(n) func_08883988(D_08A62D8C, 0, n, 0, 0, 0, 0, 0, 0)
#define IDX(p) ((p)->col + (p)->row * 8)

static inline s32 count_used(void) {
    char *p = D_089CC438 + 0x4A58;
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x60; i++, p += 0x1078) {
        if (*(u16 *)p != 0) {
            n++;
        }
    }
    return n;
}

s32 func_088F012C(Page *arg0, u16 arg1) {
    s32 ret;
    s32 moved;
    char *temp;
    s8 *q;

    ret = 0;
    switch (arg0->state) {
    case 0:
        arg0->col = 0;
        arg0->row = 0;
        arg0->tab = 0;
        arg0->state++;
        func_089030D8(arg0);
    case 1:
        moved = 0;
        if (arg1 & 0x10) {
            arg0->col--;
            SND(0x17);
        } else if (arg1 & 0x40) {
            arg0->col++;
            SND(0x17);
        } else if (arg1 & 0x80) {
            arg0->row--;
            SND(0x11);
        } else if (arg1 & 0x20) {
            arg0->row++;
            SND(0x11);
        } else if (arg1 & 0x100) {
            arg0->tab--;
            moved = 1;
            SND(0x11);
        } else if (arg1 & 0x200) {
            arg0->tab++;
            moved = 1;
            SND(0x11);
        }
        arg0->col = arg0->col < 0 ? 7 : arg0->col > 7 ? 0 : arg0->col;
        arg0->row = arg0->row < 0 ? 0xB : arg0->row > 0xB ? 0 : arg0->row;
        arg0->tab = arg0->tab < 0 ? 4 : arg0->tab > 4 ? 0 : arg0->tab;
        if (moved) {
            func_089030D8(arg0);
        } else if (arg1 & 0x4000) {
            if (arg0->rec[IDX(arg0)] != 0) {
                arg0->unkE = 0;
                arg0->unkA72C = 0;
                arg0->state++;
                arg0->cur = *arg0->rec[IDX(arg0)];
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 1) {
            if (arg0->rec[IDX(arg0)] != 0) {
                arg0->yes = 0;
                arg0->state = 3;
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x1000) {
            if (arg0->rec[IDX(arg0)] != 0) {
                arg0->state = 5;
                arg0->unk15 = arg0->hdr[IDX(arg0)]->unk26 &= 0x7F;
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x8000) {
            if (arg0->rec[IDX(arg0)] != 0 && arg0->tab == 0) {
                arg0->state = 7;
                arg0->col0 = arg0->col;
                arg0->row0 = arg0->row;
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 8) {
            if (arg0->rec[IDX(arg0)] != 0) {
                arg0->state = 6;
                memcpy(&D_09A5E6F8, arg0->hdr[IDX(arg0)]->name, 0x22);
                func_08868C04(D_08A62C60, 2, 0, arg0->hdr[IDX(arg0)]->name, &D_09A5E6F8, 0x11, 1);
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x2000) {
            ret = 0x2000;
            SND(0x14);
        }
        func_088F4A7C(arg0);
        return ret;
    case 2:
        if (arg1 & 0x100) {
            if (--arg0->unkE < 0) {
                arg0->unkE = 8;
            }
            arg0->unk10 = 0;
            arg0->unk1E = 0;
            arg0->unkF = 0;
            SND(0x11);
        } else if (arg1 & 0x200) {
            if (++arg0->unkE > 8) {
                arg0->unkE = 0;
            }
            arg0->unk10 = 0;
            arg0->unk1E = 0;
            arg0->unkF = 0;
            SND(0x11);
        } else if (arg1 & 0x2000) {
            arg0->state--;
            SND(0x14);
        } else {
            func_088F383C(arg0, arg1, &arg0->cur);
        }
        func_088F6450(arg0, &arg0->cur, arg0->unkE);
        break;
    case 3:
        if (arg1 & 0x80) {
            if (arg0->yes == 0) {
                SND(0x17);
            }
            arg0->yes = 1;
        } else if (arg1 & 0x20) {
            if (arg0->yes == 1) {
                SND(0x17);
            }
            arg0->yes = 0;
        } else if ((arg1 & 0x4000) && arg0->yes != 0) {
            arg0->state = 4;
            memset(arg0->rec[IDX(arg0)], 0, 0x1078);
            memset(arg0->hdr[IDX(arg0)], 0, 0x28);
            func_08901A60(arg0);
            func_089030D8(arg0);
            SND(0x13);
        } else if (((arg1 & 0x4000) && arg0->yes == 0) || (arg1 & 0x2000)) {
            arg0->state = 1;
            SND(0x14);
        }
        func_088F4A7C(arg0);
        temp = D_089CBBEC;
        *(s8 *)(temp + 0x534) = 0xE;
        func_08890E08(D_08A631A8, 5);
        func_08825DA8(temp);
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B0559E), 0xE, 0x10);
        func_088BA2E0(0xB8, 0xA8, arg0->yes, 1);
        return 0;
    case 4:
        if (arg1 & 0x4000) {
            arg0->state = 1;
            SND(0x13);
        }
        func_088F4A7C(arg0);
        temp = D_089CBBEC;
        *(s8 *)(temp + 0x534) = 0xE;
        func_08890E08(D_08A631A8, 5);
        func_08825DA8(temp);
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B055A0), 0xE, 0x10);
        func_088BA664(0x9C, 0xA8);
        return 0;
    case 5:
        if (arg1 & 0x5000) {
            arg0->state = 1;
            SND(0x13);
        } else if (arg1 & 0x80) {
            arg0->hdr[IDX(arg0)]->unk26--;
            SND(0x17);
        } else if (arg1 & 0x20) {
            arg0->hdr[IDX(arg0)]->unk26++;
            SND(0x17);
        } else if (arg1 & 0x2000) {
            arg0->state = 1;
            arg0->hdr[IDX(arg0)]->unk26 = arg0->unk15;
            SND(0x14);
        }
        q = &arg0->hdr[IDX(arg0)]->unk26;
        *q = *q < 0 ? 0x18 : *q > 0x18 ? 0 : *q;
        func_088F4A7C(arg0);
        return 0;
    case 6:
        if (*(u8 *)(D_08A62C60 + 0x74) == 0) {
            arg0->state = 1;
            memcpy(arg0->hdr[IDX(arg0)]->name, &D_09A5E6F8, 0x22);
            func_088530C4(D_089CC438, arg0->hdr[IDX(arg0)]->name, 1);
        }
        func_088F4A7C(arg0);
        return 0;
    case 7:
        if (arg1 & 0x10) {
            arg0->col--;
            SND(0x17);
        } else if (arg1 & 0x40) {
            arg0->col++;
            SND(0x17);
        } else if (arg1 & 0x80) {
            arg0->row--;
            SND(0x11);
        } else if (arg1 & 0x20) {
            arg0->row++;
            SND(0x11);
        }
        arg0->col = arg0->col < 0 ? 7 : arg0->col > 7 ? 0 : arg0->col;
        arg0->row = arg0->row < 0 ? 0xB : arg0->row > 0xB ? 0 : arg0->row;
        if (arg1 & 0xC000) {
            if (count_used() >= IDX(arg0)) {
                arg0->state = 1;
                func_08901FDC(arg0, arg0->col0 + arg0->row0 * 8, arg0->col + arg0->row * 8);
                func_089030D8(arg0);
                SND(0x13);
            } else {
                SND(0x15);
            }
        } else if (arg1 & 0x2000) {
            arg0->state = 1;
            SND(0x14);
        }
        func_088F4A7C(arg0);
        return 0;
    }
    return arg1 & 8;
}

}
