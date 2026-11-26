/* unit_08829F04: 0x08829F04-0x0882A168 (ULES01213)
 *
 * Bounds (hypothesis): 1 function filling free slots, between code still in
 * assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s16 x;
    s16 y;
    u8 b8;
} Slot;

extern char *D_08A62D90;
extern s32 D_08A62D8C;
extern char *D_08A631A0;
extern void func_088862A8(char *, s32);
extern void func_08885E3C(char *arg0, s16 arg1);
extern Slot *func_0882A248(char *p);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u16 func_088900C4(char *, s32);

void func_08829F04(char *arg0, s32 arg1, s16 arg2, s16 arg3) {
    Slot *e;
    s32 i;
    s32 k;
    s32 y;
    s32 j;
    s32 x;
    s32 k2;

    switch (arg1) {
    case 0:
        func_088862A8(D_08A62D90, 4);
        func_08885E3C(D_08A62D90, 0x18EB);
        arg2 += 0x23;
        arg3 += 0x17;
        for (i = 0, k = 0; i < 5; i++, k += 5) {
            e = func_0882A248(arg0);
            if (e != 0) {
                e->b2 = 1;
                e->b1 = 0;
                e->b0 = 0;
                e->b3 = arg1;
                e->x = arg2;
                e->y = arg3;
                e->b8 = k;
            }
        }
        break;
    case 1:
        func_08883988(D_08A62D8C, 0, 0xE, 0, 0, 0, 0, 0, 0);
        x = arg2 + 0xE;
        y = arg3 + 0x17;
        for (j = 0, k2 = 0; j < 3; j++, x += 0x20, k2 += 5) {
            e = func_0882A248(arg0);
            if (e != 0) {
                e->b2 = 1;
                e->b1 = 0;
                e->b0 = 0;
                e->b3 = arg1;
                e->x = x;
                e->y = y;
                if (func_088900C4(D_08A631A0, 1) & 1) {
                    e->y += (s16)(func_088900C4(D_08A631A0, 1) & 7);
                } else {
                    e->y -= (s16)(func_088900C4(D_08A631A0, 1) & 7);
                }
                e->b8 = k2;
            }
        }
        break;
    case 2:
        func_08883988(D_08A62D8C, 0, 0xD, 0, 0, 0, 0, 0, 0);
        e = func_0882A248(arg0);
        if (e != 0) {
            e->b2 = 1;
            e->b1 = 0;
            e->b0 = 0;
            e->b3 = arg1;
            e->x = arg2 + 0x2A;
            e->y = arg3 + 0x17;
            e->b8 = 0;
        }
        break;
    }
}
