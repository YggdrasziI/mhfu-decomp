/* unit_08864554: 0x08864554-0x08864634 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089A6050;
extern f32 D_089A6058;
extern f32 D_089A605C;
extern s32 __ptmf_test(f32 *);
extern int func_0880C464(void *, s32, s32);
extern s32 func_088626E4(s32);

void func_08864554(s32 arg0) {
    F3 sp14;

    func_088626E4(arg0);
    func_0880C464((void *) (arg0 + 0x1F0), 0, 0x10);
    func_0880C464((void *) (arg0 + 0x200), 0, 0x10);
    func_0880C464((void *) (arg0 + 0x210), 0, 0x10);
    *(s32 *)(arg0 + 0x228) = 0x3F800000;
    *(s32 *)(arg0 + 0x224) = 0x3F800000;
    *(s32 *)(arg0 + 0x220) = 0x3F800000;
    *(u16 *)(arg0 + 0x32A) = 0;
    *(u16 *)(arg0 + 0x328) = 0;
    *(u16 *)(arg0 + 0x326) = 0;
    *(u16 *)(arg0 + 0x324) = 0;
    *(s32 *)(arg0 + 0x2AC) = -1;
    *(s32 *)(arg0 + 0x2B0) = -1;
    *(s32 *)(arg0 + 0x2B4) = -1;
    *(u16 *)(arg0 + 0x2BA) = 0;
    *(u16 *)(arg0 + 0x2BC) = 0;
    *(u8 *)(arg0 + 0x230) = 0xFF;
    sp14.a = D_089A6050.b;
    sp14.b = D_089A6058;
    sp14.c = D_089A605C;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x3FC) = sp14;
    }
}
