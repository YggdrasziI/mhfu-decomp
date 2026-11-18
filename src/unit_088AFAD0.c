/* unit_088AFAD0: 0x088AFAD0-0x088AFB48 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFA2C and unit_088AFB48.
 *
 * Marks (+0xC6 set, +0xC7 cleared) the first of the four 0xC8-byte slots
 * at D_09A1FDE0 + 0xB8 that func_088B0514 refuses against the key arg0.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char D_09A1FDE0[];

extern s32 func_088B0514(char *, char *);

void func_088AFAD0(char *arg0) {
    s32 i;
    char *b;
    char *r;

    i = 0;
    b = D_09A1FDE0;
    do {
        r = b + 0xB8;
        if (!func_088B0514(r, arg0)) {
            r[0xC6] = 1;
            r[0xC7] = 0;
            return;
        }
        i++;
        b += 0xC8;
    } while (i < 4);
}
