Xorshift RNG reference code
===========================

The Xorshift family of random number generators were introduced by George Marsaglia
in 2003 in a paper published in the Journal of Statistical Software:

   * Marsaglia, G. (2003) Xorshift RNGs.  _Journal of Statistical Software_
     vol. 8 issue 14.  http://www.jstatsoft.org/v08/i14/

This repository contains a working copy of the reference code provided by Marsiglia
in his paper, tweaked very slightly as follows:

   * Marsaglia's paper uses ```unsigned long``` as the word type, which may be
     either 32- or 64-bit depending on the implementation.  This has been changed
     to uint32_t to ensure the word type is an unsigned 32-bit integer.

   * Some small typos in Marsaglia's paper have been corrected.  Without these
     corrections the Xorshift32 and Xorshift160 implementations depart strongly
     from uniformity.  See the git history log for details of these corrections.

In all other respects the xorNNN() functions here reflect Marsaglia's sample code
and may thus be useful to verify other implementations.

DISCLAIMER: no claims are made for the suitability of these RNGs for any purpose,
certainly not crypto or any mission-critical or security-related applications.
Even using them to verify other Xorshift implementations may be dubious, given
the observed typos in the original source material.  The author thinks he has
corrected everything that needs to be corrected, but you should check for yourself.
In other words, use this code at your own risk. :-)
