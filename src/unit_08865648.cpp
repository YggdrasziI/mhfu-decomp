/* unit_08865648: 0x08865648-0x0886574C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual call through the object's vtable.
 * The byte array at 0xBE is indexed with a signed multiply (s32)i * 64:
 * with the unsigned counter the compiler steps it as a pointer.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C();
    virtual s32 vfunc_20(u16);
} Obj;

extern "C" {

extern s32 func_08865C88(char *, s32);
extern void func_088652DC(char *);
extern void func_08863B70(char *, void *, char *);
extern void func_0885F9A0(s32, s32, s32, s32);
extern s32 func_088637C4(char *);

static inline void vadd_t(float *src, float *dst) {
    asm {
        lv.q C000, 0(dst)
        lv.q C010, 0(src)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

void func_08865648(char *arg0) {
    float v[4];
    u32 i;

    if (func_08865C88(arg0, 0x20000) == 0) {
        func_088652DC(arg0);
        func_08863B70(arg0 + 0x80, v, arg0 + 0x10);
        vadd_t(v, (float *)(arg0 + 0x200));
    }
    for (i = 0; i < *(u16 *)(arg0 + 0x1A2); i++) {
        if (*(s8 *)(arg0 + (s32)i * 64 + 0xBE) == 0 && *(u8 *)(arg0 + i + 0x1A8) != 0 &&
            ((Obj *)arg0)->vfunc_20(*(u16 *)(arg0 + i * 2 + 0x1B8)) != 0) {
            func_0885F9A0(*(s32 *)(arg0 + 0x190),
                          ((Obj *)arg0)->vfunc_20(*(u16 *)(arg0 + i * 2 + 0x1B8)), i, 1);
        }
    }
    func_088637C4(arg0 + 0x80);
}

}
