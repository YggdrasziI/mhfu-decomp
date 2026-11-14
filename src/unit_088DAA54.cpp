/* unit_088DAA54: 0x088DAA54-0x088DAA98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;
typedef struct V6C_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(s32, u8, s32); } V6C_0;

extern "C" {

extern char D_089B64FC;

void func_088DAA54(char *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)(arg0 + 0x565);
    if (temp_v1 != 0) {
        ((V6C_0 *) (arg0))->vfunc_6C(6, *(&D_089B64FC + temp_v1), 0);
    }
}

}
