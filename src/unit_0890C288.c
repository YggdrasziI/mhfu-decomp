/* unit_0890C288: 0x0890C288-0x0890C2D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890C288: walks the global destructor chain D_09A5F110 (built by
 * func_0890C2D8: next, destructor, object), unlinks each entry and calls
 * destructor(object, -1). Same shape as the Metrowerks runtime's
 * __destroy_global_chain (hypothesis, name not proven). */

#pragma optimize_for_size off

typedef int s32;

typedef struct DtorChain {
    struct DtorChain *next;
    void (*dtor)(void *, s32);
    void *obj;
} DtorChain;

extern DtorChain *D_09A5F110;

void func_0890C288(void) {
    DtorChain *gdc;

    while ((gdc = D_09A5F110) != 0) {
        D_09A5F110 = gdc->next;
        gdc->dtor(gdc->obj, -1);
    }
}
