/* unit_0889F764: 0x0889F764-0x0889F8F4 (ULES01213) */

typedef int s32;

extern char D_089B2110;
extern char D_089B2118;
extern char D_089B2120;
extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern int func_0880D9EC(char *, ...);
extern s32 func_0889F0D8(s32, s32 *, s32);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);

static inline s32 locked(s32 *msg) {
    s32 ret;
    s32 temp_a0;
    s32 temp_v1;

    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    ret = func_0889F0D8(0, msg, 0x40);
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    return ret;
}

s32 func_0889F764(s32 arg0, s32 *msg, s32 *out) {
    s32 ret;

    ret = 0;
    switch (*msg) {
    case 0:
        break;
    case 0x30000000:
        break;
    case 0x10000000:
    case 0x10000001:
    case 0x10000002:
    case 0x10000003:
    case 0x10000004:
    case 0x10000006:
    case 0x10000007:
    case 0x10000008:
    case 0x1000000A:
    case 0x1000000B:
    case 0x1000000C:
    case 0x10000009:
    case 0x1000000D:
        ret = locked(msg);
        break;
    default:
        func_0880D9EC(&D_089B2110);
        func_0880D9EC(&D_089B2118);
        func_0880D9EC(&D_089B2120, *msg);
        break;
    }
    *out = ret;
    return ret;
}
