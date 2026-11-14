/* unit_088D1DD0: 0x088D1DD0-0x088D1E40 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned short u16;
typedef int s32;
typedef struct V74_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); } V74_0;

extern "C" {

extern s32 func_08865BAC(void *);

void func_088D1DD0(char *arg0) {
    u16 temp_v0;
    u16 temp_v1;

    temp_v1 = *(u16 *)(arg0 + 0x324);
    if (*(u16 *)(arg0 + 0x684) != temp_v1) {
        *(u16 *)(arg0 + 0x684) = temp_v1;
    }
    temp_v0 = *(u16 *)(arg0 + 0x682);
    if (temp_v0 != 0) {
        *(u16 *)(arg0 + 0x682) = (u16) (temp_v0 - 1);
    }
    if ((func_08865BAC(arg0) & 0xFF) == 1) {
        ((V74_0 *) (arg0))->vfunc_74();
    }
}

}
