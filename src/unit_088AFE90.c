/* unit_088AFE90: 0x088AFE90-0x088AFFBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AFE78 and unit_088AFFBC.
 *
 * Starts a message of kind arg1: clears its 0x300-byte payload, copies the
 * 6-byte address D_09A202B8, fills the header bytes from five tables
 * indexed by the kind, and the 16-bit sequence number (+0xA, big-endian):
 * the one of the received header (D_09A20608) for a message of class 2,
 * otherwise the next value of the counter D_09A202D4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 len;
    u16 pos;
    u8 unk4;
    u8 cls;
    u8 unk6;
    u8 unk7;
    u8 unk8[2];
    u8 seq[2];
    u8 unkC;
    u8 unkD;
    u8 addr[6];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 data[0x300];
} Msg;

extern u8 D_09A202B8[];
extern u8 D_089B295C[];
extern u8 D_089B2984[];
extern u8 D_089B29AC[];
extern u8 D_089B29D4[];
extern u8 D_089B29FC[];
extern u8 D_09A20608;
extern u8 D_09A20609;
extern u16 D_09A202D4;

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);

void func_088AFE90(Msg *m, u16 kind) {
    memset(m->data, 0, sizeof(m->data));
    memcpy(m->addr, D_09A202B8, 6);
    m->unk6 = D_089B295C[kind];
    m->unk7 = D_089B2984[kind];
    m->cls = D_089B29FC[kind];
    m->len = 0;
    m->pos = 0;
    m->unk4 = D_089B29AC[kind];
    m->unk14 = D_089B29D4[kind];
    if (m->cls == 2) {
        m->seq[0] = D_09A20608;
        m->seq[1] = D_09A20609;
    } else {
        D_09A202D4++;
        m->seq[0] = D_09A202D4 >> 8;
        m->seq[1] = D_09A202D4;
    }
    m->unkC = 0;
    m->unkD = 0;
    m->unk16 = 0xFF;
    m->unk17 = 0xFF;
}
