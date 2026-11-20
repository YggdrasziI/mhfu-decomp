/* unit_088AB068: 0x088AB068-0x088AB1A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AB028 and unit_088AB1A0.
 *
 * Starts a session for a list of members: builds the settings that
 * func_088A9914 copies (member addresses, timings, and the callbacks
 * func_088AB35C / func_088AB490 / func_088AB4B0 with the object as their
 * argument), then clears the object's state bytes.
 */

/* Speed mode: 0.05f is built with lui/ori instead of read from the data,
 * and the copy loop steps two pointers. */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 unk0;
    u8 count;
    u8 self;
    u8 addr[4][0x10];
    char unk43;
    float unk44;
    s32 unk48;
    float unk4C;
    float unk50;
    float unk54;
    void *unk58;
    void *unk5C;
    void *unk60;
    void *unk64;
    void *unk68;
    void *unk6C;
} Config;

typedef struct {
    u8 mac[6];
    char unk6[0xC2];
} Member;

typedef struct {
    u8 self;
    u8 count;
    char unk2[2];
    Member member[4];
} Members;

typedef struct {
    char unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 self;
    u8 unk7;
    char unk8[0x168];
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    u8 unk174;
    u8 unk175;
} Lobby;

extern int memcpy(void *, void *, s32);
extern void func_088A9914(Config *);
extern s32 func_088AB35C(s32, s32, s32);
extern void func_088AB490(u8, u8 *);
extern void func_088AB4B0(s32, char *);

void func_088AB068(Lobby *lobby, Members *m) {
    Member *p;
    s32 i;
    Config cfg;

    p = m->member;
    for (i = 0; i < m->count; i++) {
        memcpy(cfg.addr[i], p->mac, 6);
        p++;
    }
    cfg.unk0 = 1;
    cfg.count = m->count;
    cfg.self = m->self;
    cfg.unk44 = 0.05f;
    cfg.unk48 = 1000;
    cfg.unk4C = 20.0f;
    cfg.unk54 = 60.0f;
    cfg.unk50 = 15.0f;
    cfg.unk58 = (void *) func_088AB35C;
    cfg.unk5C = lobby;
    cfg.unk60 = (void *) func_088AB490;
    cfg.unk64 = lobby;
    cfg.unk68 = (void *) func_088AB4B0;
    cfg.unk6C = lobby;
    func_088A9914(&cfg);
    lobby->self = m->self;
    lobby->unk7 = 0;
    lobby->unk170 = 0;
    lobby->unk172 = 0;
    lobby->unk171 = 0;
    lobby->unk173 = 0;
    lobby->unk174 = 1;
    lobby->unk175 = 0;
    lobby->unk1 = 0;
    lobby->unk2 = 0;
    lobby->unk3 = 0;
    lobby->unk4 = 0;
    lobby->unk5 = 0;
}
