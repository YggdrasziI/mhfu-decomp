/* unit_088B012C: 0x088B012C-0x088B01BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0118 and unit_088B01BC.
 * NonMatching: compared with text_088B012C in the report, not linked.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_09A202D0;

extern void func_0880C084(void *dst, const void *src, int size);
extern s32 func_088ADA44(s32, char *, s32, char *, s16, u8);

/* 87.7 %: the original computes the last three arguments first and loads
 * D_09A202D0 after them; ours loads it first. Tried: locals for the arguments,
 * an inline wrapper, a structure member for the global, casts. */
s32 func_088B012C(char *arg0) {
    s8 any[6] = {-1, -1, -1, -1, -1, -1};
    char addr[16];
    s32 ret;

    func_0880C084(addr, any, 6);
    ret = func_088ADA44(D_09A202D0, addr, 0x2710, arg0 + 4, *(u16 *)arg0 + 0x14, *(u8 *)(arg0 + 0x14));
    if (ret < 0) {
        return ret;
    }
    return 0;
}
