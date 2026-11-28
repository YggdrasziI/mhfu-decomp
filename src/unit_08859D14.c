/* unit_08859D14: 0x08859D14-0x0885A1B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08859D14: formats a message selected by arg0[1] into a local buffer,
 * measures its line count and widest line, and sets the box size and position.
 *
 * The position pair is a volatile stack array (reload of pos[0] after the
 * stores), separate from the buffer; both stores go through a pointer to
 * pos[1], which keeps the load of arg0+0xE after them with the original
 * registers. `line`/`s` pair: the call argument lives in a0 across the back
 * edge as in the original. Only remaining difference: the jump table symbol
 * name (jtbl_0893142C, 9 entries, 0x24 bytes, vs a local @N). */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct Box {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
} Box;

extern s32 D_08A62D8C;
extern char *D_089CC438;
extern char *D_08A631A8;
extern char D_0899D114[];
extern char D_0899D118[];
extern char D_0899D120[];
extern char D_0899D12C[];
extern char D_0899D138[];
extern s16 D_0899D110;
extern s16 D_0899D112;
extern u16 D_089ACA0C[];
extern u16 D_089ACA40[];
extern u16 D_089ACA68[];
extern u16 D_089ACA7C[];
extern u16 D_089ACA84;
extern u16 D_089ACA86;
extern u16 D_089ACA88;
extern u16 D_089ACA8A;
extern u16 D_089AD058[];

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, s32);
extern char *func_08851598(char *, s32);
extern int func_0880E8F0(char *, char *, ...);
extern char *func_0880EBF0(char *, s32);
extern s32 func_08890F70(char *, char *);
extern s32 func_08891074(char *, char *);
extern s32 func_0885A23C(Box *);

void func_08859D14(Box *arg0) {
    s16 maxw;
    s32 lines;
    char *s;
    char *p;
    char *line;
    s32 w;
    s32 t;
    char buf[0x200];
    volatile u16 pos[2];
    volatile u16 *pp;
    s32 x;

    arg0->unk2++;
    arg0->unk3 = 0;
    func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
    switch (arg0->unk1) {
    case 0:
        func_0880E8F0(buf, D_0899D114,
                      func_0885151C(D_089CC438, D_089ACA0C[arg0->unkA]));
        break;
    case 1:
        func_0880E8F0(buf,
                      func_0885151C(D_089CC438, D_089ACA40[arg0->unkA]),
                      func_08851528(D_089CC438, (u16)arg0->unk8));
        break;
    case 2:
        func_0880E8F0(buf, D_0899D118,
                      func_0885151C(D_089CC438, D_089ACA68[arg0->unkA]),
                      func_08851528(D_089CC438, (u16)arg0->unk8));
        break;
    case 3:
        func_0880E8F0(buf, D_0899D118, D_0899D120,
                      func_0885151C(D_089CC438, D_089ACA7C[arg0->unkA]));
        break;
    case 4:
    case 6:
        func_0880E8F0(buf, D_0899D114, arg0->unk20);
        break;
    case 5:
        func_0880E8F0(buf, D_0899D12C,
                      func_08851528(D_089CC438, (u16)arg0->unkA),
                      func_0885151C(D_089CC438, D_089ACA84),
                      arg0->unk8,
                      func_0885151C(D_089CC438, D_089ACA86));
        break;
    case 7:
        func_0880E8F0(buf, D_0899D138,
                      func_0885151C(D_089CC438, D_089ACA88),
                      func_0885151C(D_089CC438, D_089AD058[arg0->unkA]),
                      func_0885151C(D_089CC438, D_089ACA8A));
        break;
    case 8:
        func_0880E8F0(buf,
                      func_0885151C(D_089CC438, D_089ACA40[arg0->unkA]),
                      func_08851598(D_089CC438, (u16)arg0->unk8));
        break;
    }
    s = buf;
    lines = 0;
    maxw = 0;
    line = s;
    while (1) {
        p = func_0880EBF0(line, 10);
        if (p == 0) {
            w = func_08890F70(D_08A631A8, s);
            if (maxw < w) {
                maxw = w;
            }
            break;
        }
        lines++;
        w = func_08891074(D_08A631A8, s);
        if (maxw < w) {
            maxw = w;
        }
        line = p + 1;
        s = line;
    }
    arg0->unk14 = lines * 16 + 0x20;
    t = (s16)(maxw - 1) * 7 + 0x20;
    arg0->unkE = (t / 16) * 16;
    if (t % 16 != 0) {
        arg0->unkE += 16;
    }
    pp = &pos[1];
    pp[-1] = D_0899D110;
    pp[0] = D_0899D112;
    arg0->unkC = (x = pp[-1]) - (arg0->unkE >> 1);
    arg0->unk18 = 0x3C;
    arg0->unk4 = ((f32)pp[0] - (f32)(arg0->unk14 >> 1)) / 3.0f;
    arg0->unk10 = 0;
    arg0->unk16 = x - (((s16)(s32)maxw * 7) >> 1);
    func_0885A23C(arg0);
}
