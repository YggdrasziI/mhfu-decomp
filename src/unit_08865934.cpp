/* unit_08865934: 0x08865934-0x08865A24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef struct V3C_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); } V3C_0;

extern "C" {

extern char *D_089CC438;
extern s32 func_08865A64(s32, s32);
extern void func_08865A9C(void *, u32);
extern s32 func_08865C88(s32, s32);

void func_08865934(char *arg0) {
    s32 temp_v1;
    u8 temp_v0;

    if (*(u8 *)(arg0 + 0x33C) == 0) {
        if (func_08865C88((s32) arg0, 0x400001) != 0) {
            *(u16 *)(arg0 + 0x45C) = (u16) (*(u16 *)(arg0 + 0x45C) + 2);
        } else {
            *(u16 *)(arg0 + 0x45C) = 0U;
        }
        temp_v1 = *(s32 *)(arg0 + 0x3F4) + 2;
        *(s32 *)(arg0 + 0x3F4) = temp_v1;
        if (temp_v1 >= 0x186A0) {
            *(s32 *)(arg0 + 0x3F4) = 0x2710;
        }
        temp_v0 = *(u8 *)(arg0 + 0x276);
        if (temp_v0 != 0) {
            *(u8 *)(arg0 + 0x276) = (u8) (temp_v0 - 1);
        }
        ((V3C_0 *) (arg0))->vfunc_3C();
    }
    if (((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0)) {
        func_08865A9C(arg0, 0x800U);
        if (func_08865C88((s32) arg0, 1) != 0) {
            func_08865A64((s32) arg0, 0x2000);
        } else {
            func_08865A9C(arg0, 0x2000U);
        }
    }
}

}
