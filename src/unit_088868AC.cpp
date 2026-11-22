/* unit_088868AC: 0x088868AC-0x08886B2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: the member at 0x180 is a pointer to member function. Clearing it with 0
 * gives the original copy (first word through the symbol, the next two through
 * a base register); the compiler names that object __ptmf_null, which is the
 * only remaining relocation difference with D_09A5F114. The case constants are
 * converted member pointers checked with __ptmf_test before the store.
 */

extern "C" {

typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
}
struct C { void m(); };
typedef void (C::*PMF)();
extern "C" {

extern F2 D_089AD190;
extern f32 D_089AD198;
extern f32 D_089AD19C;
extern F2 D_089AD1A0;
extern F2 D_089AD1A8;
extern f32 D_089AD1B0;
extern f32 D_089AD1B4;
extern F2 D_089AD1B8;
extern F2 D_089AD1C0;
extern f32 D_089AD1C8;
extern f32 D_089AD1CC;
extern F2 D_089AD1D0;
extern f32 D_089AD1D8;

extern s32 __ptmf_test(f32 *);
extern void func_08886B68(char *);
extern void func_088883B8(void);
extern void func_08888B84(char *);
extern void func_08889C90(char *);
extern void func_0888A164(char *);
extern void func_0888A1D0(char *);

void func_088868AC(char *arg0, u8 arg1) {
    *(s32 *)(arg0 + 0x98) = 0;
    *(PMF *)(arg0 + 0x180) = 0;
    *(u8 *)(arg0 + 0x18C) = arg1;
    switch (arg1) {
    case 0: {
        F3 t;
        func_08886B68(arg0);
        t.a = D_089AD190.b;
        t.b = D_089AD198;
        t.c = D_089AD19C;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    case 1: {
        F3 t;
        func_088883B8();
        t.a = D_089AD1A0.a;
        t.b = D_089AD1A0.b;
        t.c = D_089AD1A8.a;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    case 2: {
        F3 t;
        func_08888B84(arg0);
        t.a = D_089AD1A8.b;
        t.b = D_089AD1B0;
        t.c = D_089AD1B4;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    case 3: {
        F3 t;
        func_08889C90(arg0);
        t.a = D_089AD1B8.a;
        t.b = D_089AD1B8.b;
        t.c = D_089AD1C0.a;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    case 4: {
        F3 t;
        func_0888A164(arg0);
        t.a = D_089AD1C0.b;
        t.b = D_089AD1C8;
        t.c = D_089AD1CC;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    case 5: {
        F3 t;
        func_0888A1D0(arg0);
        t.a = D_089AD1D0.a;
        t.b = D_089AD1D0.b;
        t.c = D_089AD1D8;
        if (__ptmf_test((f32 *)&t) != 0) {
            *(PMF *)(arg0 + 0x180) = *(PMF *)&t;
        }
        break;
    }
    }
}
}
