# Region map of `BOOT.BIN` `.text` (ULES01213)

`.text` runs from 0x08804000 to 0x0890DE38 (3572 functions found by splat), then
`.sceStub.text` (system call stubs) to 0x0890E6B8.

## Regions

| Range (approximate) | Code | Evidence |
|---|---|---|
| 0x08804000 - ~0x08811C00 | not Metrowerks style (library code, hypothesis) | below |
| ~0x08811C00 - ~0x08904000 | Metrowerks `mwccpsp` (game and engine) | 6 probe functions match (`notes/COMPILER.md`) |
| ~0x08904000 - 0x0890DE38 | not Metrowerks style; holds the entry point 0x08906934 | below |

The edges are only known to a few functions: the first edge lies between
0x08811B3C and 0x08811C84, the second between 0x08903ED0 and 0x089040A0. A few
functions inside the middle region also have the outer style (0x08901FDC,
0x089030D8, 0x08903A94, 0x08903C64), so the edges may be ragged or the measures
noisy.

## Evidence

Three measures over the splat output, all pointing to the same two outer regions:

1. **Loading a global into `$v0`.** mwccpsp writes `lui $v0, %hi(sym)` then
   `lw $v0, %lo(sym)($v0)`. In the middle region all 380 such loads use `$v0` as the
   base. In the outer regions 12 use another register (`lui $v1` /
   `lw $v0, ($v1)`), from 0x08808764 to 0x0880C57C and from 0x08907254 to
   0x089073F8; 3 use `$v0` (0x0890C20C-0x0890C254, small getters near the end of
   `.text`, maybe another object).
2. **Prologue order.** In functions that open a stack frame, mwccpsp saves `$ra`
   first: 1981 of 2051 functions between 0x08820000 and 0x08900000. Between
   0x08804000 and 0x0880C600 it is 16 of 46, between 0x08904000 and 0x08907400 it is
   5 of 24.
3. **Allegrex instructions.** `movn`, `movz`, `ext`, `ins`, `min`, `max` are dense in
   0x08804000-0x08813000 and 0x08904000-0x0890C000, rare in between (use not identified;
   0x088E9B78-0x088EB01C has a small group).

Probes: the two functions mwccpsp 3.0.1 does not reproduce (`func_0880B420`,
`func_0880EDF8`) are in the first outer region; the six it reproduces are at
0x08822990 and above.

## Compiler of the outer regions

Probe: `tools/probes/lib_leaf.c`, 5 small functions of the first outer region
(`func_0880B420` global getter, `func_0880C53C` / `func_0880C578` interrupt
suspend and resume around a nesting counter, `func_0880D97C` push on a hash
bucket, `func_0880EDF8` string length). 2026-11-11:

| Compiler | Flags | Result |
|---|---|---|
| `mwccpsp_3.0.1` builds 121, 134, 139, 147, 219 | `-O1` to `-O4`, `-O4,s` (with `-sdatathreshold 0`) | 0/5 |
| `pspsnc_1.2.7503.0` (from the sibling project) | `-O1`, `-O2`, `-O3`, `-O2 -g` | 0/5 |
| `psp-gcc` 1.3.1 / 1.7.1 (decomp.me archive) | - | not run: Linux binaries only |

What rules each one out, or not:

- **mwccpsp**: saves `$ra` at the top of the frame (`sw $ra, 0xC($sp)` in a 16-byte
  frame) and does not turn a final call into a jump; the original has
  `sw $ra, 0x0($sp)` and `j sceKernelCpuResumeIntr`.
- **SNC 1.2.7503.0**: same frame as the original (`$ra` at 0), same instruction
  shapes on `func_0880D97C`, but it writes moves as `or $rd, $rs, $zero` and
  prefers `$a0`-`$a3`; `BOOT.BIN` has no `or $rd, $rs, $zero` at all (moves are
  `addu $rd, $rs, $zero`, 2131 in the outer regions) and the original uses
  `$v0`/`$v1`. Another SNC version is not excluded.
- **GCC 3.x** (inference from GCC's MIPS frame layout, not run): saved registers sit
  at the bottom of a frame rounded up to 16, `$ra` highest, so `$ra` alone lands at
  0 and `func_0880B244` (frame 0x20, `$ra` at 0x1C, `$s0` at 0) fits; sibling calls
  become `j` from `-O2`; gas assembles `move` as `addu`. Best candidate.

Other hints that these regions are libraries (not proven): C string functions at
0x0880ED04-0x0880EE10; `.data` starts with libc strings (`"_exit"`,
`"libc:%s: should be called from main thread\n"` at 0x0890F900 and 0x0890F908); the
second region holds the entry point.

## Method

Throw-away scripts over `asm/ULES01213/boot/text*.s` (one function per `glabel`);
re-run them after any change of the splat config. A tool for this belongs in
`tools/psp` once a second use appears.
