/* unit_088971F0: 0x088971F0-0x08897290 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct S {
    char pad[0x11];
    u8 state;
    s8 timer;
} S;

s32 func_088971F0(S *arg0) {
    s32 ret = 0;

    switch (arg0->state & ~0x80) {
    case 1:
        arg0->state = 1;
        break;
    case 4:
        if (!(arg0->state & 0x80)) {
            if (arg0->timer-- <= 0) {
                arg0->timer = 0;
                arg0->state = 3;
                ret = 1;
            }
        }
        break;
    case 2:
        arg0->state = arg0->state & 0x80;
        arg0->state |= 3;
    case 3:
        if (!(arg0->state & 0x80)) {
            ret = 1;
        }
        break;
    case 0:
        break;
    }
    return ret;
}
