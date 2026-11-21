/* unit_088F7620: 0x088F7620-0x088F9058 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, called from func_088F6450.
 * Draws a scrolling list (13 visible lines from the first line at arg0 +
 * 0x23) built from the ten 0x88-byte records at arg1 + 0x640: a date line
 * when the record's date changes, a title line that depends on the record
 * type, up to three names and up to three detail lines (30 kinds). The line
 * count is stored at arg0 + 0x24 and two arrows show that the list scrolls.
 *
 * .rodata 0x089329B4-0x08932A2C (jump table of the 30 detail kinds) and
 * 0x08932A2C-0x08932A50 (jump table of the 9 record types).
 * .data 0x089B85E0-0x089B85EE and 0x089B85F0-0x089B85FE: the constants of
 * the two initialised locals (seven offsets each), each followed by 2 bytes
 * of padding.
 *
 * Optimized for speed (rotated loops, division by 10 as a multiplication,
 * records reached by strength reduction of the index), with loop unrolling
 * off: the byte-wise clear of the widths is one byte per pass.
 *
 * Register allocation: one counter per loop (`k` for the names, `j` for the
 * details), `line` declared before them; the language is re-read into a
 * block local for the kind 0x10.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    union {
        s32 id;
        struct {
            u8 a;
            u8 b;
            u16 c;
        } d;
    } u;
    s16 type;
    u16 unk6;
    u8 kinds[3];
    s32 a[3];
    s32 b[3];
    char names[3][0x12];
    char text[0x2E];
} Rec;

typedef struct {
    char pad[0x640];
    Rec recs[10];
} Big;

extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CC438;
extern s32 D_09B22D70;
extern s32 D_089B81F8[];
extern char D_089B84B8[];
extern u16 D_089AC65C[];
extern u16 D_089AC8E4;
extern u16 D_089AD058[];
extern u16 D_0893AE80[];
extern u16 D_09B05150[];
extern u16 D_09B05300[];
extern u16 D_09B055D0;
extern u16 D_09B05628[];
extern u16 D_09B0562A;
extern u16 D_09B0562C;
extern u16 D_09B0562E;
extern u16 D_09B05630;
extern u16 D_09B05634;
extern u16 D_09B05636;
extern u16 D_09B05638;
extern u16 D_09B0563A;
extern u16 D_09B0563C;
extern u16 D_09B0563E;
extern u16 D_09B05640;
extern u16 D_09B05642;
extern u16 D_09B05644;
extern u16 D_09B05648;
extern u16 D_09B0564A;
extern u16 D_09B0564C;
extern u16 D_09B0564E;
extern u16 D_09B05650;
extern u16 D_09B05652;
extern u16 D_09B05654;
extern u16 D_09B0565A;
extern u16 D_09B0565C;
extern u16 D_09B0565E;
extern u16 D_09B05660;
extern u16 D_09B05662;
extern u16 D_09B05664;
extern u16 D_09B05666;
extern u16 D_09B05668;

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern char *func_08851540(char *, u16);
extern char *func_0885156C(char *, u16);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

#pragma optimize_for_size off
#pragma opt_unroll_loops off

#define R (&((Big *) arg1)->recs[i])
#define TOP (*(s8 *)(arg0 + 0x23))
#define VISIBLE(l) ((l) < TOP + 13 && (l) >= TOP)
#define Y(l) (((l) - TOP) * 16 + 0x2D)
#define STR(d) func_09A7B790(D_09B22D70, d)
#define LANG (*(s32 *)(D_08A631A0 + 0xF7A574))
#define PUT(l, x) func_08891474(D_08A631A8, widths[lang] + (x), Y(l), buf)

void func_088F7620(char *arg0, char *arg1, s32 arg2) {
    s16 widths[7];
    char buf[0x100];
    char *temp;
    u16 line;
    s32 lang;
    u8 k;
    u8 j;
    s32 last;
    u32 i;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, STR(D_09B055D0), 0xE, 0x10);
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0x1C0, 0xD8, 0xFF, D_089B81F8[arg2]);
    last = 0;
    line = 0;
    clear((char *) widths, sizeof(widths));
    lang = LANG;
    for (i = 0; i < 10; i++) {
        if (R->u.id == 0) {
            continue;
        }
        if (last != R->u.id) {
            last = R->u.id;
            if (VISIBLE(line)) {
                func_08890E38(D_08A631A8, 0);
                func_08891474(D_08A631A8, 0x18, Y(line), D_089B84B8, R->u.d.a, R->u.d.b, R->u.d.c);
            }
            line++;
        }
        switch (R->type) {
        case 0:
        case 1:
        case 4:
            switch (R->type) {
            case 1:
                if (VISIBLE(line)) {
                    func_0880E8F0(buf, STR(D_09B0562A), R->text);
                    func_08890E38(D_08A631A8, 3);
                    PUT(line, 0x24);
                }
                break;
            case 0:
                if (VISIBLE(line)) {
                    func_0880E8F0(buf, STR(D_09B0562C), R->text);
                    func_08890E38(D_08A631A8, 3);
                    PUT(line, 0x24);
                }
                break;
            case 4:
                if (VISIBLE(line)) {
                    func_0880E8F0(buf, STR(D_09B05628[0]), R->text);
                    func_08890E38(D_08A631A8, 3);
                    PUT(line, 0x24);
                }
                break;
            }
            line++;
            for (k = 0; k < 3; k++) {
                if (R->names[k][0] == 0) {
                    break;
                }
                if (VISIBLE(line)) {
                    func_08890E38(D_08A631A8, 4);
                    func_088912BC(D_08A631A8, 0x38, Y(line), R->names[k]);
                }
                line++;
            }
            for (j = 0; j < 3; j++) {
                switch (R->kinds[j]) {
                case 0x15:
                    if (VISIBLE(line)) {
                        char *s = func_0885151C(D_089CC438, D_089AC65C[R->a[j]]);

                        func_0880E8F0(buf, STR(D_09B05638), s, R->b[j] * 10);
                        func_08890E38(D_08A631A8, 6);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x14:
                    if (VISIBLE(line)) {
                        func_0880E8F0(buf, STR(D_09B0563A), R->a[j] * 100);
                        func_08890E38(D_08A631A8, 6);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x1B:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 6);
                        func_0880E8F0(buf, STR(D_09B05640), R->a[j] + 1);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 1:
                case 3:
                case 0x12:
                    if (VISIBLE(line)) {
                        s8 len;
                        u16 *p;

                        func_08890E38(D_08A631A8, 2);
                        len = 0;
                        if (R->a[j] == 0) {
                            func_088912BC(D_08A631A8, widths[lang] + 0x30, Y(line), arg1);
                            p = (u16 *) arg1;
                        } else {
                            func_088912BC(D_08A631A8, widths[lang] + 0x30, Y(line), R->names[R->a[j] - 1]);
                            p = (u16 *) R->names[R->a[j] - 1];
                        }
                        while (*p != 0) {
                            len++;
                            p++;
                        }
                        func_08890E38(D_08A631A8, 0);
                        func_0880E8F0(buf, STR(D_09B05642), R->b[j]);
                        func_08891474(D_08A631A8, widths[lang] + 0x30 + len * 7, Y(line), buf);
                    }
                    line++;
                    break;
                case 0x17:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_0880E8F0(buf, STR(D_09B05644), R->a[j] * 100);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xA:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_0880E8F0(buf, STR(D_09B05662), R->a[j]);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 5:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_08891474(D_08A631A8, widths[lang] + 0x30, Y(line), STR(D_09B0564A));
                    }
                    line++;
                    break;
                case 4:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_08891474(D_08A631A8, widths[lang] + 0x30, Y(line), STR(D_09B05648));
                    }
                    line++;
                    break;
                case 7:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 0);
                        s = STR(D_09B05634);
                        func_0880E8F0(buf, s, func_08851528(D_089CC438, R->a[j]));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x1A:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 6);
                        s = STR(D_09B0563C);
                        func_0880E8F0(buf, s, STR(D_09B05150[R->a[j] + 0x17]));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x1D:
                    if (VISIBLE(line)) {
                        u32 n;
                        char *s;

                        n = R->a[j] + 0x17;
                        if (n > 0x1E) {
                            n++;
                        }
                        func_08890E38(D_08A631A8, 6);
                        s = STR(D_09B05668);
                        func_0880E8F0(buf, s, STR(D_09B05150[n]));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x16:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 6);
                        func_0880E8F0(buf, STR(D_09B05636), R->a[j] * 100);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x1C:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_0880E8F0(buf, STR(D_09B05666), R->a[j]);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0x10:
                    if (VISIBLE(line)) {
                        s16 offs[7] = { 0, 0, -0x44, 0xA, 0x39, 0xA, 0 };
                        s32 l = LANG;

                        func_0882A9DC(D_089CBBEC, widths[l] + 0x8C + offs[l], Y(line), D_0893AE80[R->a[j] + 0xB]);
                        func_08890E38(D_08A631A8, 6);
                        func_0880E8F0(buf, STR(D_09B0565A), R->b[j] * 100);
                        func_08891474(D_08A631A8, widths[l] + 0x30, Y(line), buf);
                    }
                    line++;
                    break;
                case 6:
                    if (VISIBLE(line)) {
                        func_08890E38(D_08A631A8, 0);
                        func_08891474(D_08A631A8, widths[lang] + 0x30, Y(line), STR(D_09B0565C));
                    }
                    line++;
                    break;
                case 8:
                    if (VISIBLE(line)) {
                        u32 n;
                        char *s;

                        func_08890E38(D_08A631A8, 0);
                        n = R->b[j];
                        s = func_0885151C(D_089CC438, D_089AC65C[R->a[j]]);
                        func_0880E8F0(buf, STR(D_09B0565E), s, n / 10, n % 10);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 9:
                    if (VISIBLE(line)) {
                        u32 n;
                        char *s;

                        func_08890E38(D_08A631A8, 0);
                        n = R->b[j];
                        s = func_0885151C(D_089CC438, D_089AC65C[R->a[j]]);
                        func_0880E8F0(buf, STR(D_09B05660), s, n / 10, n % 10);
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xB:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 5);
                        s = STR(D_09B0564C);
                        func_0880E8F0(buf, s, STR(D_09B05650));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xE:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 5);
                        s = STR(D_09B0564C);
                        func_0880E8F0(buf, s, STR(D_09B0564E));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xF:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 5);
                        s = STR(D_09B0564C);
                        func_0880E8F0(buf, s, STR(D_09B05654));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xD:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 5);
                        s = STR(D_09B0564C);
                        func_0880E8F0(buf, s, STR(D_09B05664));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                case 0xC:
                    if (VISIBLE(line)) {
                        char *s;

                        func_08890E38(D_08A631A8, 5);
                        s = STR(D_09B0564C);
                        func_0880E8F0(buf, s, STR(D_09B05652));
                        PUT(line, 0x30);
                    }
                    line++;
                    break;
                }
            }
            break;
        case 5:
            if (VISIBLE(line)) {
                s16 offs2[7] = { 0xE, 0x4C, 0, 0x4C, 0x42, 0x4C, 0xE };

                func_0882A9DC(D_089CBBEC, widths[lang] + 0x24 + offs2[lang], Y(line), D_0893AE80[R->a[0] + 0xB]);
                func_0880E8F0(buf, STR(D_09B0562E), R->b[0]);
                func_08890E38(D_08A631A8, 3);
                PUT(line, 0x24);
            }
            line++;
            break;
        case 6:
            if (VISIBLE(line)) {
                u32 n;
                char *s;

                n = R->b[0];
                if (n > 0x5DC) {
                    s = STR(D_09B05630);
                    func_0880E8F0(buf, s, func_0885151C(D_089CC438, D_089AC8E4));
                } else if (R->a[0] == 5) {
                    s = STR(D_09B05630);
                    func_0880E8F0(buf, s, func_08851540(D_089CC438, n));
                } else {
                    s = STR(D_09B05630);
                    func_0880E8F0(buf, s, func_0885156C(D_089CC438, n));
                }
                func_08890E38(D_08A631A8, 3);
                PUT(line, 0x24);
            }
            line++;
            break;
        case 8:
            if (VISIBLE(line)) {
                char *s = func_0885151C(D_089CC438, D_089AD058[R->unk6]);

                func_0880E8F0(buf, STR(D_09B0563E), s);
                func_08890E38(D_08A631A8, 3);
                PUT(line, 0x24);
            }
            line++;
            break;
        case 2:
        case 3:
            if (VISIBLE(line)) {
                s32 n;
                char *s;

                if (R->type == 2) {
                    n = 0x17;
                } else {
                    n = 0x18;
                }
                s = STR(D_09B05300[R->unk6]);
                func_0880E8F0(buf, STR(D_09B05628[n]), s);
                func_08890E38(D_08A631A8, 3);
                PUT(line, 0x24);
            }
            line++;
            break;
        }
    }
    *(s8 *)(arg0 + 0x24) = line;
    if (TOP != 0) {
        func_0882C7B4(D_089CBBEC, 0x1B8, 0x25, 0x10, 0x10, 0, 0xC0, 0x40, 0xFF, 0x9D, 0);
    }
    if (TOP + 13 < *(s8 *)(arg0 + 0x24)) {
        func_0882C7B4(D_089CBBEC, 0x1B8, 0xF5, 0x10, 0x10, 0, 0xC0, 0x40, 0xFF, 0x9D, 4);
    }
}
