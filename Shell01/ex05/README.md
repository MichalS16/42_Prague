Required turn-in file for this exercise (verbatim, `cat -e` view):

```
"\?$*'MaRViN'*$?\"$
```

Content: only the two characters `42`, nothing else (no trailing newline).

This filename contains characters (`"`, `\`, `?`, `*`) that are reserved and
forbidden in Windows/NTFS filenames, so it cannot be created on this
Windows-hosted working copy. Create it on a real POSIX filesystem (Linux/WSL)
before submission, e.g.:

```sh
printf '42' > '"\?$*'"'"'MaRViN'"'"'*$?\"'
```
