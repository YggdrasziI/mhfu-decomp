/* unit_088476F4: 0x088476F4-0x08847B74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088476F4 (ULES01213), C++: bool inline helpers keep the sltu/xor flag tests. */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {
extern char *D_089CC438;
extern s16 D_08A62C6C;
extern char *D_08A62C7C;
extern s32 D_08A62D8C;
extern u8 D_0899D19B[][24];

extern s16 func_0884FB6C(char *p);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern int func_088966C0(char *, s32);
extern s32 func_088568AC(char *, u16);
extern s32 func_08856920(char *arg0, s32 arg1);
extern s32 func_088D722C(char *arg0);
extern void func_08847B74(char *, char *);
}

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

static inline bool slot_used(char *obj) {
    return *(u8 *)((char *)(*(u8 *)(obj + 0x5EE) * 0x8C) + (s32)D_089CC438 + 0x30) != 0;
}

static inline bool locked(char *obj) {
    return (*(s32 *)(obj + 0x614) & 0x10000) != 0;
}

extern "C" {

void func_088476F4(char *arg0, char *arg1) {
    s16 pad;
    s16 btn;
    char *g;
    s32 c;
    s32 r;

    if (is_own(arg1) != 0) {
        pad = D_08A62C6C;
        btn = func_0884FB6C(D_089CC438);
        if (*(u8 *)(arg1 + 0x55E) != 0) {
            *(u8 *)(arg1 + 0x55E) -= 1;
        }
        if (*(u16 *)(arg1 + 0x5EC) != 0) {
            *(u16 *)(arg1 + 0x5EC) -= 1;
            if (*(u16 *)(arg1 + 0x5EC) == 0 ||
                slot_used(arg1) == 0) {
                *(s32 *)(arg1 + 0x614) &= ~0x10000;
            }
        }
        if (locked(arg1) == 1 || *(u8 *)(arg1 + 0x55E) != 0) {
            return;
        }
        if (btn & 0x2000) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg1 + 0x614) ^= 2;
            func_088966C0(arg0, 2);
            return;
        }
        if (btn & 0x80) {
            func_08883988(D_08A62D8C, 0, 0x16, 0, 0, 0, 0, 0, 0);
            c = *(u8 *)(arg1 + 0x55D);
            if (c & 7) {
                *(u8 *)(arg1 + 0x55D) = c - 1;
            } else {
                *(u8 *)(arg1 + 0x55D) = c + 7;
            }
        }
        if (btn & 0x20) {
            func_08883988(D_08A62D8C, 0, 0x16, 0, 0, 0, 0, 0, 0);
            if (*(u8 *)(arg1 + 0x55D) % 8 != 7) {
                *(u8 *)(arg1 + 0x55D) += 1;
            } else {
                *(u8 *)(arg1 + 0x55D) -= 7;
            }
        }
        if (btn & 0x10) {
            func_08883988(D_08A62D8C, 0, 0x16, 0, 0, 0, 0, 0, 0);
            c = *(u8 *)(arg1 + 0x55D);
            if (c < 8) {
                *(u8 *)(arg1 + 0x55D) = c + 0x18;
            } else {
                *(u8 *)(arg1 + 0x55D) = c - 8;
            }
        }
        if (btn & 0x40) {
            func_08883988(D_08A62D8C, 0, 0x16, 0, 0, 0, 0, 0, 0);
            c = *(u8 *)(arg1 + 0x55D);
            if (c >= 0x18) {
                *(u8 *)(arg1 + 0x55D) = c - 0x18;
            } else {
                *(u8 *)(arg1 + 0x55D) = c + 8;
            }
        }
        if (*(s8 *)(D_08A62C7C + 0x12D) != 0) {
            return;
        }
        c = *(u8 *)(arg1 + 0x55D);
        g = D_089CC438;
        {
            u32 w = *(u32 *)((char *)(((u32)c >> 5) * 4) + (s32)g + 0x410);
            if (w & (1 << (c % 32))) {
                return;
            }
        }
        if (!(pad & 0x4000)) {
            return;
        }
        if (*(u16 *)((char *)(c * 4) + (s32)g + 0x390) == 0) {
            return;
        }
        if (*(u8 *)(arg1 + 0x55E) != 0) {
            return;
        }
        if (func_088568AC(g, *(u16 *)(g + c * 4 + 0x390)) == 0) {
            if ((u8)func_088D722C(arg1) == 0) {
                return;
            }
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
            func_08847B74(arg0, arg1);
            return;
        }
        c = *(u8 *)(arg1 + 0x55D) * 4;
        g = D_089CC438;
        r = func_08856920(g, *(u16 *)((char *)c + (s32)g + 0x390));
        if (r < *(s16 *)((char *)c + (s32)g + 0x392)) {
            return;
        }
        if (D_0899D19B[*(u16 *)((char *)c + (s32)g + 0x390)][0] == 0xFF) {
            return;
        }
        func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
        func_08847B74(arg0, arg1);
    }
}
}
