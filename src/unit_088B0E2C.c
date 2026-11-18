/* unit_088B0E2C: 0x088B0E2C-0x088B0EC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0E04 and unit_088B0EC8.
 *
 * Returns through arg0 the number of slots in use (func_088AFBC0) and
 * copies those 0xC8-byte slots (D_09A1FDE0 + 0xB8, func_088B04B4) to
 * arg1. Returns 0.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 unk0;
    char unk4[0xC4];
} Rec;

extern char D_09A1FDE0[];

extern u8 func_088AFBC0(void);
extern s32 func_088B04B4(char *);

s32 func_088B0E2C(u8 *arg0, Rec *arg1) {
    s32 i;
    char *b;

    *arg0 = func_088AFBC0();
    i = 0;
    b = D_09A1FDE0;
    do {
        if (func_088B04B4(b + 0xB8)) {
            *arg1 = *(Rec *) (b + 0xB8);
            arg1++;
        }
        i++;
        b += 0xC8;
    } while (i < 4);
    return 0;
}
