/* unit_088EFB18: 0x088EFB18-0x088EFC04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088EF9C8 and unit_088EFC04.
 * Follows the state of the system's on-screen keyboard started by
 * func_088EF9C8 and copies the text back when it is done.
 *
 * #pragma optimize_for_size off: as in unit_088EF9C8 (hypothesis: same
 * object); the function does not depend on it.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

/* The keyboard's field description (0x34 bytes) and the parameter block of
 * sceUtilityOskInitStart (0x40 bytes), as words. */
typedef struct {
    s32 w[13];
} OskData;

typedef struct {
    /* 0x00 */ s32 w[13];
    /* 0x34 */ OskData *data;
    /* 0x38 */ s32 state;
    /* 0x3C */ s32 unk3C;
} OskParams;

/* D_09A521B4.w[11] */
extern s32 D_09A521E0;
extern OskParams D_09A521E8;
extern u16 D_09A52228[0x101];

extern void func_088DD708(void *, s32, u16 *);
extern void func_09A96758(void);
extern s32 sceUtilityOskShutdownStart(void);
extern s32 sceUtilityOskGetStatus(void);

/* The three error codes are one case group in the order 0x80110201,
 * 0x80110202, 0x801102FF (tested in the reverse order: beql FF, beq 202,
 * beq 201 to the shared block). The `seb` of the default case comes with an
 * `s8` result variable. */
s8 func_088EFB18(void *arg0) {
    OskParams *params;
    s8 ret;

    params = &D_09A521E8;
    switch (sceUtilityOskGetStatus()) {
    case 1:
        ret = 0;
        break;
    case 4:
        ret = 0;
        break;
    default:
        ret = 1;
        break;
    case 2:
        func_09A96758();
        ret = 0;
        break;
    case 3:
        if (D_09A521E0 == 2) {
            func_088DD708(arg0, 0x100, D_09A52228);
        }
        sceUtilityOskShutdownStart();
        ret = 1;
        break;
    case 0:
        switch (params->w[7]) {
        case 0x80110201:
        case 0x80110202:
        case 0x801102FF:
            ret = 1;
            break;
        default:
            ret = 0;
            break;
        }
        break;
    }
    return ret;
}
