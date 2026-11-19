/* unit_088CE75C: 0x088CE75C-0x088CF1B0 (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between unit_088CE754 and unit_088CF1B0.
 * The jump table of func_088CEE68 (0x089323B0-0x089323C8) is linked from
 * this unit.
 *
 * Material colours and visibility of the six model parts of an object (part
 * 0 at +0x50 / +0x80, parts 1-5 at +0x830 / +0x8D0), and its draw function.
 *
 * C++: virtual calls and bool conversions. Optimized for speed: the loops
 * over the material ids are unrolled by 8. The identity matrix is a VFPU
 * `asm` block (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Mat {
    u8 unk0[16];
} Mat;

typedef struct Part {
    s32 unk0;
    s32 unk4;
    Mat *unk8;
} Part;

typedef struct Tbl18 {
    u8 *unk0;
    char pad[0x14];
} Tbl18;

typedef struct Col {
    u8 kind : 4;
    u8 mode : 4;
    u8 r;
    u8 g;
    u8 b;
} Col;

typedef struct VObj { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); } VObj;

typedef struct VFx { virtual void vfunc_08(); virtual void vfunc_0C(char *, char *, float, float, float); } VFx;

extern "C" {

extern char *D_089CC438;
extern s32 *D_089CC000;
extern s32 D_08A62C58;
extern Tbl18 D_089B7B38[];
extern s32 D_089B7E54[];

extern s32 func_08851C3C(char *, s32, s32);
extern s32 func_08856D14(char *, u8);
extern void func_08860B24(s32, char *);
extern void func_08860C54(s32);
extern void func_08860EC0(s32, char *);
extern void func_08861184(s32, s32);
extern s32 func_08862748(s32, s32);
extern u8 *func_08862768(s32, s32, s32);
extern void func_088646F0(Part *, char *, char *, char *);
s32 func_088CF094(char *arg0, u8 *arg1, u8 arg2);
extern void func_088D3B94(char *, char *, char *, s16);
extern void func_088D3DBC(char *, char *, char *, s16, float *);
extern s32 func_088DCB00(void);

void func_088CE75C(char *arg0) {
    Part *part;
    u8 *ids;
    u8 flags;
    s32 n;
    s32 i;
    Mat *m;

    part = (Part *)(arg0 + 0x830);
    ids = func_08862768(part->unk0, 0, 0);
    flags = 0;
    if ((u8) func_08851C3C(D_089CC438, *(u16 *)(arg0 + 0x1E6), 2) == 1) {
        flags = D_089B7B38[*(u8 *)(arg0 + 0x4E0)].unk0[*(s16 *)(arg0 + 0x53A)];
    }
    n = (u8) func_08862748(part->unk0, 0);
    for (i = 0; i < n; i++) {
        m = &part->unk8[ids[i]];
        m->unk0[3] = 0xFF;
    }
    if (flags & 2) {
        m = &part->unk8[ids[0]];
        m->unk0[3] = 0;
    } else if (flags & 4) {
        m = &part->unk8[ids[1]];
        m->unk0[3] = 0;
    } else if (flags & 8) {
        n = (u8) func_08862748(part->unk0, 0);
        for (i = 0; i < n; i++) {
            part->unk8[ids[i]].unk0[3] = 0;
        }
    }
}

void func_088CEAB8(char *arg0) {
    Part *part;
    u8 *ids;
    Mat *m;

    part = (Part *)(arg0 + 0x850);
    ids = func_08862768(part->unk0, 0, 0);
    m = &part->unk8[ids[0]];
    m->unk0[0] = 0.65f * (float) (u32) *(u8 *)(arg0 + 0x4E4);
    m->unk0[1] = 0.65f * (float) (u32) *(u8 *)(arg0 + 0x4E5);
    m->unk0[2] = 0.65f * (float) (u32) *(u8 *)(arg0 + 0x4E6);
    m->unk0[4] = *(u8 *)(arg0 + 0x4E4) >> 1;
    m->unk0[5] = *(u8 *)(arg0 + 0x4E5) >> 1;
    m->unk0[6] = *(u8 *)(arg0 + 0x4E6) >> 1;
}

void func_088CEC84(char *arg0) {
    u8 fog;

    func_08860B24(D_08A62C58, arg0);
    func_08860EC0(D_08A62C58, arg0);
    fog = *(u8 *)(arg0 + 0x230);
    if (fog != 0xFF) {
        *D_089CC000 = 0x21000001;
        D_089CC000++;
        *D_089CC000 = 0xDF000032;
        D_089CC000++;
        *D_089CC000 = 0xDBFF0006;
        D_089CC000++;
        *D_089CC000 = 0x5D000000 | fog;
        D_089CC000++;
    } else {
        *D_089CC000 = 0x21000000;
        D_089CC000++;
        *D_089CC000 = 0xDBFFC007;
        D_089CC000++;
    }
    ((VObj *) arg0)->vfunc_4C();
    if ((bool) (*(s32 *)(arg0 + 0x614) & 0x400) == 1) {
        ((VObj *) arg0)->vfunc_78();
    }
    ((VObj *) arg0)->vfunc_50();
    *D_089CC000 = 0x5D0000FF;
    D_089CC000++;
    *D_089CC000 = 0x21000000;
    D_089CC000++;
    *D_089CC000 = 0xDBFFC007;
    D_089CC000++;
    func_08860C54(D_08A62C58);
    func_08861184(D_08A62C58, 1);
}

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

static inline char *get_anim(char *o, u8 k) {
    if (k == 0) {
        return o + 0x80;
    }
    return o + (k - 1) * 0x140 + 0x8D0;
}

static inline Part *get_part(char *o, u8 k) {
    if (k == 0) {
        return (Part *)(o + 0x50);
    }
    return (Part *)(o + (k - 1) * 0x20 + 0x830);
}

static inline char *get_pos(char *o, u8 k) {
    if (k == 0) {
        return o + 0x70;
    }
    return o + (k - 1) * 0x10 + 0xF10;
}

void func_088CEE68(char *arg0) {
    u8 col[4];
    float mtx[16] __attribute__((aligned(16)));
    char *mdl;
    s32 i;
    char *anim;
    Part *part;
    char *obj;
    u8 *ids;
    Mat *m;
    char *p0;
    char *p1;

    mdl = *(char **)(arg0 + 0x190);
    mtx_identity(mtx);
    i = 0;
    p0 = mdl + 0x2ED0;
    p1 = mdl + 0x2F10;
    for (; i < 6; i++) {
        anim = get_anim(arg0, i);
        part = get_part(arg0, i);
        obj = *(char **)(anim + 0x110);
        switch (i) {
        case 0:
        case 1:
        case 4:
            func_088D3B94(arg0, obj, mdl, i);
            break;
        case 3:
        case 5:
            func_088D3DBC(arg0, obj, mdl, i, mtx);
            break;
        case 2:
            if (*(u32 *)(anim + 0x124) > 4) {
                ((VFx *)(obj + 0x940))->vfunc_0C(p1, p0, 1.0f, 1.0f, 1.0f);
            }
            func_088D3DBC(arg0, obj, mdl, i, mtx);
            break;
        }
        if (i != 1 && (u8) func_088CF094(arg0, col, i) == 1) {
            ids = func_08862768(part->unk0, 0, 0);
            m = &part->unk8[ids[1]];
            m->unk0[0] = m->unk0[4] = col[0];
            m->unk0[1] = m->unk0[5] = col[1];
            m->unk0[2] = m->unk0[6] = col[2];
        }
        func_088646F0(part, anim, get_pos(arg0, i), arg0 + 0x10);
    }
}

s32 func_088CF094(char *arg0, u8 *arg1, u8 arg2) {
    Col *c;

    c = (Col *)(arg0 + (u8) func_08856D14(D_089CC438, arg2) * 4 + 0x10D0);
    switch (((u8 *)(arg0 + 0x10E4))[arg2]) {
    case 0:
        return 0;
    case 1:
        arg1[2] = 0x80;
        arg1[1] = 0x80;
        arg1[0] = 0x80;
        break;
    case 2:
        if (c->kind == 0xB) {
            *(s32 *) arg1 = func_088DCB00();
        } else {
            *(s32 *) arg1 = D_089B7E54[c->kind];
        }
        break;
    case 3:
        if (c->mode == 1) {
            *(s32 *) arg1 = func_088DCB00();
        } else {
            arg1[0] = c->r;
            arg1[1] = c->g;
            arg1[2] = c->b;
        }
        break;
    }
    return 1;
}

}
