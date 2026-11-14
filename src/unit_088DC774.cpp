/* unit_088DC774: 0x088DC774-0x088DC8DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: the call through the third vtable slot ($t9) only matches as a virtual
 * call. Slot names give their vtable offsets.
 */

typedef short s16;
typedef int s32;

struct V {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
};

extern "C" {
extern char *D_08A62C5C;
extern int func_0880C464(void *, s32, s32);
extern s32 func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, s32);
extern s32 func_08864544(s32, s32);
extern s32 func_09A72C50(s32);
extern void func_088DC1F0(s32, s32);
extern void func_088DB488(s32, s32, s32);

void func_088DC774(s32 arg0) {
    char *g;
    s32 tmp;
    s32 v;
    s32 var_s0;

    g = D_08A62C5C;
    tmp = func_08859B44(g + 0x80000, 0x1610, 0x10);
    if (tmp != 0) {
        func_0880C464((char *) tmp, 0, 0x1610);
        v = func_08864544(0x1610, tmp);
        if (v != 0) {
            v = func_09A72C50(v);
        }
        if (v == 0) {
            func_08859C40(g + 0x80000, tmp);
        }
        var_s0 = v;
    } else {
        var_s0 = 0;
    }
    g = D_08A62C5C;
    if (*(s32 *)(g + 0x80030) == 0) {
        *(s32 *)(g + 0x80030) = var_s0;
    } else {
        *(s32 *)(*(s32 *)(g + 0x8006C) + 0x1C4) = var_s0;
        *(s32 *)(var_s0 + 0x1C8) = *(s32 *)(g + 0x8006C);
    }
    *(s32 *)(var_s0 + 0x1C0) = 2;
    *(s32 *)(g + 0x8006C) = var_s0;
    *(s32 *)(g + 0x800A0) += 1;
    func_088DC1F0(arg0, var_s0);
    *(s16 *)(var_s0 + 0x1E6) = 1;
    ((V *) var_s0)->vfunc_10();
    func_088DB488(arg0, var_s0, 1);
}

}
