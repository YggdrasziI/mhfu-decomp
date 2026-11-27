/* unit_088144B4: 0x088144B4-0x088145C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern float *D_08A62C40;
extern void memset(void *, s32, s32);

static inline float cos_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

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

void func_088144B4(s32 arg0, float *m, float fov, float aspect, float a, float b) {
    float ab;
    float bb;
    float c;
    float d;

    memset(m, 0, 0x40);
    ab = a * *D_08A62C40;
    bb = b * b;
    fov *= 0.5f;
    c = cos_vfpu(fov) / sin_vfpu(fov);
    d = bb - ab;
    m[0] = c / aspect;
    m[5] = c;
    m[10] = -(bb + ab) / d;
    *(s32 *)&m[11] = 0xBF800000;
    m[14] = -(2.0f * bb * ab) / d;
}
