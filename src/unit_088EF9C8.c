/* unit_088EF9C8: 0x088EF9C8-0x088EFC04 (ULES01213), NonMatching
 *
 * Bounds (hypothesis): 2 functions between two units. They start the system's
 * on-screen keyboard and follow its state.
 *
 * #pragma optimize_for_size off: as in unit_088EF55C, the unit before
 * (hypothesis: same object); neither function depends on it.
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

extern OskData D_09A521B4;
/* D_09A521B4.w[11] */
extern s32 D_09A521E0;
extern OskParams D_09A521E8;
extern u16 D_09A52228[0x101];

extern void *memset(void *, s32, s32);
extern void func_088DD638(u16 *, s32, void *);
extern void func_088DD708(void *, s32, u16 *);
extern void func_09A96758(void);
extern s32 sceUtilityOskInitStart(void *);
extern s32 sceUtilityOskShutdownStart(void);
extern s32 sceUtilityOskGetStatus(void);

/* 98.81 %: the parameter block pointer is in $s0 and arg3 / type in $s1 in the
 * original, the other way round here. Tried: declaration orders, the pointer
 * set in its declaration or after the first calls, set through an integer
 * cast, no pointer local, other types for type and the arguments.
 * The field pointer set through an integer cast keeps it in one register
 * ($v1); a plain `&D_09A521B4` is folded into every store. */
s32 func_088EF9C8(void *arg0, u8 arg1, u16 arg2, void *arg3) {
    OskParams *params;
    OskData *data;
    s32 type;

    params = &D_09A521E8;
    memset(D_09A52228, 0, 0x202);
    func_088DD638(D_09A52228, 0x202, arg3);
    if (arg1 != 4) {
        type = 0xD;
    } else {
        type = 1;
    }
    memset(params, 0, 0x40);
    params->w[0] = 0x40;
    params->w[1] = 1;
    params->w[2] = 1;
    params->w[12] = 1;
    params->w[3] = 0x2A;
    params->w[4] = 0x2C;
    params->w[5] = 0x2B;
    params->w[6] = 0x29;
    params->data = &D_09A521B4;
    params->w[8] = 0;
    params->w[9] = 0;
    memset(&D_09A521B4, 0, 0x34);
    data = (OskData *) (s32) &D_09A521B4;
    data->w[12] = arg2;
    data->w[0] = 1;
    data->w[5] = 1;
    data->w[6] = 1;
    data->w[8] = (s32) D_09A52228;
    data->w[10] = (s32) D_09A52228;
    data->w[4] = type;
    data->w[1] = 0;
    data->w[2] = 0;
    data->w[3] = 0;
    data->w[7] = 0;
    data->w[11] = 0;
    data->w[9] = 0x202;
    return -(sceUtilityOskInitStart(&D_09A521E8) != 0);
}

/* 97.97 %: the test of 0x80110202 is a `beq` to the shared `ret = 1` block in
 * the original, a `beql` with the store in its delay slot here. Tried: the
 * cases apart, `default` first, `break` and `return` forms, `if` chains with
 * and without a local. The `seb` of the default case comes with an `s8`
 * result variable. */
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
            ret = 1;
            break;
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
