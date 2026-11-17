#ifndef UNK_TABLES_H
#define UNK_TABLES_H

/* Seven tables of records selected by a kind (0-6) and indexed by a 16-bit
 * number: five of 40-byte records, one of 24 and one of 28. Only the members
 * read by matched code are named. */

typedef struct {
    int unk0;
    unsigned char unk4;
    unsigned char unk5;
    char unk6[2];
    int unk8;
    char unkC[0x12];
    struct {
        unsigned char unk0;
        signed char unk1;
    } unk1E[5];
} UnkRec40;

typedef struct {
    char unk0[2];
    unsigned char unk2;
    char unk3;
    int unk4;
    char unk8[0x10];
} UnkRec24;

typedef struct {
    char unk0[2];
    unsigned char unk2;
    char unk3;
    int unk4;
    char unk8[0x14];
} UnkRec28;

extern UnkRec40 D_08973834[];
extern UnkRec40 D_08963254[];
extern UnkRec40 D_08967674[];
extern UnkRec40 D_0896B814[];
extern UnkRec40 D_0896F84C[];
extern UnkRec24 D_08959FCC[];
extern UnkRec28 D_08960B9C[];

/* The 40-byte tables again, by kind (0-4). */
extern UnkRec40 *D_08978474[];

#endif
