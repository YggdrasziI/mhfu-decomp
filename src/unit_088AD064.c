/* unit_088AD064: 0x088AD064-0x088AD0D4 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088AD00C and unit_088AD0D4.
 *
 * Registration and removal of a callback in the eight-slot table at
 * 0x09A1DB78 (see unit_088AC0E8).
 */

typedef unsigned int u32;
typedef int s32;

typedef struct {
    void (*fn)(s32, s32, void *);
    void *arg;
} Handler;

extern Handler D_09A1DB78[8];

void func_088AD064(void (*fn)(s32, s32, void *), void *arg) {
    u32 i;
    Handler *h;

    i = 0;
    h = D_09A1DB78;
    do {
        if (h->fn == 0) {
            h->fn = fn;
            h->arg = arg;
            break;
        }
        i++;
        h++;
    } while (i < 8);
}

void func_088AD09C(void (*fn)(s32, s32, void *)) {
    u32 i;
    Handler *h;

    i = 0;
    h = D_09A1DB78;
    do {
        if (h->fn == fn) {
            h->fn = 0;
            h->arg = 0;
            break;
        }
        i++;
        h++;
    } while (i < 8);
}
