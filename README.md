# Filters

Comparisons of various text filter implementations

## Get some data

Generate some data:

```
$ time paste /usr/share/dict/words <(jot -r 0 1 10) | while read WORD REPEAT; do jot -r $REPEAT | while read N; do echo "$WORD $N"; done; done >data
```

## Speed comparisons for some NO-OP filters

TODO: Count number of syscalls with `sudo dtruss -c ./wc <data 2>&1 | grep -v 'error on enabled'`.


```
$ cc -Ofast -o fread fread.c && time ./fread <data

real	0m0.037s
user	0m0.011s
sys	0m0.025s
```

```
$ cc -Ofast -o getc_unlocked getc_unlocked.c && time ./getc_unlocked <data

real	0m0.307s
user	0m0.280s
sys	0m0.026s
```

```
$ cc -Ofast -o gets gets.c && time ./gets <data

real	0m0.636s
user	0m0.608s
sys	0m0.027s
```

```
$ time perl -ne ';' <data

real	0m1.113s
user	0m1.070s
sys	0m0.040s
```

```
$ time wc -l data
 11925635 data

real	0m0.126s
user	0m0.095s
sys	0m0.030s
```

```
$ time python filter.py <data

real	0m0.725s
user	0m0.679s
sys	0m0.043s
```

```
$ time python3 filter.py <data

real	0m1.470s
user	0m1.413s
sys	0m0.051s
```

```
$ time sed -n <data

real	0m2.900s
user	0m2.859s
sys	0m0.035s
```

```
$ time awk '{}' <data

real	0m9.211s
user	0m9.154s
sys	0m0.042s
```

```
$ c++ -Ofast -o streams streams.cpp && time ./streams <data

real	0m9.256s
user	0m9.211s
sys	0m0.038s
```

```
$ c++ -Ofast -o streams_nosync streams_nosync.cpp && time ./streams_nosync <data

real	0m10.305s
user	0m10.255s
sys	0m0.040s
```

