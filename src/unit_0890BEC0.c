/* unit_0890BEC0: 0x0890BEC0-0x0890BFA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Calls ctor(p, 1) on n elements of size `size` from `block`,
 * keeping a stack record {block, size, n, dtor, count}; afterwards, if the
 * count is below the record's n and dtor is set, calls dtor(p, -1) on the
 * constructed elements from the last one down (as the assembly shows).
 *
 * The record fields are volatile: the original stores every field and
 * re-reads them after the calls (an address-exposed record in the original);
 * volatile reproduces those loads and stores without any other symbol.
 * Speed setting; opt_propagation off keeps the first count test as sltu
 * on a zero register; opt_loop_invariants off keeps the -1 constants local.
 */

#pragma optimize_for_size off
#pragma opt_propagation off
#pragma opt_loop_invariants off

typedef short s16;
typedef unsigned int u32;

typedef struct {
    char *volatile p;
    volatile u32 size;
    volatile u32 n;
    void (*volatile dtor)(void *, s16);
    volatile u32 i;
} Rec;

void func_0890BEC0(char *block, void (*ctor)(void *, s16), void (*dtor)(void *, s16), u32 size, u32 n) {
    Rec r;
    char *p;
    u32 i;

    r.p = block;
    r.size = size;
    r.n = n;
    r.dtor = dtor;
    r.i = i = 0;
    for (p = block; i < n; ) {
        ctor(p, 1);
        p += size;
        i = r.i + 1;
        r.i = i;
    }
    if (i < r.n && r.dtor != 0) {
        for (p = (char *)(r.size * i), p = r.p + (u32)p; i != 0; ) {
            p -= r.size;
            r.dtor(p, -1);
            i = r.i - 1;
            r.i = i;
        }
    }
}
