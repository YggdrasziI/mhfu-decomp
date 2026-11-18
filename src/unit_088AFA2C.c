/* unit_088AFA2C: 0x088AFA2C-0x088AFAD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF978 and unit_088AFAD0.
 *
 * Copies the 0xA4-byte body arg1 into +0x20 of the first of the four
 * 0xC8-byte slots at D_09A1FDE0 + 0xB8 that func_088B0514 refuses against
 * the key arg0.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char D_09A1FDE0[];

extern s32 func_088B0514(char *, char *);

typedef struct {
    s16 h[0x52];
} Body;

void func_088AFA2C(char *arg0, Body *arg1) {
    s32 i;
    char *b;
    char *r;

    i = 0;
    b = D_09A1FDE0;
    do {
        r = b + 0xB8;
        if (!func_088B0514(r, arg0)) {
            *(Body *) (r + 0x20) = *arg1;
            return;
        }
        i++;
        b += 0xC8;
    } while (i < 4);
}
