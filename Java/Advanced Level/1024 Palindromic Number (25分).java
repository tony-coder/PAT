import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static String reverse(String str) {
        return new StringBuffer(str).reverse().toString();
    }

    private static String solve(String N) {
        BigInteger n1 = new BigInteger(N);
        String r = reverse(N);
        BigInteger n2 = new BigInteger(r);
        return n1.add(n2).toString();
    }

    private static boolean check(String n) {
        int len = n.length();
        for (int i = 0; i < len / 2; ++i) {
            if (n.charAt(i) != n.charAt(len - i - 1))
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String N;
        int K;
        N = in.next();
        K = in.nextInt();
        int i;
        for (i = 0; i < K; i++) {
            if (check(N))
                break;
            N = solve(N);
        }
        System.out.println(N);
        System.out.println(i);
    }
}
