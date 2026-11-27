/* unit_0890BE54: 0x0890BE54-0x0890BEC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890BE54: destroys n elements of size `size` from the end of `block`,
 * calling dtor(p, -1) on each (shape of the Metrowerks runtime array
 * destructor helper; name not proven). */

#pragma optimize_for_size off
typedef short s16;
typedef unsigned int u32;

void func_0890BE54(char *block, void (*dtor)(void *, s16), u32 size, u32 n) {
    char *p;

    for (p = block + size * n; n != 0; n--) {
        p -= size;
        dtor(p, -1);
    }
}
