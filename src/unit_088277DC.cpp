/* unit_088277DC: 0x088277DC-0x08827918 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual calls.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;

struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); 
    u8 pad4[0x2E4 - 4];
    s16 f2E4;
    u8 pad2E6[0x38A - 0x2E6];
    s8 f38A;
    s8 f38B;
    u8 pad38C[0x3D4 - 0x38C];
    u8 f3D4;
    u8 pad3D5[3];
    u8 f3D8;
    u8 pad3D9[0x41E - 0x3D9];
    s16 f41E;
    u8 pad420[0x4E8 - 0x420];
    u8 f4E8[0x62E - 0x4E8];
    s16 f62E;
};

extern "C" {

extern char *D_089CC438;
extern void func_08821BD4(Obj *, u8 *);
extern void func_088D897C(Obj *);
extern s32 func_08828658(s32, Obj *);

void func_088277DC(s32 arg0, Obj *arg1) {
    s16 v;
    s16 r;
    s16 t;

    func_08821BD4(arg1, arg1->f4E8);
    func_088D897C(arg1);
    r = (s16)func_08828658(arg0, arg1);
    v = *(s8 *)(D_089CC438 + 0x6993C) + 100 + r;
    if (v > 0x96) {
        v = 0x96;
    }
    arg1->f2E4 = v;
    arg1->f41E = v;
    t = *(s16 *)(D_089CC438 + 0x69938) + 300;
    arg1->f62E = t;
    if (t < 0x4B) {
        arg1->f62E = 0x4B;
    }
    if (arg1->f62E > 0x1C2) {
        arg1->f62E = 0x1C2;
    }
    arg1->f38A = *(s8 *)(D_089CC438 + 0x6993A);
    arg1->f3D4 = 0;
    arg1->vfunc_5C();
    arg1->f38B = *(s8 *)(D_089CC438 + 0x6993B);
    arg1->f3D8 = 0;
    arg1->vfunc_60();
    arg1->vfunc_64();
}

}
