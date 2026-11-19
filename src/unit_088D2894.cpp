/* unit_088D2894: 0x088D2894-0x088D2BEC (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088D2894 asm piece, 3 functions
 * between unit_088D27F4 and unit_088D2BEC.
 *
 * Extra rotations of five bone matrices (0x250-byte bones of the model at
 * +0x190, matrix at +0x150) from the 16-bit angles at +0x68C and +0x41A, and
 * a bone position moved to world space.
 *
 * Optimized for speed. The rotations are VFPU `asm` blocks
 * (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Bone {
    char pad0[0x150];
    float mtx[16];
    char pad190[0xC0];
} Bone;

extern "C" {

extern void func_088640F8(char *, char *, float, float, float);
extern void func_088652DC(char *);
extern char *func_088D2BEC(char *, s16);

void func_088D28DC(char *arg0);

static inline Bone *get_bone(char *mdl, s32 i) {
    return (Bone *)(mdl + i * 0x250);
}

/* The angles are 16-bit turns: degrees first, then radians. */
#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))

static inline void rot_y(float *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void rot_z(float *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,S,0,0]
        vrot.q C010, S100, [-S,C,0,0]
        vidt.q C020
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

void func_088D2894(char *arg0) {
    func_088652DC(arg0);
    func_088D28DC(arg0);
    func_088640F8(arg0 + 0x80, arg0 + 0x10, 1.0f, 1.0f, 1.0f);
}

void func_088D28DC(char *arg0) {
    u16 v;
    float *m;
    u32 w;

    v = *(u16 *)(arg0 + 0x68C);
    if (v == 0) {
        return;
    }
    m = get_bone(*(char **)(arg0 + 0x190), 9)->mtx;
    rot_y(m, 0.3f * TO_RAD((s16) v));
    w = *(u16 *)(arg0 + 0x41A);
    rot_z(m, TO_RAD(w));
    m = get_bone(*(char **)(arg0 + 0x190), 10)->mtx;
    rot_y(m, 0.3f * TO_RAD(*(s16 *)(arg0 + 0x68C)));
    m = get_bone(*(char **)(arg0 + 0x190), 19)->mtx;
    rot_y(m, 0.3f * TO_RAD(*(s16 *)(arg0 + 0x68C)));
    m = get_bone(*(char **)(arg0 + 0x190), 20)->mtx;
    rot_y(m, 0.1f * TO_RAD(*(s16 *)(arg0 + 0x68C)));
}

static inline void to_world(float *mtx, float *src, float *dst) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        lv.q C230, 0x30(mtx)
        vcst.s S003, 0
        vtfm3.t C000, E200, C100
        vadd.t C000, C000, C230
        sv.q C000, 0(dst)
    }
}

void func_088D2B90(char *arg0, float *arg1, s16 arg2) {
    float *mtx;

    mtx = (float *)(arg0 + 0x10);
    to_world(mtx, (float *)(func_088D2BEC(arg0, arg2) + 0x30), arg1);
}

}
