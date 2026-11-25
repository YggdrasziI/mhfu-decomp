/* unit_0885D300: 0x0885D300-0x0885DB70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885D300: copies six 12-byte entries (from arg1 + 0x4E8, or from
 * D_089CC438 + 0x4C0 when flags 4/8 of D_089CC438 + 0x6AF14 are clear, the
 * u16 at arg1 + 0x1E6 equals D_089CC438[0x28] and arg3 != 1) into a local
 * array, then returns an s16 value selected by arg2 (switch, jump table
 * owned by the unit: jtbl_08931530, 14 words, 0x38 bytes): sums of signed
 * bytes from five 40-byte-row tables, sums of func_0885EAA4 results, or the
 * results of func_0885CE38 / func_0885DB70 / func_0885DBD0.
 * The entries are copied field by field with the last three s16 as one
 * sub-structure assignment (all loads, then all stores); the loop copy of
 * entries 1-5 steps arg1 itself. func_0885EAA4 results are sign-extended
 * again: it is declared returning s32 and cast to s16 at each use.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    Vec unk6;
} Item;

extern char *D_089CC438;
extern u8 D_08959FD6[];
extern u8 D_08959FD8[];
extern u8 D_08960BA6[];
extern s8 D_08963261[];
extern s8 D_08963262[];
extern s8 D_08963263[];
extern s8 D_08963264[];
extern s8 D_08963265[];
extern s8 D_08967681[];
extern s8 D_08967682[];
extern s8 D_08967683[];
extern s8 D_08967684[];
extern s8 D_08967685[];
extern s8 D_0896B821[];
extern s8 D_0896B822[];
extern s8 D_0896B823[];
extern s8 D_0896B824[];
extern s8 D_0896B825[];
extern s8 D_0896F859[];
extern s8 D_0896F85A[];
extern s8 D_0896F85B[];
extern s8 D_0896F85C[];
extern s8 D_0896F85D[];
extern s8 D_08973841[];
extern s8 D_08973842[];
extern s8 D_08973843[];
extern s8 D_08973844[];
extern s8 D_08973845[];

extern s16 func_0885CE38(s32, Item *);
extern s32 func_0885EAA4(s32, Item *);
extern s16 func_0885DB70(s32, u8, u16, s32);
extern s16 func_0885DBD0(s32, u8, u16, s32);

#define COPY(d, s) ((d)->unk0 = (s)->unk0, (d)->unk1 = (s)->unk1, (d)->unk2 = (s)->unk2, (d)->unk4 = (s)->unk4, (d)->unk6 = (s)->unk6)

s16 func_0885D300(s32 arg0, char *arg1, u8 arg2, u8 arg3) {
    Item buf[6];
    s16 val;
    s32 i;
    Item *dst;
    Item *src;
    char *g;

    g = D_089CC438;
    if ((s32)((*(s32 *)(g + 0x6AF14) & 4) != 0) == 1
        || (s32)((*(s32 *)(g + 0x6AF14) & 8) != 0) == 1
        || (s32)(*(u16 *)(arg1 + 0x1E6) == (u8)g[0x28]) == 0
        || arg3 == 1) {
        i = 0;
        dst = buf;
        COPY(&buf[0], (Item *)(arg1 + 0x4E8));
        for (; i < 5; i++) {
            COPY(&dst[1], (Item *)(arg1 + 0x4F4));
            arg1 += 12;
            dst++;
        }
    } else {
        src = (Item *)(g + 0x4C0);
        COPY(&buf[0], &src[0]);
        COPY(&buf[2], &src[2]);
        COPY(&buf[3], &src[3]);
        COPY(&buf[4], &src[4]);
        COPY(&buf[5], &src[5]);
        COPY(&buf[1], &src[1]);
    }
    val = 0;
    switch (arg2) {
    case 0:
        if (buf[0].unk1 == 6) {
            val = func_0885CE38(arg0, &buf[0]);
        } else {
            val = *(s16 *)(D_08959FD6 + buf[0].unk2 * 24);
        }
        break;
    case 1:
        val += (s16)func_0885EAA4(arg0, &buf[2]);
        val += (s16)func_0885EAA4(arg0, &buf[3]);
        val += (s16)func_0885EAA4(arg0, &buf[4]);
        val += (s16)func_0885EAA4(arg0, &buf[5]);
        val += (s16)func_0885EAA4(arg0, &buf[1]);
        if (buf[0].unk1 == 6) {
            val += D_08960BA6[buf[0].unk2 * 28];
        } else {
            val += D_08959FD8[buf[0].unk2 * 24];
        }
        break;
    case 2:
        val += D_08963261[buf[2].unk2 * 40];
        val += D_08967681[buf[3].unk2 * 40];
        val += D_0896B821[buf[4].unk2 * 40];
        val += D_0896F859[buf[5].unk2 * 40];
        val += D_08973841[buf[1].unk2 * 40];
        break;
    case 3:
        val += D_08963262[buf[2].unk2 * 40];
        val += D_08967682[buf[3].unk2 * 40];
        val += D_0896B822[buf[4].unk2 * 40];
        val += D_0896F85A[buf[5].unk2 * 40];
        val += D_08973842[buf[1].unk2 * 40];
        break;
    case 4:
        val += D_08963263[buf[2].unk2 * 40];
        val += D_08967683[buf[3].unk2 * 40];
        val += D_0896B823[buf[4].unk2 * 40];
        val += D_0896F85B[buf[5].unk2 * 40];
        val += D_08973843[buf[1].unk2 * 40];
        break;
    case 5:
        val += D_08963264[buf[2].unk2 * 40];
        val += D_08967684[buf[3].unk2 * 40];
        val += D_0896B824[buf[4].unk2 * 40];
        val += D_0896F85C[buf[5].unk2 * 40];
        val += D_08973844[buf[1].unk2 * 40];
        break;
    case 6:
        val = func_0885DB70(arg0, buf[0].unk1, buf[0].unk2, 1);
        break;
    case 7:
        val = func_0885DB70(arg0, buf[0].unk1, buf[0].unk2, 2);
        break;
    case 8:
        val = func_0885DB70(arg0, buf[0].unk1, buf[0].unk2, 3);
        break;
    case 9:
        val = func_0885DB70(arg0, buf[0].unk1, buf[0].unk2, 4);
        break;
    case 10:
        val = func_0885DBD0(arg0, buf[0].unk1, buf[0].unk2, 1);
        break;
    case 11:
        val = func_0885DBD0(arg0, buf[0].unk1, buf[0].unk2, 2);
        break;
    case 12:
        val = func_0885DBD0(arg0, buf[0].unk1, buf[0].unk2, 3);
        break;
    case 13:
        val += D_08963265[buf[2].unk2 * 40];
        val += D_08967685[buf[3].unk2 * 40];
        val += D_0896B825[buf[4].unk2 * 40];
        val += D_0896F85D[buf[5].unk2 * 40];
        val += D_08973845[buf[1].unk2 * 40];
        break;
    }
    return val;
}
