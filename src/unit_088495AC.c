/* unit_088495AC: 0x088495AC-0x08849848 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088495AC (ULES01213)
 *
 * Owns jump table jtbl_089311FC (0x089311FC, 0x24 bytes, 9 entries).
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A62D8C;

extern void func_0881C2E4(char *, u8 *, u16, u8);
extern s32 func_08883988(char *, s32, s32, s32, s32, s32, s32, s32, u8);
extern void func_08880760(char *, s32);

u16 func_088495AC(char *arg0, u16 arg1) {
    s8 mode = 0;

    func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 9);
    *(u16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F);
    if (arg1 & 0xA0) {
        switch (*(u8 *)(arg0 + 0x57F)) {
        case 1:
            if (*(u8 *)(arg0 + 0x5DC) != 0) {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                break;
            }
        case 0:
        case 6:
        case 7:
            *(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) ^= 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            break;
        case 8:
            mode = 1;
        case 2:
        case 3:
        case 4:
        case 5:
            if (arg1 & 0x80) {
                if (*(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) == 0) {
                    *(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) = 2;
                } else {
                    *(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) -= 1;
                }
            } else {
                *(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) += 1;
                if (*(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) > 2) {
                    *(u8 *)((char *)*(u8 *)(arg0 + 0x57F) + (s32)arg0 + 0x5DC) = 0;
                }
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            break;
        }
    }
    *(u8 *)(D_089CC438 + 0x70000 - 0x5221) = *(u8 *)(arg0 + 0x5DF);
    *(u8 *)(D_089CC438 + 0x70000 - 0x5220) = *(u8 *)(arg0 + 0x5E1);
    *(u8 *)(D_089CC438 + 0x70000 - 0x521F) = *(u8 *)(arg0 + 0x5DE);
    *(u8 *)(D_089CC438 + 0x70000 - 0x521E) = *(u8 *)(arg0 + 0x5E0);
    *(u8 *)(D_089CC438 + 0x70000 - 0x521C) = *(u8 *)(arg0 + 0x5E2);
    *(u8 *)(D_089CC438 + 0x70000 - 0x521B) = *(u8 *)(arg0 + 0x5E3);
    if (mode) {
        switch (*(u8 *)(arg0 + 0x5E4)) {
        case 0:
            mode = 1;
            break;
        case 1:
            mode = 2;
            break;
        case 2:
            mode = 3;
            break;
        }
        *(s8 *)(D_089CC438 + 0x70000 - 0x5227) = mode;
        func_08880760(D_08A62D8C, *(s8 *)(D_089CC438 + 0x70000 - 0x5227));
    }
    return arg1 & 0x2008;
}
