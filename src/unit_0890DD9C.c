/* unit_0890DD9C: 0x0890DD9C-0x0890DE0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DD9C (ULES01213)
 *
 * Reads a size at 0x14 of the record, writes back the data cache and
 * invalidates the instruction cache, clears that many bytes at the
 * record plus arg1 when the size is not zero, then calls func_0890C2FC
 * with the words at 0x18 and 0x1C and two zeros.
 */

typedef int s32;

typedef struct {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Rec;

extern void sceKernelDcacheWritebackAll(void);
extern s32 sceKernelIcacheInvalidateAll(void);
extern void memset(void *, s32, s32);
extern s32 func_0890C2FC(s32, s32, s32, s32);

void func_0890DD9C(Rec *arg0, s32 arg1)
{
    s32 n = arg0->unk14;

    sceKernelDcacheWritebackAll();
    sceKernelIcacheInvalidateAll();
    if (n != 0) {
        memset((char *)arg0 + arg1, 0, n);
    }
    func_0890C2FC(arg0->unk18, arg0->unk1C, 0, 0);
}
