/* unit_08832940: 0x08832940-0x08832A9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The fourth argument is a 32-bit value whose bytes are read one by one
 * through its address at each use (it is spilled to the caller's argument
 * area and read back before every call).
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Size_08939E14;

extern Size_08939E14 D_08939E14;

extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);

void func_08832940(char *arg0, s16 x, s16 y, u32 c) {
    Size_08939E14 *sz = (Size_08939E14 *)(s32)&D_08939E14;

    func_0882C7B4(arg0, x, y, sz->unk4, sz->unk6, ((u8 *)&c)[2], ((u8 *)&c)[1], ((u8 *)&c)[0], ((u8 *)&c)[3], 0x109, 1);
    func_0882C7B4(arg0, x - sz->unk4 + 1, y, sz->unk4, sz->unk6, ((u8 *)&c)[2], ((u8 *)&c)[1], ((u8 *)&c)[0], ((u8 *)&c)[3], 0x109, 0);
    func_0882C7B4(arg0, x - 1, y - sz->unk4 + 1, sz->unk6, sz->unk4, ((u8 *)&c)[2], ((u8 *)&c)[1], ((u8 *)&c)[0], ((u8 *)&c)[3], 0x109, 3);
    func_0882C7B4(arg0, x - 1, y, sz->unk6, sz->unk4, ((u8 *)&c)[2], ((u8 *)&c)[1], ((u8 *)&c)[0], ((u8 *)&c)[3], 0x109, 2);
}
