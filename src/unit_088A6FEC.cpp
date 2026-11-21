/* unit_088A6FEC: 0x088A6FEC-0x088A7090 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (constructor shape) before unit_088A7090 (its
 * destructor shape). Class layout and names are guesses from the code; same
 * shape as func_088B97BC (unit_088B97BC.cpp).
 */

typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {
extern float D_089B2810[2];
extern float D_089B2818;
extern char D_089BAB98;
extern char D_089BABF8;
extern s32 D_09A0FDC4;
extern s32 __ptmf_test(void *);
}

struct A { char *vt; T t; char pad[0x1C - 0x10]; };
struct D;
struct S { s32 s0; };
struct D : A, S { s32 f20; s32 f24; };

/* (this + 0x1C) - 0x1C is stored to D_09A0FDC4 without being folded (a base
 * at +0x1C cast back to the derived class: hypothesis): the sum goes through
 * an integer cast (notes/MATCHING.md); static_cast of a pointer or reference
 * and an inline member of the base fold it to `this`. */
extern "C" D *func_088A6FEC(D *d) {
    T t;
    d->vt = &D_089BAB98;
    t.v[0] = D_089B2810[0];
    t.v[1] = D_089B2810[1];
    t.v[2] = D_089B2818;
    if (__ptmf_test(&t)) {
        d->t = t;
    }
    D_09A0FDC4 = (s32) ((char *) (s32) ((char *) d + 0x1C) - 0x1C);
    d->vt = &D_089BABF8;
    d->f20 = 0;
    d->f24 = 0;
    d->s0 = 0;
    return d;
}
