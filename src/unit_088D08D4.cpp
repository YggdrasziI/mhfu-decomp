/* unit_088D08D4: 0x088D08D4-0x088D1398 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between the asm piece text_088CF2C8 and
 * unit_088D1398.
 *
 * Runs the 0x18-byte material animation records of the table at +0x7F4 that
 * belong to one model part: with bit 0x10 of the flags it updates the 8-byte
 * state of each record (at +0x7F8, indexed from the table's byte 2), with
 * bit 0x20 it applies the state (display list words written through
 * D_089CC000, or material colours through func_08862800 / func_088629DC /
 * func_08862BB8).
 *
 * C++: bool conversions. Optimized for speed. The sine is a VFPU `asm` block
 * (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Item {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    s32 unk4[5];
} Item;

typedef struct Hdr {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    char pad4[8];
    Item *unkC;
} Hdr;

typedef union State {
    float f;
    u32 u;
    u8 b;
    char pad[8];
} State;

typedef struct Game {
    char pad0[0x1C];
    u16 unk1C;
} Game;

extern "C" {

extern Game *D_089CC438;
extern u32 *D_089CC000;
extern float D_089AF984[];
extern u8 D_089AF9C8[][2];

extern s32 func_08862800(char *, s32, u8, u8, u8);
extern s32 func_088629DC(char *, s32, u8, u8, u8);
extern s32 func_08862BB8(char *, s32, u32);
extern s32 func_088CF094(char *arg0, u8 *arg1, u8 arg2);
extern s32 func_088D1BA8(char *);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

/* The angles are 16-bit turns: degrees first, then radians. */
#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))

void func_088D08D4(char *arg0, u8 arg1, s32 arg2, u8 arg3) {
    Hdr *hdr;
    char *p;
    Item *item;
    State *state;
    s32 i;
    s32 val;
    u8 flags;
    u8 c;
    float f;
    float t;
    float cur;
    u8 col[3];
    u8 *tbl;
    float prod;
    s32 in;
    u8 k;
    u32 amp;

    hdr = *(Hdr **)(arg0 + 0x7F4);
    item = hdr->unkC;
    state = (State *)(arg0 + hdr->unk2 * 8 + 0x7F8);
    p = arg0 + 0xF60;
    for (i = 0; i < (*(Hdr **)(arg0 + 0x7F4))->unk3; i++, item++, state++) {
        if (item->unk1 != arg2) {
            continue;
        }
        val = item->unk4[arg1];
        switch (item->unk0) {
        case 0x16:
        case 0x17:
            flags = arg3;
            if (flags & 0x10) {
                if (val != 0) {
                    if (!((item->unk2 & 1) & (state->f > 1.0f))) {
                        state->f = (float) (D_089CC438->unk1C % val) / (float) val;
                    }
                } else {
                    state->f = 0.0f;
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 0x16:
                    *D_089CC000 = 0x4A000000 | (state->u >> 8);
                    D_089CC000++;
                    break;
                case 0x17:
                    *D_089CC000 = 0x4B000000 | (state->u >> 8);
                    D_089CC000++;
                    break;
                }
            }
            break;
        case 0x18:
            flags = arg3;
            if (flags & 0x10) {
                if ((item->unk2 & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    t = (float) val / 255.0f;
                    cur = state->f;
                    if (t - 0.05f < cur && cur < 0.05f + t) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f = t - D_089AF984[(item->unk2 & 0xF00) >> 8] * (t - cur);
                    } else {
                        state->f = t;
                    }
                } else {
                    state->f = (float) val / 255.0f;
                }
            }
            if (flags & 0x20) {
                c = (u32) (255.0f * state->f);
                if (item->unk2 & 2) {
                    *D_089CC000 = c | ((c << 16) | 0xE0000000 | (c << 8));
                    D_089CC000++;
                } else {
                    func_08862800(p, item->unk1, c, c, c);
                    func_088629DC(p, item->unk1, c, c, c);
                }
            }
            break;
        case 0x19:
            flags = arg3;
            if (flags & 0x10) {
                if (flags & 1) {
                    f = 0.0f;
                } else if (flags & 2) {
                    f = 1.0f;
                } else {
                    f = 0.5f * (1.0f + sin_vfpu(TO_RAD(D_089CC438->unk1C << 9)));
                }
                state->u = (u32) ((float) (val & 0xFF) + (float) ((val & 0xFF00) >> 8) * f);
            }
            if (arg3 & 0x20) {
                c = state->b;
                if (item->unk2 & 2) {
                    *D_089CC000 = c | ((c << 16) | 0xE0000000 | (c << 8));
                    D_089CC000++;
                } else {
                    func_08862800(p, item->unk1, c, c, c);
                    func_088629DC(p, item->unk1, c, c, c);
                }
            }
            break;
        case 0x1B:
            flags = arg3;
            if (flags & 0x10) {
                if ((item->unk2 & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    t = (float) val / 255.0f;
                    cur = state->f;
                    if (t - 0.05f < cur && cur < 0.05f + t) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f = t - D_089AF984[(item->unk2 & 0xF00) >> 8] * (t - cur);
                    } else {
                        state->f = t;
                    }
                } else {
                    state->f = (float) val / 255.0f;
                }
            }
            if (flags & 0x20) {
                func_08862BB8(p, item->unk1, (u32) (255.0f * state->f));
                *D_089CC000 = 0x21000001;
                D_089CC000++;
                *D_089CC000 = 0xDF000032;
                D_089CC000++;
                *D_089CC000 = 0xDBFF0006;
                D_089CC000++;
            }
            break;
        case 0x1C:
            flags = arg3;
            if (flags & 0x10) {
                if (flags & 1) {
                    f = 0.0f;
                } else if (flags & 2) {
                    f = 1.0f;
                } else {
                    f = 0.5f * (1.0f + sin_vfpu(TO_RAD(D_089CC438->unk1C << 9)));
                }
                state->u = (u32) ((float) (val & 0xFF) + (float) ((val & 0xFF00) >> 8) * f);
            }
            if (arg3 & 0x20) {
                func_08862BB8(p, item->unk1, state->b);
                *D_089CC000 = 0x21000001;
                D_089CC000++;
                *D_089CC000 = 0xDF000032;
                D_089CC000++;
                *D_089CC000 = 0xDBFF0006;
                D_089CC000++;
            }
            break;
        case 0x1D:
            if (arg3 & 0x20) {
                if ((u8) func_088CF094(arg0, col, 3) == 1) {
                    func_08862800(p, item->unk1, col[0], col[1], col[2]);
                    func_088629DC(p, item->unk1, col[0], col[1], col[2]);
                } else {
                    func_08862800(p, item->unk1, 0x80, 0x80, 0x80);
                    func_088629DC(p, item->unk1, 0x80, 0x80, 0x80);
                }
            }
            break;
        case 0x1A:
            if (arg3 & 0x10) {
                k = func_088D1BA8(arg0);
                f = 0.5f * (1.0f + sin_vfpu(TO_RAD(D_089CC438->unk1C << 14)));
                tbl = D_089AF9C8[k];
                amp = tbl[1];
                prod = (float) amp;
                prod = prod * f;
                c = (u32) ((float) (u32) tbl[0] + prod);
                if (state->u > (u32) (c + (u8) amp)) {
                    if (state->u < 0x10) {
                        c = 0;
                    } else {
                        c = state->u - 0x10;
                    }
                }
                state->u = c;
            }
            if (arg3 & 0x20) {
                *D_089CC000 = state->u | ((state->u << 16) | 0xE0000000 | (state->u << 8));
                D_089CC000++;
            }
            break;
        case 0xFFFF:
            break;
        }
    }
}

}
