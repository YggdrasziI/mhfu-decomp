/* unit_088DCDEC: 0x088DCDEC-0x088DCEEC (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088DCD94 and unit_088DCEEC.
 *
 * func_088DCEBC returns the object of slot `arg1` (0-5) or 0.
 * func_088DCDEC clears the byte at +0x276 of the six objects, then, for
 * the object of the global index (+0x28 of D_089CC438), calls its virtual
 * function at 0x6C when func_08865CB8 holds for 5, func_09A677F8
 * otherwise, and clears bit 0 of its flags at +0x614.
 *
 * C++: virtual call.
 */

typedef unsigned char u8;
typedef int s32;

struct Obj {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C(s32, s32, s32);
};

struct Group {
    char pad0[0xC];
    Obj *slot[6];
};

extern "C" {

extern char *D_089CC438;

extern s32 func_08865CB8(Obj *, s32, s32);
extern void func_09A677F8(Obj *, s32, s32, s32);

Obj *func_088DCEBC(Group *arg0, s32 arg1);

void func_088DCDEC(Group *arg0) {
    Obj *obj;
    s32 i;

    for (i = 0; i < 6; i++) {
        obj = func_088DCEBC(arg0, i);
        if (obj != 0) {
            *((u8 *) obj + 0x276) = 0;
        }
    }
    obj = func_088DCEBC(arg0, *(u8 *)(D_089CC438 + 0x28));
    if ((u8) func_08865CB8(obj, 5, 0) == 1) {
        obj->vfunc_6C(5, 0, 0);
    } else {
        func_09A677F8(obj, 0, 0, 0);
    }
    *(s32 *)((char *) obj + 0x614) &= ~1;
}

Obj *func_088DCEBC(Group *arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= 6) {
        return 0;
    }
    return arg0->slot[arg1];
}

}
