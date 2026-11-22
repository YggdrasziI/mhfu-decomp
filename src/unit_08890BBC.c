/* unit_08890BBC: 0x08890BBC-0x08890C94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_088949EC(u8 *arg0);
void func_08890BBC(u8 *arg0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        arg0[0x134 + i] = 0;
        arg0[0x13A + i] = 0;
    }
    *(u16 *)(arg0 + 0x160) = 0;
    for (i = 0; i < 0x1B0; i++) {
        if (arg0[0x22968 + i] != 0) {
            arg0[0x22968 + i]--;
        }
    }
    *(u16 *)(arg0 + 0x120) = 0;
    *(u16 *)(arg0 + 0x122) = 0;
    *(u16 *)(arg0 + 0x124) = 0;
    arg0[0x12C] = 0x14;
    arg0[0x12D] = 0x14;
    arg0[0x15F] = arg0[0x12D];
    arg0[0x12E] = 0;
    arg0[0x12F] = 0;
    arg0[0x15C] = 1;
    arg0[0x131] = 0x20;
    func_088949EC(arg0);
    arg0[0x15E]++;
}
