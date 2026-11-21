/* unit_088EFC14: 0x088EFC14-0x088EFF1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two units.
 *
 * Builds the two matrices of an object (+0x90 and +0xD0) from its scale
 * (+0x190) and its local matrix (+0x150), turns them for the ids 0x21-0x24
 * and passes them on to the two objects at +0x14C and +0x148.
 *
 * C++: virtual calls. Optimized for speed. The matrix operations are VFPU
 * `asm` blocks (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Sink {
    virtual void vfunc_08();
    virtual void vfunc_0C(Mtx *, Mtx *, float, float, float);
} Sink;

typedef struct Table {
    char pad0[0x5FC];
    /* 0x5FC */ u32 unk5FC[4];
} Table;

typedef struct Obj {
    char pad0[0x90];
    /* 0x090 */ Mtx unk90;
    /* 0x0D0 */ Mtx unkD0;
    char pad110[6];
    /* 0x116 */ u16 unk116;
    char pad118[0x30];
    /* 0x148 */ Sink *unk148;
    /* 0x14C */ Sink *unk14C;
    /* 0x150 */ Mtx unk150;
    /* 0x190 */ float unk190;
    /* 0x194 */ float unk194;
    /* 0x198 */ float unk198;
} Obj;

extern "C" {

extern char *D_09C121B0;

/* The angles are 16-bit turns: degrees first, then radians. */
#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_scale(Mtx *dst, float x, float y, float z) {
    mtx_identity(dst);
    dst->m[0] = x;
    dst->m[5] = y;
    dst->m[10] = z;
}

static inline void mtx_mul(Mtx *dst, Mtx *a, Mtx *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E200, E100
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void rot_y(Mtx *m, float ang) {
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

void func_088EFC14(Obj *self, Mtx *arg1, Mtx *arg2) {
    Table *tbl;

    mtx_scale(&self->unk90, self->unk190, self->unk194, self->unk198);
    mtx_mul(&self->unk90, &self->unk150, &self->unk90);
    mtx_mul(&self->unkD0, arg1, &self->unk90);
    mtx_mul(&self->unk90, arg2, &self->unk90);
    if ((u32) (self->unk116 - 0x21) < 4) {
        tbl = *(Table **)(D_09C121B0 + 0x1220);
        if (tbl != 0) {
            rot_y(&self->unkD0, TO_RAD((float) tbl->unk5FC[0x24 - self->unk116]));
            rot_y(&self->unk90, TO_RAD((float) tbl->unk5FC[0x24 - self->unk116]));
        }
    }
    if (self->unk14C != 0) {
        self->unk14C->vfunc_0C(&self->unkD0, &self->unk90, 1.0f, 1.0f, 1.0f);
    }
    if (self->unk148 != 0) {
        self->unk148->vfunc_0C(arg1, arg2, 1.0f, 1.0f, 1.0f);
    }
}

}
