/* unit_0886005C: 0x0886005C-0x0886025C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef float f32;

static inline void mtx_identity(float *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void rot_x(float *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vidt.q C000
        vrot.q C010, S100, [0,C,S,0]
        vrot.q C020, S100, [0,-S,C,0]
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C130, 0x30(m)
        vmmul.q M200, M000, M100
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

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
        lv.q C130, 0x30(m)
        vmmul.q M200, M000, M100
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
        lv.q C130, 0x30(m)
        vmmul.q M200, M000, M100
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

void func_0886005C(char *arg0, char *arg1) {
    float *m;
    f32 sx, sy, sz;

    *(f32 *)(arg0 + 0x120) = *(f32 *)(arg1 + 0x1C);
    *(f32 *)(arg0 + 0x124) = *(f32 *)(arg1 + 0x20);
    *(f32 *)(arg0 + 0x128) = *(f32 *)(arg1 + 0x24);
    *(f32 *)(arg0 + 0x12C) = *(f32 *)(arg1 + 0x2C);
    *(f32 *)(arg0 + 0x130) = *(f32 *)(arg1 + 0x30);
    *(f32 *)(arg0 + 0x134) = *(f32 *)(arg1 + 0x34);
    *(f32 *)(arg0 + 0x138) = *(f32 *)(arg1 + 0x3C);
    *(f32 *)(arg0 + 0x13C) = *(f32 *)(arg1 + 0x40);
    *(f32 *)(arg0 + 0x140) = *(f32 *)(arg1 + 0x44);
    *(f32 *)(arg0 + 0x190) = *(f32 *)(arg1 + 0x1C);
    *(f32 *)(arg0 + 0x194) = *(f32 *)(arg1 + 0x20);
    *(f32 *)(arg0 + 0x198) = *(f32 *)(arg1 + 0x24);
    *(f32 *)(arg0 + 0x19C) = *(f32 *)(arg1 + 0x2C);
    *(f32 *)(arg0 + 0x1A0) = *(f32 *)(arg1 + 0x30);
    *(f32 *)(arg0 + 0x1A4) = *(f32 *)(arg1 + 0x34);
    *(f32 *)(arg0 + 0x1A8) = *(f32 *)(arg1 + 0x3C);
    *(f32 *)(arg0 + 0x1AC) = *(f32 *)(arg1 + 0x40);
    *(f32 *)(arg0 + 0x1B0) = *(f32 *)(arg1 + 0x44);
    *(s16 *)(arg0 + 0x110) = *(s32 *)(arg1 + 0x0);
    *(s16 *)(arg0 + 0x116) = *(s32 *)(arg1 + 0xC);
    *(s32 *)(arg0 + 0x118) = *(s32 *)(arg1 + 0x4C);
    *(s16 *)(arg0 + 0x114) = *(s32 *)(arg1 + 0x50);
    mtx_identity((float *)(arg0 + 0x90));
    sz = *(f32 *)(arg1 + 0x24);
    sy = *(f32 *)(arg1 + 0x20);
    sx = *(f32 *)(arg1 + 0x1C);
    m = (float *)(arg0 + 0x150);
    mtx_identity(m);
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
    rot_x(m, *(f32 *)(arg1 + 0x2C));
    rot_y(m, *(f32 *)(arg1 + 0x30));
    rot_z(m, *(f32 *)(arg1 + 0x34));
    m[12] = *(f32 *)(arg1 + 0x3C);
    m[13] = *(f32 *)(arg1 + 0x40);
    m[14] = *(f32 *)(arg1 + 0x44);
}
