package com.test;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T;
        T = in.nextInt();
        BigInteger A, B, C;
        for (int i = 1; i <= T; i++) {
            A = in.nextBigInteger();
            B = in.nextBigInteger();
            C = in.nextBigInteger();
            if (A.add(B).compareTo(C) > 0)
                System.out.printf("Case #%d: true\n", i);
            else
                System.out.printf("Case #%d: false\n", i);
        }
    }
}
