/* unit_08842F70: 0x08842F70-0x08843A7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: the flag tests keep their `sltu` (bool). Optimized for speed: the
 * entity loops step a byte offset and the float constants are immediates.
 *
 * `arg1 += (u16) off;` twice on u16 parameters: the conversion is emitted
 * for each sum (a local copy of the conversion is computed once and masked).
 * The float parameter precedes arg3 in the list: its position sets the order
 * of the entry moves. func_08844FC8 takes s32 for its two u16 fields: with
 * u16 the last call keeps the pointer in a2 instead of a0.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Ent;

extern "C" {
extern char *D_089CC438;
extern f32 D_08938A7C[];
extern f32 D_0893897C[];
extern f32 D_08938980[];
extern s32 D_0893B5FC[];
extern s32 D_0893B608[];
extern char *D_09C121B0;
extern Ent D_09CDEF40[];
extern char *D_09A4F060;
extern u16 *D_09CE470C[];
extern s32 D_09A4F0C4;

extern void func_088444A4(char *, char *);
extern void func_0884469C(char *);
extern void func_08832B98(char *, s32);
extern s32 func_08844578(char *, char *);
extern void func_0882900C(char *, f32 *, f32 *, f32 *, u16);
extern void func_0884424C(char *, s32, f32, f32, f32);
extern s32 func_08844654(char *, char *);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, s32, s32);
extern void func_0884558C(char *, s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern s32 func_088446CC(char *, u16);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08844744(char *, char *, f32, f32, f32);
extern char *func_088DCEBC(s32, s32);
extern void func_08844FC8(char *, s32, s32, f32, f32, f32);

}

static inline s32 has_flag(char *e) {
    return (bool)(*(s32 *)(e + 0x638) & 4);
}

static inline char *get_ent(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

extern "C" void func_08842F70(char *arg0, u16 arg1, u16 arg2, f32 scale, s32 arg3) {
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    char *ent;
    char *p;
    s32 idx;
    f32 sx;
    f32 sy;
    f32 rate;
    f32 off;
    u16 bx;
    u16 by;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    s16 px;
    s16 py;
    s16 w;
    s16 h;
    u8 side;

    idx = *(u8 *)(D_089CC438 + 0x6AF10);
    rate = D_08938A7C[idx];
    p = *(char **)(arg0 + 0x530);
    func_088444A4(arg0, p);
    func_0884469C(arg0);
    sx = 152.0f * *(f32 *)(arg0 + 0x564) * scale;
    sy = 152.0f * *(f32 *)(arg0 + 0x568) * scale;
    bx = arg1;
    by = arg2;
    off = 152.0f * (0.5f * (1.0f - rate) * scale);
    arg1 += (u16)off;
    arg2 += (u16)off;
    func_08832B98(arg0, 1);
    for (i = 0; i < 20; i++) {
        ent = get_ent(D_09C121B0, i);
        if ((u8)func_08844578(arg0, ent) == 0) {
            continue;
        }
        if (has_flag(ent)) {
            func_0882900C(arg0, &x, &y, &z, *(u16 *)(ent + 0x29A));
            x *= scale;
            y *= scale;
            if (0.0f == z) {
                Ent *e = &D_09CDEF40[*(u16 *)(ent + 0x29A)];
                x = sx * (e->unk0 + 0.5f * e->unk10);
                z = 32.0f;
                y = sy * (e->unk4 + 0.5f * e->unk14);
            }
            x = (f32)arg1 + x * rate;
            y = (f32)arg2 + y * rate;
            func_0884424C(arg0, 0x70C0C010, x, y, rate * (z * scale));
        }
    }
    if ((u8)func_08844654(arg0, p) == 1) {
        if (arg3 == 0) {
            func_08832B98(arg0, 0);
            func_0882C11C(arg0, bx, by, (s32)(152.0f * scale), (s32)(152.0f * scale), 0xFF, 0xFF, 0xFF, 0xC8, D_0893B5FC[*(u8 *)(arg0 + 0x578)]);
            func_08832B98(arg0, 1);
        } else {
            func_0882C11C(arg0, bx, by, (s32)(152.0f * scale), (s32)(152.0f * scale), 0xFF, 0xFF, 0xFF, 0xC8, D_0893B608[*(u8 *)(arg0 + 0x578)]);
        }
    } else {
        x = 150.0f * (*(f32 *)(p + 0x260) * *(f32 *)(arg0 + 0x564));
        y = 150.0f * (*(f32 *)(p + 0x268) * *(f32 *)(arg0 + 0x568));
        x = x + (f32)(u16)off;
        y = y + (f32)(u16)off;
        x0 = x - 20.0f;
        x1 = x + 20.0f;
        if (x0 < 0) {
            x0 = 0;
        }
        if ((f32)x1 > 150.0f) {
            x1 = 150;
        }
        y0 = y - 20.0f;
        y1 = y + 20.0f;
        if (y0 < 0) {
            y0 = 0;
        }
        if ((f32)y1 > 150.0f) {
            y1 = 150;
        }
        px = (f32)bx + (f32)x0 * scale;
        py = (f32)by + (f32)y0 * scale;
        w = scale * (f32)(x1 - x0);
        h = scale * (f32)(y1 - y0);
        if (arg3 == 0) {
            func_08832B98(arg0, 0);
            func_0884558C(arg0, px, py, w, h, x0, y0, x1, y1, 0xC8);
            func_08832B98(arg0, 1);
        } else {
            func_0884558C(arg0, px, py, w, h, x0, y0, x1, y1, 0xC8);
        }
    }
    side = *(u8 *)(arg0 + 0x578);
    if (side == (u8)func_088446CC(arg0, *D_09CE470C[*(s32 *)(D_09A4F060 + 0x284) * 2])) {
        x = sx * D_0893897C[idx * 2];
        y = sy * D_08938980[idx * 2];
        func_0882A9DC(arg0, (f32)arg1 + (x - 6.0f), (f32)arg2 + (y - 6.0f), 0x94);
    }
    for (i = 0; i < 20; i++) {
        ent = get_ent(D_09C121B0, i);
        if ((u8)func_08844578(arg0, ent) == 0) {
            continue;
        }
        y = *(f32 *)(ent + 0x268) * sy;
        if (!(y < 0.0f)) {
            x = *(f32 *)(ent + 0x260) * sx;
            func_08844744(arg0, ent, (f32)arg1 + x, (f32)arg2 + y, scale);
        }
    }
    for (i = 0; i < 4; i++) {
        ent = func_088DCEBC(D_09A4F0C4, i);
        if (ent == 0) {
            continue;
        }
        if ((bool)(*(s32 *)(ent + 4) & 1) != 0 && i != *(u8 *)(D_089CC438 + 0x28)) {
            side = *(u8 *)(arg0 + 0x578);
            if (side == (u8)func_088446CC(arg0, *(u16 *)(ent + 0x29A))) {
                x = *(f32 *)(ent + 0x260) * sx;
                y = *(f32 *)(ent + 0x268) * sy;
                func_08844FC8(arg0, *(u16 *)(ent + 0x1F4), *(u16 *)(ent + 0x1E6), (f32)arg1 + x, (f32)arg2 + y, scale);
            }
        }
    }
    p = *(char **)(arg0 + 0x530);
    x = *(f32 *)(p + 0x260) * sx;
    y = *(f32 *)(p + 0x268) * sy;
    func_08844FC8(arg0, *(u16 *)(p + 0x1F4), *(u16 *)(p + 0x1E6), (f32)arg1 + x, (f32)arg2 + y, scale);
    func_08832B98(arg0, 0);
}
