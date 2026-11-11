# Provenance of reused code and data

Every file, function or data set taken from another project, with the project, its
commit, its license and the changes made.

## Shared tools (`tools/psp/`)

The [psp-decomp-tools](https://github.com/YggdrasziI/psp-decomp-tools) submodule, the
owner's own project (CC0-1.0); its README lists the provenance of each tool.

## Build scripts (`tools/`)

| Our file | Source | Changes |
|---|---|---|
| `tools/configure.py` | the owner's jd-tlf-decomp project (CC0-1.0) | modules and versions from `decomp.toml`, relocation step only for PRX modules, Metrowerks compiler |
| `tools/extract.py` | the owner's jd-tlf-decomp project (CC0-1.0) | versions and files of this game |

`LICENSE` (CC0-1.0) is the same as the sibling projects'.

## Project documents

`SPEC.md` and `notes/` follow the structure of the owner's sibling projects, rewritten
for this game.
