/* unit_088652DC: 0x088652DC-0x088653D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern "C" {

extern void func_088655F8(f32 *arg0, u16 *arg1);
extern void func_088655E0(Mtx *);
extern void func_08865530(Mtx *, Mtx *, f32);
extern void func_08865480(Mtx *, Mtx *, f32);
extern void func_088653D0(Mtx *, Mtx *, f32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_mul3(Mtx *dst, Mtx &rb) {
    Mtx *b = &rb;
    asm {
        lv.q C100, 0(dst)
        lv.q C110, 0x10(dst)
        lv.q C120, 0x20(dst)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        vmmul.t E000, E100, E200
        sv.s S000, 0(dst)
        sv.s S001, 4(dst)
        sv.s S002, 8(dst)
        sv.s S010, 0x10(dst)
        sv.s S011, 0x14(dst)
        sv.s S012, 0x18(dst)
        sv.s S020, 0x20(dst)
        sv.s S021, 0x24(dst)
        sv.s S022, 0x28(dst)
    }
}

void func_088652DC(char *arg0) {
    Mtx s;
    struct { f32 v[4]; } __attribute__((aligned(16))) ang;
    f32 x;
    f32 y;
    f32 z;

    z = *(f32 *)(arg0 + 0x228);
    y = *(f32 *)(arg0 + 0x224);
    x = *(f32 *)(arg0 + 0x220);
    mtx_identity(&s);
    s.m[0] = x;
    s.m[5] = y;
    s.m[10] = z;
    func_088655F8(ang.v, (u16 *)(arg0 + 0x1F0));
    func_088655E0((Mtx *)(arg0 + 0x10));
    func_08865530((Mtx *)(arg0 + 0x10), (Mtx *)(arg0 + 0x10), ang.v[1]);
    func_08865480((Mtx *)(arg0 + 0x10), (Mtx *)(arg0 + 0x10), ang.v[0]);
    func_088653D0((Mtx *)(arg0 + 0x10), (Mtx *)(arg0 + 0x10), ang.v[2]);
    z = *(f32 *)(arg0 + 0x208);
    y = *(f32 *)(arg0 + 0x204);
    x = *(f32 *)(arg0 + 0x200);
    ((Mtx *)(arg0 + 0x10))->m[12] = x;
    ((Mtx *)(arg0 + 0x10))->m[13] = y;
    ((Mtx *)(arg0 + 0x10))->m[14] = z;
    mtx_mul3((Mtx *)(arg0 + 0x10), s);
}

}
