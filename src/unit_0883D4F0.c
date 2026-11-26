/* unit_0883D4F0: 0x0883D4F0-0x0883D66C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting; the 6-byte key compare and the table search are
 * static inline helpers.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09A0B544;
extern s32 D_08A62D8C;
extern s32 D_08A631A8;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0881C45C(s32, void *, s32, s32);
extern int func_08890E08(s32, s32);
extern void func_08825DA8(char *);
extern void func_0883A07C(char *, s32, char *);

static inline s32 cmp6(char *a, char *b) {
    s32 j;
    for (j = 0; j < 6; j++) {
        if ((u8)b[0x1172 + j] < (u8)a[j]) return -1;
        if ((u8)a[j] < (u8)b[0x1172 + j]) return 1;
    }
    return 0;
}

static inline char *find(char *key) {
    char *g = D_09A0B544;
    s32 n = *(signed char *)(g + 0xEE3);
    s32 i;
    for (i = 0; i < n; i++) {
        if (cmp6((void *)(g + 0x57C + i * 0xC8), key) == 0) return g + 0x57C + i * 0xC8;
    }
    return 0;
}

s32 func_0883D4F0(char *arg0, s32 arg1) {
    char *e;

    e = find(arg0);
    if (e == 0 || *(u8 *)(e + 0xBF) == 5) return 1;
    if ((u16)arg1 & 0x2000) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    func_0881C45C((s32)arg0, arg0 + 0x582, arg1, 2);
    if (e != 0) {
        *(u8 *)(arg0 + 0x534) = 10;
        func_08890E08(D_08A631A8, 1);
        func_08825DA8(arg0);
        func_0883A07C(arg0, *(u8 *)(arg0 + 0x582), e);
    }
    return 0;
}
