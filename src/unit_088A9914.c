/* unit_088A9914: 0x088A9914-0x088A9CDC (ULES01213)
 *
 * Bounds (hypothesis): last function of the old asm piece text_088A93A4,
 * before unit_088A9CDC.
 *
 * Starts a session: clears the session and its buffers, attaches the static
 * buffers, then copies the caller's settings (peer count clamped to 4).
 */

/* Speed mode: the buffer loop is unrolled by 8. */
#pragma optimize_for_size off

#include "unk_peer.h"

typedef struct {
    u8 unk0;
    u8 count;
    u8 self;
    char addr[4][0x10];
    char unk43;
    float unk44;
    s32 unk48;
    float unk4C;
    float unk50;
    float unk54;
    s32 (*unk58)(s32, s32, s32);
    s32 unk5C;
    void (*unk60)(s32, s32);
    s32 unk64;
    void (*unk68)(s32, s32);
    s32 unk6C;
} Config;

extern void memset(void *, s32, s32);
extern int func_0880C084(void *, void *, s32);
extern void func_088A84B4(Session *, s32, u8);
extern s32 func_0880DA7C(void);
extern void func_088A7DC0(void);
extern Session D_09A1D5D0;
extern Store D_09A1D59C[4];
extern Store D_09A1D590;
extern Store D_09A1D584;
extern Store D_09A1D578;
extern Store D_09A1D56C;
extern char D_09A1D170[];
extern char D_09A15170[];
extern char D_09A13170[];
extern char D_09A12970[];
extern char D_09A12170[];

void func_088A9914(Config *arg0) {
    s32 i;
    s32 n;
    u8 cnt;

    n = arg0->count;
    if (n > 4) {
        n = 4;
    }
    memset(&D_09A1D5D0, 0, sizeof(Session));
    memset(D_09A1D59C, 0, sizeof(D_09A1D59C));
    memset(&D_09A1D590, 0, sizeof(Store));
    memset(&D_09A1D584, 0, sizeof(Store));
    memset(&D_09A1D578, 0, sizeof(Store));
    memset(&D_09A1D56C, 0, sizeof(Store));
    D_09A1D5D0.unk1C = 1;
    cnt = n;
    for (i = 0; i < cnt; i++) {
        func_088A84B4(&D_09A1D5D0, (u8) i, 1);
    }
    for (i = 0; i < cnt; i++) {
        D_09A1D59C[i].cap = 0xFF;
        D_09A1D59C[i].buf = D_09A1D170 + i * 0xFF;
    }
    D_09A1D590.cap = 0x8000;
    D_09A1D590.buf = D_09A15170;
    D_09A1D584.cap = 0x2000;
    D_09A1D584.buf = D_09A13170;
    D_09A1D578.cap = 0x800;
    D_09A1D578.buf = D_09A12970;
    D_09A1D56C.cap = 0x800;
    D_09A1D56C.buf = D_09A12170;
    for (i = 0; i < cnt; i++) {
        D_09A1D5D0.unk8[i] = -1;
        D_09A1D5D0.unk114[i] = func_0880DA7C() | 0x80;
        D_09A1D5D0.unk118[i] = 0;
    }
    D_09A1D5D0.unk20 = arg0->unk0;
    D_09A1D5D0.count = n;
    D_09A1D5D0.self = arg0->self;
    for (i = 0; i < cnt; i++) {
        func_0880C084(D_09A1D5D0.addr[i], arg0->addr[i], 0x10);
    }
    D_09A1D5D0.unkCC = arg0->unk44;
    D_09A1D5D0.unkD4 = arg0->unk48;
    D_09A1D5D0.unk130 = arg0->unk4C;
    D_09A1D5D0.unk134 = arg0->unk54;
    D_09A1D5D0.unk13C = arg0->unk50;
    D_09A1D5D0.unk140 = arg0->unk58;
    D_09A1D5D0.unk144 = arg0->unk5C;
    D_09A1D5D0.unk148 = arg0->unk60;
    D_09A1D5D0.unk14C = arg0->unk64;
    D_09A1D5D0.unk150 = arg0->unk68;
    D_09A1D5D0.unk154 = arg0->unk6C;
    func_088A7DC0();
}
