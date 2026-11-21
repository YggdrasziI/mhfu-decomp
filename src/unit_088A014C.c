/* unit_088A014C: 0x088A014C-0x088A1500 (ULES01213)
 *
 * Bounds (hypothesis): func_088A014C is a static function defined before its
 * callers (they keep argument registers across the call to it, which the
 * compiler only does for a static callee defined earlier in the same file),
 * so the unit holds func_088A014C and every caller of it; all of them are in
 * this range.
 *
 * Functions optimized for speed are preceded by `#pragma optimize_for_size
 * off`; `#pragma optimize_for_size reset` restores the default after them.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

/* Parameter block of func_088A0360 (flags word, then values). */
typedef struct {
    u16 flags;
    u8 b2;
    u8 b3;
    u8 pad4[4];
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u8 pad10;
    u8 b11;
    u8 pad12;
    u8 b13;
} Params;

/* Parameter block of func_088A061C. */
typedef struct {
    u16 flags;
    u8 b2;
    u8 b3;
    u8 b4;
} Args;

/* Entry of the list walked with func_0889F4BC / func_0889F4F0. */
typedef struct {
    s32 type;
    u32 b4;
    u8 pad08[0x0C];
    u8 b14[7];
    u8 b1b;
} Entry;

/* Entry of the 16-entry table D_09A0D140 (and the spare D_09A0D240). */
typedef struct {
    s16 a, b, c, d;
    s32 e;
    s16 f;
} Rect;

/* Message with an entry index at offset 8. */
typedef struct {
    char pad[8];
    u8 unk8;
    u8 unk9;
    char padA[2];
    s32 unkC;
    u8 unk10;
} Msg;

/* Block passed to func_088A1500 by func_088A1200. */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Cmd;

extern s32 D_09A0D138;
extern s32 D_09A0D13C;
extern Rect D_09A0D140[16];
extern Rect D_09A0D240;
extern char D_089B2170;
extern char D_089B2374[];
extern char D_089B237C[];
extern char D_089B239C[];
extern char D_089B23CC[];

extern void func_0889F07C(void);
extern void func_0889F288(void);
extern char *func_0889F4BC(void);
extern char *func_0889F4F0(void);
extern char *func_0889F544(void);
extern void func_0889F6A0(void);
extern void func_0889FD08(char *);
extern int func_0880D9EC(char *, ...);
extern void func_088A00B0(char *);
extern void func_088A00D0(void);
extern void func_088A1500(void *);
extern void func_088A4280(char *);

void func_088A0938(Rect *o);
void func_088A09E4(char *o);
s16 func_088A0AFC(s32 arg0);
s32 func_088A1200(void);
s32 func_088A1268(char *arg0);
s32 func_088A13A4(char *arg0);
s32 func_088A13AC(u16 *p);
s32 func_088A140C(u16 *p);
void func_088A146C(u16 *p);
void func_088A14B8(u16 *p, Args *x);

/* Converts a 16-bit flag word into another bit layout. */
static s32 func_088A014C(u16 *arg0) {
    u16 flags = *arg0;
    s32 ret = 0;

    if (flags & 1) {
        ret |= 1;
    }
    if (flags & 2) {
        ret |= 2;
    } else if (flags & 8) {
        ret |= 4;
    } else if (flags & 4) {
        ret |= 0x80;
    }
    if (flags & 0x10) {
        ret |= 8;
    }
    if (flags & 0x20) {
        ret |= 0x10;
    }
    if (flags & 0x40) {
        ret |= 0x20;
    }
    if (flags & 0x80) {
        ret |= 0x40;
    }
    return ret;
}

#pragma optimize_for_size off

/* Compares the fields of a against b selected by the bits of m. */
s32 func_088A01D8(u8 *a, u8 *b, s32 m) {
    s32 mask = m;
    s32 bit;

    for (bit = 1; mask != 0; bit <<= 1) {
        switch (mask & bit) {
        case 0:
        case 1:
            break;
        case 2:
            if (!(a[8] & 0x80)) {
                return 0;
            }
            break;
        case 4:
            if (a[8] & 0x80) {
                return 0;
            }
        case 0x80:
            if ((a[8] & 0xF) != (b[4] & 0xF)) {
                return 0;
            }
            break;
        case 8:
            if (a[9] != b[5]) {
                return 0;
            }
            break;
        case 0x10:
            if (a[10] != b[6]) {
                return 0;
            }
            break;
        case 0x20:
            if (a[11] != b[7]) {
                return 0;
            }
            break;
        case 0x40:
            if (*(s32 *)a != *(s32 *)(b + 0x18)) {
                return 0;
            }
            break;
        default:
            func_0880D9EC(D_089B2374);
            func_0880D9EC(D_089B237C);
            func_0880D9EC(D_089B239C);
            break;
        }
        mask &= ~bit;
    }
    return 1;
}

/* Applies a command (arg2) to every matching list entry. */
s32 func_088A0360(Params *arg0, s32 arg1, s32 arg2) {
    char *p;
    char *q;
    s32 ret;
    s32 v;

    ret = 1;
    for (p = func_0889F4BC(); p != 0; p = func_0889F4F0()) {
        if (*(s32 *)p == 0) {
            continue;
        }
        q = p + 0x14;
        if (func_088A01D8((u8 *)q, (u8 *)arg0, arg1) == 0) {
            continue;
        }
        if (*(u8 *)(q + 7) <= arg0->b3) switch (arg2) {
        case 0x10000002:
            func_088A00B0(p);
            *(s32 *)p = 7;
            break;
        case 0x10000001:
            if (*(s32 *)p == 1) {
                func_088A00B0(p);
                *(s32 *)p = 7;
            } else {
                *(s32 *)p = 3;
            }
            break;
        case 0x10000003:
            if (arg0->flags & 0x100) {
                v = arg0->h8;
                if (v >= 0 && v < 0x80) {
                    *(s16 *)(p + 0x24) = v > 0 ? v * 0xFFF / 127 : 0;
                }
            }
            if (arg0->flags & 0x200) {
                v = arg0->hA;
                if (v >= 0 && v < 0x80) {
                    *(u8 *)(p + 0x21) = v;
                    *(u8 *)(p + 0x18) = (*(u8 *)(p + 0x18) & ~0xC0) | (arg0->b2 & 0xC0);
                }
            }
            if (arg0->flags & 0x400) {
                *(s16 *)(p + 0x28) = arg0->hC;
            }
            if (arg0->flags & 0x800) {
                if (arg0->hE > 0x1FFF) {
                    arg0->hE = 0x1FFF;
                } else if (arg0->hE < -0x2000) {
                    arg0->hE = -0x2000;
                }
                v = arg0->hE;
                if (v >= 0) {
                    *(s16 *)(p + 0x2C) = *(u16 *)(p + 0x2E) * v / 0x1FFF;
                } else {
                    *(s16 *)(p + 0x2C) = *(u16 *)(p + 0x30) * v / 0x2000;
                }
            }
            if (arg0->flags & 0x4000) {
                *(u8 *)(p + 0x1B) = arg0->b3;
            }
            if (arg0->flags & 0x1000) {
                *(u8 *)(p + 0x2A) = arg0->b13;
            }
            if (arg0->flags & 0x2000) {
                *(s16 *)(p + 0x32) = arg0->b11;
            }
            break;
        } else {
            ret = 0;
        }
    }
    return ret;
}

/* Updates the bytes 0x1B, 0x1E, 0x1F of every matching list entry. */
s32 func_088A061C(u16 *a, s32 b, Args *args) {
    char *p;
    s32 v;

    for (p = func_0889F4BC(); p != 0; p = func_0889F4F0()) {
        if (*(s32 *)p != 0 && func_088A01D8((u8 *)(p + 0x14), (u8 *)a, b) != 0) {
            if (args->flags & 0x100) {
                p[0x1B] = args->b2;
            } else if (args->flags & 0x200) {
                v = (u8)p[0x1B] + args->b2;
                if (v > 0x7F) {
                    p[0x1B] = 0x7F;
                } else if (v < 0) {
                    p[0x1B] = 0;
                } else {
                    p[0x1B] = v;
                }
            }
            if (args->flags & 0x400) {
                p[0x1E] = args->b3;
            }
            if (args->flags & 0x800) {
                p[0x1F] = args->b4;
            }
        }
    }
    return 0;
}

/* Returns the matching entry of type 1 or 2 with the lowest b1b (then the
 * highest b4). */
Entry *func_088A072C(u16 *a0) {
    Entry *e;
    Entry *best;
    s32 key;

    best = 0;
    key = func_088A014C(a0);
    for (e = (Entry *)func_0889F4BC(); e != 0; e = (Entry *)func_0889F4F0()) {
        if (e->type != 1 && e->type != 2) {
            continue;
        }
        if (func_088A01D8(e->b14, (u8 *)a0, key)) {
            if (best == 0) {
                best = e;
            } else if (e->b1b > best->b1b) {
            } else if (e->b1b < best->b1b) {
                best = e;
            } else if (e->b1b == best->b1b) {
                if (e->b4 > best->b4) {
                    best = e;
                }
            }
        }
    }
    return best;
}

/* Counts the matching entries (a1 == 1: only those of type 1 or 2). */
s32 func_088A0820(u16 *a0, s32 a1) {
    s32 key;
    s32 count;
    char *p;

    key = func_088A014C(a0);
    count = 0;
    for (p = func_0889F4BC(); p != 0; p = func_0889F4F0()) {
        if (func_088A01D8((u8 *)(p + 0x14), (u8 *)a0, key) == 1) {
            if (a1 == 0) {
                count++;
            } else if (a1 == 1) {
                if ((unsigned)(*(s32 *)p - 1) < 2) {
                    count++;
                }
            }
        }
    }
    return count;
}

#pragma optimize_for_size reset

/* Resets the spare entry and the 16 table entries. */
void func_088A08E4(void) {
    int i;
    Rect *p;

    func_088A0938(&D_09A0D240);
    for (i = 0, p = D_09A0D140; i < 16; i++) {
        func_088A0938(p);
        p++;
    }
}

void func_088A0938(Rect *o) {
    o->a = 0xFFF;
    o->b = 0xFFF;
    o->d = 0xFFF;
    o->c = 0;
    o->e = 0;
    o->f = 0;
}

#pragma optimize_for_size off

/* Steps the spare entry and the 16 table entries, scaled by the spare one. */
void func_088A0958(void) {
    s32 i;
    Rect *r;

    func_088A09E4((char *)&D_09A0D240);

    for (i = 0, r = D_09A0D140; i < 16; i++) {
        func_088A09E4((char *)r);
        r->a = D_09A0D240.a * r->a / 4095;
        r++;
    }
}

/* Offset 4 is a 16.16 value whose integer half is the s16 at offset 6. */
void func_088A09E4(char *o) {
    if (*(s32 *)(o + 8) != 0) {
        *(s32 *)(o + 4) += *(s32 *)(o + 8);
        if (*(s32 *)(o + 8) < 0) {
            if (*(s16 *)(o + 6) <= *(s16 *)(o + 0xC)) {
                *(s16 *)(o + 6) = *(s16 *)(o + 0xC);
                *(s16 *)(o + 4) = 0;
                *(s32 *)(o + 8) = 0;
            }
        } else {
            if (*(s16 *)(o + 6) >= *(s16 *)(o + 0xC)) {
                *(s16 *)(o + 6) = *(s16 *)(o + 0xC);
                *(s16 *)(o + 4) = 0;
                *(s32 *)(o + 8) = 0;
            }
        }
    }
    *(s16 *)(o + 0) = (*(s16 *)(o + 2) * *(s16 *)(o + 6)) / 4095;
}

#pragma optimize_for_size reset

void func_088A0A80(char *arg0, s16 arg1, s16 arg2) {
    *(s32 *)arg0 = 0;
    *(s16 *)(arg0 + 4) = arg1;
    *(s16 *)(arg0 + 6) = arg2;
}

void func_088A0A90(char *arg0) {
    func_088A0A80(arg0, 0, 0);
}

void func_088A0A9C(char *arg0) {
    *(s32 *)arg0 = (s32) (*(s32 *)arg0 + *(u16 *)(arg0 + 4));
}

s32 func_088A0AB0(char *arg0) {
    s32 temp_lo;
    s32 var_v0;

    temp_lo = *(u16 *)(arg0 + 6) * func_088A0AFC((u32) *(u32 *)arg0 >> 8);
    var_v0 = temp_lo >> 0xF;
    if (temp_lo < 0) {
        var_v0 = (s32) (temp_lo + 0x7FFF) >> 0xF;
    }
    return var_v0;
}

s16 func_088A0AFC(s32 arg0) {
    s32 temp_v1;

    temp_v1 = arg0 % 1024;
    if (temp_v1 < 0x100) {
        return ((s16 *)&D_089B2170)[(temp_v1 % 256)];
    }
    if (temp_v1 < 0x200) {
        return ((s16 *)&D_089B2170)[(0x200 - temp_v1)];
    }
    if (temp_v1 < 0x300) {
        return (s16) -((s16 *)&D_089B2170)[(temp_v1 % 256)];
    }
    if (temp_v1 < 0x400) {
        return (s16) -((s16 *)&D_089B2170)[(0x400 - temp_v1)];
    }
    return 0;
}

/* Three forwarders and a flag setter. Parameters of the forwarders other
 * than the first are not known. */
void func_088A0BE4(char *p) { func_088A0AFC((s32)(p + 0x100)); }
void func_088A0BEC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) { func_088A1200(); }
void func_088A0BF4(void) { func_088A1200(); }
void func_088A0BFC(Msg *m) { D_09A0D13C = m->unk8 & 1; }

#pragma optimize_for_size off

/* Scales a byte (0..127) to 0..4095 into a table entry. */
void func_088A0C10(Msg *m) {
    Rect *s;
    s32 v;

    if (m->unk8 == 0xFF) {
        s = &D_09A0D240;
    } else {
        s = &D_09A0D140[m->unk8];
    }
    v = m->unk9;
    if (v > 0) {
        v = v * 4095 / 127;
    } else {
        v = 0;
    }
    s->b = v;
}

#define LEVEL(m) ((m)->unk10 > 0 ? (m)->unk10 * 4095 / 127 : 0)

/* Sets the signed value and the scaled level of one table entry. */
void func_088A0C74(Msg *m) {
    Rect *r;
    int d;

    if (m->unk8 == 0xFF) {
        r = &D_09A0D240;
    } else {
        r = &D_09A0D140[m->unk8];
    }
    d = r->d;
    if (LEVEL(m) < d) {
        r->e = -m->unkC;
        r->f = LEVEL(m);
    } else {
        r->e = m->unkC;
        r->f = LEVEL(m);
    }
}

#pragma optimize_for_size reset

/* Resets one table entry (or the spare entry for index 0xFF). */
void func_088A0D70(Msg *m) {
    Rect *r;

    if (m->unk8 == 0xFF) {
        r = &D_09A0D240;
    } else {
        r = &D_09A0D140[m->unk8];
    }
    r->d = 0xFFF;
    r->c = 0;
    r->e = 0;
    r->f = 0;
}

void func_088A0DB0(char *arg0) {
    func_088A1500(arg0 + 0x8);
}

#pragma optimize_for_size off

/* Starts a new list entry from the parameters at a. */
void func_088A0DB8(char *a) {
    char *o;
    s32 v;

    for (o = func_0889F4BC(); o != 0; o = func_0889F4F0()) {
        v = D_09A0D138 + *(s32 *)(a + 0x34);
        if (v == *(s32 *)(*(char **)(o + 0x10) + 0x24) && *(u8 *)(o + 0xC) > 0) {
            return;
        }
    }
    if (func_088A1268(a + 8) == 0) {
        return;
    }
    func_088A13A4(a + 8);
    o = func_0889F544();
    if (o == 0) {
        func_0880D9EC(D_089B2374);
        func_0880D9EC(D_089B237C);
        func_0880D9EC(D_089B23CC);
        return;
    }
    *(s32 *)(o + 0x8) = *(s32 *)(a + 0x1C);
    *(s32 *)(o + 0x4) = 0;
    *(u8 *)(o + 0xC) = *(u8 *)(a + 0x3C);
    *(s32 *)(o + 0x14) = *(s32 *)(a + 0x4);
    *(u8 *)(o + 0x18) = *(u8 *)(a + 0xA);
    *(u8 *)(o + 0x19) = *(u8 *)(a + 0xA);
    *(u8 *)(o + 0x1A) = 1;
    *(u8 *)(o + 0x1B) = *(u8 *)(a + 0xB);
    *(u8 *)(o + 0x1C) = *(u8 *)(a + 0xC) | ((*(u16 *)(a + 0x8) & 2) ? 0x80 : 0);
    *(u8 *)(o + 0x1D) = *(u8 *)(a + 0xD);
    *(u8 *)(o + 0x1E) = (*(u16 *)(a + 0x8) & 0x20) ? *(u8 *)(a + 0xE) : 0xFF;
    *(u8 *)(o + 0x1F) = (*(u16 *)(a + 0x8) & 0x40) ? *(u8 *)(a + 0xF) : 0xFF;
    *(s32 *)(o + 0x34) = *(s32 *)(a + 0x30);
    *(u8 *)(o + 0x20) = *(u8 *)(a + 0x25);
    *(u8 *)(o + 0x21) = *(s16 *)(a + 0x12);
    *(s16 *)(o + 0x22) = (*(u8 *)(a + 0x24) > 0) ? (*(u8 *)(a + 0x24) * 4095) / 127 : 0;
    *(s16 *)(o + 0x24) = (*(s16 *)(a + 0x10) > 0) ? (*(s16 *)(a + 0x10) * 4095) / 127 : 0;
    *(s16 *)(o + 0x26) = *(s16 *)(a + 0x26);
    *(s16 *)(o + 0x28) = *(s16 *)(a + 0x14);
    *(u8 *)(o + 0x2A) = *(u8 *)(a + 0x1B);
    *(u16 *)(o + 0x30) = *(u16 *)(a + 0x28);
    *(u16 *)(o + 0x2E) = *(u16 *)(a + 0x2A);
    *(s16 *)(o + 0x2C) = 0;
    v = *(s16 *)(a + 0x16);
    if (v > 0x1FFF) {
        *(s16 *)(a + 0x16) = 0x1FFF;
    } else if (v < -0x2000) {
        *(s16 *)(a + 0x16) = -0x2000;
    }
    v = *(s16 *)(a + 0x16);
    if (v >= 0) {
        *(s16 *)(o + 0x2C) = (*(u16 *)(o + 0x2E) * v) / 8191;
    } else {
        *(s16 *)(o + 0x2C) = (*(u16 *)(o + 0x30) * v) / 8192;
    }
    func_088A0A90(o + 0x38);
    func_088A0A90(o + 0x40);
    *(s32 *)(*(char **)(o + 0x10) + 0x28) = *(s32 *)(a + 0x38);
    *(u16 *)(*(char **)(o + 0x10) + 0x16) = *(u16 *)(a + 0x2C);
    *(u16 *)(*(char **)(o + 0x10) + 0x18) = *(u16 *)(a + 0x2E);
    *(s32 *)(*(char **)(o + 0x10) + 0x24) = D_09A0D138 + *(s32 *)(a + 0x34);
    *(s32 *)(*(char **)(o + 0x10) + 0xC) |= 0x900;
    if (*(u8 *)(o + 0x18) & 0xC) {
        *(s16 *)(o + 0x32) = *(u8 *)(a + 0x19) << 4;
    } else {
        *(s16 *)(o + 0x32) = 0;
    }
    func_0889FD08(o);
    func_088A4280(*(char **)(o + 0x10));
    *(s32 *)(o + 0x0) = 1;
}

#pragma optimize_for_size reset

void func_088A10E0(char *arg0) {
    func_088A13AC((u16 *)(arg0 + 0x8));
}

void func_088A10E8(char *arg0) {
    func_088A140C((u16 *)(arg0 + 0x8));
}

void func_088A10F0(char *arg0) {
    func_088A146C((u16 *)(arg0 + 0x8));
}

#pragma optimize_for_size off

/* Copies the values at arg0 + 0x24 into every matching list entry. */
void func_088A10F8(char *arg0) {
    char *key;
    char *p;
    s32 flags;

    key = arg0 + 0x8;
    flags = func_088A014C((u16 *)key);
    if (!(*(u16 *)key & 1)) {
        key[3] = 0x7F;
        flags |= 1;
    }
    for (p = func_0889F4BC(); p != 0; p = func_0889F4F0()) {
        s32 kind = *(s32 *)p;
        if (kind == 0 || kind == 7) {
            continue;
        }
        if (func_088A01D8((u8 *)(p + 0x14), (u8 *)key, flags) == 0) {
            continue;
        }
        if (*(u8 *)(p + 0x1B) > *(u8 *)(key + 3)) {
            continue;
        }
        *(s32 *)(p + 0x38) = 0;
        *(u16 *)(p + 0x3C) = *(u16 *)(arg0 + 0x24);
        *(u16 *)(p + 0x3E) = *(u16 *)(arg0 + 0x26);
        *(s32 *)(p + 0x40) = 0;
        *(u16 *)(p + 0x44) = *(u16 *)(arg0 + 0x28);
        *(u16 *)(p + 0x46) = *(u16 *)(arg0 + 0x2A);
    }
}

#pragma optimize_for_size reset

void func_088A11F0(char *arg0) {
    func_088A14B8((u16 *)(arg0 + 0x8), (Args *)(arg0 + 0x24));
}

/* Resets the state and sends a default command block to func_088A1500. */
s32 func_088A1200(void) {
    Cmd m;

    func_0889F6A0();
    func_0889F288();
    func_0889F07C();
    func_088A08E4();
    D_09A0D13C = 0;
    m.unk0 = -1;
    m.unk4 = 0;
    m.unk8 = 0;
    m.unkC = 0;
    m.unk10 = 1;
    m.unk14 = 0;
    func_088A1500(&m);
    return 0;
}

#pragma optimize_for_size off

/* Optimized for speed (the loop is guarded and tested at the bottom). The
 * body is an inline helper whose returns become jumps to the final call:
 * this keeps the instructions left dead after each `b` (the blocks whose
 * first instruction was copied into a branch-likely delay slot). */
static inline s32 body(char *arg0) {
    s32 ret;
    char *p;
    u32 i;
    u32 count;
    u32 n;
    u32 v;

    ret = 1;
    v = func_088A0820((u16 *)arg0, ret);
    n = *(u8 *)(arg0 + 0x10);
    if (n == 0) {
        if (*(u16 *)arg0 & 1) {
            return func_088A0360((Params *)arg0, func_088A014C((u16 *)arg0), 0x10000001);
        }
        return 1;
    }
    if (v < n) {
        return 1;
    }
    count = v + 1 - n;
    for (i = 0; i < count; i++) {
        p = (char *)func_088A072C((u16 *)arg0);
        if (p != 0) {
            if (*(u16 *)arg0 & 1) {
                if (*(u8 *)(arg0 + 3) < *(u8 *)(p + 0x1B)) {
                    return 0;
                }
            }
            if (*(s32 *)p == 1) {
                func_088A00B0(p);
                *(s32 *)p = 7;
            } else {
                ret = 1;
                *(s32 *)p = 4;
            }
        }
    }
    return ret;
}

s32 func_088A1268(char *arg0) {
    s32 ret;

    ret = body(arg0);
    func_088A00D0();
    return ret;
}

#pragma optimize_for_size reset

s32 func_088A13A4(char *arg0) {
    return 0;
}

s32 func_088A13AC(u16 *p) {
    s32 flags;
    s32 ret;
    flags = func_088A014C(p);
    if (!(*p & 1)) {
        ((u8 *)p)[3] = 0x7F;
        flags |= 1;
    }
    ret = func_088A0360((Params *)p, flags, 0x10000001);
    func_088A00D0();
    return ret;
}

s32 func_088A140C(u16 *p) {
    s32 flags;
    s32 ret;
    flags = func_088A014C(p);
    if (!(*p & 1)) {
        ((u8 *)p)[3] = 0x7F;
        flags |= 1;
    }
    ret = func_088A0360((Params *)p, flags, 0x10000002);
    func_088A00D0();
    return ret;
}

void func_088A146C(u16 *p) {
    s32 flags = func_088A014C(p);
    if (!(*p & 1)) {
        ((u8 *)p)[3] = 0x7F;
        flags |= 1;
    }
    func_088A0360((Params *)p, flags, 0x10000003);
}

void func_088A14B8(u16 *p, Args *x) {
    s32 flags = func_088A014C(p);
    if (!(*p & 1)) {
        ((u8 *)p)[3] = 0x7F;
        flags |= 1;
    }
    func_088A061C(p, flags, x);
}
