/* unit_0882774C: 0x0882774C-0x088277DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Returns 1 when one of the five slots of the five selected records has
 * byte value 1 (arg0 is unused).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Ent {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} Ent;

typedef struct Arg {
    char pad[0x4F6];
    Ent e[1];
} Arg;

extern s32 D_0893AEB8[];
extern char *D_08978474[];

s32 func_0882774C(char *arg0, Arg *arg1) {
    s32 i;
    s32 j;
    u8 *p;

    for (i = 0; i < 5; i++) {
        p = (u8 *)D_08978474[D_0893AEB8[i]];
        p += arg1->e[D_0893AEB8[i]].unk0 * 40;
        p += 0x1E;
        for (j = 5; j > 0; j--) {
            if (*p == 1) {
                return 1;
            }
            p += 2;
        }
    }
    return 0;
}
