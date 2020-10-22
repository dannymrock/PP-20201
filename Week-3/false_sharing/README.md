False sharing
-----

Compile:
```
make clean
make
```

With false sharing:
```
$ ./false-sharing.out 4 2000000000
Time 9.0866 s
```

With array padding:
```
$ ./false-sharing-sol.out 4 2000000000
Time 3.7847 s
```