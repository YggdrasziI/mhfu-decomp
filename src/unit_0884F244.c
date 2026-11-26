/* unit_0884F244: 0x0884F244-0x0884F2CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884F244 */

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned short u16;

extern s32 sceIoLseek(s32, s64, s32);
extern s32 sceKernelDelayThreadCB(u32);

void func_0884F244(char *s, s32 arg1) {
    s32 pos;
    s32 r;

    pos = arg1 + (*(s32 *)((char *)(*(u16 *)(s + 0x111E) * 4) + (s32)s + 0x2AC0) << 11);
    while (1) {
        r = sceIoLseek(*(s32 *)(s + 0x1010), pos, 0);
        if (r == pos) {
            *(s32 *)(s + 0x2FBD0) = pos;
            return;
        }
        sceKernelDelayThreadCB(10000);
    }
}
