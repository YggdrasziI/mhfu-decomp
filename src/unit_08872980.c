/* unit_08872980: 0x08872980-0x08872AAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s16 hp;
    u8 a;
    u8 b;
} Entry;

typedef struct {
    char pad0[0x6A54A];
    Entry tbl[5][8];
    char pad1[0x6AF12 - 0x6A54A - 5 * 8 * 4];
    u16 quest;
} Game;

extern Game *D_089CC438;
extern s32 func_0887276C(char *, s32);

void func_08872980(char *arg0) {
    u8 slot;
    s32 rank;
    Game *game;
    Entry *entry;

    slot = func_0887276C(arg0, *(u8 *)(arg0 + 0x74A));
    if (slot == 0xFF) {
        return;
    }
    game = D_089CC438;
    if (game->quest >= 10000 && game->quest < 20000) {
        if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 7) {
            rank = 0;
        } else {
            rank = 1;
        }
    } else {
        if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 6) {
            rank = 2;
        } else if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 9) {
            rank = 3;
        } else {
            rank = 4;
        }
    }
    entry = &game->tbl[rank][slot];
    ((u8 *)(arg0 + 0x5C2))[*(u8 *)(arg0 + 0x74A)] = *(u16 *)(*(char **)(arg0 + 0x720) + 0x774);
    entry->a = ((u8 *)(arg0 + 0x5C2))[*(u8 *)(arg0 + 0x74A)];
    entry->b = ((u8 *)(arg0 + 0x61C))[*(u8 *)(arg0 + 0x74A)];
    entry->hp = *(s16 *)(*(char **)(arg0 + 0x720) + 0x2E4);
    *(s16 *)(arg0 + 0x114) = *(s16 *)(*(char **)(arg0 + 0x720) + 0x2E4);
    if (entry->hp <= 0) {
        entry->hp = 0;
        entry->a = 0;
        entry->b = 0;
    }
}
