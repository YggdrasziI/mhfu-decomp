/* unit_088A5454: 0x088A5454-0x088A5548 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    char unk0[0x8];
    u32 unk8;
    char unkC[0x4];
    s32 unk10[1];
} T;

extern char D_089B269C[];
extern char D_089B26A4[];
extern char D_089B26AC[];
extern char D_089B26C0[];
extern int func_0880D9EC(char *, ...);
extern s32 func_088A53A4(s32);
extern s32 func_088A53D0(T *);

s32 func_088A5454(char *arg0, u8 arg1) {
    T *p;
    s32 off;

    if (func_088A53A4((s32) arg0) != 1) {
        func_0880D9EC(D_089B269C);
        func_0880D9EC(D_089B26A4);
        func_0880D9EC(D_089B26AC);
        return 0x80000006;
    }
    p = (T *) (arg0 + *(s32 *) (arg0 + 0x14));
    if (func_088A53D0(p) != 1) {
        func_0880D9EC(D_089B269C);
        func_0880D9EC(D_089B26A4);
        func_0880D9EC(D_089B26C0);
        return 0x80000007;
    }
    if (p->unk8 < arg1) {
        return 0x8000000E;
    }
    off = p->unk10[arg1];
    if (off == -1) {
        return 0x8000000E;
    }
    return *(u8 *) ((s32) p + off);
}
