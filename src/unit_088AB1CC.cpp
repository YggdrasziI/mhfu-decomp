/* unit_088AB1CC: 0x088AB1CC-0x088AB35C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088AB1A0 and unit_088AB35C.
 *
 * C++: the flag test keeps its `sltu` (bool).
 *
 * Per-frame step of the session object started by func_088AB068 (mode in
 * unk7, started flag in unk170), and its restart.
 */

typedef unsigned char u8;
typedef int s32;

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

extern "C" {

extern char *D_08A631A0;

void func_088A72F8(void);
s32 func_088A7300(void);
void func_088A7308(void);
void func_088A733C(void);
void func_088A7368(void);
void func_088A7370(void);
s32 func_088A7378(void);

void func_088AB1CC(Lobby *lobby) {
    if ((bool) (*(s32 *) (D_08A631A0 + 0xF7A57C) & 1) != 0) {
        if (lobby->unk174 != 0) {
            switch (lobby->unk7) {
            case 0:
                if (lobby->unk170 == 0) {
                    if (func_088A7300() != 0) {
                        lobby->unk7 = 1;
                    }
                    if (lobby->unk175 == 0) {
                        func_088A7308();
                    } else {
                        func_088A733C();
                    }
                    if (func_088A7378() != 0) {
                        lobby->unk170 = 1;
                        func_088A7370();
                        lobby->unk7 = 1;
                    }
                }
                break;
            case 1:
                if (lobby->unk170 == 0) {
                    func_088A72F8();
                    if (lobby->unk175 == 0) {
                        func_088A7308();
                    } else {
                        func_088A733C();
                    }
                    if (func_088A7378() != 0) {
                        lobby->unk170 = 1;
                        func_088A7370();
                    }
                }
                break;
            }
            lobby->unk1 = 0;
            lobby->unk2 = 0;
            lobby->unk3 = 0;
            lobby->unk4 = 0;
            lobby->unk5 = 0;
        }
    }
}

void func_088AB30C(Lobby *lobby) {
    func_088A7368();
    if (lobby->unk175 == 0) {
        func_088A7308();
    } else {
        func_088A733C();
    }
    func_088A7370();
}

}
