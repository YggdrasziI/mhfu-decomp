/* unit_088B97BC: 0x088B97BC-0x088B9884 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (constructor shape) before unit_088B9884.
 * Class layout and names are guesses from the code.
 */

typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;
extern "C" {
extern float D_089B2B34;
extern float D_089B2B38;
extern float D_089B2B3C;
extern char D_089BAB98;
extern char D_089BAC6C;
extern char *D_089CC438;
extern s32 D_09A44C5C;
extern s32 __ptmf_test(void *);
}
struct A { char *vt; T t; char pad[0x1C - 0x10]; };
struct D;
struct S { s32 s0; };
struct D : A, S { char pad2[0x5C - 0x20]; char f5C; };

/* (this + 0x1C) - 0x1C is stored to D_09A44C5C without being folded (a base
 * at +0x1C cast back to the derived class: hypothesis): the sum goes through
 * an integer cast (notes/MATCHING.md); static_cast of a pointer or reference
 * and an inline member of the base fold it to `this`. */
extern "C" D *func_088B97BC(D *d) {
    T t;
    d->vt = &D_089BAB98;
    t.v[0] = D_089B2B34;
    t.v[1] = D_089B2B38;
    t.v[2] = D_089B2B3C;
    if (__ptmf_test(&t)) {
        d->t = t;
    }
    D_09A44C5C = (s32) ((char *) (s32) ((char *) d + 0x1C) - 0x1C);
    d->vt = &D_089BAC6C;
    d->f5C = 0;
    *(s32 *)((char *)d + 0x34) = 0;
    *(s32 *)(D_089CC438 + 0x6AF14) &= ~1;
    return d;
}
