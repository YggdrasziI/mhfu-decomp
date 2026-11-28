/* unit_088CAF54: 0x088CAF54-0x088CB004 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088CAF54
 *
 * C++: virtual call through $t9 (vtable slot 0x1C). Resets the halfword
 * fields at 0x3E8-0x410, sets bit 1 of the flags at 4, then copies the
 * member-pointer constant at 0x089B5374 to 0x3D8 when __ptmf_test accepts it.
 */

typedef short s16;
typedef int s32;
typedef float f32;
typedef struct F3 { f32 v[3]; } F3;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C();
} Obj;

extern "C" {

extern f32 D_089B5370[2];
extern f32 D_089B5378;
extern f32 D_089B537C;
extern s32 __ptmf_test(f32 *);
extern void func_088CB364(Obj *);

void func_088CAF54(Obj *arg0) {
    char *p = (char *)arg0;
    F3 sp14;

    *(s16 *)(p + 0x400) = 0;
    *(s16 *)(p + 0x3E8) = 0;
    *(s16 *)(p + 0x40C) = 0x1E0;
    *(s16 *)(p + 0x3F4) = 0x1E0;
    *(s16 *)(p + 0x410) = 0;
    *(s16 *)(p + 0x3F8) = 0;
    *(s16 *)(p + 0x404) = 0;
    *(s16 *)(p + 0x3EC) = 0;
    *(s32 *)(p + 4) = *(s32 *)(p + 4) | 2;
    arg0->vfunc_1C();
    func_088CB364(arg0);
    sp14.v[0] = D_089B5370[1];
    sp14.v[1] = D_089B5378;
    sp14.v[2] = D_089B537C;
    if (__ptmf_test((f32 *)&sp14) != 0) {
        *(F3 *)(p + 0x3D8) = sp14;
    }
}

}
