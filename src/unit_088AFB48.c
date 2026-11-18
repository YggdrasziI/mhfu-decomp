/* unit_088AFB48: 0x088AFB48-0x088AFBC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFAD0 and unit_088AFBC0.
 *
 * Returns 0 when a slot at D_09A1FDE0 + 0xB8 that func_088B0514 refuses
 * against the key arg0 has its +0xC7 flag clear, 1 otherwise.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char D_09A1FDE0[];

extern s32 func_088B0514(char *, char *);

s32 func_088AFB48(char *arg0) {
    s32 i;
    char *b;

    i = 0;
    b = D_09A1FDE0;
    do {
        if (!func_088B0514(b + 0xB8, arg0)) {
            if (((u8 *) b)[0x17F] == 0) {
                return 0;
            }
        }
        i++;
        b += 0xC8;
    } while (i < 4);
    return 1;
}
