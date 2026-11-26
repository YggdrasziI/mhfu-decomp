/* unit_0884F0D8: 0x0884F0D8-0x0884F190 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884F0D8: seek the file to the start of table entry idx, retrying until it succeeds. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;

extern s32 sceIoLseek(s32, s64, s32);
extern s32 sceKernelDelayThreadCB(u32);
extern void func_0884EC3C(void *, u32);

void func_0884F0D8(char *arg0, u16 arg1) {
    s32 *ent;
    s32 off;
    s32 v;
    s32 r;

    *(u8 *)(arg0 + 0x111C) = 1;
    *(u16 *)(arg0 + 0x111E) = arg1;
    ent = (s32 *)(arg0 + 0x2AC0) + arg1;
    off = *ent << 11;
    while (1) {
        r = sceIoLseek(*(s32 *)(arg0 + 0x1010), off, 0);
        if (r == off) {
            break;
        }
        sceKernelDelayThreadCB(10000);
    }
    v = *ent << 11;
    *(s32 *)(arg0 + 0x2FBD0) = v;
    func_0884EC3C(arg0, v / 2048);
}
