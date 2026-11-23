/* unit_0886BBE4: 0x0886BBE4-0x0886BCD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 type;
    s16 a;
    s16 b;
    s16 c;
    s32 pad;
} Msg;

typedef struct {
    u16 flags;
    char pad2[0xA];
} Slot;

typedef struct {
    Slot slot[0x2B];
    s32 unk204;
    s32 unk208;
    s32 unk20C;
    s32 unk210;
} Mgr;

extern s32 D_09A1DAEC;
extern Mgr *D_09A4F0D0;
extern char *D_089CC434;
extern void func_088AB514(s32, s32, Msg *);
extern void func_088B87B0(char *, u8);

void func_0886BBE4(char *arg0) {
    Msg m;
    Mgr *g;
    s32 i;

    m.type = 6;
    m.a = 0;
    m.b = *(s8 *)(arg0 + 0x20);
    m.c = 0;
    func_088AB514(D_09A1DAEC, 6, &m);
    g = D_09A4F0D0;
    g->unk210 = g->unk204;
    g->unk20C = g->unk208;
    for (i = 0x15; i <= 0x2A; i++) {
        g->slot[i].flags &= ~2;
    }
    func_088B87B0(D_089CC434, 1);
}
