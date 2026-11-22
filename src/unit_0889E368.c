/* unit_0889E368: 0x0889E368-0x0889E440 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    s8 a[8];
} Id8;

extern char *D_08A631A0;
extern Id8 func_0889E1E0(s32);
extern u8 *func_0889C518(s32);

static inline s32 cmp6(u8 *a, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (a[i] < b[i]) return -1;
        if (b[i] < a[i]) return 1;
    }
    return 0;
}
s32 func_0889E368(s32 arg0) {
    u8 on = (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0;

    if (on) {
        u8 id[8];
        *(Id8 *)id = func_0889E1E0(arg0);
        return cmp6(id, func_0889C518(arg0)) == 0;
    }
    return 1;
}
