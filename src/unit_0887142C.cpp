/* unit_0887142C: 0x0887142C-0x088714CC (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between code still in assembly: a tail call
 * through a vtable and the function after it (symbol sizes in symbol_addrs.txt).
 */

#pragma exceptions off
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V38 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); } V38;

extern "C" {

extern V38 *D_089CC434;
extern char *D_08A62C7C;

extern u8 *func_08869774(char *, s32);
extern u16 func_09AB31C8(u8);

s32 func_0887142C(void) {
    return D_089CC434->vfunc_38();
}

u16 func_08871444(void) {
    u8 *list;
    u16 r;
    s32 i;

    list = func_08869774(D_08A62C7C, 0);
    if (list == 0) {
        return 0xFFFF;
    }
    r = 0xFFFF;
    for (i = 0; i < 4; i++) {
        u16 v = func_09AB31C8(list[0]);
        if (v != 0xFFFF) {
            r = v;
        }
        list += 4;
    }
    return r;
}

}
