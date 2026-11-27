/* unit_088188A8: 0x088188A8-0x088188B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088188A8: tail call forwarding two fields of the object. */

typedef unsigned char u8;
typedef int s32;

extern void func_0881AAA4(char *, s32, u8);

void func_088188A8(char *arg0) {
    func_0881AAA4(arg0, *(s32 *)(arg0 + 0x530), *(u8 *)(arg0 + 0x57F));
}
