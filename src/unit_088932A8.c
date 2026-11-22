/* unit_088932A8: 0x088932A8-0x08893390 (ULES01213) */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x158];
    u16 unk158;
    u16 unk15A;
    u8 pad15C[0x162 - 0x15C];
    u16 unk162;
    u8 pad164[0x2628 - 0x164];
    u16 unk2628[1];
} Obj;

u16 func_088932A8(u8 *arg0) {
    Obj *obj = (Obj *)arg0;
    s32 n;
    s32 start;
    s32 i;
    s32 j;

    n = *(u16 *)(arg0 + 0x11E);
    if (*(u16 *)(arg0 + 0x15A) < n) {
        return *(u16 *)(arg0 + 0x158);
    }
    start = *(u16 *)(arg0 + 0x162);
    for (i = start; i < n; i++) {
        if (arg0[i + 0x22968] == 0) {
            for (j = 0; j < 0xFFF0; j++) {
                if (obj->unk2628[j] == i) {
                    obj->unk2628[j] = 0xFFFF;
                    break;
                }
            }
            return i;
        }
    }
    if (start != 0) {
        (*(u16 *)(arg0 + 0x162))--;
    }
    start = *(u16 *)(arg0 + 0x162);
    for (j = 0; j < 0xFFF0; j++) {
        if (obj->unk2628[j] == start) {
            obj->unk2628[j] = 0xFFFF;
            break;
        }
    }
    return *(u16 *)(arg0 + 0x162);
}
