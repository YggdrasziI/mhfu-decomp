/* unit_088DE6EC: 0x088DE6EC-0x088DE7C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DE6A0 and unit_088DE7C8.
 *
 * NonMatching, 97.0 %: the code stays in the assembly piece text_088DE6EC.
 *
 * Requests the five resources of number `arg1` in the resource table
 * (unit_088DD8A8): ids `arg1 + 0x16B0` and `arg1 + 0x15A6`, then those of
 * the tables at 0x09CE4848 and 0x089A9470 (4-byte records).
 *
 * Gap: after the call to func_088711C0 the original copies the 16-bit
 * number to `$v0` before scaling it (`addu v0, s0, zero`; `sll s0, v0,
 * 2`); ours scales it in place (`sll s0, s0, 2`), or masks it again when
 * the number is a `u16` local (`andi v0, s0, 0xFFFF`, same length). Tried:
 * `u16`, `s32` and `u32` numbers, a second local of each type for the
 * index, casts on the index, records as a structure, the offset as a
 * local, the result of func_088711C0 assigned first.
 *
 * Optimized for speed, as unit_088DD8A8.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
};

struct Table {
    Entry e[43];
    u32 unk204;
    u32 unk208;
    u32 unk20C;
    u32 unk210;
    u8 unk214;
    u8 unk215;
    u8 unk216;
};

extern "C" {

extern char *D_08A62C7C;
extern u16 D_089A9470[];
extern u16 D_089A9472[];
extern u16 D_09CE4848[];

extern void func_088711C0(char *, s32);
extern void func_088DDBD8(Table *, s32, u16, s32);

void func_088DE6EC(Table *arg0, s32 arg1) {
    s32 n = (u16) arg1;

    func_088DDBD8(arg0, 0x15, n + 0x16B0, 0);
    func_088DDBD8(arg0, 0x29, n + 0x15A6, 0);
    func_088711C0(D_08A62C7C, arg1);
    func_088DDBD8(arg0, 0x26, D_09CE4848[n * 2], 0);
    func_088DDBD8(arg0, 0x27, D_089A9470[n * 2], 0);
    func_088DDBD8(arg0, 0x28, D_089A9472[n * 2], 0);
}

}
