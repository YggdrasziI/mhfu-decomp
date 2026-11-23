/* unit_088665A8: 0x088665A8-0x088666B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088665A8: frees the 15 object lists at +0x80028. */

typedef int s32;

struct Obj {
    virtual void vfunc_08(s32);
};

extern "C" {

extern void func_08859AE4(void *, void *, s32);
extern int func_08859C40(void *, Obj *);

void func_088665A8(char *arg0) {
    s32 i;
    char *p;
    Obj *o;
    Obj *next;

    for (i = 0, p = arg0; i < 15; i++) {
        o = *(Obj **)(p + 0x80028);
        if (o != 0) {
            next = *(Obj **)((char *)o + 0x1C4);
            if (o != 0) {
                o->vfunc_08(1);
            }
            func_08859C40(arg0 + 0x80000, o);
            if (next != 0) do {
                o = *(Obj **)((char *)next + 0x1C4);
                if (next != 0) {
                    next->vfunc_08(1);
                }
                func_08859C40(arg0 + 0x80000, next);
                next = o;
            } while (o != 0);
        }
        *(s32 *)(p + 0x80028) = 0;
        *(s32 *)(p + 0x80064) = 0;
        p += 4;
    }
    *(s32 *)(arg0 + 0x800A0) = 0;
    func_08859AE4(arg0 + 0x80000, arg0, 0x80000);
}

}
