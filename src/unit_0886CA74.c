/* unit_0886CA74: 0x0886CA74-0x0886CADC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    char pad0[0x10];
    u16 unk10;
    char pad12[0xE];
} Ent;

typedef struct {
    char pad0[4];
    Ent ent[20];
} Mgr;

extern Mgr *D_09A4F060;
extern s8 D_08A62C9C[];
void func_0886CA74(char *arg0) {
    Ent *e = D_09A4F060->ent;
    s32 i;

    *(u8 *)(arg0 + 0x21) = 0;
    for (i = 0; i < 20; i++) {
        e->unk10 = 0xFFFF;
        D_08A62C9C[i] = -1;
        e++;
    }
}
