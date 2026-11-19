/* unit_088CB364: 0x088CB364-0x088CB46C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CB364 asm piece, 1 function
 * between unit_088CB32C and unit_088CB46C.
 *
 * C++: virtual call. Sets the state at 0x444 (0, 1 or 2) from a flag, a
 * check and two clock values (alternates every 7200 units after 900).
 * Optimized for speed: `/ 7200` is a multiplication by 0x91A2B3C5
 * (notes/COMPILER.md, "Speed and space").
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0();
    virtual u8 vfunc_A4();

    char pad4[0x440];
    s32 unk444;
} Obj;

#pragma optimize_for_size off

extern "C" {

extern s32 D_08A62C7C;
extern s32 D_09C121B0;
extern s32 func_0886A30C(s32, s32);
extern s32 func_0886A35C(s32, s32);
extern s32 func_09AB3B88(s32, s32, s32, s32);

void func_088CB364(Obj *arg0) {
    s32 t;

    if (arg0->vfunc_A4() == 0) {
        arg0->unk444 = 0;
    } else if (func_0886A30C(D_08A62C7C, 1) == 0) {
        if ((u8) func_09AB3B88(D_09C121B0, 0x36, 1, 1) == 1) {
            arg0->unk444 = 2;
        } else {
            t = func_0886A35C(D_08A62C7C, 1);
            if (t - func_0886A35C(D_08A62C7C, 0) < 900) {
                arg0->unk444 = 0;
            } else if ((func_0886A35C(D_08A62C7C, 0) / 7200) & 1) {
                arg0->unk444 = 0;
            } else {
                arg0->unk444 = 1;
            }
        }
    }
}

}
