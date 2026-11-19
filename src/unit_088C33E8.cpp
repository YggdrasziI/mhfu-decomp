/* unit_088C33E8: 0x088C33E8-0x088C3460 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C33E8 asm piece, 1 function
 * between unit_088C3138 and unit_088C3460.
 *
 * C++: virtual calls. Updates each object of the list at +0xA2E0 (linked
 * through +0x14, virtual function at vtable offset 0x1C) and passes those
 * whose bit 0 at +4 is clear to func_088C7184.
 */

typedef int s32;

typedef struct Obj {
    virtual void vfunc_08(s32);
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    s32 flags;
    char pad8[0xC];
    Obj *next;
} Obj;

extern "C" {

extern void func_088C7184(char *, Obj *);

void func_088C33E8(char *arg0) {
    Obj *o;
    Obj *next;

    o = *(Obj **) (arg0 + 0xA2E0);
    if (o != 0) {
        do {
            o->vfunc_1C();
            next = o->next;
            if ((bool) (o->flags & 1) == 0) {
                func_088C7184(arg0, o);
            }
            o = next;
        } while (next != 0);
    }
}

}
