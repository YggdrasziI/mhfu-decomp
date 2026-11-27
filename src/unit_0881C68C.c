/* unit_0881C68C: 0x0881C68C-0x0881C884 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C68C: move a grid cursor (left/right 0xA0, up/down 0x50) with wrap. */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 pad0[4];
    s16 idx;
    u8 cols;
    s8 y;
    u8 x;
    u8 w;
    u8 h;
} Grid;

extern s32 D_08A62D8C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0881C68C(s32 arg0, Grid *g, u16 pad, u8 flag)
{
    s16 x = g->x;
    s16 y = g->y;
    s16 n;

    if ((pad & 0xA0) && g->w > 1) {
        if (pad & 0x80) {
            x--;
            if (x < 0) {
                x = g->w - 1;
            }
        } else {
            x++;
            if (x >= g->w) {
                x = 0;
            }
        }
        if (x == g->w - 1) {
            if (y >= g->h) {
                y = g->h - 1;
                g->y = y;
            }
        }
        g->x = x;
        if (flag == 0) {
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        } else {
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (pad & 0x50) {
        if (x >= g->w - 1) {
            n = g->h;
        } else {
            n = g->cols;
        }
        if (n > 1) {
            if (pad & 0x10) {
                y--;
                if (y < 0) {
                    y = n - 1;
                }
            } else {
                y++;
                if (y >= n) {
                    y = 0;
                }
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        g->y = y;
    }
    g->idx = y + g->cols * x;
}
