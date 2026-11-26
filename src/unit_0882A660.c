/* unit_0882A660: 0x0882A660-0x0882A864 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, a four-state effect drawn centred on
 * (x, y). The globals read are const so that their loads are not held
 * behind the byte stores; the colours are kept in locals (s16 and s8) and
 * narrowed by the u8 parameters of func_0882C11C.
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
    u8 pad8;
    u8 size;
    u8 alpha;
    u8 unkB;
} Effect;

extern const s16 D_08938708;
extern const u8 D_0893870A;
extern const s16 D_0893870C;
extern const s16 D_0893870E;
extern const s16 D_08938710;
extern const u8 D_08938712;
extern const u8 D_08938714;
extern const s16 D_08938716;

extern void func_0882C11C(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32);
extern void func_08832A9C(char *, s32);

void func_0882A660(char *arg0, Effect *p) {
    s16 d;

    switch (p->state) {
    case 0:
        p->state++;
        p->size = D_08938708;
        p->alpha = D_0893870C;
        break;
    case 1: {
        s16 c = D_08938716;
        func_0882C11C(arg0, p->x - (p->size >> 1), p->y - (p->size >> 1), p->size, p->size,
                      c, c, c - 0x80, p->alpha, 0x81);
    }
        p->state++;
        p->size += D_0893870A;
        p->unkB = D_08938710;
        break;
    case 2:
        d = D_0893870E;
        if (p->alpha - d <= 0) {
            p->state++;
        } else {
            p->alpha -= d;
            {
                s16 c = D_08938716;
                func_0882C11C(arg0, p->x - (p->size >> 1), p->y - (p->size >> 1), p->size, p->size,
                              c, c, c - 0x80, p->alpha, 0x81);
            }
            p->unkB += D_08938712;
            func_08832A9C(arg0, 0);
            {
                s8 c = D_08938714;
                func_0882C11C(arg0, p->x - (p->unkB >> 1), p->y - (p->unkB >> 1), p->unkB, p->unkB,
                              c, c, c, p->alpha, 0x80);
            }
            func_08832A9C(arg0, 1);
        }
        break;
    case 3:
        p->unk2 = 0;
        break;
    }
}
