/* unit_08851078: 0x08851078-0x08851144 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    u16 a;
    s16 b;
} Pair;

typedef struct {
    char pad[0x390];
    Pair ent[32];
    s32 unk410;
    s32 unk414;
} Obj;

extern char *D_08A62C7C;
extern Pair *func_08869880(char *);

void func_08851078(Obj *arg0) {
    Pair *src;
    s32 i;

    for (i = 0; i < 32; i++) {
        arg0->ent[i].a = 0;
        arg0->ent[i].b = 0;
    }
    src = func_08869880(D_08A62C7C);
    i = 0;
    while (src->a != 0) {
        arg0->ent[i].a = src->a;
        arg0->ent[i].b = src->b;
        src++;
        i++;
        if (i >= 32) break;
    }
    arg0->unk410 = 0;
    arg0->unk414 = 0;
}
