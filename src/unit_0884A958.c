/* unit_0884A958: 0x0884A958-0x0884AAD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_0884A958: 0x0884A958-0x0884AAD0 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern f32 D_0893B1D8[];
extern u8 D_0893B1EC[];

extern void func_0884AE14(char *, s16);
extern void func_08832B98(char *, s32);
extern void func_0884AAD0(char *, s32, s32, s16, f32, u8);
extern void func_0884AB78(char *, s32, s32, s16, f32, u8);
extern void func_0884AC20(char *, s32, s32, s16, f32, u8);

void func_0884A958(char *arg0) {
    f32 scale;
    u8 idx;
    u8 k;

    if (*(s8 *)(arg0 + 0x11AE) == 0) {
        return;
    }
    func_0884AE14(arg0, *(s16 *)(arg0 + 0x11BC));
    idx = *(u8 *)(arg0 + 0x11B1);
    switch (idx) {
    case 0:
        break;
    case 1:
        break;
    case 2:
    case 3:
    case 4:
        scale = 0.607f * D_0893B1D8[idx];
        k = D_0893B1EC[idx];
        func_08832B98(arg0, 1);
        switch (*(u8 *)(arg0 + 0x11AD)) {
        case 0:
            func_0884AAD0(arg0, 0xF0, 0x88, *(s16 *)(arg0 + 0x11B8), 2.0f * scale, k);
            break;
        case 1:
            func_0884AB78(arg0, 0xF0, 0x86, *(s16 *)(arg0 + 0x11B8), 2.2f * scale, k);
            break;
        case 2:
            func_0884AC20(arg0, 0xF0, 0x88, *(s16 *)(arg0 + 0x11B8), 2.2f * scale, k);
            break;
        }
        func_08832B98(arg0, 0);
        break;
    }
}
