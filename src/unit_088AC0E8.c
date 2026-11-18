/* unit_088AC0E8: 0x088AC0E8-0x088AC308 (ULES01213)
 *
 * Bounds (hypothesis): first 2 functions of the old asm piece
 * text_088AC0E8, after unit_088AC0D0.
 *
 * Event handlers: set the state flags at 0x09A1DB70 and call the eight
 * registered callbacks of the table at 0x09A1DB78 (function, argument).
 */

typedef unsigned int u32;
typedef int s32;

typedef struct {
    void (*fn)(s32, s32, void *);
    void *arg;
} Handler;

extern s32 D_09A1DB70;
extern s32 D_09A1DB74;
extern Handler D_09A1DB78[8];

void func_088AC0E8(s32 event, s32 arg) {
    u32 i;
    Handler *h;
    Handler *q;
    u32 j;

    if (event == 1) {
        D_09A1DB74 = 0;
        D_09A1DB70 |= 2;
    } else if (event == 2) {
        D_09A1DB74 = 0;
        D_09A1DB70 |= 4;
    } else if (event == 0) {
        D_09A1DB74 = arg;
        for (i = 0, h = D_09A1DB78; i < 8; i++, h++) {
            if (h->fn != 0) {
                h->fn(arg, 8, h->arg);
            }
        }
    } else if (event == 3) {
        for (j = 0, q = D_09A1DB78; j < 8; j++, q++) {
            if (q->fn != 0) {
                q->fn(0, 7, q->arg);
            }
        }
    }
}

void func_088AC1FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 i;
    Handler *h;

    if (arg0 == 3 && arg1 == 4) {
        D_09A1DB74 = 0;
        D_09A1DB70 |= 2;
    }
    if (arg0 == 4 && arg1 == 0) {
        if (arg2 == 6) {
            D_09A1DB74 = arg3;
            for (i = 0, h = D_09A1DB78; i < 8; i++, h++) {
                if (h->fn != 0) {
                    h->fn(arg3, 8, h->arg);
                }
            }
        } else {
            D_09A1DB74 = 0;
        }
    }
    if (arg1 == 0 && arg2 == 5) {
        D_09A1DB70 |= 4;
    }
}
