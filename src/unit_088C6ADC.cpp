/* unit_088C6ADC: 0x088C6ADC-0x088C6D2C (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between code already split
 * (unit_088C6AD4 before, unit_088C6D2C after).
 *
 * C++: func_088C6ADC is a virtual call. It ends with a jump through the vtable
 * (`jr $t9`) instead of `jalr`: C++ only makes this tail call with
 * `#pragma exceptions off` (notes/MATCHING.md).
 * func_088C6B84 clears 0x100 bytes unrolled by 8: optimized for speed
 * (`#pragma optimize_for_size off`, notes/COMPILER.md, "Speed and space").
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct VA8_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual s32 vfunc_A8(); } VA8_0;



#pragma exceptions off

/* 0x100 byte flags at 0xA2E8, cleared by func_088C6B84 and tested by func_088C6BCC */
typedef struct Flags {
    char pad0[0xA2E8];
    u8 flags[0x100];
} Flags;

extern "C" {

extern char *D_089CC438;
extern s32 D_09CFB798;
extern s32 D_08A62D8C;
extern s32 func_09C19580(s32, s32);
extern s32 func_08883FF0(s32, s32, s32);
extern void func_08885494(s32, s32, s32, s32, s32);
extern s32 func_08883B54(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08884748(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_088C6ADC(VA8_0 **arg0) {
    return (*arg0)->vfunc_A8();
}

s32 func_088C6AF0(void) {
    return 0;
}

u16 func_088C6AF8(void) {
    u8 *p;
    s32 v;

    p = (u8 *)(D_089CC438 + 0x6A238);
    v = p[1];
    if (p[6] & 1) {
        v = 3;
    }
    if (p[2] < 2) {
        v = (u16) (v + 4);
    }
    if ((u8) func_09C19580(D_09CFB798, 0x5F) == 0) {
        v = (u16) (v + 8);
    }
    return (u16) v + 0x17BB;
}

#pragma optimize_for_size off
void func_088C6B84(Flags *arg0) {
    s32 i;

    for (i = 0; i < 0x100; i++) {
        arg0->flags[i] = 0;
    }
}

#pragma optimize_for_size reset
s32 func_088C6BCC(Flags *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 ret;

    ret = 0;
    if (func_08883FF0(D_08A62D8C, arg6, arg7) == 0) {
        if (arg0->flags[arg5] != 0) {
            arg0->flags[arg5] = 0;
            func_08885494(D_08A62D8C, arg1, arg4, arg5, 0);
        }
    } else {
        if (arg0->flags[arg5] == 0) {
            ret = func_08883B54(D_08A62D8C, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 0, 0, 0);
            arg0->flags[arg5] = 1;
        } else {
            func_08884748(D_08A62D8C, arg1, arg3, arg4, arg5, arg6, arg7, 0, 0);
        }
    }
    return ret;
}

}
