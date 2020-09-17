n: length of the vector, always a power of 2	[depends on vector input]
p: prime number of the form kn + 1		[chosen]
k: positive integer				[chosen, but depends on prime]
r: primitive root of the prime p		[calculated]

e.g.,

vec 	= [v0,v1,v2,v3]
n 	= 4
p	= 5
k 	= 2

r	= 2

if my understanding holds, this should now work up to 63 bit primes

Intel Core i5-8600K

Cores: 		6
Threads: 	6
Base Frequency:	3.60 GHz

L1-I: 		192 KB	6x32 KB		8-way set associative	write-back
L1-D:		192 KB	6x32 KB		8-way set associative	write-back
L2:		1.5 MB	6x256 KB	4-way set associative	write-back
L3:		9   MB	6x1.5 MB	12-way set associative	write-back


To inverse:
1) perform an NTT with the modulo inverse of the original root
2) multiply each element with the modulo inverse of the length, modulo the modulus

note: if DIT is used without bit reversing for the forward, DIF can be used without bit reversing for the backward and vice versa
