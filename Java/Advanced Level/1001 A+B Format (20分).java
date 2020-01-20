import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b;
        Scanner in = new Scanner((System.in));
        a = in.nextInt();
        b = in.nextInt();
        int sum = a + b;
        String s = Integer.toString(sum);
        int cnt = 1;
        String ans = new String();
        if (sum >= 0) {
            for (int i = s.length() - 1; i >= 0; i--, cnt++) {
                //System.out.print(s.charAt(i));
                ans += s.charAt(i);
                if (cnt % 3 == 0 && cnt != s.length())
                    //System.out.print(",");
                    ans += ",";
            }
        } else {
            for (int i = s.length() - 1; i >= 1; i--, cnt++) {
                //System.out.print(s.charAt(i));
                ans += s.charAt(i);
                if (cnt % 3 == 0 && cnt != s.length() - 1)
                    //System.out.print(",");
                    ans += ",";
            }
            ans += "-";
        }
        for (int i = ans.length() - 1; i >= 0; i--) {
            System.out.print(ans.charAt(i));
        }
    }
}
