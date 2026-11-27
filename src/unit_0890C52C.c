/* unit_0890C52C: 0x0890C52C-0x0890C564 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* Calls a destructor-like function pointer at +8 on the object at +0. */

typedef int s32;

typedef void (*DtorFn)(void *obj, s32 flag);

typedef struct {
    void *obj;
    s32 unk4;
    DtorFn dtor;
} Rec;

void __end__catch(Rec *r) {
    void *o = r->obj;
    if (o != 0) {
        if (r->dtor != 0) {
            r->dtor(o, -1);
        }
    }
}
