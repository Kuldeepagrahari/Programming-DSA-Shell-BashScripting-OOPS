int minBitFlips(int start, int goal) {
        int xorr = start ^ goal;
        int setBits = __builtin_popcount(xorr);
        return setBits;
    }