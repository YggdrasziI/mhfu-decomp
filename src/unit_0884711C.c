/* unit_0884711C: 0x0884711C-0x088471D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884711C: three pieces drawn with D_0893934C's half size at 0x4. */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x0 */ s16 pad0;
    /* 0x2 */ s16 pad2;
    /* 0x4 */ s16 h;
} Metrics;

extern Metrics D_0893934C;

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);

void func_0884711C(char *a0, u16 x, u16 y, u16 w, u16 t0)
{
    Metrics *m = (Metrics *)(s32)&D_0893934C;

    func_0882A9DC(a0, x, y, 0x21);
    func_0882AF70(a0, x + m->h, y, w - m->h * 2, t0, 0x22);
    func_0882A9DC(a0, x + w - m->h, y, 0x23);
}
