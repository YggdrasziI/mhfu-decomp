/* unit_08872B7C: 0x08872B7C-0x08872BFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;

typedef struct {
    s8 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    s16 f;
} Msg;

extern char *D_089CC438;
extern s32 D_09A1DAEC;
extern void func_088AB514(s32, s32, char *);

void func_08872B7C(char *arg0) {
    u8 *p = (u8 *)(D_089CC438 + 0x418);
    s32 v;
    Msg msg;

    if (*p == 1) {
        v = *(s32 *)(arg0 + 0x678);
        if (v <= 0) {
            if (v == 0) {
                *p = 0;
                *(s8 *)(arg0 + 0x724) += 1;
                msg.a = 0x12;
                msg.b = 0;
                msg.c = *(s8 *)(arg0 + 0x724);
                msg.d = 0;
                func_088AB514(D_09A1DAEC, 6, (char *)&msg);
            } else {
                *p = 0;
            }
        }
    }
}
