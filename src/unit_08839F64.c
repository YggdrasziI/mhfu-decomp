/* unit_08839F64: 0x08839F64-0x0883A07C (ULES01213)
 *
 * State 0: calls func_0883488C then func_0883A758. State 1: looks up the
 * 0xC8-byte entry of D_09A0B544 (+0x57C, count s8 at +0xEE3) whose first six
 * bytes equal those at +0x1172 and, if found, passes it to func_0883A07C.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_09A0B544;

extern void func_0883488C(char *, s32);
extern void func_0883A758(void *p, int a, int b, int c, int d);
extern void func_0883A07C(char *, u8, u8 *);

static inline s32 cmp6(u8 *a, char *obj) {
    s32 k;
    for (k = 0; k < 6; k++) {
        if (*(u8 *)((char *)((s32)obj + k) + 0x1172) < a[k]) {
            return -1;
        }
        if (a[k] < *(u8 *)((char *)((s32)obj + k) + 0x1172)) {
            return 1;
        }
    }
    return 0;
}

static inline u8 *find(char *base, char *obj) {
    s32 i;
    for (i = 0; i < *(s8 *)(base + 0xEE3); i++) {
        if (cmp6((u8 *)(base + 0x57C + i * 200), obj) == 0) {
            return (u8 *)(base + i * 200 + 0x57C);
        }
    }
    return 0;
}

void func_08839F64(char *arg0) {
    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        func_0883488C(arg0, 1);
        func_0883A758(arg0, 0xF0, 0x28, *(s8 *)(arg0 + 0x57F), 0);
        break;
    case 1:
        {
            u8 *r = find(D_09A0B544, arg0);
            if (r != 0) {
                func_0883A07C(arg0, *(u8 *)(arg0 + 0x582), r);
            }
        }
        break;
    }
}
