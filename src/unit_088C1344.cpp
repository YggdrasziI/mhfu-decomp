/* unit_088C1344: 0x088C1344-0x088C13E8 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C1344 asm piece, 1 function
 * between unit_088C12BC and unit_088C13E8.
 *
 * C++: virtual calls. Looks up the value of the 0x8C-byte entry k of
 * D_089CC438 (bytes +0x40, +0x41, func_08852954) and passes it to the
 * object k of D_09A4F0C4 (virtual functions at vtable offsets 0x20, 0x24).
 *
 * NonMatching: the image keeps the original code.
 */

typedef short s16;
typedef int s32;
typedef unsigned char u8;

typedef struct V24 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual s32 vfunc_20(s16); virtual void vfunc_24(s16, s32, s32); } V24;

typedef struct {
    u8 pad[0x40];
    u8 a;
    u8 b;
    u8 pad42[0x4A];
} Ent;

extern "C" {

extern char *D_089CC438;
extern s32 D_09A4F0C4;

extern s32 func_08852954(char *, u8, u8);
extern V24 *func_088DCEBC(s32, s32);

static inline s16 lookup(s16 i) {
    return func_08852954(D_089CC438, *(u8 *) (D_089CC438 + i * 0x8C + 0x40), *(u8 *) (D_089CC438 + i * 0x8C + 0x41));
}

/* NonMatching, 88.54 %: the original copies arg1 to $s0 unextended and
 * sign-extends it at each use (index, func_088DCEBC), then keeps the value
 * in $s0 (seh after the call, again before the virtual calls) and the
 * object in $s1; ours extends arg1 once and swaps $s0 / $s1. Tried: s16 or
 * s32 parameter and value, explicit casts, the value in the parameter,
 * inline helpers for the lookup and the object, an entry structure. */
void func_088C1344(char *arg0, s32 k) {
    s16 v;
    V24 *o;

    v = lookup(k);
    o = func_088DCEBC(D_09A4F0C4, (s16) k);
    o->vfunc_24(v, o->vfunc_20(v), -1);
}

}
