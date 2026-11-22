/* unit_088901E0: 0x088901E0-0x088901F8 (ULES01213)
 *
 * C++: virtual call (vtable slot 0x38) on the object at D_089CC434, made as a
 * tail call (`jr $t9`), which C++ only does with `#pragma exceptions off`.
 */

typedef int s32;
typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(s32); } V38_0;

#pragma exceptions off

extern "C" {

extern V38_0 *D_089CC434;

void func_088901E0(s32 arg0, s32 arg1) {
    D_089CC434->vfunc_38(arg1);
}

}
