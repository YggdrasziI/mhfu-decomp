/* unit_08865810: 0x08865810-0x08865934 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Anim {
    char pad0[0x58];
} Anim;

typedef struct Obj {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual s32 vfunc_20(s32);

    char pad4[0x7C];
    Anim unk80;
    char padD8[0xCA];
    u16 unk1A2;
} Obj;

extern "C" {

extern void func_08863DF4(Anim *, s32, u32, s32, float);

void func_08865810(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, float arg4) {
    u32 i;

    if (arg3 == -1) {
        for (i = 0; i < arg0->unk1A2; i++) {
            arg2 = arg0->vfunc_20(arg1 + (s32) (i * 200));
            func_08863DF4(&arg0->unk80, arg2, (u32) arg4, i, 0.0f);
        }
    } else {
        func_08863DF4(&arg0->unk80, arg2, (u32) arg4, arg3, 0.0f);
    }
}

}
