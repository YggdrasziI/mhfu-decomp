/* unit_088C349C: 0x088C349C-0x088C351C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C349C asm piece, 1 function
 * between unit_088C3460 and unit_088C351C.
 *
 * C++: virtual calls. Destroys each object of the list at +0xA2E0 (virtual
 * function at vtable offset 8 with 1, as a deleting destructor), frees it
 * with func_08859C40 from the heap at +0xA28C and empties the list.
 */

typedef int s32;

typedef struct Obj {
    virtual void vfunc_08(s32);
    s32 flags;
    char pad8[0xC];
    Obj *next;
} Obj;

extern "C" {

extern void func_08859C40(char *, Obj *);

void func_088C349C(char *arg0) {
    Obj *o;
    Obj *next;

    o = *(Obj **) (arg0 + 0xA2E0);
    if (o != 0) {
        do {
            next = o->next;
            if (o != 0) {
                o->vfunc_08(1);
            }
            func_08859C40(arg0 + 0xA28C, o);
            o = next;
        } while (next != 0);
    }
    *(Obj **) (arg0 + 0xA2E0) = 0;
}

}
