/* unit_0883FAD4: 0x0883FAD4-0x0883FD44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Owns the jump table jtbl_0893115C (0x0893115C, 0x2C bytes).
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern char *D_08A631A8;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern u8 func_088567B4(char *);
extern void func_08896484(char *);
extern void func_0889645C(char *);
extern void func_08842EE8(char *);
extern void func_08818950(char *);
extern void func_08818C94(char *, s32);
extern void func_08818F74(char *);
extern void func_08816F24(char *);
extern void func_088172D8(char *);
extern void func_08818264(char *);
extern void func_0883B870(char *);
extern void func_088188A8(char *);
extern void func_088188B4(char *);
extern void func_088180CC(char *);
extern void func_08849848(char *);
extern void func_08849CAC(char *);
extern void func_0881908C(char *);
extern void func_08845A34(char *);
extern void func_08849478(char *);

void func_0883FAD4(char *arg0) {
    *(u8 *)(arg0 + 0x534) = 10;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(arg0);
    if (func_088567B4(D_089CC438) == 1) {
        if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 0x100) != 0) == 1) {
            if (*(u8 *)(arg0 + 0x52D) != 0) {
                if (*(u8 *)(arg0 + 0x57C) == 1 && *(u8 *)(arg0 + 0x57D) == 4) {
                    func_08896484(arg0);
                }
            }
            func_0889645C(arg0);
        }
    } else if (*(u8 *)(arg0 + 0x604) != 0) {
        if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 0x100) != 0) == 0) {
            func_08842EE8(arg0);
        }
    } else if (*(u8 *)(arg0 + 0x52F) != 0) {
        func_08818950(arg0);
    } else if (*(u8 *)(arg0 + 0x52D) != 0) {
        switch (*(u8 *)(arg0 + 0x57C)) {
        case 0:
            func_08818C94(arg0, 0);
            func_08818F74(arg0);
            break;
        case 1:
                switch (*(u8 *)(arg0 + 0x57D)) {
                case 0: func_08816F24(arg0); break;
                case 1: func_088172D8(arg0); break;
                case 2: func_08818264(arg0); break;
                case 3: func_0883B870(arg0); break;
                case 4: func_08896484(arg0); break;
                case 6: func_088188A8(arg0); break;
                case 7: func_088188B4(arg0); break;
                case 8: func_088180CC(arg0); break;
                case 9: func_08849848(arg0); break;
                case 10: func_08849CAC(arg0); break;
                }
                break;
        }
        if (*(s32 *)(arg0 + 0x5E8) & 4) {
            func_0881908C(arg0);
        }
    } else {
        if ((s32)((*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 2) != 0) == 0 && *(u8 *)(arg0 + 0x554) == 0) {
            func_08842EE8(arg0);
            func_08845A34(arg0);
        }
    }
    func_08849478(arg0);
}
