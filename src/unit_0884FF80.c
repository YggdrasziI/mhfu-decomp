/* unit_0884FF80: 0x0884FF80-0x0884FFB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FF80: adds to a u16 counter at 0x44CC + idx * 2, clamped to 9999. */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[0x44CC];
    u16 cnt[1];
} Obj;

void func_0884FF80(Obj *p, u8 idx, u16 n) {
    p->cnt[idx] += n;
    if (p->cnt[idx] > 9999) {
        p->cnt[idx] = 9999;
    }
}
