# Overlays

`BOOT.BIN` has 300 program headers: one PT_LOAD (the executable), then 299 empty
slots (type 0, file size 0) whose section headers name the overlays. Each overlay
section `<name>.ovl` has a matching relocation section `.rel<name>.ovl`, also empty in
this file. The code of the overlays is therefore loaded at run time from another file.

| Load address | Count | Sections |
|---|---|---|
| 0x09A5F200 | 12 | `demo_task`, `edit_task`, `movie_task`, `install_task`, `arcade_task`, `show_select_task`, `lobby_task`, `download_task`, `gallery_task`, `game_task`, `option_task`, `cont_task` (`.ovl`) |
| 0x09C19000 | 2 | `demo_sub.ovl`, `game_sub.ovl` |
| 0x09D1A180 | 17 | `em01`, `em02`, `em07`, `em14`, `em15`, `em17`, `em20`, `em21`, `em33`, `em40`, `em54`, `em55`, `em58`, `em59`, `em75`, `em82`, `em83` (`.ovl`) |
| 0x09D63000 | 267 | `stage000.ovl` ... `stage266.ovl` |
| 0x09D65400 | 1 | `debug.elf` |

Program header memory sizes give the size reserved for each overlay (from
`tools/psp/prx_info.py`).

## Where the overlays are (hypothesis)

`PSP_GAME/USRDIR/DATA.BIN` (772732928 bytes) is the only large file on the disc. Its
first megabyte has an entropy of 8.0 bits per byte and no header: it is encrypted or
compressed. That the overlays are inside it is a hypothesis until a decrypted file
is found at one of the load addresses above.

## Next steps

1. Understand the `DATA.BIN` format (encryption, file table).
2. Find the overlay files, check them against the program header sizes.
3. One splat config per overlay group, linked against the symbols of `BOOT.BIN`.
