/* unit_08873044: 0x08873044-0x08873488 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern char *D_089CBBEC;
extern u16 D_089AC5A0[];
extern s32 D_089A853C[];
extern s32 D_089A8540[];
extern s32 D_089A8544[];
extern s32 D_089A8548[];
extern s32 D_089A854C[];
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);

void func_08873044(u8 *arg0, u8 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    u8 var_v1;

    if (*(u32 *)(arg0 + 0x28) & 0x400000) {
        return;
    }
    switch (arg1) {
    case 0x3: case 0x4: case 0x5: case 0xC: case 0xD: case 0x10: case 0x19:
    case 0x1E: case 0x22: case 0x23: case 0x3D: case 0x3E: case 0x3F:
    case 0x45: case 0x46:
        var_v1 = 0;
        var_s0 = 1;
        break;
    case 0x9: case 0x13: case 0x17: case 0x18: case 0x38: case 0x39:
    case 0x42: case 0x49:
        var_v1 = 0;
        var_s0 = 0;
        break;
    case 0x30: case 0x43: case 0x56: case 0x57: case 0x4F: case 0x50:
        var_v1 = 1;
        var_s0 = 0;
        break;
    default:
        var_v1 = 1;
        var_s0 = 1;
        break;
    }
    if (!var_v1) {
        if (arg3 > 20 && arg2 < 21 && arg0[0x766] == 0) {
            arg0[0x766] = 1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[D_089A854C[var_s0 * 5]]));
        }
        if (arg3 > 10 && arg2 < 11 && arg0[0x765] == 0) {
            arg0[0x765] = 1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[D_089A8548[var_s0 * 5]]));
        }
        if (arg3 > 5 && arg2 < 6 && arg0[0x764] == 0) {
            arg0[0x764] = 1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[D_089A8544[var_s0 * 5]]));
        }
    } else {
        if (arg3 > 2 && arg2 < 3 && arg0[0x763] == 0) {
            arg0[0x763] = 1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[D_089A8540[var_s0 * 5]]));
        }
        if (arg3 > 1 && arg2 < 2 && arg0[0x762] == 0) {
            arg0[0x762] = 1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[D_089A853C[var_s0 * 5]]));
        }
    }
}
