/* unit_088CA100: 0x088CA100-0x088CA2D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088CA100: vtable method of D_089BACDC (ULES01213). */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 lo;
    u8 hi;
    u8 state;
    u8 val;
    s16 timer;
} Blink;

extern char *D_089CC438;
extern char *D_08A631A0;
extern u8 func_088567B4(char *);
extern u16 func_088900C4(char *, s32);
extern s32 func_08862D34(s32, s32, s32);
extern s32 func_08862800(s32, s32, u8, u8, u8);
extern s32 func_088629DC(s32, s32, u8, u8, u8);
extern s32 func_08862BB8(s32, s32, u8);
extern s32 func_0886171C(s32, s32, char *, s32);

void func_088CA100(char *arg0, s32 arg1, Blink *b, s32 arg3) {
    u8 lo;

    if (func_088567B4(D_089CC438) == 0) {
        switch (b->state) {
        case 0:
            if (--b->timer < 0) {
                b->timer = func_088900C4(D_08A631A0, 1) % 60 + 30;
                b->state++;
            }
            break;
        case 1:
            lo = b->lo;
            b->val = lo + func_088900C4(D_08A631A0, 1) % (b->hi - lo);
            if (--b->timer < 0) {
                b->state++;
            }
            break;
        case 2:
            if (b->val > 0xFB) {
                b->timer = func_088900C4(D_08A631A0, 1) % 180 + 180;
                b->val = 0xFF;
                b->state = 0;
            } else {
                b->val += 4;
            }
            break;
        }
    }
    func_08862D34(arg1, (u8)arg3, 2);
    func_08862800(arg1, (u8)arg3, 0xFF, 0xFF, 0xFF);
    func_088629DC(arg1, (u8)arg3, 0xFF, 0xFF, 0xFF);
    func_08862BB8(arg1, (u8)arg3, b->val);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
}
