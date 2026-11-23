/* unit_0886A77C: 0x0886A77C-0x0886A7D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A77C: sends message 0x15 with an entry index and its byte at +0x787. */

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
    char pad0[0x7];
    s8 unk7;
    char pad8[0x24];
} Entry;

typedef struct {
    char pad0[0x780];
    Entry ent[1];
} Owner;

extern s32 D_09A1DAEC;
extern void func_088AB514(s32, s32, Msg *);

void func_0886A77C(Owner *arg0, s32 arg1) {
    Msg m;
    u8 i = arg1;

    m.type = 0x15;
    m.a = 0;
    m.b = i;
    m.c = arg0->ent[i].unk7;
    func_088AB514(D_09A1DAEC, 6, &m);
}
