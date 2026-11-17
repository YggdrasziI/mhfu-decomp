/* unit_088516A4: 0x088516A4-0x08851C3C (ULES01213)
 *
 * Bounds (hypothesis): 3 functions of the same shape between code still in
 * assembly and unit_08851C3C. Their jump tables (0x089313A8-0x089313F0) are
 * linked from this unit.
 *
 * The five tables of 40-byte records (include/unk_tables.h) are declared here
 * a second time at +2: the code addresses that member by its own symbol.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 unk0;
    char pad[38];
} W40;

typedef struct {
    char unk0[0x10];
    u8 unk10;
    char unk11[2];
    u8 unk13;
    u8 unk14;
    char unk15[0x29];
    u16 unk3E;
    char unk40[0xA];
    u16 unk4A;
    char unk4C[0xA];
    u16 unk56;
    char unk58[0xA];
    u16 unk62;
    char unk64[0xA];
    u16 unk6E;
} Sub30;

typedef struct {
    char unk0[0x13];
    u8 unk13;
    char unk14[2];
    u8 unk16;
    u8 unk17;
    char unk18[0x16];
    u16 unk2E;
    char unk30[0xA];
    u16 unk3A;
    char unk3C[0xA];
    u16 unk46;
    char unk48[0xA];
    u16 unk52;
    char unk54[0xA];
    u16 unk5E;
} Sub4A0;

extern W40 D_08963254[];
extern W40 D_08963256[];
extern W40 D_08967674[];
extern W40 D_08967676[];
extern W40 D_0896B814[];
extern W40 D_0896B816[];
extern W40 D_0896F84C[];
extern W40 D_0896F84E[];
extern W40 D_08973834[];
extern W40 D_08973836[];

s32 func_088516A4(s32 arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4) {
    s32 ret = -1;

    switch (arg2) {
    case 0:
        if (arg1 == 0) {
            ret = D_08973834[arg3].unk0;
        } else {
            ret = D_08973836[arg3].unk0;
        }
        break;
    case 1:
        ret = arg3;
        break;
    case 2:
        if (arg4 == 1) {
            if (arg1 == 0) {
                ret = D_08963254[arg3].unk0;
            } else {
                ret = D_08963256[arg3].unk0;
            }
        } else {
            ret = arg3;
        }
        break;
    case 3:
        if (arg1 == 0) {
            ret = D_08967674[arg3].unk0;
        } else {
            ret = D_08967676[arg3].unk0;
        }
        break;
    case 4:
        if (arg1 == 0) {
            ret = D_0896B814[arg3].unk0;
        } else {
            ret = D_0896B816[arg3].unk0;
        }
        break;
    case 5:
        if (arg1 == 0) {
            ret = D_0896F84C[arg3].unk0;
        } else {
            ret = D_0896F84E[arg3].unk0;
        }
        break;
    }
    return ret;
}

s32 func_0885187C(char *arg0, s32 arg1, u32 arg) {
    s32 ret = -1;
    Sub30 *p = (Sub30 *)(arg0 + arg1 * 0x8C + 0x30);

    switch (arg) {
    case 0:
        if (p->unk10 == 0) {
            ret = D_08973834[p->unk3E].unk0;
        } else {
            ret = D_08973836[p->unk3E].unk0;
        }
        break;
    case 1:
        ret = p->unk13;
        break;
    case 2:
        if (p->unk10 == 0) {
            ret = D_08963254[p->unk4A].unk0;
        } else {
            ret = D_08963256[p->unk4A].unk0;
        }
        if (ret == 0) {
            ret = p->unk14;
        }
        break;
    case 3:
        if (p->unk10 == 0) {
            ret = D_08967674[p->unk56].unk0;
        } else {
            ret = D_08967676[p->unk56].unk0;
        }
        break;
    case 4:
        if (p->unk10 == 0) {
            ret = D_0896B814[p->unk62].unk0;
        } else {
            ret = D_0896B816[p->unk62].unk0;
        }
        break;
    case 5:
        if (p->unk10 == 0) {
            ret = D_0896F84C[p->unk6E].unk0;
        } else {
            ret = D_0896F84E[p->unk6E].unk0;
        }
        break;
    }
    return ret;
}

s32 func_08851A68(char *arg0, u32 arg) {
    Sub4A0 *p = (Sub4A0 *)(arg0 + 0x4A0);
    s32 ret = -1;

    switch (arg) {
    case 0:
        if (p->unk13 == 0) {
            ret = D_08973834[p->unk2E].unk0;
        } else {
            ret = D_08973836[p->unk2E].unk0;
        }
        break;
    case 1:
        ret = p->unk16;
        break;
    case 2:
        if (p->unk13 == 0) {
            ret = D_08963254[p->unk3A].unk0;
        } else {
            ret = D_08963256[p->unk3A].unk0;
        }
        if (ret == 0) {
            ret = p->unk17;
        }
        break;
    case 3:
        if (p->unk13 == 0) {
            ret = D_08967674[p->unk46].unk0;
        } else {
            ret = D_08967676[p->unk46].unk0;
        }
        break;
    case 4:
        if (p->unk13 == 0) {
            ret = D_0896B814[p->unk52].unk0;
        } else {
            ret = D_0896B816[p->unk52].unk0;
        }
        break;
    case 5:
        if (p->unk13 == 0) {
            ret = D_0896F84C[p->unk5E].unk0;
        } else {
            ret = D_0896F84E[p->unk5E].unk0;
        }
        break;
    }
    return ret;
}
