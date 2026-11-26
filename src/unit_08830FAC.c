/* unit_08830FAC: 0x08830FAC-0x0883104C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08830FAC: two pieces drawn with D_08939A30's half size at 0x4. */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x0 */ s16 pad0;
    /* 0x2 */ s16 pad2;
    /* 0x4 */ s16 h;
} Metrics;

extern Metrics D_08939A30;

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);

void func_08830FAC(char *a0, u16 x, u16 y, u16 w, u16 t0)
{
    Metrics *m = (Metrics *)(s32)&D_08939A30;

    func_0882A9DC(a0, x + w - m->h, y, 0xB6);
    func_0882AF70(a0, x, y, w - m->h, t0, 0xB5);
}
