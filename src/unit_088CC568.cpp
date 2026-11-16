/* unit_088CC568: 0x088CC568-0x088CC604 (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): 1 function (constructor shape) before unit_088CC604.
 * Class layout and names are guesses from the code; same shape as
 * func_088B97BC (unit_088B97BC.cpp).
 */

typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {
extern float D_089B5618[2];
extern float D_089B5620;
extern char D_089BAB98;
extern char D_089BAD98;
extern s32 D_09A4F068;
extern s32 __ptmf_test(void *);
}

struct A { char *vt; T t; char pad[0x1C - 0x10]; };
struct D;
struct S { s32 s0; inline void reg(); };
struct D : A, S { char pad2[0x8C - 0x20]; char f8C; };
inline void S::reg() { D_09A4F068 = (s32) &static_cast<D &>(*this); }

/* The original stores (this + 0x1C) - 0x1C to D_09A4F068 without folding it (a
 * base at +0x1C cast back to the derived class, as an inlined base constructor
 * would do); every form tried folds it to `this` (see func_088B97BC). */
extern "C" D *func_088CC568(D *d) {
    T t;
    d->vt = &D_089BAB98;
    t.v[0] = D_089B5618[0];
    t.v[1] = D_089B5618[1];
    t.v[2] = D_089B5620;
    if (__ptmf_test(&t)) {
        d->t = t;
    }
    {
        S &s = *d;
        s.reg();
    }
    d->vt = &D_089BAD98;
    d->f8C = 0;
    return d;
}
