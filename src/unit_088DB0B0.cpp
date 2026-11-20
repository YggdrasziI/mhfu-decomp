/* unit_088DB0B0: 0x088DB0B0-0x088DB15C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DB0A0 and unit_088DB15C.
 *
 * Gives each of the six objects of func_088DCEBC its index (+0x1E6) and the
 * global 16-bit value at +0x6AF0E (+0x29A), then calls its virtual function
 * at 0x40: all objects for mode 0, those with the byte at +0x2A4 set for
 * mode 1.
 *
 * C++: virtual call.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct V40 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); } V40;

extern "C" {

extern char *D_089CC438;

extern char *func_088DCEBC(s32, s32);

void func_088DB0B0(s32 arg0, s32 arg1) {
    s32 i;
    char *obj;

    i = 0;
    do {
        obj = func_088DCEBC(arg0, i);
        if (obj != 0) {
            if (arg1 == 0 || (arg1 == 1 && *(u8 *)(obj + 0x2A4) != 0)) {
                *(u16 *)(obj + 0x1E6) = i;
                *(u16 *)(obj + 0x29A) = *(u16 *)(D_089CC438 + 0x6AF0E);
                ((V40 *) obj)->vfunc_40();
            }
        }
        i++;
    } while (i < 6);
}

}
