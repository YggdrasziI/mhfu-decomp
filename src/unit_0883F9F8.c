/* unit_0883F9F8: 0x0883F9F8-0x0883FAD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A631A8;
extern void func_08825DA8(void *);
extern int func_0883FDF4(char *);
extern int func_08840338(char *);
extern int func_088405E4(char *);
extern int func_08841100(char *);
extern int func_08841520(char *);
extern int func_08841908(char *);
extern int func_08842628(char *);
extern int func_088428EC(char *);
extern s32 func_088567B4(void *);
extern int func_08890E08(s32, s32);

void func_0883F9F8(char *arg0) {
    u8 temp_a0;

    if ((func_088567B4(D_089CC438) & 0xFF) != 1) {
        *(s8 *)(arg0 + 0x534) = 9;
        func_08890E08(D_08A631A8, 0);
        func_08825DA8(arg0);
        func_0883FDF4(arg0);
        func_08841520(arg0);
        if (*(u8 *)(arg0 + 0x5DB) == 0) {
            func_08840338(arg0);
            func_088405E4(arg0);
            func_08841100(arg0);
            func_08841908(arg0);
            func_08842628(arg0);
        } else {
            if ((*(s8 *)(arg0 + 0x57B) == 0) && ((temp_a0 = *(u8 *)((*(char **)(arg0 + 0x530)) + 0x1E8), (temp_a0 == 1)) || (temp_a0 == 5))) {
                func_088428EC(arg0);
            }
        }
    }
}
