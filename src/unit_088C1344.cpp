/* unit_088C1344: 0x088C1344-0x088C13E8 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C1344 asm piece, 1 function
 * between unit_088C12BC and unit_088C13E8.
 *
 * C++: virtual calls. Looks up the value of the 0x8C-byte entry k of
 * D_089CC438 (bytes +0x40, +0x41, func_08852954) and passes it to the
 * object k of D_09A4F0C4 (virtual functions at vtable offsets 0x20, 0x24).
 */

typedef short s16;
typedef int s32;
typedef unsigned char u8;

typedef struct V24 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual s32 vfunc_20(s32); virtual void vfunc_24(s32, s32, s32); } V24;

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
extern V24 *func_088DCEBC(s32, s16);

static inline s16 lookup(s16 i) {
    return func_08852954(D_089CC438, *(u8 *) (D_089CC438 + i * 0x8C + 0x40), *(u8 *) (D_089CC438 + i * 0x8C + 0x41));
}

void func_088C1344(char *arg0, s32 k) {
    V24 *o; s32 kk; s16 v;
    kk = k;
    v = lookup(kk);
    o = func_088DCEBC(D_09A4F0C4, kk);
    kk = v;
    o->vfunc_24(kk, o->vfunc_20(kk), -1);
}

}
