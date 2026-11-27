/* unit_0881B7F0: 0x0881B7F0-0x0881B9A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881B7F0 (ULES01213), 0x0881B7F0-0x0881B9A0
 *
 * Draws the distinct non-zero bytes of a 5-byte list, one line each
 * (colour 0 or 10 from func_0882822C); a default line when there is none.
 * Optimized for speed. The duplicate search is a static inline helper taking
 * the byte as an s32 (gives the `andi a0, s3, 0xFF` before the loop).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089ACEEC[];
extern char D_08938478;

extern char *func_0885151C(char *, u16);
extern u8 func_0882822C(char *, char *, u8, u8 *);
extern int func_088915B0(char *, s32, s16, s8, char *, ...);
extern void func_08891474(char *, s32, s16, char *, ...);

static inline u8 find_byte(u8 *buf, u8 n, s32 c)
{
    u8 uniq = 1;
    s32 j;

    for (j = 0; j < n; j++) {
        if ((u8)c == buf[j]) {
            uniq = 0;
            break;
        }
    }
    return uniq;
}

void func_0881B7F0(char *a0, u8 *s, char *a2, s32 x, s16 y, s16 dy)
{
    u8 seen[8];
    u8 c;
    u8 n;
    s32 i;
    s32 col;

    n = 0;
    for (i = 0; i < 5; i++) {
        c = s[i];
        if (c != 0) {
            if (find_byte(seen, n, c) == 1) {
                seen[n] = c;
                n++;
                if (func_0882822C(a0, a2, c, s) == 1) {
                    col = 0;
                } else {
                    col = 10;
                }
                func_088915B0(D_08A631A8, x, y, (s8)col, &D_08938478,
                              func_0885151C(D_089CC438, D_089ACEEC[c]));
                y += dy;
            }
        }
    }
    if (n == 0) {
        func_08891474(D_08A631A8, x, y, &D_08938478,
                      func_0885151C(D_089CC438, D_089ACEEC[0]));
    }
}
