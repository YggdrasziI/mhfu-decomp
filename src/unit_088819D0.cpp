/* unit_088819D0: 0x088819D0-0x08881A30 (ULES01213)
 *
 * func_088819D0: returns 1 if the 0x40 virtual method of D_089CC434
 * (argument 2) returns 1, else whether the word at +0x8B94 is non-zero.
 *
 * C++: virtual call returning an s32 tested as u8.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct V40 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); virtual void vfunc_3C(); virtual s32 vfunc_40(s32); } V40;

extern "C" {

extern V40 *D_089CC434;

s32 func_088819D0(char *arg0) {
    if ((u8)D_089CC434->vfunc_40(2) != 1) {
        switch (*(s32 *)(arg0 + 0x8B94)) {
        case 0:
            return 0;
        }
    }
    return 1;
}

}
