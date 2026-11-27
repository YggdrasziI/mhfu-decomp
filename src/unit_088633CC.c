/* unit_088633CC: 0x088633CC-0x0886364C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
#pragma opt_unroll_loops off
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef float f32;

typedef struct Entry {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
} Entry;

typedef struct Header {
    u32 unk0;
    u32 unk4;
    s32 unk8;
} Header;

extern s32 D_089A5C44[];
extern f32 func_088630D0(void *arg0, f32 arg3, Entry *arg1, void *arg2);

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

void func_088633CC(char *arg0, f32 arg4, f32 *arg1, f32 *arg2, float *arg3, char *arg5) {
    Header *hdr;
    u32 i;
    Entry *e;
    f32 *dst;
    s32 idx;
    s32 j;
    f32 *s;
    f32 *d;
    f32 sx, sy, sz;

    j = 0;
    d = arg2;
    s = arg1;
    for (; j < 9; j += 3) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        s += 3;
        d += 3;
    }
    hdr = *(Header **)(arg0 + 0x64);
    if (hdr != 0) {
        e = (Entry *)(hdr + 1);
        if ((hdr->unk0 & 0x1FF) != 0)
        for (i = 0; i < hdr->unk4; i++) {
            idx = D_089A5C44[e->unk0];
            dst = (f32 *)((char *)arg2 + idx * 4);
            *dst = func_088630D0(arg0, arg4, e, arg5 + idx * 2);
            if (e->unk0 & 0x38) {
                *dst *= 0.0003834952f;
            } else {
                *dst *= 0.0625f;
            }
            hdr = *(Header **)(arg0 + 0x64);
            e = (Entry *)((char *)e + e->unk8);
        }
    }
    sz = arg2[2];
    sy = arg2[1];
    sx = arg2[0];
    mtx_identity(arg3);
    arg3[0] = sx;
    arg3[5] = sy;
    arg3[10] = sz;
    rot_x(arg3, arg2[3]);
    rot_y(arg3, arg2[4]);
    rot_z(arg3, arg2[5]);
    arg3[12] = arg2[6];
    arg3[13] = arg2[7];
    arg3[14] = arg2[8];
}
