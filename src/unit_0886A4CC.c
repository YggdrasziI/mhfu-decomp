/* unit_0886A4CC: 0x0886A4CC-0x0886A524 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A4CC: appends an entry pointer to the i-th 44-byte list of a
 * table at +0x768 (5 entries each, count byte at +0x1E of the list),
 * copying two of the entry's fields into per-list byte arrays. */

typedef signed char s8;
typedef short s16;

typedef struct {
    s16 unk0;
    s16 unk2;
    s8 unk4;
} Item;

typedef struct {
    Item *items[5];
    s8 unk14[5];
    s8 unk19[5];
    s8 count;
    char pad[44 - 0x1F];
} List;

typedef struct {
    char pad0[0x768];
    List lists[1];
} Owner;

void func_0886A4CC(Owner *p, int i, Item *item)
{
    p->lists[i].items[p->lists[i].count] = item;
    p->lists[i].unk19[p->lists[i].count] = item->unk4;
    p->lists[i].unk14[p->lists[i].count] = item->unk0;
    p->lists[i].count++;
}
