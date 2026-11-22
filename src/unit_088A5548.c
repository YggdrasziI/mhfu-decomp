/* unit_088A5548: 0x088A5548-0x088A5774 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern int func_0880D9EC(char *, ...);
extern s32 func_088A53A4(s32);
extern s32 func_088A53D0(s32);
extern s32 func_088A53FC(s32);
extern s32 func_088A5428(s32);

extern char D_089B269C;
extern char D_089B26A4;
extern char D_089B26AC;
extern char D_089B26C0;
extern char D_089B26D4;
extern char D_089B26E8;

typedef struct {
    char unk0[0x8];
    s32 unk8;
    char unkC[0x8];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Header;

typedef struct {
    char unk0[0x2];
    u8 unk2;
    u8 unk3;
    char unk4[0x8];
    u16 unkC;
} EntryA;

typedef struct {
    char unk0[0xA];
    u16 unkA;
} EntryB;

typedef struct {
    char unk0[0x14];
} EntryC;

s32 func_088A5548(s32 *out, Header *hdr, u8 arg2, u8 arg3, u8 arg4) {
    char *p1;
    char *p2;
    char *p3;
    char *base;
    EntryA *a;
    EntryB *b;
    EntryC *c;

    if (hdr->unk8 != 2) {
        return -1;
    }
    p1 = (char *) hdr + hdr->unk14;
    p2 = (char *) hdr + hdr->unk18;
    p3 = (char *) hdr + hdr->unk1C;
    if (func_088A53A4((s32) hdr) != 1) {
        func_0880D9EC(&D_089B269C);
        func_0880D9EC(&D_089B26A4);
        func_0880D9EC(&D_089B26AC);
        return 0x80000006;
    }
    if (func_088A53D0((s32) p1) != 1) {
        func_0880D9EC(&D_089B269C);
        func_0880D9EC(&D_089B26A4);
        func_0880D9EC(&D_089B26C0);
        return 0x80000007;
    }
    if (func_088A53FC((s32) p2) != 1) {
        func_0880D9EC(&D_089B269C);
        func_0880D9EC(&D_089B26A4);
        func_0880D9EC(&D_089B26D4);
        return 0x80000008;
    }
    if (func_088A5428((s32) p3) != 1) {
        func_0880D9EC(&D_089B269C);
        func_0880D9EC(&D_089B26A4);
        func_0880D9EC(&D_089B26E8);
        return 0x80000009;
    }
    base = p1 + ((s32 *) (p1 + 0x10))[arg2];
    a = (EntryA *) (base + arg4 * sizeof(EntryA) + 8);
    b = (EntryB *) (p2 + a->unkC * sizeof(EntryB) + 0x10);
    c = (EntryC *) (p3 + b->unkA * sizeof(EntryC) + 0x10);
    if (arg3 < a->unk2 || arg3 > a->unk3) {
        return 0x8000000F;
    }
    out[0] = (s32) base;
    out[1] = (s32) a;
    out[2] = (s32) b;
    out[3] = (s32) c;
    return 0;
}
