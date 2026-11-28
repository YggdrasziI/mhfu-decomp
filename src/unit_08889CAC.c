/* unit_08889CAC: 0x08889CAC-0x0888A164 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08889CAC: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;
extern char *D_089CBBEC;
extern f32 D_08933C20;
extern f32 D_08933C24;
extern f32 D_08933C28;

extern s32 func_0888D888(void);
extern s32 func_09A8B888(char *);
extern s32 func_088D27CC(char *);
extern s32 func_08830F74(char *);
extern s32 func_09A8B8F8(char *);
extern s32 func_09A8B998(char *);
extern s32 func_08865F68(char *arg0, s32 arg1);
extern void func_0888D958(char *, char *, s32, s32, char *);
extern void func_08897BD8(char *, f32 *, Vec *);

static inline void copy_q(char *src, char *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void copy_m(char *src, char *dst) {
    asm {
        lv.q C000, 0(src)
        lv.q C010, 0x10(src)
        lv.q C020, 0x20(src)
        lv.q C030, 0x30(src)
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mul_m(char *b, char *a, char *dst) {
    asm {
        lv.q C100, 0(b)
        lv.q C110, 0x10(b)
        lv.q C120, 0x20(b)
        lv.q C130, 0x30(b)
        lv.q C200, 0(a)
        lv.q C210, 0x10(a)
        lv.q C220, 0x20(a)
        lv.q C230, 0x30(a)
        vmmul.q E000, E200, E100
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void xform3(char *mtx, char *src, Vec *dst) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0(dst)
    }
}

void func_08889CAC(char *arg0) {
    Vec t;
    Vec pos;
    char *g;
    char *s;
    char *p;
    char *r;
    f32 *v;
    u16 k;

    g = D_089CBBE4;
    p = *(char **)(g + 0xA84);
    s = arg0 + 0xA0;
    arg0[0x91] = 0;
    if ((s32)((*(u32 *)(p + 0x614) & 0x1000) != 0) == 0) {
        *(s32 *)(arg0 + 0x98) = 0;
        return;
    }
    s[0x68] = func_0888D888();
    switch (*(u8 *)(arg0 + 0x98)) {
    case 0:
        s[0x6A] = 0;
        switch (*(s8 *)(s + 0x68)) {
        case 0:
            if ((u8)func_09A8B888(p) == 1) {
                return;
            }
            s[0x69] = 1;
            if ((u8)func_088D27CC(p) == 1) {
                s[0x6A] = 1;
                *(f32 *)(s + 0x50) = 0.34906587f;
                *(f32 *)(s + 0x54) = 0.959931076f;
                *(f32 *)(s + 0x58) = 1.63702226f;
            }
            break;
        case 1:
            s[0x69] = 0;
            s[0x6A] = 1;
            *(f32 *)(s + 0x50) = 0.52359879f;
            *(f32 *)(s + 0x54) = 0.959931076f;
            *(f32 *)(s + 0x58) = 2.29183125f;
            break;
        case 2:
        case 3:
            s[0x69] = 0x11;
            *(f32 *)(arg0 + 0x88) = 0.785398185f;
            break;
        }
        (*(u8 *)(arg0 + 0x98))++;
        break;
    case 1:
        break;
    default:
        goto tail;
    }
    if (*(u8 *)(s + 0x6A) != 0) {
        if ((u8)func_08830F74(D_089CBBEC) == 0) {
            k = *(u16 *)(g + 0xA70);
            if ((k & 0x20) || (k & 0x80)) {
                v = (f32 *)(*(s8 *)(s + 0x68) == 0 ? s + 0x5C : s + 0x60);
                if (k & 0x80) {
                    *v -= 0.0223402139f;
                    if (*v < *(f32 *)(s + 0x50)) {
                        *v = *(f32 *)(s + 0x50);
                    }
                }
                if (*(u16 *)(g + 0xA70) & 0x20) {
                    *v += 0.0223402139f;
                    if (*v > *(f32 *)(s + 0x54)) {
                        *v = *(f32 *)(s + 0x54);
                    }
                }
            }
        }
    }
    switch (*(s8 *)(s + 0x68)) {
    case 0:
        if ((u8)func_09A8B8F8(p) == 0) {
            copy_q(p + 0x200, s + 0x40);
            copy_m((char *)func_08865F68(p, 0xE), s);
            *(f32 *)(s + 0x34) += 20.0f;
        } else {
            copy_q(p + 0x200, s + 0x40);
            r = (char *)func_09A8B998(p);
            mul_m((char *)func_08865F68(p, 0), r, s);
            *(f32 *)(s + 0x34) += 20.0f;
        }
        *(f32 *)(arg0 + 0x88) = *(f32 *)(s + 0x5C);
        break;
    case 1:
        func_0888D958(arg0, s, *(s16 *)(p + 0x680), (s16)(*(s32 *)(p + 0x1F4) + 0x8000), p + 0x200);
        *(f32 *)(arg0 + 0x88) = *(f32 *)(s + 0x60);
        break;
    case 2:
    case 3:
        func_0888D958(arg0, s, *(s16 *)(p + 0x680), (s16)(*(s32 *)(p + 0x1F4) + 0x8000), p + 0x200);
        break;
    }
tail:
    pos.x = *(f32 *)(s + 0x30);
    pos.y = *(f32 *)(s + 0x34);
    pos.z = *(f32 *)(s + 0x38);
    t.x = *(f32 *)((char *)&D_08933C20 + *(s8 *)(s + 0x68) * 32);
    t.y = 0.0f;
    t.z = *(f32 *)((char *)&D_08933C28 + *(s8 *)(s + 0x68) * 32);
    xform3(s, (char *)&t, &t);
    func_08897BD8(arg0, &pos.x, &t);
    *(f32 *)(arg0 + 4) += *(f32 *)((char *)&D_08933C24 + *(s8 *)(s + 0x68) * 32);
    xform3(s, (char *)&D_08933C20 + *(s8 *)(s + 0x68) * 32 + 0x10, &t);
    func_08897BD8(arg0 + 0x10, &pos.x, &t);
    *(f32 *)(arg0 + 0x14) += *(f32 *)((char *)&D_08933C24 + *(s8 *)(s + 0x68) * 32);
    arg0[0x91] = 1;
}
