/* unit_0884A72C: 0x0884A72C-0x0884A958 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884A72C: 0x0884A72C-0x0884A958 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern char *D_08A631A0;
extern char *D_08A62D8C;
extern f32 D_0893B1CC[];
extern u16 D_0893B1F4[];

extern u32 func_088900C4(char *, s32);
extern void func_08882D20(char *, s32, u16);

void func_0884A72C(char *arg0) {
    if (*(s8 *)(arg0 + 0x11AE) == 0) {
        return;
    }
    if (++*(s16 *)(arg0 + 0x11BC) >= 300) {
        *(s8 *)(arg0 + 0x11AE) = 0;
        return;
    }
    switch (*(u8 *)(arg0 + 0x11AD)) {
    case 0:
        if (*(u8 *)(arg0 + 0x11B0) == 0) {
            if (++*(s16 *)(arg0 + 0x11BA) > 100) {
                *(s16 *)(arg0 + 0x11BA) = 100;
                (*(u8 *)(arg0 + 0x11B0))++;
            }
        }
        break;
    case 1:
        if (++*(s16 *)(arg0 + 0x11BA) >= 100) {
            *(s16 *)(arg0 + 0x11BA) = 100;
            (*(u8 *)(arg0 + 0x11B0))++;
        }
        break;
    case 2:
        if (++*(s16 *)(arg0 + 0x11BA) >= 113) {
            *(s16 *)(arg0 + 0x11BA) = 113;
            (*(u8 *)(arg0 + 0x11B0))++;
        }
        break;
    }
    switch (*(u8 *)(arg0 + 0x11B1)) {
    case 0:
        if (*(s16 *)(arg0 + 0x11BA) >= 15) {
            (*(u8 *)(arg0 + 0x11B1))++;
        }
        break;
    case 1:
        if (*(s16 *)(arg0 + 0x11BA) >= 60) {
            (*(u8 *)(arg0 + 0x11B1))++;
            *(s16 *)(arg0 + 0x11B8) = D_0893B1CC[*(u8 *)(arg0 + 0x11AD)] *
                (-1.0f + 1.52587890625e-05f * (2.0f * (f32)func_088900C4(D_08A631A0, 1)));
        }
        break;
    case 2:
        (*(u8 *)(arg0 + 0x11B1))++;
        func_08882D20(D_08A62D8C, 1, D_0893B1F4[*(u8 *)(arg0 + 0x11AD)]);
        break;
    case 3:
        (*(u8 *)(arg0 + 0x11B1))++;
        break;
    }
}
