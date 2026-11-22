/* unit_08895220: 0x08895220-0x088952A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    u8 d;
    u8 e;
} Entry;

void func_08895220(char *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, s16 arg5) {
    s32 idx = *(s8 *) (arg0 + 0x12F);
    s32 count = ((u8 *) (arg0 + 0x13A))[idx];
    Entry *e;

    if (count < 10) {
        if (arg5 == 12) {
            arg5 = 11;
        }
        e = (Entry *) (arg0 + idx * 0x50 + (u8) count * 8 + 0x22B18);
        e->a = arg1;
        e->b = arg2;
        e->c = arg3;
        e->d = arg5;
        e->e = arg4;
        ((u8 *) (arg0 + 0x13A))[*(s8 *) (arg0 + 0x12F)]++;
    }
}
