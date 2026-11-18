/* unit_088AFBC0: 0x088AFBC0-0x088AFC28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFB48 and unit_088AFC28.
 *
 * Counts the four 0xC8-byte slots at D_09A1FDE0 + 0xB8 that
 * func_088B04B4 accepts.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_09A1FDE0[];

extern s32 func_088B04B4(char *);

u8 func_088AFBC0(void) {
    s32 i;
    u8 n;
    char *b;

    n = 0;
    i = 0;
    b = D_09A1FDE0;
    do {
        if (func_088B04B4(b + 0xB8)) {
            n++;
        }
        i++;
        b += 0xC8;
    } while (i < 4);
    return n;
}
