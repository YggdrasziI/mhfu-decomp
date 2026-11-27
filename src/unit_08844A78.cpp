/* unit_08844A78: 0x08844A78-0x08844EA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual u8 vfunc_44();
} Obj;

extern "C" {

extern char *D_08A631A0;
extern u8 func_09AD8358(Obj *);
extern u8 func_088D6AC8(s32, s32);

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

u32 func_08844A78(char *arg0, Obj *arg1) {
    if (*((u8 *)arg1 + 0x298) == 5 || (u8)arg1->vfunc_44() == 1) {
        u32 phase;
        float ang;
        u32 a;

        phase = (u16)(*(u8 *)(D_08A631A0 + 0xF7A554) << 8);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        a = (u8)((s8)(48.0f * sin_vfpu(ang)) + 0x80);
        return a | ((a << 16) | 0xD0000000 | (a << 8));
    }
    if ((u8)func_09AD8358(arg1) == 1 && func_088D6AC8(*(s32 *)(arg0 + 0x530), 0x5A) != 0) {
        u32 phase;
        float ang;

        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        return ((s8)(48.0f * sin_vfpu(ang)) + 0x70) | 0xFFF0F000;
    }
    if (*(u8 *)(arg0 + 0x5E7) < 2) {
        u32 phase;
        float ang;
        float s;

        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        s = sin_vfpu(ang);
        return ((((s8)(54.0f * s) + 0x53) << 8) | 0xFFFA0000) | ((s8)(6.0f * s) + 0xDD);
    }
    if (*((u8 *)arg1 + 0x4B9) == 1) {
        u32 phase;
        float ang;

        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0xF) << 12);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        return (((s8)(64.0f * sin_vfpu(ang)) + 0x48) << 8) | 0xFFF00000;
    } else {
        u32 phase;
        float ang;

        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        return (((s8)(48.0f * sin_vfpu(ang)) + 0x80) << 8) | 0xFF1000E0;
    }
}

}
