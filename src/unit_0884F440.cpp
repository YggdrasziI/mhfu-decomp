/* unit_0884F440: 0x0884F440-0x0884F510 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct V20 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual s32 vfunc_1C(u16); } V20;

typedef struct {
    u16 block;
    u16 offset;
} Slot;

extern "C" {

extern int func_0884F3FC(void *, u16);

void func_0884F440(V20 *arg0) {
    u16 n;
    u32 sum;
    Slot *e;
    u32 i;
    u32 sz;

    n = 0;
    sum = 0;
    e = (Slot *) ((char *) arg0 + 0x29348);
    for (i = 0; i < 0x1A01; i++, e++) {
        if (func_0884F3FC(arg0, i)) {
            sz = arg0->vfunc_1C(i);
            if (sum + sz > 0x370000) {
                sum = 0;
                n++;
            }
            e->block = n;
            e->offset = sum >> 11;
            sum += sz;
        } else {
            e->block = 0xFFFF;
            e->offset = 0;
        }
    }
}

}
