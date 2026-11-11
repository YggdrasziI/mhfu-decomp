/* unit_0887FDAC: 0x0887FDAC-0x0887FE5C (ULES01213)
 *
 * Bounds (hypothesis): a run of accessors on an array of 20-byte entries that
 * starts at offset 0x18 of an object; the functions around are unrelated.
 * Field names are not known.
 */

typedef unsigned short u16;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 flags;
} Entry; /* 0x14 bytes */

typedef struct {
    char pad[0x18];
    Entry entries[1];
} Table;

int func_0887FDAC(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unk0;
}

int func_0887FDC4(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unk4;
}

int func_0887FDDC(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unk8;
}

u16 func_0887FDF4(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unkC;
}

u16 func_0887FE0C(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unkE;
}

u16 func_0887FE24(Table *t, int i) {
    Entry *e = &t->entries[i];

    return e->unk10;
}

int func_0887FE3C(Table *t, int i) {
    Entry *e = &t->entries[i];

    return (e->flags & 1) != 0;
}
