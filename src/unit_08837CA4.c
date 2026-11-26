/* unit_08837CA4: 0x08837CA4-0x08837D54 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    u8 unk0;
    u8 pad[11];
} Ent;

typedef struct State {
    char pad0[0x13];
    u8 unk13;
    char pad14[0xA9 - 0x14];
    Ent ent[(0x4020 - 0xA9) / 12];
    char pad[0x4020 - 0xA9 - ((0x4020 - 0xA9) / 12) * 12];
    u16 unk4020;
} State;

extern char *D_089CC438;
extern char *D_08A62C54;

extern char *func_0885CA50(char *, char *);

s32 func_08837CA4(char *arg0, char *arg1) {
    State *s;
    char *r;
    u8 m;

    if ((unsigned int)(*(u8 *)(arg1 + 1) - 5) < 2) {
        return 1;
    }
    s = (State *)(D_089CC438 + 0x4A0);
    r = func_0885CA50(D_08A62C54, arg1);
    m = s->unk13 == 0 ? 1 : 2;
    if (!(*(u8 *)(r + 4) & m)) {
        return 0;
    }
    m = s->ent[s->unk4020].unk0 == 5 ? 4 : 8;
    if (!(*(u8 *)(r + 4) & m)) {
        return 0;
    }
    return 1;
}
