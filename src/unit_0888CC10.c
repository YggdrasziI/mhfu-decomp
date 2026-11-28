/* unit_0888CC10: 0x0888CC10-0x0888D004 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888CC10: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    u16 id;
    u16 size;
    u16 flags;
} Entry;

/* 0x30-byte key of the table at +0xE0, ended by a negative frame. */
typedef struct {
    s32 frame;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    Vec unk10;
    Vec unk20;
} Key;

typedef struct {
    u8 pad0[0x1F4];
    s32 unk1F4;
    u8 pad1F8[8];
    Vec unk200;
} Pl;

typedef struct {
    Vec unk0;
    Vec unk10;
    u8 pad20[0x60];
    f32 unk80;
    f32 unk84;
    f32 unk88;
    u8 pad8C[8];
    s16 unk94;
    u8 pad96[0xA];
    Vec unkA0;
    u8 padB0[0x30];
    Key *unkE0;
    u8 padE4[0xC];
    Pl *unkF0;
    u8 padF4[0x48];
    u8 unk13C;
} Obj;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern Entry D_0893843C[];

extern void func_088140C4(char *, Vec *);
extern s32 func_09C3AAA8(char *, Vec *, Vec *, f32, Vec *, u16);
extern float func_09C3DA00(char *, Vec *);

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_add3(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_sub(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(b)
        lv.q C010, 0(a)
        vsub.q C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_scale(Vec *v, f32 t, Vec *dst) {
    f32 *pt = &t;
    asm {
        lv.q C000, 0(v)
        lv.s S010, 0(pt)
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void rot_y(Vec *v, f32 ang) {
    f32 *pa = &ang;
    asm {
        lv.q C000, 0(v)
        lv.q C100, 0(v)
        lv.s S110, 0(pa)
        vcst.s S111, VFPU_2_PI
        vmul.s S122, S110, S111
        vsin.s S120, S122
        vcos.s S121, S122
        vmul.s S000, S121, S100
        vmul.s S130, S120, S102
        vadd.s S000, S000, S130
        vmul.s S002, S120, S100
        vmul.s S130, S121, S102
        vsub.s S002, S130, S002
        sv.q C000, 0(v)
    }
}

u8 func_0888CC10(Obj *arg0) {
    Vec *cam;
    Key *k;
    s32 frame;
    Entry *e;
    char *g;
    Vec tmp50;
    Vec tmp40;
    Vec tmp30;
    Key *prev;
    f32 t;
    f32 a;
    Pl *pl;
    f32 rad28;
    u16 mask;
    f32 h;

    g = D_089CBBE4;
    cam = &arg0->unkA0;
    frame = arg0->unk94 * 2;
    k = arg0->unkE0;
    e = &D_0893843C[arg0->unk13C];
    if (e->flags & 2) {
        func_088140C4(g, &tmp50);
        vec_copy(&tmp50, cam);
    }
    while (k->frame >= 0) {
        if (frame == k->frame) {
            vec_copy(&k->unk10, &arg0->unk0);
            vec_copy(&k->unk20, &arg0->unk10);
            arg0->unk80 = -(6.2831855f * (k->unk8 / 360.0f));
            arg0->unk88 = 6.2831855f * (k->unk4 / 360.0f);
            break;
        }
        if (frame < k->frame) {
            prev = k - 1;
            t = (f32)(frame - prev->frame) / (f32)(k->frame - prev->frame);
            vec_sub(&prev->unk10, &k->unk10, &tmp40);
            vec_scale(&tmp40, t, &tmp40);
            vec_add3(&tmp40, &prev->unk10, &arg0->unk0);
            vec_sub(&prev->unk20, &k->unk20, &tmp40);
            vec_scale(&tmp40, t, &tmp40);
            vec_add3(&tmp40, &prev->unk20, &arg0->unk10);
            a = k->unk8 - prev->unk8;
            a = a * t;
            arg0->unk80 = -(6.2831855f * ((a + prev->unk8) / 360.0f));
            a = k->unk4 - prev->unk4;
            a = a * t;
            arg0->unk88 = 6.2831855f * ((a + prev->unk4) / 360.0f);
            break;
        }
        k++;
    }
    if (e->flags & 1) {
        /* read through cam (+0x50), not arg0->unkF0: the original uses 0x50(s3) */
        pl = *(Pl **)((char *)cam + 0x50);
        if (pl != 0) {
            rot_y(&arg0->unk0, 6.2831855f * ((360.0f * (f32)pl->unk1F4 / 65536.0f) / 360.0f));
            rot_y(&arg0->unk10, 6.2831855f * ((360.0f * (f32)pl->unk1F4 / 65536.0f) / 360.0f));
            vec_add3(&arg0->unk0, &pl->unk200, &arg0->unk0);
            vec_add3(&arg0->unk10, &pl->unk200, &arg0->unk10);
        }
    }
    if (e->flags & 2) {
        rad28 = 28.0f;
        mask = 0x8009;
        if (func_09C3AAA8(D_09D1A060, cam, &arg0->unk0, rad28, &tmp30, mask) != 0) {
            vec_copy(&tmp30, &arg0->unk0);
        }
        if (func_09C3AAA8(D_09D1A060, &arg0->unk10, &arg0->unk0, rad28, &tmp30, mask) != 0) {
            vec_copy(&tmp30, &arg0->unk0);
        }
        tmp30.y = func_09C3DA00(D_09D1A060, &arg0->unk0);
        h = rad28 + tmp30.y;
        if (h > arg0->unk0.y) {
            arg0->unk0.y = h;
        }
    }
    return k->frame < 0;
}
