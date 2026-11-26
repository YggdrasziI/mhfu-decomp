/* unit_0882A28C: 0x0882A28C-0x0882A43C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Small state machine (hypothesis: a fade effect) drawing one quad through
 * func_0882C11C. The two volatile reads in case 2 only fix the load order
 * (D_089386F0, then e->w, then D_089386F2), nothing else showed it.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 state;
    u8 pad1;
    u8 unk2;
    u8 pad3;
    s16 x;
    s16 y;
    u8 timer;
    u8 w;
    u8 alpha;
} Fade;

extern s16 D_089386F0;
extern s16 D_089386F2;
extern s16 D_089386F4;
extern s16 D_089386F6;
extern s16 D_089386F8;

extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);

void func_0882A28C(char *arg0, Fade *e) {
    switch (e->state) {
    case 0:
        e->w = 6;
        e->alpha = 0x40;
        if (e->timer <= 0) {
            e->state++;
        } else {
            e->timer--;
        }
        break;
    case 1:
        e->timer = D_089386F4;
        e->state++;
        break;
    case 2: {
        u8 dw = *(volatile u8 *)&D_089386F0;
        u8 w = *(volatile u8 *)&e->w;
        u8 da = D_089386F2;
        e->w = w + dw;
        e->alpha += da;
        e->timer--;
        if (e->timer <= 0) {
            e->state++;
        }
        func_0882C11C(arg0, e->x - (e->w >> 1), e->y - (D_089386F8 >> 1), e->w, D_089386F8,
                      0x80, 0x20, 0xCC, e->alpha, 0x81);
        break;
    }
    case 3:
        if (e->alpha - D_089386F6 <= 0) {
            e->state++;
        } else {
            e->alpha -= D_089386F6;
            func_0882C11C(arg0, e->x - (e->w >> 1), e->y - (D_089386F8 >> 1), e->w, D_089386F8,
                          0x80, 0x20, 0xCC, e->alpha, 0x81);
        }
        break;
    case 4:
        e->unk2 = 0;
        break;
    }
}
