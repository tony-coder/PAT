import java.math.BigInteger;
import java.util.Scanner;

public class TestMain {
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
        String A, B, C;
        A = in.next();
        int cnt = 0;
        while (cnt < 10 && !check(A)) {
            B = reverse(A);
            C = solve(A);
            System.out.printf("%s + %s = %s\n", A, B, C);
            A = C;
            cnt++;
        }
        if (cnt == 10)
            System.out.println("Not found in 10 iterations.");
        else
            System.out.printf("%s is a palindromic number.\n", A);
    }
}
