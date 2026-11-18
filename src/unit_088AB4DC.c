/* unit_088AB4DC: 0x088AB4DC-0x088AB500 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between unit_088AB4B0 and
 * unit_088AB500.
 *
 * Fills the 4-byte header of a message (length = payload size + 4) and
 * hands it to func_088A72F0.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 len;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} MsgHeader;

extern void func_088A72F0(MsgHeader *, s32);

void func_088AB4DC(u8 kind, u8 arg1, u8 size, u8 arg3, MsgHeader *msg) {
    msg->len = size + 4;
    msg->unk2 = arg1;
    msg->unk3 = kind;
    msg->unk1 = arg3;
    func_088A72F0(msg, 0);
}
